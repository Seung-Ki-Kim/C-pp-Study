#include <iostream>
using namespace std;


class Enemy {
protected:
    int attackPower;
public:
    virtual void attack() {}
    void setAttackPower(int value) {
        attackPower = value;
    }
};


class Ninja : public Enemy {
public:
    void attack() {
        cout << "Ninja Attack : " << attackPower << endl;
    }
};

class Monster : public Enemy {
public:
    void attack() {
        cout << "Monster Attack : " << attackPower << endl;
    }
};


int main() {
    Ninja n;
    Monster m;

    Enemy *e1 = &n;
    Enemy *e2 = &m;

    e1 -> setAttackPower(5);
    e2 -> setAttackPower(10);

    n.attack();
    m.attack();

    e1 -> attack();
    e2 -> attack();

    return 0;
}