


#include "room.h"
#include "noble.h"

#include <iostream>

void Noble::displayRoom()
{

	if (getLibraryType() == hayden) {
		cout << "Room Name: " << getName() << "\n" << "Room Number: " << getNo() << "\n" << "Library Type : Hayden" << endl;
	}
	else {
		cout << "Room Name: " << getName() << "\n" << "Room Number: " << getNo() << "\n" << "Library Type: Noble" << endl;
	}


}
