/* Review: 04.08.2020
Vektor:
- Jedes Vektorelement, dass den Wert i gespeichert hat, soll gelöscht werden. --> deleteMatch(int i)
- Speicher- und Laufeffizient
- fehlende Operatoren und Methoden hinzufügen

Kelb Review:
- deleteMatch muss, wie hier nun, speicher- und laufzeiteffizient sein.
*/


void deleteMatch(int i) {
     unsigned removed = 0;
     for(unsigned j = 0, k = 0; j < m_N; ++j) {
         if(m_pField[j] != i) {
             m_pField[k++] = m_pField[j];
         } else {
             ++removed;
         }
     }
     m_N -= removed;
 }

int& operator[](unsigned idx) {
    return m_pField[idx];
}

const int& operator[](unsigned idx) const {
    return m_pField[idx];
}
