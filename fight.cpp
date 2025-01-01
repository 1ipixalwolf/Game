#include<iostream>
#include<ctime>  // For srand and rand()
#include<thread> 
#include "main.h"
#include "combatants.h"
#include "fight.h"

int fight(Combatants* player) {
    int wens = 0;
    int enemyMove = 2; 
    char playMore;
    bool super = false;
    
    // Store player stats in temp variables
    int playerAttack = player->GetAttack();
    int playerHealth = player->GetHealth();
    
    //Create an enemy
    Combatants enemy;
    enemy.GenerateRandomName();
    enemy.SetAttack(1);
    enemy.SetHealth(2);
    int enemyAttack = enemy.GetAttack();
    int enemyHealth = enemy.GetHealth();

    do {
        //Loop to take turns until the enemy is at 0 health
        while(enemyHealth > 0) {
            //Print stats for user to see their progress
            player->PrintStats();
            enemy.PrintStats();

            cout << "Your move! Type / to attack or o to defend" << endl;
            char playerMove; 
            cin >> playerMove;
            switch (playerMove)
            {
            case '/':
                if (enemyMove == 0) {break;}
                else {
                    enemyHealth -= playerAttack;
                    cout << "Hit!" << endl;
                    break;
                }
            case 'o':
                cout << "Protect" << endl;
                break;
            case 'q':
                cout << "Good Game!" << endl;
                return wens;
            default:
                cout << "invalid. Try again." << endl;
                cin >> playerMove;
                break;
            }

            //Stop game if enemy is already dead
            if (enemyHealth <= 0) {
                cout << "Win!" << endl;
                wens++;
                break;
            }

            // pause for 3 seconds before continuing
            this_thread::sleep_for(chrono::seconds(3));
            
            enemyMove = rand() % 2;     // Enemy randomly decides to defend or attack
            //Enemy's turn
            cout << "Enemy's Turn: " << endl;
            if (enemyMove == 0) {
                cout << "o Enemy healed" << endl;
            }
            else {
                cout << "/" << endl;
                if (playerMove == 'o') {cout << "Blocked" << endl;}
                else {
                    cout << "You're hit!" << endl;
                    playerHealth -= enemyAttack;
                }
            }

            // Lose condition
            if (playerHealth <= 0) {
                cout << "Defeated!" << endl;
                break;
            }
        }
        cout << "Press y to continue" << endl;
        cin >> playMore;
            
        // Adjust enemy stats based on wens
        switch (wens)
        {
        case 0: {
            break;
        }
        case 5: {
            enemy.GenerateRandomName();
            enemyAttack += 10;
            enemyHealth += 10;
            break;
        }
        case 15: {
            enemy.GenerateRandomName();
            enemyHealth += 20;
            enemyAttack += 20;
            break;
        }
        default: {
            enemy.GenerateRandomName();
            enemyHealth += 2;
            enemyAttack += 2;
            break;
        }
        }
        enemy.SetAttack(enemyAttack);
        enemy.SetHealth(enemyHealth);

    } while (playMore == 'y');
    
    cout << endl << endl;
    return wens;
}