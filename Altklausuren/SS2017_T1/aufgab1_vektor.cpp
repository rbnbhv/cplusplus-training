/* Review: 06.08.2020

Kelb Review:
- so passt es
*/

#include <iostream>
using namespace std;

class Vector {

private:

    unsigned m_S = 1;
    unsigned m_N = 0;
    int *m_pField = new int[m_S];

public:
    friend ostream &operator<<(ostream &os, const Vector &vec) {
        for(unsigned i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        return os;
    }
    //Zugriffsoperator
    int& operator[](unsigned idx) {
        return m_pField[idx];
    }
    //Zugriffsoperator
    const int& operator[](unsigned idx) const {
        return m_pField[idx];
    }
    //push_back
    void push_back(int i) {
        if (m_N >= m_S)
            resize();
        m_pField[m_N++] = i;
    }
    void pop_back() {
        --m_N;
        if(m_N <= (m_S/2)) {
            const unsigned cNewSize = m_S/2;
            int* pNewObjects = new int[cNewSize];
            for(unsigned i = 0; i < cNewSize; ++i)
                pNewObjects[i] = m_pField[i];
            delete [] m_pField;
            m_S = cNewSize;
            m_pField = pNewObjects;
            pNewObjects = nullptr;
        }
    }
    //size
    unsigned size() const {
        return m_N;
    }
private:

    void resize() {
        const unsigned cNewSize = m_S * 2;
        int* pNewObjects = new int[cNewSize];
        for(unsigned i = 0; i < m_S; ++i)
            pNewObjects[i] = m_pField[i];
        delete [] m_pField;
        m_S = cNewSize;
        m_pField = pNewObjects;
        pNewObjects = nullptr;
    }
};

int main() {
    Vector vec1;
    vec1.push_back(2);
    vec1.push_back(5);
    vec1.push_back(2);
    vec1.push_back(9);
    vec1.push_back(1);
    vec1.push_back(1);
    cout << vec1 << endl;
    vec1.pop_back();
    vec1.pop_back();
    vec1.pop_back();
    vec1.pop_back();
    cout << vec1 << endl;
    return 0;
}
