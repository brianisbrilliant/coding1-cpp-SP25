#pragma once		// this means, only compile this one time.
#include <iostream>

enum rooms {BED, LAUNDRY, LIVING, KITCHEN, BATH, FOYER, GARAGE, DINING, LIBRARY, SOLARIUM, DEN, HALL, INVENTORY};

class item {
public:
	rooms location;		// where the item is stored

	item() {
		std::cout << "Creating a new item!\n";
		location = BED;
	}

	void setLocation(rooms newLocation) {
		if (newLocation != location) {
			location = newLocation;
		}
		else {
			std::cout << "I am already in that location.\n";
		}
	}
};