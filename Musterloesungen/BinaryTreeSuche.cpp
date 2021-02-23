/*
29.08.2020 - Ruben Allenstein
Blatt 7 - Aufgabe 3:
Implementieren Sie für den binären Suchbaum über unsigned
int eine rekursive Suchmethode und eine Methode,
die die Anzahl der Knoten zurückliefert.
*/

class BinaryTree {
    
    // Iterative Suche
    string* iterSearch(int key) {
        Node *p_Tmp = m_pRoot;
        while (p_Tmp) {
            if (key == p_Tmp->m_key) {
                return &p_Tmp->m_data;
            }
            p_Tmp = (key < p_Tmp->m_key) ? p_Tmp->m_pLeft : p_Tmp->m_pRight
        }
        return nullptr;
    }
    
    // Rekursive Suche
    string *recSearch(int key) {
        return recSearch(m_pRoot, key);
    }
    string *recSearch(Node *p_Tmp, int key) {
        if(!p_Tmp) {
            return nullptr;
        }
        if(key == p_Tmp->m_key) {
            return &p_Tmp->m_data;
        }
        return key < p_Tmp->m_key ? recSearch(p_Tmp->m_pLeft, key) : recSearch(p_Tmp->m_pRight, key);
    }
};

int main() {
    
}
