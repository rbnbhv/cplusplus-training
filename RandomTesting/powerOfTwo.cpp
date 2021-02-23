#include <iostream>

using std::cout;

double pow(double a, int b) {
    double result = 1.0;
    for (int i = 0; i < b; ++i) {
        result *= a;
    }
    return result;
}

int main() {
    cout << pow(3.33,3) << std::endl;
}
