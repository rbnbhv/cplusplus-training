/*
 27.03.2020 - Ruben Allenstein
 Aufgabe 2:
 Implementieren Sie den Bubble-, Selection- und Insertionsort und Quicksort für int-Arrays. Testen Sie Ihre Programme mit
 Arrays der Größen 10, 100, 1000 und 10000. Dabei sollen die Arrays bereits sortiert, invers sortiert und mit zufälligen
 Zahlen belegt sein.
 */

#include <iostream>
using namespace std;

void init_sorted(int field_sorted[], int length) {
    for (int i = 0; i < length; ++i) {
        field_sorted[i] = i;
    }
}

void init_inversSorted(int field_inversSorted[], int length) {
    for (int i = 0; i < length; ++i) {
        field_inversSorted[length - 1 - i] = i;
    }
}

void init_unsorted(int field_unsorted[], int length) {
    for (int i = 0; i < length; ++i) {
        field_unsorted[i] = rand();
    }
}

void init(int field_sorted[], int field_inversSorted[], int field_unsorted[], int length) {
    init_sorted(field_sorted, length);
    init_inversSorted(field_inversSorted, length);
    init_unsorted(field_unsorted, length);
}

void swap(int field[], int iPos1, int iPos2) {
    int tmp = field[iPos1];
    field[iPos1] = field[iPos2];
    field[iPos2] = tmp;
}

void print(int field[], int length) {
    for (int i = 0; i < length; ++i) {
        cout << field[i] << " ";
    }
    cout << endl << "--------------------------------------------------------" << endl;
}

void bubble_sort(int field[], int length) {
    for (int i1 = 1; i1 < length; ++i1) {
        bool bAtLeastOneSwap = false;
        for (int i2 = 0; i2 < length - i1; ++i2) {
            if (field[i2] > field[i2 + 1]) {
                swap(field, i2, i2 + 1);
                bAtLeastOneSwap = true;
            }
        }
        print(field, length);
        if (!bAtLeastOneSwap) {
            return;
        }
    }
}

int main() {
    const int length = 10; // kann auf die Größen 100, 1000 & 10000 hochskaliert werden
    int field_sorted[length];
    int field_inversSorted[length];
    int field_unsorted[length];
    init(field_sorted, field_inversSorted, field_unsorted, length);
    cout << "Sorted Array:\n" << endl;
    bubble_sort(field_sorted, length);
    cout << "inversSorted Array:\n" << endl;
    bubble_sort(field_inversSorted, length);
    cout << "Unsorted Array:\n" << endl;
    bubble_sort(field_unsorted, length);
}
