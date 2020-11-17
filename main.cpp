#include <iostream>
#include <string>
#include "Game.hpp"
#include "Helpful.hpp"

using namespace std;

void clearScreen()
{
    #ifdef _WIN32
        system("CLS");
    #else 
        system("clear");
    #endif
}

int main() {
    
    clearScreen(); 
    string wantToPlay = ""; 
    Helpful h; 
    
    cout << "\t~~~~~~~~~~~~~~~~~~~~~~~" << endl <<"\t"; 
         h.slowPrinting("Do you want to start?"); //<< "\t Do you want to start?" << endl
         cout << "\t~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl <<"\t"; 
         h.slowPrinting("Please type  ~ yes ~  if you wish to do so."); //<< "\t Please type  ~ yes ~  if you wish to do so." << endl 
         cout << "\t"; 
         h.slowPrinting("Anything else will cancel the game. You can type in  ~ exit ~  throughout the game to leave.");
         cout << endl << endl << ">> ";

    cin >> wantToPlay; 
    //wantToPlay = "yes";

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
