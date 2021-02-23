#include <iostream>
using namespace std;

class Vector {
private:
    const unsigned m_W;
    unsigned m_S;
    unsigned m_N = 0;
    int* m_pField = nullptr;
    
public:
    // Construktor:
    Vector(unsigned s = 1, unsigned w = 0) : m_S(s), m_W(w), m_pField(new int[m_S]){
    }
    
    // Copy-Construktor:
    Vector(const Vector& vec) : m_W(vec.m_W), m_S(vec.m_S), m_N(vec.m_N) {
        copyHelper(vec);
    }
    
    // Destruktor:
    ~Vector() {
        delete[] m_pField;
    }
    
    void copyHelper(const Vector& vec) {
        m_pField = new int[m_S];
        for (unsigned i = 0; i < m_N; ++i) {
            m_pField[i] = vec.m_pField[i];
        }
    }
    
    //assignment operator
    Vector& operator =(const Vector& vec) {
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
        for (unsigned i = m_N; i >= 1; --i) {
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
    
    int& operator[](unsigned idx) {
        return m_pField[idx];
    }
    
    const int& operator[](unsigned idx) const {
        return m_pField[idx];
    }
};

int main() {
    Vector vec1;
    vec1.push_back(1);
    vec1.push_back(2);
    vec1.push_back(3);
    cout << vec1 << endl;
    
    Vector vec2;
    vec2.push_back(9);
    vec2.push_back(11);
    vec2.push_back(12);
    vec2.push_back(13);
    vec2.push_back(11);
    cout << vec2 << endl;
    
    vec2.pop_front();
    vec2.pop_front();
    vec2.pop_front();
    vec2.pop_front();
    vec2.pop_front();
    
    cout << vec2 << " Vor diesem Satz ist kein Wert mehr da " << endl;
    vec2 = vec1;
    cout << vec2 << endl;
    return 0;
}
