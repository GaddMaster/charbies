#ifndef BOW_H
#define BOW_H

//Include headers and libraries
#include "GameObject.h"

//Using namespace std
using namespace std;

//Class Enemy inherits from GameObject class
class Bow : public GameObject
{
	//Puclic functions
	public:
		Bow();
		virtual ~Bow();
		int update(char(&gameArray)[51][80], int player_x, int player_y, int level);
		char ObjectCharacter();
		string objectType();
		void armWeapon(int weapon);
		int getWeapon();
		string returnWeaponString();
};
#endif
