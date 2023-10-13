
#include <iostream>
#include <fstream>
#include <string>
#include "Container.h"
#include "room.h"
#include "noble.h"
#include "hayden.h"

using namespace std;


void executeAction(char c);
Room* searchRoom(string name_input);


void addRoom(string name_input, int no_input, libraryType type);
void displayList();
void save(string fileName);
void load(string fileName);

Container* list = NULL;				// global list

int main()
{
	char c = 'i';


	load("list.txt");
	do {
		cout << "\nCSE240 HW7\n";
		cout << "Please enter your selection:\n";
		cout << "\t a: add a new room\n";
		cout << "\t d: display room list\n";
		cout << "\t c: change library type\n";
		cout << "\t q: quit\n";
		cin >> c;
		cin.ignore();
		executeAction(c);
	} while (c != 'q');

	save("list.txt");

	list = NULL;

	return 0;
}

// Ask for details from user for the given selection and perform that action
// Read the function case by case
void executeAction(char c)
{
	string name_input;
	int no_input;
	int type_input = 2;
	libraryType type;
	Room* roomResult = NULL;

	switch (c)
	{
	case 'a':	// add room
		// input room details from user
		cout << endl << "Enter room name: ";
		getline(cin, name_input);
		cout << "Enter number of rooms: ";
		cin >> no_input;
		cin.ignore();

		while (!(type_input == 0 || type_input == 1))
		{
			cout << "Enter library type: " << endl;
			cout << "0. Hayden " << endl;
			cout << "1. Noble" << endl;
			cin >> type_input;
			cin.ignore();
		}
		type = (libraryType)type_input;

		// searchRoom() will return the room object if found, else returns NULL
		roomResult = searchRoom(name_input);
		if (roomResult == NULL)
		{
			addRoom(name_input, no_input, type);
			cout << endl << "Room added to list!" << endl << endl;
		}
		else
			cout << endl << "Room already present in the list!" << endl << endl;

		break;

	case 'd':		// display the list
		displayList();
		break;

	case 'c':		// change room type
		cout << endl << "Enter room name: ";
		getline(cin, name_input);
		// searchRoom() will return the room node if found, else returns NULL
		roomResult = searchRoom(name_input);
		if (roomResult == NULL)
		{
			cout << endl << "Room not in list!" << endl << endl;
		}
		else
		{
			// if room exists in the list, then ask user for new number of rooms
			cout << endl << "Enter new library type: " << endl;
			cout << "0. Hayden " << endl;
			cout << "1. Noble" << endl;
			cin >> type_input;
			cin.ignore();
			type = (libraryType)type_input;
			// 'roomResult' contains the room whose Library Type is to be changed.
			// Call the function with appropriate arguments.


			cout << endl << "Library type changed!" << endl << endl;
		}
		break;

	case 'q':		// quit
		break;

	default: cout << c << " is invalid input!\n";
	}

}

Room* searchRoom(string name_input)
{

	Container* tempList = list;			// work on a copy of 'list'

	while (tempList != NULL)			// parse till end of list
	{
		if (tempList->room->getName() == name_input)
		{
			return tempList->room;	// return the room if found
		}

		tempList = tempList->next;		// parse the list
	}

	return NULL;						// return NULL if room not found in list
}



void changeLibraryType(Room* roomP, int newLibType) {
	if (newLibType == 0) {
		roomP->lib = hayden;
	}
	if (newLibType == 1) {
		roomP->lib = noble;
	}
	else {
		cout << "Not a valid room type" << endl;
	}

}


//Add room to global linked list

void addRoom(string name_input, int no_input, libraryType type)
{
	Container* tempList = list;
	Container* newContainer = new Container;
	Room* newRoom;
	if (type == 0) {
		newRoom = new Hayden(name_input, no_input, type);
	}
	else {
		newRoom = new Noble(name_input, no_input, type);
	}

	newContainer->room = newRoom;
	newContainer->next = NULL;

	if (list == NULL) {
		list = newContainer;
		return; //bye
	}

	while (tempList->next != NULL) { //Tranverse the linked list to reach the end then add a node
		tempList = tempList->next;
	}
	tempList->next = newContainer;
	return;


}

//Display list of rooms uses polymorphism 

void displayList()
{
	Container* tempList = list;

	while (tempList) {
		tempList->room->displayRoom();
		tempList = tempList->next;
	}

}

//save a list into a file


void save(string fileName)
{
	Container* tempList = list;


	int size = 0;

	ofstream file;

	while (tempList != NULL) {
		size++;
		tempList = tempList->next;
	}

	file.open(fileName);
	if (file.is_open()) {
		tempList = list;
		file << size << endl;
		int type;

		while (tempList != NULL) {
			type = tempList->room->getLibraryType();
			string name = tempList->room->getName();
			int num = tempList->room->getNo();
			file << name << endl;
			file << num << endl;
			file << type << endl;
			tempList = tempList->next;
		}
		file.close();

	}



}

//Load a list from a file

void load(string fileName)
{

	Container* newNode = list;


	int size = 0;

	ifstream file;

	file.open(fileName);


	string name;
	int num;
	int numType;
	libraryType type;

	if (file.is_open()) {
		file >> size;

		for (int i = 0; i < size; i++) {

			Container* newNode = new Container();

			file >> name;
			file >> num;
			file >> numType;

			if (numType == 0) {
				type = hayden;
			}
			else {
				type = noble;
			}

			Room* newRoom = new Room(name, num, type);
			newNode->room = newRoom;
			newNode->next = list;
			list = newNode;

		}
		file.close();

	}


}
