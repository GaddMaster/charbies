#ifndef TREASURE_H
#define TREASURE_H

//Include header GameObject
#include "GameObject.h"

//Player class inherits from GameObject Class
class Treasure : public GameObject
{
	//Player Public functions 
	public:
		Treasure();
		virtual ~Treasure();
		int update(char(&gameArray)[51][80], int player_x, int player_y, int level);
		char ObjectCharacter();
		string objectType();
		void armWeapon(int weapon);
		int getWeapon();
		string returnWeaponString();
};
#endif

