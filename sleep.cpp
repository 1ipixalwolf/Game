#include<iostream>
#include "main.h"
#include "combatants.h"
#include "sleep.h"
using namespace std;

//This game is designed to make the user exit and go to bed
char sleep(Combatants* player) {
    string nothing;

    cout << "You're trying to sleep " << player->GetName() << endl;
    for (int i = 0; i < 4; i++) {
        cin >> nothing;
        cout << "Sleep" << endl;
        if (i == 3) {cout << "SLEEP!!" << endl;}
    }

    int rest = 0;
    while (rest < 9) {
        cin >> nothing;
        cout << "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz" << endl;
        rest++;
    }

    player->SetHealth(player->GetHealth() + rest);
    cout << "Ok, fine " << player->GetName() << ", you can wake up." << endl << endl;

    return 'z';
}