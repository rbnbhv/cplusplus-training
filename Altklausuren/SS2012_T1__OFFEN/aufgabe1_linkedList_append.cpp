/* Review: 10.08.2020
Aufgabe 1: Linked List
Implementieren Sie eine Objektmethode List<T> append(List<T> arg), die die Liste arg an die aktuelle Liste anfügt und
 zurückliefert. Die aktuelle Liste darf nicht verändert werden. Die aktuelle Liste und das Argument arg dürfen nur jeweils
 einmal durchlaufen werden.

 Frage:
 anbei die Methode append, bei unserem Lösungsansatz bleibt die aktuelle Liste in dessen Reihenfolge erhalten, die übergebende
 angehängte Liste ist allerdings invertiert. Ist das so richtig?

 Antwort:
 das ist so noch nicht richtig. Die aktuelle Liste wird verändert. Wenn
 Sie am Ende Ihres Programms l ausgeben, sehen Sie, dass l sich verändert
 hat. Das soll nicht sein. Auch sollen sich die Elemente der übergebenen
 Liste nicht invertieren. Die übergebene Liste sollte Call-by-Referenz
 übergeben werden, ansonsten haben Sie ja schon bei der Übergabe eine
 Kopie angelegt.
 
 Frage:
 anbei die neue append Methode. Wir bitten um einen Review.

Antwort:
 Sie denken zu kompliziert. Wenn Sie zusätzlich zu der geforderten
 append-Methode noch eine push_back Methode in der Liste implementieren,
 wird die append-Methode um die Hälfte kürzer und Sie müssen die
 Ergebnisliste nach dem Aufbau nicht noch einmal durchlaufen.
 
 */

#include <iostream>
using namespace std;

class List {
    class ListElem {
    public:
        ListElem(int elem, ListElem *next) {
            m_elem = elem;
            m_next = next;
        }

        friend ostream& operator<<(ostream& os, const ListElem& crArg) {
            os << crArg.m_elem << " ";
            if (crArg.m_next)
                os << *crArg.m_next;
            return os;
        }
        ListElem *m_next;
        int m_elem;
    };

public:
     List append(const List &arg) {
        ListElem* p1 = m_Head;
        ListElem* p2 = arg.m_Head;
        List newList;
        while(p1) {
            newList.push_front(p1->m_elem);
            p1 = p1->m_next;
        }
        while(p2) {
            newList.push_front(p2->m_elem);
            p2 = p2->m_next;
        }
        ListElem* p = newList.m_Head;
        ListElem* prev = nullptr;
        ListElem* next = nullptr;
        newList.m_Tail = newList.m_Head;
        while (p) {
            next = p->m_next;
            p->m_next = prev;
            prev = p;
            p = next;
        }
        newList.m_Head = prev;
        return newList;
    }
    void push_front(int elem) {
        m_Head = new ListElem(elem, m_Head);
        if(m_Tail == nullptr) {
            m_Tail = m_Head;
        }
    }
    friend ostream& operator<<(ostream& os, const List& crArg) {
        if (crArg.m_Head)
            os << *crArg.m_Head;
        return os;
    }
private:
    ListElem *m_Head = nullptr;
    ListElem *m_Tail = nullptr;
};

int main() {
    List l;
    l.push_front(59);
    l.push_front(60);
    l.push_front(61);
    l.push_front(62);
    l.push_front(63);
    cout << l << endl;
    List l2;
    l2.push_front(1);
    l2.push_front(2);
    l2.push_front(3);
    l2.push_front(4);
    l2.push_front(5);
    cout << l2 << endl;
    cout << l.append(l2) << endl;
    cout << l << endl;
    return 0;
}
