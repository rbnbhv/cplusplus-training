/*
Gegeben sei die folgende Implementierung eines Binärbaums. Implementieren Sie die beiden Operatoren
friend bool operator==(const BinTree&, const Bintree&) und BinTree& operator=(const BinTree&).
 
 class BinTree {
    struct Node {
        Node(int iKey) : m_iKey(iKey) {}
        int m_iKey;
        Node* m_pLeft = nullptr;
        Node* m_pRight = nullptr;
    };
 
    Node* m_pRoot = nullptr;
 }
 
 --> Meine Aufgabe:
     friend bool operator==()
     BinTree& operator =()
     copyHelper()
     destroy()
 */

#include <iostream>
using namespace std;

class BinTree {
   struct Node {
       Node(int iKey) : m_iKey(iKey) {
       }
       int m_iKey;
       Node* m_pLeft = nullptr;
       Node* m_pRight = nullptr;
   };

   Node* m_pRoot = nullptr;
    
public:
    Node* copyHelper(Node *node) {
        if (!node) {
            return nullptr;
        }
        Node *copyRoot = new Node(node->m_iKey);
        copyRoot->m_pLeft = copyHelper(node->m_pLeft);
        copyRoot->m_pRight = copyHelper(node->m_pRight);
        return nullptr;
    }
    
    void destroy(Node *node) {
        if (node) {
            destroy(node->m_pLeft);
            destroy(node->m_pRight);
            delete node;
        }
    }
    
    BinTree& operator =(const BinTree& crArg) {
        if(this == &crArg) {
            return *this;
        }
        destroy(m_pRoot);
        m_pRoot = copyHelper(crArg.m_pRoot);
        return *this;
    }
    
    friend bool operator==(const BinTree& crArg1, const BinTree& crArg2) {
        return &crArg1 == &crArg2;
    }
}
