#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

void print_array(int array[], int count) {
    cout << "Deine Tipps waren ";
    for (int i = 0; i < count; ++i) {
        cout << array[i] << ", ";
    }
    cout << "du hast somit insgesamt " << count << " Versuche gebraucht!" << endl;
}

void play_game() {
    const int SIZE = 6;
    int guesses[SIZE];
    int count = 0;

    int random = rand() % 20;
   // cout << random << endl;
    bool found = false;
    while(!found) {
        int guess;
        cout << "Bitte schätze die Zahl: ";
        cin >> guess;
        guesses[count++] = guess;
        if (count >= SIZE) {
            cout << "Zu viele Versuche! Du hast es nicht geschafft!" << endl;
            break;
        }
        if (guess < random) {
            cout << "Dein Tipp ist zu klein" << endl;
        }
        else if(guess > random) {
            cout << "Deine Tipp ist zu groß" << endl;
        }
        else {
            cout << "Good Job! Korrekt!" << endl;
            print_array(guesses, count);
            found = true;
        }
    }
}

int main() {
    srand((unsigned)time(NULL));
    int choice;
    do {
        cout << "1. Play Game" << endl << "2. Quit" << endl;
        cin >> choice;

        switch (choice) {
            case 1:
                play_game();
                break;
            case 2:
                cout << "okay, ciao" << endl;
        }
    }
    while (choice == 1);
    return 0;
 }
