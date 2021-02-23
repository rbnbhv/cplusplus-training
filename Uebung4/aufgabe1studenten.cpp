/*
 16.06.2020 - Ruben Allenstein
 Aufgabe 2:
 Implementieren Sie eine Klasse Student, die einen Namen, Vornamen (beides als char*), eine Matrikelnummer und das Fachsemester
 (beides unsigned int) enthält. Implementieren Sie eine weitere Klasse Verwaltung, die ein Array von Studenten enthält. Diese Klasse soll
 neue Studenten anlegen und bestehende Studenten löschen können. Sie soll das Fachsemester aller Studenten erhöhen können, Studenten bestimmter
 oder auch aller Fachsemester ausgeben können. Implementieren Sie noch eine Suchfunktion, so dass nach Namen oder Matrikelnummer gesucht
 werden kann. Wird nach Namen gesucht, müssen u.U. mehrere Studenten zurückgegeben werden.
 Achten Sie darauf, dass im Destruktor alle Daten wieder freigegeben werden
 */

#include <iostream>
using namespace std;

class Student {
    friend class Verwaltung;
    char* name;
    char* vorname;
    unsigned matrikelnummer;
    unsigned fachsemester;
    
public:
    Student() {
        
    }
    
    ~Student() {
        cout << "Der Destuktor löscht alle Daten wieder" << endl;
    }
};

class Verwaltung {
public:
    Verwaltung() {
        unsigned length;
        cout << "Wie viele Stundenten sollen hinzugefügt werden?" << endl;
        cin >> length;
        Student *arrayOfStudent  = new Student[length];
        for (int i = 0; i < length; ++i) {
            cout << "Vorname eingeben:" << endl;
            cin >> arrayOfStudent[i].vorname;
            cout << "Nachname eingeben:" << endl;
            cin >> arrayOfStudent[i].name;
            cout << "Matrikelnr eingeben:" << endl;
            cin >> arrayOfStudent[i].matrikelnummer;
            cout << "Fachsemester eingeben:" << endl;
            cin >> arrayOfStudent[i].fachsemester;
        }
        print_Array(arrayOfStudent, length);
        delete[] arrayOfStudent;
    }
    
    void print_Array(Student *arrayOfStudent, unsigned length) {
        for (int i = 0; i < length; ++i) {
            cout << "Der Name von Student " << i << " ist " << arrayOfStudent[i].vorname << endl;
        }
    }
    
    ~Verwaltung() {
        cout << "Der Destruktor löscht alle Daten wieder" << endl;
    }
};

int main() {
    Verwaltung();
}
