//Klausur Sommersemester 2019


#include <iostream>

using namespace std;

struct A {
    A() {
        cout << "+A" << endl;
    }
    A(const A&) {
        cout << "+A(A)" << endl;
    }
    ~A() {
        cout << "-A" << endl;
    }
};

struct B {
    B() {
        cout << "+B" << endl;
    }
    B(const B& b) : m_a(b.m_a) {
        cout << "+B(B)" << endl;
    }
    ~B() {
        cout << "-B" << endl;
    }
    A m_a;
};

struct X : public B {
    X() {
        cout << "+X" << endl;
    }
    X(const X& x) : B(x) {
        cout << "+X(X)" << endl;
    }
    ~X() {
        cout << "-X" << endl;
    }
};

void test(const X& a = X()) {
    X x = a; //X x(a);
}

int main() {
    test();
    cout << "*" << endl;
    X* p = new X();
    test(*p);
    return 0;
}
