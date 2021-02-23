#include <iostream>
using namespace std;

class Vector {
    const unsigned m_W;
    unsigned m_S;
    unsigned m_N = 1;
    int *m_pField = nullptr;
    
    Vector(unsigned s = 1, unsigned w = 0) : m_W(w), m_S(s), m_pField(new int[m_S]) {
    }
    
    Vector(const Vector& vec) : m_W(vec.m_W), m_S(vec.m_S), m_N(vec.m_N) {
        copyHelper(vec);
    }
    
    ~Vector() {
        delete[] m_pField;
    }
    
    Vector& operator =(const Vector& vec) {
        if(this == &vec) {
            return *this;
        }
        delete[] m_pField;
        m_S = vec.m_S;
        m_N = vec.m_N;
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
        ++m_N;
        for (unsigned i = 1; i < m_N; ++i) {
            m_pField[i] = m_pField[i-1]
        }
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
        const unsigned newSize = m_W == 0 ? m_S * 2 : m_S + m_W;
        int* newField = new int[newSize];
        for (unsigned i = 0; i < newSize; ++i) {
            newField[i] = m_pField[i];
        }
        delete[] m_pField;
        m_S = newSize;
        m_pField = newField;
        newField = nullptr;
    }
    
public:
    void pop_front() {
        for (unsigned i = 0; i < m_N-1; ++i) {
            m_pField[i] = m_pField[i+1];
        }
        --m_N;
    }
    
    void pop_back() {
        if (m_N <= m_S/2) {
            const unsigned newSize = m_S/2;
            int *newField = new int[newSize];
            for (unsigned i = 0; i < newSize; ++i) {
                newField[i] = m_pField[i];
            }
            delete[] m_pField;
            m_S = newSize;
            m_pField = newField;
            newField = nullptr;
        }
    }
    
    friend ostream& operator << (ostream& os, const Vector& vec) {
        for (unsigned i = 0; i < vec.size(); ++i) {
            cout << vec[i] << " ";
        }
        return os;
    }
    
    unsigned size() const {
        return m_N;
    }
    
    int& operator[] (unsigned idx) {
        return m_pField[idx];
    }
    
    const int& operator[] (unsigned idx) const {
        return m_pField[idx];
    }
    
    void deleteStartEnd(unsigned start, unsigned end) {
        for (unsigned i = end+1 ; idx = 0; i < m_N; ++i) {
            m_pField[start + idx] = m_pField[end + 1 + idx];
            ++idx;
        }
        m_N -= end - start + 1;
    }
    
    void deleteEverySec() {
        for (unsigned i = 0, idx = 0; i < m_N; ++i) {
            if (i % 2 != 0) {
                m_pField[idx++] = m_pField[i];
            }
        }
        m_N = idx;
    }
    
    void deleteMatch(int k) {
        for (unsigned i = 0, idx = 0; i < m_N; ++i) {
            if (m_pField[i] != k) {
                m_pField[idx++] = m_pField[i];
            }
        }
        m_N = idx;
    }
};
