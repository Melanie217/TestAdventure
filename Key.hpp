#ifndef KEY_HPP
#define KEY_HPP

#include <string>

using namespace std; 

class Key 
{
    public: 
        Key(); 
        Key(string name, string roomID);
        string getName(); 
        bool getPickedUp(); 
        void setPickedUp(bool b); 
        string getRoomID(); 

    private:
        string name;
        bool hasBeenPickedUp; 
        string roomID; 
                

};

Key::Key()
{
    name = ""; 
    hasBeenPickedUp = false; 
    roomID = "";
}

Key::Key(string name, string roomID)
{
    this->name = name; 
    this->roomID = roomID; 
    hasBeenPickedUp = false; 
}

string Key::getName()
{
    return name; 
}
bool Key::getPickedUp()
{
    return hasBeenPickedUp; 
} 
string Key::getRoomID()
{
    return roomID; 
}

void Key::setPickedUp(bool b)
{
    hasBeenPickedUp = b; 
}


#endif