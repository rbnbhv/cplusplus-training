#include <iostream>

using std::cout;
using std::endl;

int  main() {
    int n;
    std::cin >> n;
    const int SIZE =  n;
    int array[SIZE];
    cout << sizeof(array) << endl;
}
