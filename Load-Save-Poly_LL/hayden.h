
#ifndef _HAYDEN_H
#define _HAYDEN_H


class Hayden : public Room {

public:
	Hayden(string roomName, int noOfRooms, libraryType libType)
		:Room(roomName, noOfRooms, libType) {

	}

	void displayRoom();

};



#endif // _HAYDEN_H

