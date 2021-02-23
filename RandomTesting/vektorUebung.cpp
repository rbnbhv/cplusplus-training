#include <vector>
#include <iostream>
using namespace std;

void print_vek(vector <int> vekNew) {
    for (int i = 0; i < vekNew.size(); ++i) {
        cout << vekNew[i] << "\t";
    }
    cout << vekNew.size() << endl;
}

vector <int> use_vector() {
    vector <int> vec {10,20,30,40,50};
    vec.at(0) = 100;
    vec.at(vec.size()-1) = 1000;
    return vec;
}

int main() {
    vector <int> xyz = use_vector();
    print_vek(xyz);
}
