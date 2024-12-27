#include "combatents.h"

// Constructor initializing attack and health (default to 0 if no values are provided)
Combatents::Combatents(int attack, int health) {
    this->attack = attack;
    this->health = health;
}

// Setter for attack
void Combatents::SetAttack(int attack) {
    this->attack = attack;
}

// Setter for health
void Combatents::SetHealth(int health) {
    this->health = health;
}

// Getter for attack
int Combatents::GetAttack() const {
    return attack;
}

// Getter for health
int Combatents::GetHealth() const {
    return health;
}

// Print the values of attack and health
void Combatents::PrintStats() const {
    cout << "Attack: " << attack << endl;
    cout << "Health: " << health << endl;
}
