


#include "room.h"
#include "hayden.h"

#include <iostream>

void Hayden::displayRoom()
{

	if (getLibraryType() == hayden) {
		cout << "Room Name: " << getName() << "\n" << "Room Number: " << getNo() << "\n" << "Library Type : Hayden" << endl;
	}
	else {
		cout << "Room Name: " << getName() << "\n" << "Room Number: " << getNo() << "\n" << "Library Type: Noble" << endl;
	}


}
