#include <iostream>
using namespace std;

//Methode deleteSingle, die jeden Knoten, der genau einen Nachfolger hat, aus dem Baum löscht. Bedenken sie, dass dies auch die
// Wurzel sein kann.

class T {
    struct L {
        L(int i, const string& data) : m_i(i), m_Data(data) { }
        
        int m_i;
        string m_Data;
        L* m_Left = nullptr;
        L* m_Right = nullptr;
    };

    public:

    void insertRec(int key, const string& data) {
        m_Root = insertRec(m_Root, key, data);
    }

    static L* insertRec(L* node, int i, const string& data) {
        if(node == nullptr) {
            return new L(i, data);
        } else {
            if(i < node->m_i) {
                node->m_Left = insertRec(node->m_Left, i, data);
            } else if (i > node->m_i) {
                node->m_Right = insertRec(node->m_Right, i, data);
            }
            return node;
        }
    }

    void print(const string& prefix, const L* node, bool isLeft) {
        if(node != nullptr) {
            cout << prefix;
            cout << (isLeft ? "├──" : "└──" );

            cout << node->m_i << endl;

        print( prefix + (isLeft ? "│   " : "    "), node->m_Left, true);
        print( prefix + (isLeft ? "│   " : "    "), node->m_Right, false);
        }
    }

    void print() {
        print("", m_Root, false);
    }

    bool remove2(int key) {
        L** tmp = &m_Root;
        while((*tmp) != nullptr) {
            if(key < (*tmp)->m_i) {
                tmp = &((*tmp)->m_Left);
            } else if (key > (*tmp)->m_i) {
                tmp = &((*tmp)->m_Right);
            } else {
                //gefunden
                L* pToDelete = nullptr;
                //Wenn es keinen rechten Nachfolger gibt
                if((*tmp)->m_Right == nullptr) {
                    pToDelete = *tmp;
                    *tmp = (*tmp)->m_Left;
                } else {
                    L** pNF = &((*tmp)->m_Right);
                    while((*pNF)->m_Left != nullptr) {
                        pNF = &(*pNF)->m_Left;
                    }
                    pToDelete = *pNF;
                    (*tmp)->m_i = (*pNF)->m_i;
                    (*tmp)->m_Data = (*pNF)->m_Data;
                    *pNF = (*pNF)->m_Right;
                }
                delete pToDelete;
                return true;
            }
        }
        return false;
    }

    private:
        L* m_Root = nullptr;
};

int main() {
    /*
    T t;
    t.insertRec(8, "8");
    t.insertRec(5, "5");
    t.insertRec(10, "10");
    t.insertRec(2, "2");
    t.insertRec(6, "6");
    t.insertRec(9, "9");
    t.insertRec(11, "11");

    //t.print();
    //t.remove1(2);
    //t.print();

    T t2;
    t2.insertRec(20, "20");
    t2.insertRec(40, "40");
    t2.insertRec(14, "14");
    t2.insertRec(9, "9");
    t2.insertRec(16, "16");
    t2.insertRec(35, "35");
    t2.insertRec(50, "50");
    t2.insertRec(3, "3");
    t2.insertRec(11, "11");
    t2.insertRec(15, "15");
    t2.insertRec(17, "17");
    t2.insertRec(32, "32");
    t2.insertRec(36, "36");
    t2.insertRec(45, "45");
    t2.insertRec(60, "60");

    t2.print();
    t2.remove1(40);
    t2.print();*/

    T t;

    t.insertRec(5, "5");
    t.insertRec(3, "3");
    t.insertRec(2, "2");
    t.insertRec(10, "10");
    t.insertRec(9, "9");
    t.insertRec(13, "13");
    t.insertRec(12, "12");
    t.insertRec(15, "15");
    t.insertRec(11, "11");
    t.insertRec(14, "14");
    t.insertRec(18, "18");

    cout << "Vor löschen:" << endl;
    t.print();

    t.remove1(13);

    cout << "Nach löschen: " << endl;
    t.print();
}
