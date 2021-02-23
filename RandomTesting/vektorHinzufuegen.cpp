#include <iostream>
#include <vector>
using namespace std;


int main() {
    vector <int> vekName {1,2,3,4,5,6,7};
  
    cout <<vekName.at(1) << endl;
    cin >> vekName.at(1);
    cout <<vekName.at(1) << endl;
    
    vekName.push_back(51515);
    cout << vekName.at(7) << endl;
    
    cout << vekName.size() << " Die Größe des Vektors wird mit name.size() festgelegt" << endl;
    for (int i = 0; i < vekName.size(); ++i) {
        cout << vekName[i] << "\t";
    }
    cout << endl;
    return 0;
}
