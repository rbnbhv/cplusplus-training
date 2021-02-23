//
//  extraMethodenLL.cpp
//  Uebungen
//
//  Created by Ruben Allenstein on 04.10.20.
//  Copyright © 2020 Ruben Allenstein. All rights reserved.
//

#include <stdio.h>


void deleteIndex(int index) {
    ListElem **p = &m_pHead;
    for (unsinged i = 0; i < index; ++i) {
        if (((*p)->m_pNext) == m_pTail) {
            m_pTail = *p;
        }
        p = &((*p)->m_pNext);
    }
    ListElem *pToDelete = *p;
    *p = (*p)->m_pNext;
    delete pToDelete;
}

void deleteEverySecond() {
    ListElem *prev = m_pHead;
    ListElem *node = m_pHead->m_pNext;
    while (prev && node) {
        prev->m_pNext = node->m_pNext;
        delete node;
        prev = prev->m_pNext;
        if (prev) {
            node = prev->m_pNext;
            m_pTail = prev;
        }
    }
}

void invert() {
    ListElem *p = m_pHead;
    ListElem *prev = nullptr;
    ListElem *next = nullptr;
    m_pTail = m_pHead;
    while (p) {
        next = p->m_pNext;
        p->m_pNext = prev;
        prev = p;
        p = next;
    }
    m_pHead = prev;
}
