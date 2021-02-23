/*
 Linked List -  deleteMatch (lösche alle Elemente mit dem Wert i aus der Liste)
Frage:
 Wir haben noch nicht solch eine deleteMatch Variante zur einfach verketteten Liste besprochen.
 Ist diese soweit in Ordnung?
 
 Antwort:
 spontan konnte ich keinen Fehler sehen. Mich hatte erst die erste while
 Schleife irritiert und mich gefragt, warum Sie kein if verwendet haben.
 Aber da am Anfang ja mehrere Elemente u.U. gelöscht werden müssen, ist
 der initiale Fall in der Tat durch eine Schleife zu lösen. Ihre Lösung
 ist daher auch in zwei Teile aufgeteilt. Der erste Teil löscht und setzt
 den Kopf (m_pHead) um, solange vorne zu löschende Elemente gespeichert
 sind. Der zweite Teil löst dann das Problem in der restlichen Liste.

 Sie können die Aufteilung in zwei Teile umgehen, indem Sie mit Pointern
 auf Pointern arbeiten. Dann gibt es keine Unterscheidung zwischen dem
 m_pHead und einem beliebigen m_pNext mehr. Im Grunde sind beides
 Speicherbereiche, die jeweils einen Pointer auf ein ListElem enthalten.
 Ob Sie das eine oder das andere ändern, spielt für den Speicher keine
 Rolle. Ein Lösung sähe dann so aus:

      void deleteMatch2(int i) {
          ListElem** p = &m_pHead;
          ListElem* pLast = nullptr;
          while(*p) {
              if ((*p)->m_iCont == i) {
                  ListElem* tmp = *p;
                  *p = (*p)->m_pNext;
                  delete tmp;
              } else {
                  pLast = *p;
                  p = &(*p)->m_pNext;
              }
          }
          m_pTail = pLast;
      }

 p zeigt immer (ist niemals ein nullptr) auf einen Speicher, der einen
 Pointer auf ein ListElem enthält. Dieser kann natürlich nullptr werden,
 p selber nie. Der blöde m_pTail macht die elegante Lösung ein wenig
 kaputt, daher gibt es noch zusätzlich den normalen pLast Pointer, der
 suksessiv auf das jeweils letzte nicht gelöschte Element zeigt. Damit
 zeigt er dann am Ende der Schleife auf das letzte gültige Element und
 kann für m_pTail verwendet werden.
 
 */

#include <iostream>
using namespace std;

class LinkedList {
    struct ListElem {
        ListElem* m_pNext = nullptr;
        int m_iCont;

        ListElem(int iElem, ListElem* pNext) : m_pNext(pNext), m_iCont(iElem) {

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
    void push_front(int iElem) {
        m_pHead = new ListElem(iElem, m_pHead);
        if(!m_pTail)
            m_pTail = m_pHead;
    }
    void push_back(int iElem) {
        ListElem *node = new ListElem(iElem, nullptr);
        if(!m_pHead)
            m_pHead = m_pTail = node;
        else {
            m_pTail->m_pNext = node;
            m_pTail = m_pTail->m_pNext;
        }
    }
    
    void deleteMatch(int i) {
        ListElem** p = &m_pHead;
        ListElem* pLast = nullptr;
        while(*p) {
            if ((*p)->m_iCont == i) {
                ListElem* tmp = *p;
                *p = (*p)->m_pNext;
                delete tmp;
            } else {
                pLast = *p;
                p = &(*p)->m_pNext;
            }
        }
        m_pTail = pLast;
    }
    
    int front() {
        return m_pHead->m_iCont;
    }
    int back() {
        return m_pTail->m_iCont;
    }
};

int main() {
    LinkedList list0;
//    list0.push_back(100);
//    list0.push_back(100);
//    list0.push_back(100);
//    list0.push_back(100);
//    list0.push_back(100);
    list0.push_back(100);
    list0.push_back(98);
    list0.push_back(110);
    list0.push_back(100);
    list0.push_back(199);
    list0.push_back(978);
    list0.push_back(100);
    list0.push_back(100);
    cout << list0 << endl;
    list0.deleteMatch(100);
//    list0.deleteMatch(978);
//    list0.deleteMatch(98);
    cout << list0 << endl;
    cout << list0.front() << endl;
    cout << list0.back() << endl;
    return 0;
}
