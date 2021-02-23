#include <iostream>
using namespace std;

struct A {
    A() { cout << "+A" << endl; }
    A(const A&) { cout << "+A(A)" << endl; }
    ~A() { cout << "-A" << endl; }
};

struct B {
    B() { cout << "+B" << endl; }
    B(const B& x) : m_a(x.m_a) { cout << "+B(B)" << endl; }
    ~B() { cout << "-B" << endl; }
    
    A m_a;
};

B* test2(B b) {
    return new B(b);
}

B* test(const B& b) {
    B x;
    delete test2(x);
    return test2(b);
}

int main() {
    B b;
    test(b);
    return 0;
}
