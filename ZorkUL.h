#ifndef ZORKUL_H_
#define ZORKUL_H_

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ZorkUL {

private:
    Parser parser;
    vector <Room> rooms;
    Room *currentRoom;
    void createRooms();
    bool processCommand(Command command);
    void goRoom(Command command);
    void createItems();
    string displayItems();
    void playerName();

public:
	ZorkUL();
	void play();
    string goToRoom(string direction);
    string printWelcome();
    string printHelp();
    string teleport();
    string showMap();
    Room getCurrentRoom();
};

#endif /*ZORKUL_H_*/
