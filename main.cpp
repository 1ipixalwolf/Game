#include<iostream>
#include<fstream>
#include<limits>
#include "Combatants.h"
#include "dread.h"
#include "fight.h"
#include "math.h"
#include "main.h"
#include "sleep.h"
using namespace std;

// Display the game menu
void menu() {
    // Create the player with a pointer
    Combatants* player = new Combatants();

    // Read stats from file
    ifstream upstats("stats.txt");
    int playerHealth = 2;  // Default health
    int playerAttack = 2;  // Default attack

    if (upstats.is_open()) {
        upstats >> playerAttack >> playerHealth;
        upstats.close();
    } else {
        cout << "Problem opening stats file! Using default stats." << endl;
    }

    player->SetAttack(playerAttack);
    player->SetHealth(playerHealth);

    // Main menu loop
    while (true) {
        cout << "Type the number of the game you wish to play:" << endl;
        cout << "1. Dread" << endl;
        cout << "2. Fight" << endl;
        cout << "3. Math" << endl;
        cout << "4. Sleep" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); // Clear error state
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "Invalid input. Please enter a number between 1 and 5." << endl;
            continue;
        }

        switch (choice)
        {
        case 1: {
            dread(player);
            break;
        }
        case 2: {
            fight(player);
            break;
        }
        case 3: {
            math(player);
            break;
        }
        case 4: {
            sleep(player);
            break;
        }
        case 5: {
            cout << "Exiting and saving game." << endl;
            ofstream updateStats_out;
            updateStats_out.open("stats.txt");
            if (updateStats_out.is_open()) {
                updateStats_out << player->GetAttack() << " " << player->GetHealth();
                updateStats_out.close();
            }
            else {cout << "Problem saving stats!" << endl;}
            delete player;
            break;
        }
        default: {
            cout << "Invalid choice" << endl;
            break;
        }
        }
    }
}

int main() {
    menu();
    return 0;
}
