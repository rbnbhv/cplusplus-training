#include <iostream>

using namespace std;

int x =  5;

void testVariable() {
    x = 10;
    // int x = 12;
    cout << "Der Wert von x lautet: " << x << endl;
}

void testF() {
    int x = 11;
    cout << "die globale Variable x lautet: " << ::x << endl;
    if (x != ::x) {
        cout << "Die beiden x'e sind ungleich!" << endl;
    }
}

int main() {
    cout << x << endl;
    int x = 10;
    cout << x << endl;
    testVariable();
    testF();
}
