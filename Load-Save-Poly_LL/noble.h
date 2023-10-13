

#ifndef _NOBLE_H_
#define _NOBLE_H_

class Noble : public Room {

public:
	Noble(string roomName, int noOfRooms, libraryType libType)
		:Room(roomName, noOfRooms, libType) {

	}

	void displayRoom();

};




#endif // _NOBLE_H_
