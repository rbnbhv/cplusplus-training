/*
15.06.2020 - Ruben Allenstein
 Aufgabe 4:
 Erweitern Sie die Implementierungen von Vektoren und Listen um eine pop_front und pop_back Methode, die das
 erste bzw. letzte Element entfernt.
 
 Frage:
 Wir versuchen mit m_pTail nicht ständig die Liste durchlaufen zu müssen, was jedoch beim pop_back nicht möglich zu verhindern
 ist. Dennoch finden wir es von uns noch zu kompliziert gestaltet. Was sagen Sie?
 
 Antwort:
 sieht besser aus. Bei pop_back muss man durch die ganze Liste laufen,
 weil Sie auf das vorletzte Element zugreifen müssen, auf das Sie aber
 keinen direkten Zugriff haben. Ich hätte die pop_back Methode so
 implementiert:

          if (m_pHead == m_pTail) {
              delete m_pHead;
              m_pHead = m_pTail = nullptr;
          } else {
              auto p = m_pHead;
              while (p->m_pNext != m_pTail)
                  p = p->m_pNext;
              delete m_pTail;
              m_pTail = p;
              m_pTail->m_pNext = nullptr;
          }

 dadurch sparen Sie sich das if in der while-Schleife. Ist ein bisschen
 schneller, aber Ihre Lösung ist auch richtig, aber schwer zu verstehen,
 weil die Schleife p testet, Sie danach aber direkt in if
 (p->m_pNext->m_pNext) den Nachfolger von p dereferenzieren, ohne ihn
 vorher getestet zu haben. Das funktioniert nur, weil Sie am Ende der
 Schleife p auf p->m_pNext setzen _UND_ im Fall des Löschens p->m_pNext
 auf nullptr setzen. Insgesamt eine Argumentation, die man nicht auf
 Anhieb erkennt.

 
 */

#include <iostream>

using namespace std;

class A {

private:
    int val;

public:
    A(int v = 0) : val(v) {

    }
    friend ostream &operator<<(ostream &os, const A &a) {
        os << a.val << "  ";
        return os;
    }
};

class LinkedList {
    struct ListElem {
        ListElem* m_pNext = nullptr;
        A m_iCont;

        ListElem(A iElem, ListElem* pNext) : m_pNext(pNext), m_iCont(iElem) {

        }
        friend ostream& operator<<(ostream& os, const ListElem& crArg) {
            os << crArg.m_iCont << " ";
            if (crArg.m_pNext)
                os << *crArg.m_pNext;
            return os;
        }
    };
private:
    ListElem* m_pHead = nullptr;
    ListElem* m_pTail = nullptr;

public:
    LinkedList() {

    }
    LinkedList(const LinkedList &llist) {
        copyHelper(llist);
    }
    ~LinkedList() {
        destroy();
    }
    LinkedList &operator=(const LinkedList &llist) {
        if(this == &llist)
            return *this;
        destroy();
        copyHelper(llist);
        return *this;
    }
    void copyHelper(const LinkedList &llist) {
        ListElem* p = llist.m_pHead;
        while(p) {
            this->push_back(p->m_iCont);
            p = p->m_pNext;
        }
    }
    void destroy() {
        ListElem *p = nullptr;
        while(m_pHead) {
            p = m_pHead->m_pNext;
            delete m_pHead;
            m_pHead = p;
        }
        m_pTail = nullptr;
    }
    friend ostream& operator<<(ostream& os, const LinkedList& crArg) {
        if (crArg.m_pHead)
            os << *crArg.m_pHead;
        return os;
    }
    void push_front(A iElem) {
        m_pHead = new ListElem(iElem, m_pHead);
        if(!m_pTail)
            m_pTail = m_pHead;
    }
    void push_back(A iElem) {
        ListElem *node = new ListElem(iElem, nullptr);
        if(!m_pHead)
            m_pHead = m_pTail = node;
        else {
            m_pTail->m_pNext = node;
            m_pTail = m_pTail->m_pNext;
        }
    }
    void pop_front() {
        ListElem *p = m_pHead;
        m_pHead = m_pHead->m_pNext;
        delete p;
        if (!m_pHead)
            m_pTail = nullptr;
    }
    void pop_back() {
        ListElem *p = m_pHead;
        if(p->m_pNext) {
            while(p) {
                    if(!p->m_pNext->m_pNext) {
                        m_pTail = p;
                        delete p->m_pNext;
                        p->m_pNext = nullptr;
                    }
                p = p->m_pNext;
            }
        } else {
            delete p;
            m_pHead = nullptr;
            m_pTail = nullptr;
        }
    }
    A front() {
        return m_pHead->m_iCont;
    }
    A back() {
        return m_pTail->m_iCont;
    }
};

int main() {
    LinkedList list0;
    list0.push_back(100);
    cout << list0 << endl;
    list0.push_back(99);
    cout << list0 << endl;
    list0.push_back(98);
    cout << list0 << endl;
    list0.push_back(110);
    cout << list0 << endl;
    list0.push_back(199);
    cout << list0 << endl;
    list0.push_back(978);
    cout << list0 << endl;
    cout << list0.front() << endl;
    cout << list0.back() << endl;
    list0.pop_front();
    cout << list0 << endl;
    list0.pop_front();
    cout << list0 << endl;
    list0.pop_front();
    cout << list0 << endl;
    list0.pop_front();
    cout << list0 << endl;
    list0.pop_front();
    cout << list0 << endl;
    list0.pop_front();
    cout << list0 << endl;
    list0.push_back(100);
    cout << list0 << endl;
    list0.push_back(99);
    cout << list0 << endl;
    list0.push_back(98);
    cout << list0 << endl;
    list0.pop_back();
    cout << list0 << endl;
    list0.pop_back();
    cout << list0 << endl;
    list0.pop_back();
    cout << list0 << endl;
    list0.push_back(199);
    cout << list0 << endl;
    list0.push_back(978);
    cout << list0 << endl;
    LinkedList list1(list0);
    cout << list1 << endl;
    LinkedList list2 = list1;
    list1.pop_front();
    cout << list1 << endl;
    cout << list2 << endl;
    return 0;
}
