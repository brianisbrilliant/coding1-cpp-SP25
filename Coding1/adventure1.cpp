

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    //welcome the player
    //set up the game
    int health = 10;
    int attack = 0;
    int block = 0;
    int turns = 0;
    //seed the random number generator
    srand(time(0));
    //start the loop
    do {
        
        turns += 1;                                                 //add 1 to turns
        
        cout << "An enemy attacks!\n";                              //start the encounter
  
        attack = rand() % 5;                                        //randomly generate numbers for attack(range = 0 - 4) and block(range = 0 - 4)
        block = rand() % 5;
        
        if (block >= attack) {                                      //if block is greater or equal to attack, successful block
            cout << "Successful block!\n";
        }
        else {                                                      //otherwise, subtract attack value from health.
            cout << "You've been hit!\n";
            health -= attack;
            cout << "Your health is now " << health << ".\n";
        }

        if (health < 1) {
            cout << "You have died!\n";
            break;
        }
        
        cout << "Would you like to keep adventuring?\nType 'yes' to continue: ";            //ask the player if they would like to keep adventuring. if they don't, break out of the loop.
        string input;

        cin >> input;

        if (input != "yes") {
            break;
            cout << "Going home now!\n";
        }

    } while (health > 0 && turns < 8);                             //keep looping while health is greater than zero and fewer than 4 turns have happened


        //if health is greater than 0, congratulate player
    if (health > 0) {
        cout << "You survived your adventure!\n";
    }
    //otherwise, tell the player they're dead.
    else {
        cout << "Your body is laying by the road. Enjoy the afterlife, if it exists.\n";
    }
            




}

