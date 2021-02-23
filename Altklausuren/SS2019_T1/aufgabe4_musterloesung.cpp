#include <iostream>
using namespace std;

class V {
public:
    class iterator {
        int* p;
    public:
        iterator(int* value) : p(value) {
        }
        iterator& operator++() {
            ++p;
            return *this;
        }
        
        bool operator != (const iterator& other) {
            return p != other.p;
        }
        
        int& operator *() {
            return *p;
        }
    };

    iterator begin() {
        return iterator(m_E);
    }

    iterator end() {
       return iterator(m_E + m_N);
    }

    const iterator begin() const {
        return iterator(m_E);
    }

    const iterator end() const {
        return iterator(m_E + m_N);
    }

    friend std::ostream& operator<<(std::ostream& os, const V& v) {
        for(int i : v)
            std::cout << i << " ";
        return os;
    }

    void push_back(int i) {
        if(m_N >= m_S)
            resize();
        m_E[m_N++] = i;
    }

    void resize() {
        const unsigned cuiNewSize = m_S * 2;
        int* pNewObjects = new int[cuiNewSize];
        for(unsigned i = 0; i < m_S; ++i) {
            pNewObjects[i] = m_E[i];
        }
        delete[] m_E;
        m_S = cuiNewSize;
        m_E = pNewObjects;
        pNewObjects = nullptr;
    }

    int& operator[](unsigned index){
        return m_E[index];
    }

    const int& operator[](unsigned index) const {
        return m_E[index];
    }

    unsigned size() const {
        return m_N;
    }
private:

    int* m_E = new int[1];
    unsigned m_S = 1;
    unsigned m_N = 0;
};

int main() {
    V v;
    v.push_back(1);
    std::cout << v << std::endl;
    for(V::iterator i = v.begin(); i != v.end(); ++i)
        ++(*i);
    std::cout << v << std::endl;
    for(V::iterator i = v.begin(); i != v.end(); ++i)
        ++(*i);
    std::cout << v << std::endl;
    v.push_back(1);
    v.push_back(1);
    for(V::iterator i = v.begin(); i != v.end(); ++i)
        ++(*i);
    std::cout << v << std::endl;
    v.push_back(1);
    std::cout << v << std::endl;
    for(V::iterator i = v.begin(); i != v.end(); ++i)
        ++(*i);
    std::cout << v << std::endl;
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    v.push_back(1);
    for(V::iterator i = v.begin(); i != v.end(); ++i)
        ++(*i);
    std::cout << v << std::endl;
    return 0;
}
