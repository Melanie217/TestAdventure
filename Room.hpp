#if defined(_WIN32) || defined(_WIN64)          //depending on OS, you have to change the clear screen command
    #define PLATFORM "windows"
#elif defined(__linux__)
    #define PLATFORM "linux"
#elif defined(__APPLE__)
    #define PLATFORM "osx"
#endif

#ifndef ROOM_HPP
#define ROOM_HPP


#include <iostream>
#include <string> 
using namespace std; 

enum Direction {NORTH = 0, EAST = 1, SOUTH = 2, WEST = 3}; 

string getDirectionAsString(Direction d) 
{
    if (d == NORTH)
        return "NORTH";
    else if (d == EAST)
        return "EAST";
    else if (d == SOUTH)
        return "SOUTH";
    else
        return "WEST";

}

class Room
{
    public: 
        Room(); 
        Room(string id, string name, string description); 
        void setDirections(string north, string east, string south, string west); 
        void printRoom(); //Room Output to Terminal 
        void printDirections(); //Neighbours/Directions
        string getId();
        string getName(); 
        string getDescription(); 
        bool directionAvailable(Direction d); //can User go in that direction? Is it set? 
        string getNextRoom(Direction d);  //Get next Room ID

    private:
        string id; 
        string name; 
        string description;
        string directions[4]; 
}; 

Room::Room()
{
    id = " "; 
    name = " "; 
    description = " "; 

    for(int i = 0; i<4; i++) //set direction to default
    {
        directions[i] = "NULL"; 
    }; 
}

Room::Room(string id, string name, string description)
{
    this->id = id; 
    this-> name = name; 
    this->description = description; 

    for(int i = 0; i<4; i++)
    {
        directions[i] = "NULL";
    }; 

}

void Room::setDirections(string north, string east, string south, string west)
{
    directions[0] = north; 
    directions[1] = east; 
    directions[2] = south; 
    directions[3] = west; 
}

void Room::printRoom()
{
    /*if(PLATFORM == "osx" || PLATFORM == "linux")
        system("clear");
    else
    {
        system("CLS");
    }*/

    string roomName = "|| " + name + " ||";
    for (int i = 0; i< roomName.size(); i++)
        cout << "-";

    cout << endl

         << roomName << endl;
    for (int i = 0; i< roomName.size(); i++)
        cout << "-";
    cout << endl << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << "\t" << description << endl
         << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl; 


}

void Room::printDirections()
{
    cout << "\t Please choose a direction: "; 
    for (int i = 0; i<4; i++)
    {
        if (directions[i] != "NULL")
            cout << " ~ " << getDirectionAsString(Direction(i)) ; 
    }
    cout << endl; 
}
string Room::getId()
{
    return id; 
}
string Room::getName()
{
    return name; 
}
string Room::getDescription()
{ return description;
}

bool Room::directionAvailable(Direction d)
{
    for(int i = 0; i<4; i++) 
    {
        if (d == Direction(i) && directions[i] != "NULL")
            return true; 
    }
    return false; 
}

string Room::getNextRoom(Direction d)
{
    return directions[d]; //returns the ID of the neighbourROom in the direction User wants to go 
}

#endif