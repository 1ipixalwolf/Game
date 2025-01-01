#include "combatants.h"
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

// Constructor initializing attack and health (default to 0 if no values are provided)
Combatants::Combatants(string name, int attack, int health) {
    this->name = name;
    this->attack = attack;
    this->health = health;
}

// Setter for name
void Combatants::SetName(string name) {
    this->name = name;
}

// Setter for attack
void Combatants::SetAttack(int attack) {
    this->attack = attack;
}

// Setter for health
void Combatants::SetHealth(int health) {
    this->health = health;
}

// Getter for name
string Combatants::GetName() const {
    return name;
}
// Name generator to randomly give enemies different names
string Combatants::GenerateRandomName() {
    vector<string> names = {"Abby", "Homer", "EV", "Shadow", "Vader", "Storm", "Abigail", "Alexander", "Alice", "Amelia", "Andrew", "Angela", "Anthony", "Arthur", "Ava", "Benjamin", "Caleb", "Caroline", "Catherine", "Charlotte", "Christopher", "Claire", "Daniel", "David", "Diana", "Eleanor", "Elizabeth", "Emily", "Emma", "Ethan", "Evelyn", "Finn", "Gabriel", "Grace", "Hannah", "Henry", "Isaac", "Isabella", "Jack", "Jacob", "James", "Jasmine", "Jonathan", "Joseph", "Julia", "Katherine", "Kayla", "Kevin", "Kimberly", "Lauren", "Leo", "Liam", "Lily", "Lucas", "Lucy", "Madison", "Margaret", "Maria", "Mason", "Matthew", "Mia", "Michael", "Natalie", "Nathan", "Noah", "Nora", "Olivia", "Owen", "Patrick", "Penelope", "Peter", "Rachel", "Rebecca", "Riley", "Ryan", "Samuel", "Sarah", "Scarlett", "Sebastian", "Sophia", "Sophie", "Stella", "Steven", "Thomas", "Timothy", "Tyler", "Victoria", "Violet", "William", "Wyatt", "Xavier", "Zachary", "Zoe", "Aaron", "Allison", "Audrey", "Brandon", "Chloe", "Ella", "Gabriel", "Harper", "Isaac", "Logan", "Naomi", "Piper", "Quinn", "Buggy", "Kay", "Ron", "Baddy", "Steve", "Sarah", "Ren", "Melvin", "Kyle", "Ray", "Layla", "Slimer", "Brocoli", "Box", "Fart", "Bayly", "Goooop", "Sneaker", "Sam", "Alix", "Dance", "Evolen", "Cash", "Trisha", "Salad", "Becky", "Dillon", "Garry", "Hanna", "Izaak", "Jack", "Jenna", "Mark", "Mary", "Man", "Max", "Nail", "Noah", "Oscar", "Peter", "Rain", "Tate", "Unicorn", "Venom", "Spider", "Bug", "Growler", "Snapper", "HuggyWuggy", "Zomby", "Sculker", "Snake", "Void"};
    int i = rand() % names.size();
    this->name = names.at(i);
    return name;
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
    cout << name << " Attack: " << attack << " " << "Health: " << health << endl;
}
