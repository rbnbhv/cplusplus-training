#include <stdio.h>
using namespace std;

class Vector {
private:
    const unsigned m_S;
    unsigned m_W;
    unsigned m_N = 0;
    int *m_pField = nullptr;
    
public:
    Vector(unsigned s = 1, unsigned w = 0) :  m_W(w), m_S(s), m_pField(new int[m_S]) {
        
    }
    
    Vector(const Vector& vec) : m_S(vec.m_S), m_N(vec.m_N), m_W(vec.m_W) {
        copyHelper(vec);
    }
    
    ~Vector() {
        destroy[] m_pField;
    }
    
    Vector& operator = (Vector& vec) {
        if (this == &vec) {
            return *this;
        }
        destroy[] m_pField;
        copyHelper(vec);
        return *this;
    }
    
    void copyHelper(const Vector& vec) {
        m_pField = new int[m_S];
        for (unsigned i = 0; i < m_N; ++i) {
            m_pField[i] = vec.m_pField[i];
        }
    }
    
    void push_front(int elem) {
        if (m_N >= m_S) {
            resize();
        }
        for (unsigned i = m_N; i > 0; --i) {
            m_pField[i] = m_pField[i-1];
        }
        m_pField[0] = elem;
        ++m_N;
    }
    
    void push_back(int elem) {
        if (m_N >= m_S) {
            resize();
        }
        m_pField[m_N++] = elem;
    }
    
private:
    void resize() {
        const unsigned newSize = m_W == 0 ? m_S*2 : m_S + m_W;
        int* newField = new int[newSize];
        for (unsigned i = 0; i < m_S; ++i) {
            newField[i] = m_pField[i];
        }
        delete[] m_pField;
        m_S = newSize;
        m_pField = newField;
        newField = nullptr;
    }
    
public:
    void pop_front() {
        --m_N;
        for (unsigned i = 0; i < m_N; ++m_N) {
            m_pField[i] = m_pField[i+1];
        }
    }
    
    void pop_back() {
        --m_N;
        if (m_N <= m_S/2) {
            const unsigned NewSize = m_S/2;
            int* newObjects = new int[newSize];
            for (unsigned i = 0; i < NewSize; ++i) {
                newObjects[i] = m_pField[i];
            }
            delete[] m_pField;
            m_pField = newObjects;
            m_S = NewSize;
            newObjects = nullptr;
        }
    }
    
    void deleteStartEnd(unsigned start, unsigned end) {
        for (unsigned j = end +1, idx = 0; j < m_N; ++j) {
            m_pField[start + idx] = m_pField[end + 1 + idx];
            ++idx;
        }
        m_N -= end - start + 1;
    }
    
    void deleteMatch(int i) {
        unsigned removed = 0;
        for (unsigned j = 0, k = 0; j < m_N; ++i) {
            if (m_pField[j] != i) {
                m_pField[k++] = m_pField[j];
            }
            else {
                ++removed;
            }
        }
        m_N -= removed;
    }
};
