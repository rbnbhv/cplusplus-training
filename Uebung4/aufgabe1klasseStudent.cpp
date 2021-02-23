/*
 02.06.2020 - Ruben Allenstein
 Aufgabe 1:
 Implementieren Sie eine Klasse Student, die einen Namen, Vornamen (beides als char*), eine Matrikelnummer und das Fachsemester
 (beides unsigned int) enthält. Implementieren Sie eine weitere Klasse Verwaltung, die ein Array von Studenten enthält. Diese
 Klasse soll neue Studenten anlegen und bestehende Studenten löschen können. Sie soll das Fachsemester aller Studenten erhöhen
 können, Studenten bestimmter oder auch aller Fachsemester ausgeben können. Implementieren Sie noch eine Suchfunktion, so dass
 nach Namen oder Matrikelnummer gesucht werden kann. Wird nach Namen gesucht, müssen u.U. mehrere Studenten zurückgegeben werden.
 Achten Sie darauf, dass im Destruktor alle Daten wieder freigegeben werden
 */

#include <iostream>

using namespace std;

class Class_Student {
    
private:
    
    
public:
    const unsigned* id;
    unsigned semester;
    const char* firstname;
    char* lastname;
    
    Class_Student(){
        
    }
    
    
    ~Class_Student(){
        cout << "Destructor (Class_Student) gibt nun die Daten wieder frei!" << endl << endl;
    }
};

class Class_Verwaltung {
    
public:
    
    Class_Verwaltung() {
        cout << "Geben Sie an, wie viele Studenten angelegt werden sollen!" << endl;
        unsigned length;
        cin >> length;
        cout << endl << endl;
        Class_Student *arrayOfStudents = new Class_Student[length];
        Class_Verwaltung *initStammdaten = new Class_Verwaltung(arrayOfStudents, length);
        delete[] arrayOfStudents;
    }
    
    Class_Verwaltung(Class_Student *arrayOfStudents, unsigned length) {
        unsigned tmpID;
        string tmpFirstname;
        string tmpLastname;
        for(unsigned i = 0; i < length; ++i) {
            cout << "Geben Sie die Matrikelnummer des Studenten ein..." << endl;
            cin >> tmpID;
            arrayOfStudents[i].id = &tmpID;
            cout << "Geben Sie das Fachsemester des Studenten ein..." << endl;
            cin >> arrayOfStudents[i].semester;
            cout << "Geben Sie den Vornamen des Studenten ein..." << endl;
            cin >> tmpFirstname;
            arrayOfStudents[i].firstname = convertToCharPtr(tmpFirstname);
            cout << "Geben Sie den Namen des Studenten ein..." << endl;
            cin >> tmpLastname;
            arrayOfStudents[i].lastname = convertToCharPtr(tmpLastname);
            cout << endl;
        }
        print(arrayOfStudents);
        //        Class_Student *newArray = addStudents(arrayOfStudents, length);
        //        print(newArray);
    }
    
    Class_Student addStudents(Class_Student arrayOfStudents, unsigned length) {
        cout << "Geben Sie an, wie viele weitere Studenten angelegt werden sollen!" << endl;
        unsigned newLength;
        cin >> newLength;
        cout << endl << endl;
        *arrayOfStudents = new Class_Student[length + newLength];
        unsigned tmpID;
        string tmpFirstname;
        string tmpLastname;
        for(unsigned i = length; i < (length + newLength); ++i) {
            cout << "Geben Sie die Matrikelnummer des Studenten ein..." << endl;
            cin >> tmpID;
            arrayOfStudents[i].id = &tmpID;
            cout << "Geben Sie das Fachsemester des Studenten ein..." << endl;
            cin >> arrayOfStudents[i].semester;
            cout << "Geben Sie den Vornamen des Studenten ein..." << endl;
            cin >> tmpFirstname;
            arrayOfStudents[i].firstname = convertToCharPtr(tmpFirstname);
            cout << "Geben Sie den Namen des Studenten ein..." << endl;
            cin >> tmpLastname;
            arrayOfStudents[i].lastname = convertToCharPtr(tmpLastname);
            cout << endl;
        }
        return arrayOfStudents;
    }
    
    char* convertToCharPtr(string str) {
        char* name = new char[sizeof(str)];
        for(unsigned i = 0; i < sizeof(str); ++i) {
            name[i] = str[i];
        }
        return name;
    }
    
    void print(Class_Student *arr) {
        //        unsigned length = 1;
        for(unsigned i = 0; i < length; ++i) {
            cout << "Matrikelnummer: " << *arr[i].id << endl;
            cout << "Semester: " << arr[i].semester << endl;
            cout << "Vorname: " << arr[i].firstname << endl;
            cout << "Nachname: " << arr[i].lastname << endl;
            cout << endl;
        }
    }
    
    ~Class_Verwaltung(){
        cout << "Destructor (Class_Verwaltung) gibt nun die Daten wieder frei!" << endl << endl;
    }
};

int main() {
    Class_Verwaltung start;
    return 0;
}
