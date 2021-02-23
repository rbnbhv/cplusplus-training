// Was gibt das Programm aus?
// SS2020 - Aufgabe 1 - geschrieben im Oktober 2020

#include <iostream>
using namespace std;

struct A {
    A() {
        cout << "+A" << endl;
    }

    A(const A&) {
        cout << "A(A)" << endl;
    }
    
    ~A() {
        cout << "-A" << endl;
    }
    
    A& operator-(const A&) {
        cout << "-A" << endl;
        return *this;
    }
};

struct B {
    B() {
        cout << "+B" << endl;
    }

    B(const B& crArg) : m_a(crArg.m_a){
        cout << "B(B)" << endl;
    }
    
    ~B() {
        cout << "-B" << endl;
    }
    
    A m_a;
};

void test(B b,unsigned ui) {
    cout << "test " << ui << endl;
    if (ui > 0) {
        test(b, ui-1);
    }
    else {
        A a;
        cout << "Schluss" << endl;
    }
}

int main() {
    A a;
    B b;
    B* pB = new B();
    test(b,2);
    A aa = a;
    a = pB->m_a;
    return 0;
}
