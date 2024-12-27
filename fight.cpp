#include<iostream>
#include<ctime>  // For srand and rand()
#include<thread> 
#include "main.h"
#include "combatents.h"
#include "fight.h"
using namespace std;

int fight(Combatents* player) {
    int wens;
    char move;
    char playMore;
    bool currEbeeten = false;
    
    // Store player stats in temp variables
    int pa = player->GetAttack();
    int ph = player->GetHealth();
    
    //Create an enimy
    Combatents e1;
    e1.SetAttack(1);
    e1.SetHealth(2);
    int ea = e1.GetAttack();
    int eh = e1.GetHealth();

    do {
        //Loop to take turns until the enimy is at 0 health
        while(eh > 0) {
            //Print stats for user to see their progress
            cout << "Your Stats: " << "Attack " << pa << " Health " << ph << endl;
            cout << "Enamy Stats: " << "Attack " << ea << " Health " << eh << endl;

            cout << "Your move! Type / to attack or o to defend" << endl;
            cin >> move;
            switch (move)
            {
            case '/':
                eh -= pa;
                cout << "Hit!" << endl;
                break;
            case 'o':
                ph++;
                cout << "Protect" << endl;
                break;
            case 'q':
                cout << "Good Game!" << endl;
                break;
            default:
                cout << "invalid. Try again." << endl;
                cin >> move;
                break;
            }

            //Stop game if enamy is already dead
            if (eh <= 0) {
                cout << "Win!" << endl;
                wens++;
                break;
            }

            // Pause for 3 seconds before continuing
            this_thread::sleep_for(chrono::seconds(3));
            
            //Enamy's turn
            cout << "Enamy's Turn: " << endl;
            //Randomly deside to heal or attack
            int em = rand() % 2;
            if (em == 0) {
                cout << "o Enamy healed" << endl;
                eh++;
            }
            else {
                cout << "/ you're hit!" << endl;
                ph--;
            }

            // Lose conditon
            if (ph <= 0) {
                cout << "Defeted!" << endl;
                break;
            }
        }
        cout << "Press y to continue" << endl;
        cin >> playMore;
            
        // Adjust enamy stats based on wens
        switch (wens)
        {
        case 0:
            break;
        case 5:
            eh += 10;
            ea += 10;
            break;
        case 15:
            eh += 20;
            ea += 20;
            break;
            
        default:
            eh += 2;
            ea += 2;
            break;
        }

    }while(playMore == 'y');
    return wens;
}