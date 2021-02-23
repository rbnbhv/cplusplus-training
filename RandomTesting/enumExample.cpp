#include <iostream>

using namespace std;

enum Farben {rot, gruen, blau, gelb};

int main() {
    
    Farben f = rot;
    
    cout << f << "\n";
    
    if (f == gruen) {
        cout << "F ist grün";
    }
    else {
        cout << "noch nicht grün genug" << endl;
    }
    
    f = (Farben)(f+1);
    
    cout << f << endl;
}
