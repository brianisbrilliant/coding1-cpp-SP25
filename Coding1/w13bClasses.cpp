#include <iostream>
#include <string>
using namespace std;


class human {

protected:		// change from private to allow child classes to inherit these variables.

	string name;
	int health;
	int damage;

public:
	human(string givenName, int givenHealth = 10, int givenBaseDamage = 4) {
		name = givenName;
		health = givenHealth;
		damage = givenBaseDamage;

		cout << "I have shown up!\n";
	}

	human() {
		name = "Tim";
		health = 10;
		damage = 4;
	}

	void SayHello() {
		cout << "Hello! My name is " << name << " and my total health is " << health << ".\n";
	}

	void SayGoodbye() {
		cout << "I was recalled to the factory for medical help.\n";
	}

	void SetHealth(int givenHealth) {
		if (givenHealth < 1) {
			health = 0;
			cout << "Oh no! " << name << " died!\n";
		}
		else if (givenHealth > 30) {
			health = 30;
			cout << name << " is at full health!\n";
		}
		else {
			health = givenHealth;
			cout << name << " has " << health << " hit points left!\n";
		}
	}

	void SetDamage(int baseDamage) {
		if (health < 15) {
			baseDamage = 5;
		}
		else if (health > 15) {
			baseDamage = damage;
		}
	}

	void ChangeHealth(int by = 1) {
		int tempHealth = health;
		tempHealth += by;
		SetHealth(tempHealth);
	}

	int GetHealth() {
		return health;
	}
	int GetDamage() {
		return damage;
	}


	void SetName(string givenName) {
		if (givenName.size() < 2) {
			cout << "Name is too short!\n";
			return;     // return nothing out of a void function to end the function. THIS WILL NOT END THE PROGRAM
		}
		else if (givenName.size() > 20) {
			cout << "Name is too long!\n";
			return;
		}
		else {
			name = givenName;
		}
	}
	string GetName() {
		return name;
	}
};

// the wizard class inherits from the human class.
// everything that the human class has, so does the wizard.
class wizard : public human {
public:
	int mana;

	void castSpell() {
		cout << name << " casts a spell!\n";
	}

	// build a spell that poisons any human.
	// it will cut their health in half.
	void poison(human& target) {
		cout << "The terrible wizard " << name << " has poisoned " << target.GetName() << "!!\n";
		
		int halfOfTargetHealth = target.GetHealth() / 2;
		
		target.ChangeHealth(-halfOfTargetHealth);
	}

};

// create another child class of human. your pick on what it is.


int main() {

	wizard dumblydore;
	dumblydore.SetName("Abloose");
	dumblydore.SayHello();
	dumblydore.castSpell();

	cout << "Are you read to meet my new human?\n";

	human kaydyn;
	kaydyn.SetName("Kaydyn Wilson");
	kaydyn.SetHealth(50);

	dumblydore.poison(kaydyn);

	cout << "[Checking health after poison]\n";
	kaydyn.SayHello();

	wizard pendragon;
	pendragon.SetName("Pendragon");
	dumblydore.poison(pendragon);


	cout << "This is my new human! Their name is " << kaydyn.GetName() << " and they have a base health of " << kaydyn.GetHealth() << " hit points and at full health they can do " << kaydyn.GetDamage() << " points of damage!\n";
	cout << "Greet everyon human!\n";
	kaydyn.SayHello();

	kaydyn.ChangeHealth(14);
	cout << "Oh no! Kaydyn decided to go adventuring and they came back hurt!\n";
	cout << "They now have " << kaydyn.GetHealth() << " hit points left and can only do " << kaydyn.GetDamage() << " points of damage now!\n";

	kaydyn.SayGoodbye();

	return 0;
}