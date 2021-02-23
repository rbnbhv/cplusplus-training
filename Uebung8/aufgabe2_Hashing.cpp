/*
23.08.2020 - Ruben Allenstein
Aufgabe 2:
Implementieren Sie eine Hashtabelle, die Strings auf float Werte abbildet. Denken Sie an den Destruktor, Copykonstruktor und
 Zuweisungsoperator. Implementieren Sie für die Hashtabelle auch eine remove Methode, die Elemente aus der Hashtabelle löscht.
 Die remove Methode bekommt einen Schlüssel (sprich String) übergeben. Testen Sie Ihre Methode und prüfen Sie, ob Sie nach dem
 Löschen noch immer alle anderen Elemente finden können. Wann ist es sinnvoll, ein resize durchzuführen?
*/

#include <iostream>
using namespace std;

class Hashing {

    struct Node {

        Node(const char* iKey = nullptr, const float& crData = 0, bool b = false) : m_iKey(stringDuplicate(iKey)), m_Data(crData), flag(b) {

        }

        Node(const Node&) = delete;

        Node& operator=(const Node&) = delete;

        ~Node() {
            delete[] m_iKey;
        }

        friend bool operator==(const Node& str1, const Node& str2)  {
            return stringCompare(str1.m_iKey, str2.m_iKey) == 0;
        }

        static int stringCompare(const char* strg1, const char* strg2) {
            while( ( *strg1 != '\0' && *strg2 != '\0' ) && *strg1 == *strg2 ) {
                ++strg1;
                ++strg2;
            }
            if(*strg1 == *strg2) {
                return 0;
            } else {
                return *strg1 - *strg2;
            }
        }

        static unsigned stringLength(const char* source) {
            unsigned i;
            for (i = 0; source[i] != '\0'; ++i);
            return i;
        }

        static char* stringCopy(char* destination, const char* source) {
            char* start = destination;
            while(*source != '\0') {
                *destination = *source;
                ++destination;
                ++source;
            }
            *destination = '\0';
            return start;
        }

        static char* stringDuplicate(const char* source) { //difference to stringCopy -> stringDuplicate will allocate memory, that has to be freed later
            char* duplicate = new char[stringLength(source) + 1];
            if(!duplicate)
                return nullptr;
            stringCopy(duplicate, source);
            return duplicate;
        }

        const char* m_iKey;
        float m_Data;
        bool flag;
    };

public:

    Hashing() {
        initArray();
    }

    Hashing(const Hashing& ha) {
        copyHelper(ha);
    }
    Hashing& operator=(const Hashing& ha) {
        if(this == &ha)
            return *this;
        destroy();
        copyHelper(ha);
        return *this;
    }

    ~Hashing() {
        destroy();
    }

    void initArray() {
        m_pEntries = new Node*[m_uiCapacity];
        for(unsigned ui = 0; ui < m_uiCapacity; ++ui)
            m_pEntries[ui] = nullptr;
    }

    void destroy() {
        for(unsigned i = 0; i < m_uiCapacity; ++i) {
            if(m_pEntries[i]) {
                delete m_pEntries[i];
            }
        }
        delete[] m_pEntries;
    }
    void copyHelper(const Hashing& ha) {
        m_uiCapacity = ha.m_uiCapacity;
        m_uiNrOfEntries = ha.m_uiNrOfEntries;
        initArray();
        for(unsigned i = 0; i < m_uiCapacity; ++i) {
            if(ha.m_pEntries[i] && !ha.m_pEntries[i]->flag) {
                this->insert(ha.m_pEntries[i]->m_iKey, ha.m_pEntries[i]->m_Data);
            }
        }
    }

    void remove(const char* iKey) {
        Node n(iKey);
        unsigned uiIndex = hashKey(n.m_iKey, m_uiCapacity);
        for(unsigned ui = 0; ui < m_uiCapacity; ++ui) {
            if (m_pEntries[uiIndex] && n == *m_pEntries[uiIndex]) {
                m_pEntries[uiIndex]->flag = true;
                --m_uiNrOfEntries;
            }
            uiIndex = (uiIndex + 1) % m_uiCapacity;
        }
    }


