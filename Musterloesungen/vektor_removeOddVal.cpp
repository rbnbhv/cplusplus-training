/* 17.08.2020
 Vektoren: remove Odd Value
 */

#include <iostream>

class V {
public:
    friend std::ostream& operator<<(std::ostream& os, const V& v) {
        for(unsigned ui = 0; ui < v.size(); ++ui)
            std::cout << v[ui] << " ";
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

    void removeOddVal() {
        unsigned j = 0;
        for(unsigned i = 0; i < m_N; ++i) {
            if(m_E[i] % 2 == 0) {
                m_E[j] = m_E[i];
                ++j;
            }
        }
        m_N = j;
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
    v.push_back(3);
    std::cout << v << std::endl;
    v.push_back(4);
    std::cout << v << std::endl;
    v.push_back(8);
    std::cout << v << std::endl;
    v.push_back(5);
    std::cout << v << std::endl;
    v.push_back(3);
    std::cout << v << std::endl;
    v.push_back(5);
    std::cout << v << std::endl;
    v.push_back(8);
    std::cout << v << std::endl;
    v.push_back(7);
    std::cout << v << std::endl;
    v.push_back(7);
    std::cout << v << std::endl;
    v.push_back(6);
    std::cout << v << std::endl;
    v.push_back(7);
    std::cout << v << std::endl;
    v.push_back(3);
    std::cout << v << std::endl;
    v.push_back(4);
    std::cout << v << std::endl;
    v.push_back(8);
    std::cout << v << std::endl;
    v.push_back(5);
    std::cout << v << std::endl;
    v.push_back(3);
    std::cout << v << std::endl;
    v.push_back(5);
    std::cout << v << std::endl;
    v.push_back(8);
    std::cout << v << std::endl;
    v.push_back(7);
    std::cout << v << std::endl;
    v.push_back(7);
    std::cout << v << std::endl;
    v.push_back(6);
    std::cout << v << std::endl;
    v.push_back(7);
    std::cout << v << std::endl;
    v.removeOddVal();
    std::cout << v << std::endl;
    return 0;
}
