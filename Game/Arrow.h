#ifndef ARROW_H
#define ARROW_H

//Include headers and libraries
#include "GameObject.h"

//Using namespace std
using namespace std;

//Class Enemy inherits from GameObject class
class Arrow : public GameObject
{
	//Puclic functions
	public:
		Arrow();
		virtual ~Arrow();

		//this is initially deided on object creation, the player passes a int back from its update fucntion. 
		//the game class update function then spawns arrow and sets it on course
		Arrow(int direction);//value for direction

		//If a arrow has been created, it already has a position and direction value
		//we simple move it along that course until it hits object
		//then the collision function in the game class will deal with it
		int update(char(&gameArray)[51][80], int player_x, int player_y, int level);

		char ObjectCharacter();//return character value, ^ or v or > or <
		string objectType();//arrow type string return
		void armWeapon(int weapon);//may not use here
		int getWeapon();
		string returnWeaponString();

	private:

		WORD colors[11];

		HANDLE hstdin;
		HANDLE hstdout;
		CONSOLE_SCREEN_BUFFER_INFO csbi;

};
#endif

