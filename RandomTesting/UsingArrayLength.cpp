#include <iostream>

using std::cout;

int main() {
    int guesses[7];
    int arrayExample[] = {1,2,55,6,14,8};
    
    int size = sizeof(guesses); // zeigt die Bytes des Arrays an
    int size1 = sizeof(arrayExample);
    
    int arrayLength = sizeof(guesses) / sizeof(int);
//  int arrayLength = sizeof(guesses) / sizeof(guesses[0]);

    
    
    cout << size << "\t" << size1 << std::endl << "\t" << arrayLength << std::endl;

}
