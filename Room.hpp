#ifndef ROOM_HPP
#define ROOM_HPP


#include <iostream>
#include <string> 
#include "Helpful.hpp"
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
        void printRoom(bool hasKey, bool roomIsKey); //Room Output to Terminal 
        void printDirections(); //Neighbours/Directions
        int keys; 
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
        string roomHasKey; 
        Helpful h; 
}; 

Room::Room()
{
    id = " "; 
    name = " "; 
    description = " "; 
    keys = 0; 
    roomHasKey = "Oh! Looks like you found a key! What is it for?";

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
    keys = 0; 
    roomHasKey = "Oh! Looks like you found a key! What is it for?"; 

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

void Room::printRoom(bool hasKey, bool roomIsKey)
{
    if(hasKey)
        keys = 1; 

    string roomName = "|| " + name + " ||";
    string numKeys = "|| Keys: " + to_string(keys) + " ||";

    for (int i = 0; i< roomName.size(); i++)
        cout << "-";

    cout << endl << roomName << endl;
    for (int i = 0; i< roomName.size(); i++)
        cout << "-";
        
    cout << endl << numKeys << endl;
    for (int i = 0; i< numKeys.size(); i++)
        cout << "-";

    cout << endl << endl;

    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl
         << "\t"; 
    h.slowPrinting(description); 
    if(roomIsKey) 
    {
        cout << endl << "\t"; 
        h.slowPrinting(roomHasKey); 
    }
    cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl << endl; 


}

void Room::printDirections()
{
    cout << "\t"; 
    h.slowPrinting("Please choose a direction: "); 
    cout << endl << "\t"; 
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