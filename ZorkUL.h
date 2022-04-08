#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Default player name (I like star wars)
inline const string name = "Obi-Wan Kenobi"; // pre-processor directives (inline)

class ZorkUL
{

private:
    vector <Room> rooms;
    Room *currentRoom;
    void createRooms();
    //bool processCommand(Command command);

    void createItems();
    string displayItems();
    Room& croom = *currentRoom; // use of C++ referneces

public:
	ZorkUL();
    //void play();
    string goToRoom(string direction);
    string printWelcome();
    string printHelp();
    string teleport();
    string showMap();
    Room getCurrentRoom();
    //void goRoom(Command command);

};

#endif /*ZORKUL_H_*/
