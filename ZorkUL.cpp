#include <iostream>
#include <ctime>
#include <cstdlib>
#include "ZorkUL.h"

using namespace std;

/*
int main(int argc, char argv[]) {
	ZorkUL temp;
	temp.play();
	return 0;
}
*/

ZorkUL::ZorkUL()
{
	createRooms();
    srand(time(0));
}

// Function to create all of the rooms and store them in an array of pointers for ease of access
void ZorkUL::createRooms()
{
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("a");
            a->addItem(new Item("x", 1, 11)); //adds items to the room
            a->addItem(new Item("y", 2, 22));
        rooms.push_back(*a); //adds the room to the vector rooms
	b = new Room("b");
            b->addItem(new Item("xx", 3, 33));
            b->addItem(new Item("yy", 4, 44));
        rooms.push_back(*b);
	c = new Room("c");
        rooms.push_back(*c);
	d = new Room("d");
        rooms.push_back(*d);
	e = new Room("e");
        rooms.push_back(*e);
	f = new Room("f");
        rooms.push_back(*f);
	g = new Room("g");
        rooms.push_back(*g);
	h = new Room("h");
        rooms.push_back(*h);
	i = new Room("i");
        rooms.push_back(*i);
    j = new Room("j");
        rooms.push_back(*j);

// Sets the available exits for each room
//             (North,  East,   South,  West)
    a->setExits(f,      b,      d,      c);
    b->setExits(NULL,   j,      NULL,   a);
    c->setExits(NULL,   a,      NULL,   NULL);
    d->setExits(a,      e,      NULL,   i);
    e->setExits(NULL,   NULL,   NULL,   d);
    f->setExits(NULL,   g,      a,      h);
    g->setExits(NULL,   NULL,   NULL,   f);
    h->setExits(NULL,   f,      NULL,   NULL);
    i->setExits(NULL,   d,      NULL,   NULL);
    j->setExits(NULL,   NULL,   NULL,   b);

    currentRoom = a; // Sets the default starting room as room a
}

// Function to allow the player to see the map
string ZorkUL::showMap()
{
    string map;
    map =   "[h] --- [f] --- [g] \n"
            "         |          \n"
            "         |          \n"
            "[c] --- [a] --- [b] --- [j] \n"
            "         |          \n"
            "         |          \n"
            "[i] --- [d] --- [e] \n";

    return map;
}

/*
// Function to allow the player to create thier name
void ZorkUL::playerName() {
    string name;

    cout << "Enter your name: ";
    cin >> name;

    cout << "Your name is " << name << endl;
    cout << endl; // Second endl just makes it look neater in the console :)
}
*/

// Function to welcome the player to the game
string ZorkUL::printWelcome()
{
    return "Welcome to this absolute beauty of a Zork clone! \n"
           "I mean it's just so much better than the original... \n"
           "They didnt even have buttons... \n"
           "\n Click on the *Help* button for instructions on how to use the controls \n";
}

// Function to display the instructions on how to use the controls
string ZorkUL::printHelp()
{
    return "Click on the directional buttons according to the direction you want to go \n"
           "Click on the teleport button to be teleported to a random room \n"
           "Click on the map button to see the map\n";

}

// Function for teleporting the player to a random room
string ZorkUL::teleport()
{
    currentRoom = &rooms.at((int) rand() % rooms.size());
        return currentRoom->longDescription() + "\n I warned you, theres no doors now. \n I bet you wished you listened :)";
}


// Function to list all of the items in a room
string ZorkUL::displayItems()
{
    return currentRoom->displayItem();
}

// Function to tell the player what room they are currently in
Room ZorkUL::getCurrentRoom()
{
    return *currentRoom;
}

// Function for moving between the rooms, returns a message if there is no room in the direction selected
string ZorkUL::goToRoom(string direction)
{
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL) {
        return "Thats a wall... maybe try like I don't know..? A door!";
    } else {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}



/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */

/*
bool ZorkUL::processCommand(Command command) {
	if (command.isUnknown()) {
		cout << "invalid input"<< endl;
		return false;
	}

	string commandWord = command.getCommandWord();
	if (commandWord.compare("info") == 0)
		printHelp();

	else if (commandWord.compare("map") == 0)
		{
        cout << "[h] --- [f] --- [g]" << endl;
		cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[c] --- [a] --- [b] --- [j]" << endl;
		cout << "         |         " << endl;
		cout << "         |         " << endl;
		cout << "[i] --- [d] --- [e]" << endl;
		}

	else if (commandWord.compare("go") == 0)
		goRoom(command);

    else if (commandWord.compare("take") == 0)
    {
       	if (!command.hasSecondWord()) {
		cout << "incomplete input"<< endl;
        }
        else
         if (command.hasSecondWord()) {
        cout << "you're trying to take " + command.getSecondWord() << endl;
        int location = currentRoom->isItemInRoom(command.getSecondWord());
        if (location  < 0 )
            cout << "item is not in room" << endl;
        else
            cout << "item is in room" << endl;
        cout << "index number " << + location << endl;
        cout << endl;
        cout << currentRoom->longDescription() << endl;
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }

    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/

/** COMMANDS **/

/*
string ZorkUL::go(string direction) {
	//Make the direction lowercase
	//transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
	//Move to the next room
	Room* nextRoom = currentRoom->nextRoom(direction);
	if (nextRoom == NULL)
		return("direction null");
	else
	{
		currentRoom = nextRoom;
		return currentRoom->longDescription();
	}
}
*/

/**
 *  Main play routine.  Loops until end of play.
 */

/*
void ZorkUL::play() {
    playerName();
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
}
*/

