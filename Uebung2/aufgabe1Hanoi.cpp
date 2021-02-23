/*
 27.03.2020 - Ruben Allenstein
 Aufgabe 1:
 Implementieren Sie in die Türme von Hanoi (ohne Klassen, nur mit Text auf dem Konsolenfenster wie
 in Prog I „Hanoi2“ Lösung, bei der die Türme als Blockgrafik ausgegeben werden).
 */

#include <iostream>
using namespace std;

const int anzTowers = 3;
const int hoeheTowers = 5;

void setInitTower(int towers[][hoeheTowers]) {
    for (int i = 0; i < hoeheTowers; ++i) {
        towers[0][i] = 2 * i + 1;
    }
}
void init(int towers[][hoeheTowers]) {
    for (int i = 0; i < anzTowers; ++i) {
        for (int j = 0; j < hoeheTowers; ++j) {
            towers[i][j] = 0;
        }
    }
    setInitTower(towers);
}

void printStone(int iWidth) {
    if (iWidth == 0) {
        for (int i = 0; i < 21; ++i) {
            cout << " ";
        }
    }
    else {
        for (int i = 0; i < (21 - iWidth) / 2; ++i) {
            cout << " ";
        }
        for (int i = 0; i < iWidth; ++i) {
            cout << "+";
        }
        for (int i = 0; i < (21 - iWidth) / 2; ++i) {
            cout << " ";
        }
    }
}

void printTowers(int towers[][hoeheTowers]) {
    for (int j = 0; j < hoeheTowers; ++j) {
        for (int i = 0; i < anzTowers; ++i) {
            printStone(towers[i][j]);
        }
        cout << endl;
    }
    cout << "----------------------------------------------------------------------\n\n";
}

void moveStone(int towers[][hoeheTowers], int iFrom, int iTo) {
    for (int i = 0; i < hoeheTowers; ++i) {
        if (towers[iFrom][i] != 0) {
            int iStone = towers[iFrom][i];
            towers[iFrom][i] = 0;
            for (int j = 0; j < hoeheTowers; ++j) {
                if (towers[iTo][j] != 0) { towers[iTo][j - 1] = iStone;
                    return;
                }
            }
            towers[iTo][hoeheTowers - 1] = iStone;
            return;
        }
    }
}

void move(int towers[][hoeheTowers], int n, int von, int nach, int ueber) {
    if (n > 0) {
        move(towers, n - 1, von, ueber, nach);
        moveStone(towers, von, nach);
        printTowers(towers);
        move(towers, n - 1, ueber, nach, von);
    }
}
int main() {
    int towers[anzTowers][hoeheTowers];
    init(towers);
    printTowers(towers);
    move(towers, hoeheTowers, 0, 2, 1);
    return 0;
}
