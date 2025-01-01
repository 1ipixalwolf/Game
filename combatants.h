#ifndef Combatants_H
#define Combatants_H

#include <iostream>
using namespace std;

class Combatants {
public:
    // Constructor (Optional: can be default constructor or with parameters)
    Combatants(string name = "Bad_Guy", int attack = 1, int health = 2);

    // Setters
    void SetName(string name);
    void SetAttack(int attackLvl);
    void SetHealth(int healthLvl);

    // Getters
    string GetName() const;
    string GenerateRandomName();
    int GetAttack() const;
    int GetHealth() const;

    // Method to print the stats
    void PrintStats() const;

private:
    string name;
    int attack;
    int health;
};

#endif 
