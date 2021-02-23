#include <iostream>
using namespace std;


class Vector {
private:
    const unsigned m_W;
    unsigned m_S;
    unsigned m_N = 0;
    int* m_pField = nullptr;
    
public:
    Vector(unsigned s = 1, unsigned w = 0) : m_W(w), m_S(s), m_pField(new int[m_S]) {
    }
    
    Vector(const Vector& vec) : m_S(vec.m_S), m_N(vec.m_W), m_W(vec.m_W){
        copyHelper(vec);
    }
    ~Vector() {
        delete[] m_pField;
    }
    
    Vector& operator =(const Vector& vec) {
        if (this == &vec) {
            return *this;
        }
        delete[] vec.m_pField;
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
private:
    void resize() {
        const unsigned newSize = m_W == 0 ? m_S * 2 : m_W+m_S;
        int* newField = new int[newSize];
        for (unsigned i = 0; i < m_S; ++i) {
            newField[i] = m_pField[i];
        }
        delete[] m_pField;
        m_pField = newField;
        m_S = newSize;
        newField = nullptr;
    }
    
public:
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
        else {
            m_pField[m_N++] = elem;
        }
    }
    
    void pop_front() {
        --m_N;
        for (unsigned i = 0; i < m_N; ++i) {
            m_pField[i] = m_pField[i+1];
        }
    }
    
    void pop_back() {
        --m_N;
    }
    
    unsigned size() const {
           return m_N;
       }
    
    friend ostream& operator << (ostream& os, const Vector& vec) {
         for (unsigned i = 0; i < vec.size(); ++i) {
             cout << vec[i] << " ";
         }
         return os;
     }
    
    int& operator[](int index) {
        return m_pField[index];
    }

    const int& operator[](int index) const {
        return m_pField[index];
    }

};

int main() {
    
}
