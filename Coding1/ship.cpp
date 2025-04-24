#include "ship.h"


// define the constructor.
ship::ship() {
	name = "SS Minnow";
	fuel = 50;
	type = FRIGATE;
}

void ship::status() {
	cout << "The good ship " << name << " has " << fuel << " fuel.\n";
	cout << "The ship is a ";

	switch (type) {
	case FIGHTER: cout << "fighter.\n";
		break;
	case FRIGATE: cout << "frigate.\n";
		break;
	case FREIGHTER: cout << "freighter.\n";
		break;
	case CRUISER: cout << "cruiser.\n";
		break;
	default: cout << "unknown.\n";
		break;
	}

}