#if defined(_WIN32) || defined(_WIN64)          //depending on OS, you have to change the clear screen command
    #define PLATFORM "windows"
#elif defined(__linux__)
    #define PLATFORM "linux"
#elif defined(__APPLE__)
    #define PLATFORM "osx"
#endif

#include <iostream>
#include <string>
#include "Game.hpp"

using namespace std;

int main() {
    if(PLATFORM == "osx" || PLATFORM == "linux")
        system("clear");
    else
    {
        system("CLS");
    }
    string wantToPlay = ""; 
    
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~" << endl 
         << "\t Do you want to start?" << endl
         << "\t~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl
         << "\t Please type  ~ yes ~  if you wish to do so." << endl 
         << "\t Anything else will cancel the game. You can type in  ~ exit ~  throughout the game to leave." << endl << endl
         << ">> ";

    cin >> wantToPlay; 
    cin.clear();
    fflush(stdin); // need this, so cin buffer is clear for next user Input
    transform(wantToPlay.begin(), wantToPlay.end(), wantToPlay.begin(), ::tolower); //user Input to uppercase, to compare it with Directions

    if(PLATFORM == "osx" || PLATFORM == "linux")
            system("clear");
        else
        {
        system("CLS");
        }

    if(wantToPlay == "yes")
    {
        Game game; //Game start
        game.run();
    } else //User does not want to play the game. Exit. 
    {
        cout << "\t~~~~~~~~~~~~~~~~~~~~" << endl 
             << "\t See you next time!" << endl
             << "\t~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        return 0; 
    }
    
        
    
     
}