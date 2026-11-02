#include <iostream> 
#include <memory> 
#include <string> 
using namespace std;

class Character { public: 
virtual unique_ptr<Character> clone() const = 0; virtual void showInfo() const = 0;
virtual ~Character() = default;
};

class Warrior : public Character {
     private: string name; int health; int damage;
public: Warrior(string name, int health, int damage) : name(name), health(health), damage(damage) {}
// Copy constructor
Warrior(const Warrior& other)
    : name(other.name),
      health(other.health),
      damage(other.damage) {}

// Clone method
unique_ptr<Character> clone() const override {
    return make_unique<Warrior>(*this);
}

void showInfo() const override {
    cout << "Warrior: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Damage: " << damage << endl;
}
};

class Mage : public Character {
     private: string name; int health; int magicPower;
public: Mage(string name, int health, int magicPower) : name(name), health(health), magicPower(magicPower) {}
Mage(const Mage& other)
    : name(other.name),
      health(other.health),
      magicPower(other.magicPower) {}

unique_ptr<Character> clone() const override {
    return make_unique<Mage>(*this);
}

void showInfo() const override {
    cout << "Mage: " << name << endl;
    cout << "Health: " << health << endl;
    cout << "Magic Power: " << magicPower << endl;
}
};

int main() {
            Warrior original("Aragorn", 100, 50);
    unique_ptr<Character> warriorClone = original.clone();

cout << "Original Character:\n";
original.showInfo();

cout << "\nCloned Character:\n";
warriorClone->showInfo();

Mage mage("Gandalf", 80, 100);
unique_ptr<Character> mageClone = mage.clone();
cout << "\nCloned Mage:\n";
mageClone->showInfo();

return 0;
}