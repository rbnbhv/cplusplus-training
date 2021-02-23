/* Review: 07.08.2020
Aufgabe 2: BinTree
 Implementieren Sie eine Objektmethode, die den maximalen und den minmalen Wert der in den Knoten gespeicherten int-Werten zurückliefert. (unsortierter Binärbaum)
 
 Ansatz:
 Die minMax Methode sollte auf einen unsortierten Binärbaum angewandt werden.
 Wir hoffen mit unserem rekursiven Lösungsansatz einmal den ganzen Baum zu durchlaufen.

 In Kommentaren haben wir ein Lösungsansatz für einen sortierten Baum.

 Kelb Review:
das funktioniert so noch nicht. Sie durchlaufen den gesamten Baum,
bekommen aber dennoch nicht in jedem Fall das Maximum und Minimum. Das
Problem sieht man aber nur bei unsortierten Bäumen. Sie reichen zwei
Werte min und max in die Rekursion hinab. Da ist das Problem. Wenn in
z.B. dem linken Teilbaum das Maximum liegt, im rechten Teilbaum aber ein
Wert liegt, der kleiner als das Maximum im linken Teilbaum, aber größer
als das bisherige Maximum ist, wird dann das lokale Maximum des rechten
Teilbaums genommen. Das wäre aber falsch. Man kann das auf zwei Arten
korrigieren. Zum einen min und max als Referenzen übergeben, oder ---
die bessere Variante --- min und max gar nicht übergeben, sondern die
Werte direkt aus dem Result Array verwenden. Dazu müssen Sie zum Anfang
das Array mit dem Wert aus der Wurzel füllen, was auch das Problem
(siehe unten) mit dem Baum, der nur aus der Wurzel besteht, lösen würde.
 
 Antwort:
 danke, wir haben nun minMax für sortierte und unsortierte Bäume umgestellt.
 Wir hoffen, dass es jetzt passt - wir hatten nämlich Probleme einen unsortierten Baum zu erstellen um die Methode zu testen.
 
 Kelb Review:
 ja, so passt es. Die Methode int* minMax(L* node, int* arr) sollte aber
 besser kein int* zurück liefern, weil das Ergebnis eh das übergebene
 Argument arr ist.
 */

#include <iostream>

using namespace std;

class T {
    struct L {
        L(int i) : m_c(i) {

        }
        int m_c;
        L* m_Left = nullptr;
        L* m_Right = nullptr;
    };

private:
    L* m_Root = nullptr;

public:
    int* minMax() {
        int* arr = new int[2];
        arr[0] = m_Root->m_c;
        arr[1] = m_Root->m_c;
        minMax(m_Root, arr);
        return arr;
    }
    void minMax(L* node, int* arr) {
        if(!node)
            return;
        if(node->m_c < arr[0])
            arr[0] = node->m_c;
        if(node->m_c > arr[1])
            arr[1] = node->m_c;
        minMax(node->m_Left, arr);
        minMax(node->m_Right, arr);
    }
    bool insert2(int iKey) {
        L* pTmp = m_Root;
        L* pFather = nullptr;
        while (pTmp) {
            pFather = pTmp;
            if (iKey < pTmp->m_c)
                pTmp = pTmp->m_Left;
            else if (pTmp->m_c < iKey)
                pTmp = pTmp->m_Right;
            else
                return false;
        }
        pTmp = new L(iKey);
        if (pFather == nullptr)
            m_Root = pTmp;
        else if (iKey < pFather->m_c)
            pFather->m_Left = pTmp;
        else
            pFather->m_Right = pTmp;
        return true;
    }
    void printTree(ostream& os, L* node) {
        if(!node)
            return;
        cout << node->m_c << ":  ";
        if(node->m_Left)
            cout << "Left: " << node->m_Left->m_c<< "; ";
        if(node->m_Right)
            cout << "Right: " << node->m_Right->m_c << "; ";
        cout << endl;
        printTree(os, node->m_Left);
        printTree(os, node->m_Right);
    }

     friend ostream& operator<<(ostream &os, T& bt) {
        if(bt.m_Root)
            bt.printTree(os, bt.m_Root);
        return os;
    }
};

int main() {
    T tree;
    tree.insert2(3);
    tree.insert2(8);
    tree.insert2(13);
    tree.insert2(5);
    tree.insert2(7);
    tree.insert2(2);
    tree.insert2(9);
    tree.insert2(6);
    cout << tree << endl;
    cout << "Min: " << tree.minMax()[0] << ", Max: " << tree.minMax()[1] << endl;
    return 0;
}
