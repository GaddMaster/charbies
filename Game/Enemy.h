#ifndef ENEMY_H
#define ENEMY_H

//Include headers and libraries
#include "GameObject.h"
#include "Coordinates.h"

//Using namespace std
using namespace std;

//Class Enemy inherits from GameObject class
class Enemy : public GameObject
{
	//Puclic functions
	public:
		Enemy();
		virtual ~Enemy();
		int update(char(&gameArray)[51][80], int player_x, int player_y, int level);
		int giveDamage();
		string objectType();
		char ObjectCharacter();
		void armWeapon(int weapon);
		int getWeapon();
		string returnWeaponString();

	private:

		//VARIABLES FOR AI COMPUTATION
		bool y_same;
		bool x_same;
		bool up;
		bool down;
		bool left;
		bool right;
		bool moved;
		float slope;
		bool skip;
		bool path_found;
		bool gridlock;
		int serialID;
		string coordinate_name;
		int optimal_directions[4];
		int origCoorX;
		int origCoorY;

		//We want to create a path finder to our player position
		//We need a list of positions to move through each game loop
		//This list and iterator is used the the enemy update function
		list <Coordinates*> listOfCoordinates;
		list <Coordinates*>::iterator coor_iter;

};
#endif
