
#ifndef _ROOM_H_
#define _ROOM_H_

#include <string>
using namespace std;

enum libraryType { hayden = 0, noble };	// definition of libraryType

class Room {
private:
	string name; // private data members
	int no;
	libraryType lib;

public:
	Room(string roomName, int noOfRooms, libraryType libType); // constructor

	// accessor methods
	string getName();
	int getNo();
	libraryType getLibraryType();

	virtual void displayRoom()
	{}


	friend void changeLibraryType(Room* roomP, int newLibType);


};

#endif // _ROOM_H_
