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
    const int SIZE = 251;
    int guesses[SIZE];
    int count = 0;
 
    int random = rand() % 251;
    // cout << random << endl;
    while(true) {
        int guess;
        cout << "Bitte schätze die Zahl: ";
        cin >> guess;
        guesses[count++] = guess;
        if (guess < random) {
            cout << "Dein Tipp ist zu klein" << endl;
        }
        else if(guess > random) {
            cout << "Deine Tipp ist zu groß" << endl;
        }
        else {
            cout << "Good Job! Korrekt" << endl;
            print_array(guesses, count);
            break;
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
                return 0;
        }
    }
    while (choice != 1);
}
