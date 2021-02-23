/*
 15.06.2020 - Ruben Allenstein
 Der Bubblesort.
 */

#include <iostream>
#include <ctime>

using namespace std;


void init_unsorted(int arrayToSort[], int length) {
    cout << "Das noch unsortiere Array" << endl;
    for (int i = 0; i < length; ++i) {
        arrayToSort[i] = rand() % 20;
        cout << arrayToSort[i] << "\t";
    }
    cout << endl;
}

void init(int arrayToSort[], int length) {
    init_unsorted(arrayToSort, length);
}

void swap(int field[], int iPos1, int iPos2) {
    int tmp = field[iPos1];
    field[iPos1] = field[iPos2]; field[iPos2] = tmp;
}

void print(int field[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << field[i] << "\t";
    }
    cout << endl;
}

void bubble_sort(int arrayToSort[], int length) {
    for (int i = 1; i < length; ++i) {
        bool bAtLeastOneSwap = false;
        for (int j = 0; j < length - i; ++j) {
            if (arrayToSort[j] > arrayToSort[j + 1]) {
                swap(arrayToSort, j, j + 1);
                bAtLeastOneSwap = true;
            }
        }
        print(arrayToSort, length);
        if (!bAtLeastOneSwap) {
            return;
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    const int length = 10; // kann auf die Größen 100, 1000 & 10000 hochskaliert werden
    int arrayToSort[length];
    init(arrayToSort, length);
    cout << endl << "Nach Durchgang 1:" << endl;
    bubble_sort(arrayToSort, length);
}
