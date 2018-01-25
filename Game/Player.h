#ifndef PLAYER_H
#define PLAYER_H

//INHERITANCE GAME OBJECT CLASS MODEL
#include "GameObject.h"


class Player : public GameObject
{
	//PUBLIC FUNCTIONS
	public:
		Player();
		virtual ~Player();
		int update(char(&gameArray)[51][80], int player_x, int player_y, int level);
		int giveDamage();
		string objectType();
		char ObjectCharacter();
		void armWeapon(int weapon);
		int getWeapon();
		string returnWeapon();

	//PLAYER ONLY PRIVATE VARIABLES
	private:
		int input;//PLAIN INPUT VARIABLE FOR GENERAL USE
		bool can_move;//PLAYER IS NOT STUCK - USED IN PLAYER UPDATE FUNCTION
		bool m_bow;//DOES PLAYER HAVE A BOW
		bool bomb;//DOES PLAYER HAVE A BOMB

		string weapon;//WEAPON CURRENTLY HELD FOR USER INFORMATION PANAL AT BOTTOM
}; 
#endif

