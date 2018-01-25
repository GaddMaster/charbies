#ifndef GAME_H
#define GAME_H

//Included headers of classes
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include "Treasure.h"
#include "Bow.h"
#include "Arrow.h"

//Included libraries
#include <list>
#include <cstdlib>
#include <conio.h>
#include <array>
#include <time.h>
#include <string>
#include <iostream>
#include <fstream>
#include <windows.h>
#include <iomanip>

//Using namespace std
using namespace std;

//Class Game
class Game
{

	//Public functions for Game
	public:
		Game();
		~Game();
		Game(int level);
		void init();
		void update();
		signed int Collide();
		void clean();
		void gotToXnY(int x, int y);
		void gameOver();
		void wellDone();
		void ClearScreen();
		void story();
		void passLevelOne();
		void passLevelTwo();
		void passLevelThree();
		// Move Cursor to position X and Y
		void Game::playerPosition();


	private:

		//Level value for other classes and fucntions
		int m_level;

		//Our first Array is for doing calculations in background.
		//Our second Array is for displaying our map.
		//We compute our 1st array during execution, then we
		//translate it to our virtual array for displaying to our user.
		//We have 3 levels to choose from.
		char gameArray[51][80];
		char m_char;
		ifstream fileInput;
		ifstream in_gameOver;
		ifstream in_wellDone;
		ifstream in_story;
		ifstream in_passLevelOne;
		ifstream in_passLevelTwo;
		ifstream in_passLevelThree;
		int m_time;

		//Random & ID Number
		int serialID;
		int randomInt;

		//Coordinates Variables
		char space;
		int x;
		int y;
		int loop_x;
		int loop_y;
		int end;
		int ObjectX;
		int ObjectY;
		int movement;
		int* P_movement = &movement;
		bool trap;
		int lastDash;
		int returnUp;

		//List and iterators
		list <GameObject*> listOfObjects;
		list <GameObject*>::iterator iter;
		list <GameObject*>::iterator iter2;

		//Game Objects
		GameObject* P_Player;
		int enemies_count;
		int treasureCount;
		int treasure;
		string enemy_ID;
		string treasure_ID;
		GameObject* bow;
		
		//arrow shooting , bomb dropping , return values from update function can affect this
		int updateReturn;
};
#endif