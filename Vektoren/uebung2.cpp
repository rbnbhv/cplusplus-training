#include <iostream>
using namespace std;

class Vector {
private:
    const unsigned m_W;
    unsigned m_S;
    unsigned m_N = 0;
    int *m_pField = nullptr;
    
public:
    Vector(unsigned s = 1, unsigned w = 0) : m_W(w), m_S(s), m_pField(new int[m_S]) {
    }
    
    Vector(const Vector& vec) : m_W(vec.m_W), m_S(vec.m_S), m_N(vec.m_N) {
        copyHelper(vec);
    }
    
    ~Vector() {
        delete[] m_pField;
    }
    
    void copyHelper(const Vector& vec) {
        m_pField = new int[m_S];
        for (unsigned i = 0; i < m_N; ++i) {
            m_pField[i] = vec.m_pField[i];
        }
    }
    
    Vector& operator =(Vector& vec) {
        if (this == &vec) {
            return *this;
        }
        delete[] m_pField;
        m_S = vec.m_S;
        m_N = vec.m_N;
        copyHelper(vec);
        return *this;
    }
    
    void push_front(int elem) {
        if (m_N >= m_S) {
            resize();
        }
        for (unsigned i = m_N; i > 0; ++i) {
            m_pField[i] = m_pField[i-1];
        }
        m_N++;
        m_pField[0] = elem;
    }
    
    void push_back(int elem) {
        if (m_N >= m_S) {
            resize();
        }
        m_pField[m_N++] = elem;
    }
    
private:
    void resize() {
        const unsigned newSize = m_W == 0 ? m_S * 2 : m_N + m_W;
        int* newField = new int[newSize];
        for (unsigned i = 0; i < m_S; ++i) {
            newField[i] = m_pField[i];
        }
        m_S = newSize;
        delete[] m_pField;
        m_pField = newField;
        newField = nullptr;
    }
    
public:
    void pop_front() {
        --m_N;
        for (unsigned i = 0; i < m_N; ++i) {
            m_pField[i] = m_pField[i+1];
        }
    }
    
    void pop_back() {
        --m_N;
        if (m_N <= (m_S/2)) {
            const unsigned newSize = m_S/2;
            int* pNewObjects = new int[newSize];
            for (unsigned i = 0; i < newSize; ++i) {
                pNewObjects[i] = m_pField[i];
            }
            delete[] m_pField;
            m_S = newSize;
            m_pField = pNewObjects;
            pNewObjects = nullptr;
        }
    }
    
    unsigned size() const {
        return m_N;
    }
    
    friend ostream& operator <<(ostream& os, const Vector& vec) {
        for (unsigned i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        return os;
    }
    
    int& operator[](int idx) {
        return m_pField[idx];
    }
    
    const int& operator[](int idx) const {
        return m_pField[idx];
    }
    
    void deletestartEnd(unsigned start, unsigned end) {
        for (unsigned i = end + 1, idx = 0; i < m_N ; ++i) {
            m_pField[start + idx] = m_pField[end + idx + 1];
            ++idx;
        }
        m_N -= end - start + 1;
    }
    
    void deleteEverySecond() {
        unsigned idx = 0;
        for (unsigned i = 0; i < m_N; ++i) {
            if (i % 2 == 0) {
                m_pField[idx++] = m_pField[i];
            }
        }
        m_N = idx;
    }
    
    void deleteMatch(int j) {
        unsigned removed = 0;
        for (unsigned i = 0, k = 0; j < m_N; ++i) {
            if (m_pField[i] != j) {
                m_pField[k++] = m_pField[i];
            }
            else {
                ++removed;
            }
        }
        m_N -= removed;
    }
};
