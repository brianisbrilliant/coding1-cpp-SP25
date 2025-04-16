// THIS IS MY SCRIPT NOW
// Brian Foster
// Inheritance




#include <iostream>
#include <string>
using namespace std;

// global debugging variable
bool debug = true;

class Human {

protected:
    string name;
    int health;
    int damage;


public:
    Human(string givenName, int givenHealth = 10, int givenBaseDamage = 4) {
        name = givenName;
        SetHealth(givenHealth);             // this let's us clamp the input
        SetDamage(givenBaseDamage);         // this let's us clamp the input

        //SayHello();
    }

    Human() {
        //SayHello();
    }

    void SayHello() {
        cout << "name is " << name << ", health is " << health << ", damage is " << damage << ".\n";
    }
    

    virtual void SetHealth(int byAmount) {
        if (debug) {
            cout << "at top of SetHealth(byAmount), health = " << health << ", byAmount = " << byAmount << ".\n";
        }

        // sometimes the health starts out at a crazy large
        // random number. let's clamp it before changing it.
        if (health < 0)     health = 0;
        if (health > 100)   health = 100;

        health += byAmount;

        if (health < 0)     health = 0;     // clamping health to be no lower than zero.
        if (health > 100)   health = 100;     // clamping health to be no higher than 100.

    }

    void SetName(string givenName) {
        name = givenName;
    }

    void SetDamage(int givenDamage) {
        damage = givenDamage;
    }

    int GetHealth() {
        return health;
    }

    int GetDamage() {
        return damage;
    }

    string GetName() {
        return name;
    }
};  // end of the Human class.


// if private or protected, all public thinigs in the human class are made private.
class barbarian : public Human {
    // this class should inherit all of the things that a human has.
    
public:
    // add a constructor. (optional, will run after human constructor.)
    // if not the default constructor, need to create new constructor.
    barbarian(string givenName, int givenHealth = 10, int givenBaseDamage = 4) {
        SetName(givenName);
        SetHealth(givenHealth);             // this let's us clamp the input
        SetDamage(givenBaseDamage);         // this let's us clamp the input
    }

    // add a Yell() function
    void Yell() {
        cout << "The Barbarian unleashes an inhuman yell, boosting all of his team's stats.\n";
    }

    // add a doubleSwing() function.
    void doubleSwing(Human& target) {
        cout << "The barbarian swings both weapons at " << target.GetName() << "!\n";
        
        // call the SetDamage() function on the human target.
        // use the damage from "This" instance of a barbarian"
        // double the damage, because it's a double swing, obviously.
        int tempDamage = GetDamage() * 2;
        target.SetHealth(-tempDamage);              // subtract the damage of the two swings from 
                                                        // the target's health.
    }

};  // end of barbarian class

// distill your learning. 
// create a shopkeep class that inherits from the human class.
// add a dropGold() function.
// add a shopName variable.
class shopkeep : public Human {
private:
    int gold;
    string shopName;
public:
    shopkeep() {
        gold = 15;
    }

    void SetShopName(string givenShopName) {
        shopName = givenShopName;
    }

    string GetShopName() { return shopName; }

    // overloading the human::setHealth() function
    void SetHealth(int byAmount) override {         // override keyword says "do this one, not the parent class one"
        if (health < 0)     health = 0;                 // the parent class function must be virtual.
        if (health > 100)   health = 100;

        health += byAmount;

        if (health <= 0) {
            cout << "The proprietor of " << shopName << " has died!\n";
            cout << "They dropped " << gold << " gold.\n";
            gold = 0;
        }
    }
};


int main() {
    barbarian bane("Bane", 22, 4);
    bane.SayHello();


    Human aiden("Aiden");
    aiden.SayHello();
    cout << "Health: " << aiden.GetHealth() << endl;
    cout << "Damage: " << aiden.GetDamage() << endl;

    aiden.SetHealth(15);
    cout << "setting health \n";
    aiden.SetDamage(6);
    cout << "setting damage \n";

    cout << "Updated Health: " << aiden.GetHealth() << endl;
    cout << "Updated Damage: " << aiden.GetDamage() << endl;

    cout << "\n\nLet's have the barbarian attack aiden.\n";

    bane.doubleSwing(aiden);

    aiden.SayHello();

    shopkeep papaJohn;
    papaJohn.SetName("Papa John");
    papaJohn.SetShopName("Papa John's Pizza Tavern");
    papaJohn.SetHealth(5);

    bane.doubleSwing(papaJohn);

    papaJohn.SayHello();

    return 0;
}
