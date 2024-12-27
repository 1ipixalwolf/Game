//This will eventually contain more dinamic parts to be a chose youre own adventure
#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include "main.h"
#include "combatents.h"
#include "dread.h"

using namespace std;

void dread(Combatents* player) {
    string location = "stories/";

    //Vector of possible file names
    vector<string> chapters;
    chapters.push_back("robot");
    chapters.push_back("doggy");
    chapters.push_back("poo");
    chapters.push_back("space");
    chapters.push_back("jokes");


    cout << "Welcome to your story!" << endl;
    cout << "Type a number between 1 and 5." << endl;
    
    //Give user control of what file is opend
    char choise;
    int i;
    cin >> choise;
    switch (choise)
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
    default: {
        cout << "Invalid choise.";
        break;
    }
    }
    
    location += chapters.at(i) + "/" + chapters.at(i) + ".txt";
    //Open salected file
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

    // First choise 
    cin >> choise;
    if (i == 0) {
        if (choise == 'a') {
            //Open salected file
            story.open("stories/robot/a.txt");
            
            if (story.is_open()) {
                // Read each line from the file and store it in line
                while (getline(story, line)) {
                    cout << line << endl;
                }

                // Close the file stream once all lines have been read
                story.close();

                if (player->GetAttack() < 30) {
                    cout << "Red is tragically broken. The end" << endl;
                }
            }
            else {
                // Print an error message if the file cannot be opened
                cout << "Unable to open file!" << endl;
            }
        }
        
    }
    
    cout << "Thanks for stopping in! Good by!" << endl;

}

// // For testing
// int main() {
//     Combatents* player = new Combatents();
//     player->SetAttack(2);
//     player->SetHealth(3);
//     dread(player);
//     return 0;
// }
