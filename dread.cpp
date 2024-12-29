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
    string base;
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
    cout << "To return to the main minu, type x" << endl;
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
    case 'x': {
        return;
    }
    default: {
        cout << "Invalid choise.";
        break;
    }
    }
    base = location + chapters.at(i) + "/";
    location = base + chapters.at(i) + ".txt";
    
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
    switch (choise)
    {
    case 'a': {
        location = base + "a.txt";
        break;
    }
    case 'b': {
        location = base + "b.txt";
        break;
    }
    case 'c': {
        location = base + "c.txt";
        break;
    }
    case 'x': {
        return;
    }
    default:
        break;
    }
    //Open salected file
    story.open(location);      
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
    
    if ((i == 0) && (choise == 'a')) {
        if (!fast) {
            cout << "Red is tragically broken. The end" << endl;
        }
    }
    cout << "Thanks for stopping in! Good by!" << endl;

}
