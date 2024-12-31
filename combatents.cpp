#include "Combatants.h"

// Constructor initializing attack and health (default to 0 if no values are provided)
Combatants::Combatants(int attack, int health) {
    this->attack = attack;
    this->health = health;
}

// Setter for attack
void Combatants::SetAttack(int attack) {
    this->attack = attack;
}

// Setter for health
void Combatants::SetHealth(int health) {
    this->health = health;
}

// Getter for attack
int Combatants::GetAttack() const {
    return attack;
}

// Getter for health
int Combatants::GetHealth() const {
    return health;
}

// Print the values of attack and health
void Combatants::PrintStats() const {
    cout << "Attack: " << attack << endl;
    cout << "Health: " << health << endl;
}
