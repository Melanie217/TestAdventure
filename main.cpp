#include <iostream>
#include <string>
#include "Game.hpp"

using namespace std;

void clearScreen()
{
    #ifdef __linux__ 
        system("clear");
    #elif __APPLE__
        system("clear");
    #elif _WIN32
        system("CLS");
    #endif
}

int main() {
    clearScreen(); 
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

    clearScreen(); 

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
