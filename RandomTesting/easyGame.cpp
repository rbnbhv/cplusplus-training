/* Udemy C++ Program */

#include <iostream>
#include <stdio.h>

using namespace std;


class Account {
    friend int main();
    string name = "";
    double balance = 5000;
    
    void deposit(double amount) {
        balance += amount;
        cout << balance << endl;
    }
    
    
    void withdraw(double amount) {
        balance -= amount;
        cout << balance << endl;
    }
};


class Player : Account {
    friend int main();
private:
    //attributes
    string name;
    int health;
    int xp;
    
    //methods:

    void talk(string blabla) {
        cout << name << " says " << blabla << endl;
    }
};



int main() {
    Player frank;
    frank.name = "Frank";
    frank.health = 100;
    frank.talk("ey du schurke!");
    
    Player *enemy = new Player();
    enemy->name = "Enemy";
    (*enemy).xp = 10;
    (enemy)->health = 100;
    (*enemy).talk("Jetzt bist du tot!");
    delete enemy;
    
    Account franks_account;
    franks_account.name = "Frank";
    franks_account.balance = 2500;
    franks_account.deposit(500);
    frank.deposit(50055.0);
    return 0;
    
}
