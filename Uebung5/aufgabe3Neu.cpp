#include <iostream>

using namespace std;


class Rational {
    int num, denom;
public:
    void set(int n, int d) {
        num = n;
        denom = d;
    }
    
    int getNum() {
        return num;
    }
    
    int getDenom() {
        return denom;
    }
    
    int operator > (const Rational &r2) const {
        float n1 = (float)num / (float)denom;
        float n2 = (float)r2.num / (float)r2.denom;
        if(n1 > n2)
            return 1;
        if(n1 == n2)
            return 0;
        if (n1 < n2)
            return -1;
    }
    
    //    bool operator > (const Rational &r2) const {
    //        return (float)num / denom > (float)r2.num / r2.denom;
    //    }
};

void swap(Rational &r1, Rational &r2) {
    Rational temp;
    temp.set(r1.getNum(),r1.getDenom());
    r1.set(r2.getNum(),r2.getDenom());
    r2.set(temp.getNum(),temp.getDenom());
}

void sort(Rational arr[], int n) {
    int i, j;
    for (i = 0; i < n-1; i++)
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1])
                swap(arr[j], arr[j+1]);
}

void displayArray(const char *desc, Rational *arr, size_t sz) {
    std::cout << desc;
    for (size_t idx = 0; idx < sz; ++idx) {
        std::cout << "  " << arr[idx].getNum() << "/" << arr[idx].getDenom();
    }
    std::cout << '\n';
}

int main(int argc, char** argv) {
    Rational *arr;
    int n = 10;
    cout<< "You may enter up to 10 relational numbers. How many?" <<endl;
    cin>> n;
    arr = new Rational[n];
    return 0;
}
