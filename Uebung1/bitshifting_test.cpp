#include <iostream>
using namespace std;

int getLength(int n) {
    int cnt = 0;
    for (unsigned i = 0; i < 32; ++i) {
        if ((n &(1 << i)) != 0) {
            ++cnt;
        }
    }
    return cnt;
}

int main() {
    cout << getLength(7) << endl;
}
