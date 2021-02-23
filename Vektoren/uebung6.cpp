#include <iostream>
using namespace std;

class Vector {
private:
    const unsigned m_W;
    unsigned m_S;
    unsigned m_N = 0;
    int *m_pField = nullptr;

public:
    // Konstruktor
    Vector(unsigned s = 1, unsigned w = 0) : m_S(s), m_W(w), m_pField(new int[m_S]) {
    }
    
    // Copy-Konstruktor
    Vector(const Vector &vec) : m_S(vec.m_S), m_W(vec.m_W), m_N(vec.m_N){
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
    
    //Assignment Operator
    Vector& operator=(const Vector& vec) {
        if(this == &vec) {
            return *this;
        }
        delete [] m_pField;
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
        int *newField = new int[newSize];
        for (unsigned i = 0; i < m_S; ++i) {
            newField[i] = m_pField[i];
        }
        delete [] m_pField;
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
    
    void deleteStartEnd(unsigned start, unsigned end) {
        for (unsigned j = end + 1, idx = 0; j < m_N; ++j) {
            m_pField[start + idx] = m_pField[end + 1 + idx];
            ++idx;
        }
        m_N -= end - start + 1;
    }
    
    void deleteEverySecond() {
        unsigned idx = 0;
        for (unsigned j = 0; j < m_N; ++j) {
            if (j % 2 == 0) {
                m_pField[idx++] = m_pField[j];
            }
        }
        m_N = idx;
    }
    
    void deleteMatch(int i) {
        unsigned removed = 0;
        for (unsigned j = 0, k = 0; j < m_N; ++j) {
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

int main() {
    Vector vec2;
    vec2.push_back(9);
    vec2.push_back(11);
    vec2.push_back(12);
    vec2.push_back(13);
    vec2.push_back(14);
    vec2.push_back(15);
    vec2.push_back(16);
    vec2.push_back(17);
    cout << vec2 << endl << endl;
    vec2.deleteStartEnd(1,3);
    cout << vec2 << endl << endl << endl;
    vec2.deleteEverySecond();
    cout << vec2 << endl;
}
