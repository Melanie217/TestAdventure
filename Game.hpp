#ifndef GAME_HPP
#define GAME_HPP

#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include "Room.hpp"

using namespace std;

class Game
{
public:
    Game(); //Constructor
    void run();
    void createRoom(string id, string name, string description, string north, string east, string south, string west);
    bool roomSetUp(); //reads rooms from a txt file
    map<string, Room *> rooms;  //sort Rooms with ID into map
    void userInput();

private:
    Room *currentRoom;  //points to current Room
    string endRoom;     //Saves endRoom so we can check if we arrived yet 
    bool end;           //is the game over? 
};

Game::Game() //define Constructor
{
    currentRoom = nullptr;
    end = false;
    string endRoom = "";
    roomSetUp();
}

void Game::run() //define void run -> should run/start the game
{
    while (!end) //game loop
    {
        currentRoom->printRoom();

        if (currentRoom->getId() == endRoom)
        {
            end = true;
            continue;
        }
        currentRoom->printDirections();
        cout << endl
             << endl;

        userInput(); //reads UserInput
    }

    cout << "~ The End ~" << endl
         << endl
         << endl;
}

bool Game::roomSetUp()
{   // Hier Exception Handling evtl einfügen? -> Was für errors können passierne 
    string file = "rooms.txt";
    ifstream input(file);
    if (!input.good())
    {
        return false;
    }

    string buffer, id, name, description, north, east, south, west;

    while (input >> buffer) //reads in file 
    {
        if (buffer == "BEGIN_ROOM")
        {
            input >> id;
            input.ignore();
            getline(input, name); //Name
            getline(input, description); //Description

            input >> buffer; //North
            input >> north;

            input >> buffer; //East
            input >> east;

            input >> buffer; //South
            input >> south;

            input >> buffer; //West
            input >> west;

            createRoom(id, name, description, north, east, south, west);
        }
        else if (buffer == "START_ROOM")
        {
            input >> buffer;
            currentRoom = rooms[buffer];
        }
        else if (buffer == "ENDING_ROOM")
        {
            input >> endRoom;
        }
    }
    return true;
}

void Game::createRoom(string id, string name, string description, string north, string east, string south, string west)
{
    rooms[id] = new Room(id, name, description);
    rooms[id]->setDirections(north, east, south, west);
}

void Game::userInput()
{   
    //Hier Exception Handling einfügen. -> was kann passieren? 
    string input;
    cout << "\t Where would you like to go? ";
    cout << " >> ";
    getline(cin, input);
    transform(input.begin(), input.end(), input.begin(), ::toupper); //user Input to uppercase, to compare it with Directions
    bool rightInput = false;

    for (int i = 0; i < 4; i++)
    {
        Direction d = Direction(i);
        string gamedir = getDirectionAsString(d);

        if (input == gamedir) //if input is in Directions, it will continue 
        {
            rightInput = true;
            if (currentRoom->directionAvailable(d))
            {
                cout << "\t You chose " << input << endl
                     << endl
                     << endl;
                currentRoom = rooms[currentRoom->getNextRoom(d)];
            }
            else
            {
                cout << "\t You cannot go " << input << endl;
            }
        }
    }
    if (!rightInput && input == "EXIT") //if User wants to exit it will happen here 
    {
        cout << endl << endl 
             << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl 
             << "\t Thank you for playing :)" << endl
             << "\t See you next time!" << endl
             << "\t~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl;
        exit(0); 
    }
    else if(!rightInput)//otherwise it was not valid
    {
        cout << "\t Unknown Command" << endl;
    }
}

#endif