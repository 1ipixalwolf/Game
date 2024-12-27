#ifndef COMBATENTS_H
#define COMBATENTS_H

#include <iostream>
using namespace std;

class Combatents {
public:
    // Constructor (Optional: can be default constructor or with parameters)
    Combatents(int attack = 1, int health = 2);

    // Setters
    void SetAttack(int attackLvl);
    void SetHealth(int healthLvl);

    // Getters
    int GetAttack() const;
    int GetHealth() const;

    // Method to print the stats
    void PrintStats() const;

private:
    int attack;
    int health;
};

#endif 
