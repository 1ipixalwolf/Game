#include<iostream>
#include<cmath>
#include "main.h"
#include "Combatants.h"
#include "math.h"
using namespace std;

int math(Combatants* player)
{
    int solved = 0;
    int ans;
    srand(rand()%100);
    cout << "Solve math problems to leval up! \nType 200 to exit." << endl;
    while (true) {
        int a = 1 + rand() % 8;
        int b = 1 + rand() % 12;
        
        cout << a << " * " << b << " =" << endl;
        
        cin >> ans;
        
        // Exit if 200 is typed
        if (ans == 200) {break;}

        // Check answer
        if (a * b == ans) {
            cout << "Correct!!" << endl;
            solved++;
        } else {
            cout << "Try again" << endl;
            cin >> ans;
        }
    }
    cout << "Great job!! \nyou solved " << solved << " problems!" << endl;
    cout << "Points: " << solved << endl;

    char stat; 
    if (solved % 2 == 0) {
        cout << "Would you like to apply points to a. attack, b. health, or c. both?" << endl;
        cin >> stat;
        if (stat == 'c') {
            player->SetAttack(player->GetAttack() + (solved / 2));
            player->SetHealth(player->GetHealth() + (solved / 2));
        }
    }
    else {
        cout << "Would you like to apply points to a. attack, or b. health?" << endl;
        cin >> stat;
    }
    if (stat == 'a') {player->SetAttack(player->GetAttack() + solved);}
    else if (stat == 'b') {player->SetHealth(player->GetHealth() + solved);}

    cout << endl << endl;
    return solved;
}