    void insert(const char* iKey, const float& crData) {
        unsigned uiIndex = hashKey(iKey, m_uiCapacity);
        for(unsigned ui = 0; ui < m_uiCapacity; ++ui) {
            if (m_pEntries[uiIndex] && m_pEntries[uiIndex]->flag) {
                delete m_pEntries[uiIndex];
                m_pEntries[uiIndex] = nullptr;
            }
            if (!m_pEntries[uiIndex]) {
                m_pEntries[uiIndex] = new Node(iKey, crData); //flag = false, erfolgt im Node Konstruktor
                ++m_uiNrOfEntries;
                if (m_uiNrOfEntries > m_uiCapacity*8/10)
                    resize();
                return;
            }
            uiIndex = (uiIndex + 1) % m_uiCapacity;
        }
    }

    float* search(const char* iKey) const {
        Node n(iKey);
        unsigned uiIndex = hashKey(n.m_iKey, m_uiCapacity);
        for(unsigned ui = 0; ui < m_uiCapacity && m_pEntries[uiIndex]; ++ui) {
            if (n == *m_pEntries[uiIndex] && !m_pEntries[uiIndex]->flag) {
                return &m_pEntries[uiIndex]->m_Data;
            }
            else if(n == *m_pEntries[uiIndex] && m_pEntries[uiIndex]->flag) {
                return nullptr;
            }
            uiIndex = (uiIndex + 1) % m_uiCapacity;
        }
        return nullptr;
    }

    void resize() {
        const unsigned cuiOldCapacity = m_uiCapacity;
        Node** pOldEntries = m_pEntries;
        m_uiCapacity = (m_uiCapacity + 1) * 2 - 1;
        m_pEntries = new Node*[m_uiCapacity];
        for(unsigned ui = 0; ui < m_uiCapacity; ++ui)
            m_pEntries[ui] = nullptr;
        m_uiNrOfEntries = 0;
        for(unsigned ui = 0; ui < cuiOldCapacity; ++ui) {
            if (pOldEntries[ui] && !m_pEntries[ui]->flag) {
                insert(pOldEntries[ui]->m_iKey, pOldEntries[ui]->m_Data);
                delete pOldEntries[ui];
            }
        }
        delete[] pOldEntries;
    }

    unsigned hashKey(const char* cpStr, unsigned uiLength) const {
        unsigned res;
        for(res = 0; *cpStr != '\0'; ++cpStr)
            res = ((res << 6) + *cpStr) % uiLength;
        return res;
    }

    void printHashtable() {
        for(unsigned i = 0; i < m_uiCapacity; ++i) {
            if(m_pEntries[i] && !m_pEntries[i]->flag) {
                cout << m_pEntries[i]->m_iKey << " ";
            }
        }
        cout << endl;
    }

private:

    unsigned m_uiCapacity = 1023;
    Node** m_pEntries = nullptr;
    unsigned m_uiNrOfEntries = 0;
};


int main() {
    Hashing ha;
    ha.insert("Hallo", 1.0);
    ha.insert("Juhu", 2.0);
    ha.insert("super", 3.0);
    ha.insert("top1", 4.0);
    ha.insert("top2", 5.0);
    ha.insert("Hallo", 6.0);
    ha.insert("top4", 7.0);
    ha.insert("top5", 8.0);
    ha.printHashtable();
    Hashing ha3;
    ha3.insert("ABC", 1.0);
    ha3.insert("Hans", 2.0);
    ha3.insert("Mueller", 3.0);
    ha3.printHashtable();
    ha3 = ha;
    ha3.printHashtable();
    ha3.remove("Juhu");
    ha3.printHashtable();
    ha3.remove("Hallo");
    ha3.printHashtable();
    ha3.insert("Hallo", 9.0);
    ha3.printHashtable();
    cout << *ha3.search("super") << endl;
    return 0;
}
