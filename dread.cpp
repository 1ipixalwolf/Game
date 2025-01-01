//This will eventually contain more dynamic parts to be a chose your own adventure
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "main.h"
#include "combatants.h"
#include "dread.h"

using namespace std;

void dread(Combatants* player) {
    string location = "stories/";
    string base;
    char choice;
    int i;
    int branch = 0;
    bool fast;

    if (player->GetAttack() < 30) {fast = false;}
    else {fast = true;}

    //Vector of possible file names 
    vector<string> chapters;
    chapters.push_back("robot");
    chapters.push_back("doggy");
    chapters.push_back("poo");
    chapters.push_back("space");
    chapters.push_back("jokes");

    cout << "Welcome to your story!" << endl;
    cout << "To return to the main menu, type x" << endl;
    cout << "Type a number between 1 and 5." << endl;
    
    // Loop to read and open each file as it corresponds to the user's choices
    do {
        branch++;
        //Give user control of what file is opend
        cin >> choice;
        switch (choice)
        {            
            case '1': {
                i = 0;
                break;
            }
            case '2': {
                i = 1;
                break;
            }
            case '3': {
                i = 2;
                break;
            }
            case '4': {
                i = 3;
                break;
            }
            case '5': {
                i = 4;
                break;
            }

            case 'a': {
                base += "a";
                break;
            }
            case 'b': {
                base += "b";
                break;
            }
            case 'c': {
                base += "c";
                break;
            }

            case 'x': {
                return;
            }
            default: {
                cout << "Invalid choice.";
                break;
            }
        }
        if (branch == 1) {
            base = location + chapters.at(i) + "/";
            location = base + chapters.at(i);
        }
        else {location = base;}
        location += ".txt";
        //Open selected file
        ifstream story;
        story.open(location);
        
        string line;     //store each line of the file
        if (story.is_open()) {
            // Read each line from the file and store it in line
            while (getline(story, line)) {
                cout << line << endl;
            }

            // Close the file stream once all lines have been read
            story.close();
        }
        else {
            // Print an error message if the file cannot be opened
            cout << "Unable to open file!" << endl;
        }

        // Check player's stats to see outcome of their choice
        if ((i == 0) && (choice == 'a') && (branch == 2)) {
            if (!fast) {
                cout << "Red is tragically broken. The end" << endl << endl;
                branch = 200;
            }
        }

    } while (branch != 200);
    
    cout << "Thanks for stopping in! \nGood by!" << endl << endl << endl;
}
