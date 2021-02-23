/*
31.07.2020 - Ruben Allenstein
Blatt 7 - Aufgabe 2 - Fuer Linked List:
 Implementieren Sie einen binären Suchbaum über unsigned int. Denken Sie an den Destruktor, Copykonstruktor, Zuweisungsoperator
 und Ausgabeoperator.

***********************************************************************************************

Kelb Review:
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
