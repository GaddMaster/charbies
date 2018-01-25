#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//Included libraries
#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <stdio.h>   
#include <cstddef>
#include <ctime>
#include <conio.h>
#include <windows.h>


#define KEY_UP 72
#define KEY_DOWN 80
#define KEY_LEFT 75
#define KEY_RIGHT 77

#define KEY_W 119
#define KEY_D 100
#define KEY_S 115
#define KEY_A 97

#define EXIT 27

#define INFO 0x08

//Using namespace std
using namespace std;

//Class GameObject
class GameObject
{
	//Public Functions for GameObject
	public:
		GameObject();//constructor
		~GameObject();//de constructor
		void spawn(string typeID, int health, int speed, int x, int y, int stamina);//spawn object with handfull of values

		//set x and y coordinates
		void setGameObject_X(int x);
		void setGameObject_Y(int y);

		void setHealth(int health);//set health

		//Update function passing down a pointer to our game array for the use of sub objects
		//It also returns a int which allows subobjects to pass back a message
		//for our player object this meassge can be as example fire a arrow <> 1=fire up, 2=fire right, , 3=fire down, 4=fire left
		//this return hands back a signal tyo the main game class advising it what to do. this can be used for endless reasons
		virtual int update(char(&gameArray)[51][80], int player_x, int player_y, int level);

		virtual string objectType();//return object type string
		virtual int giveDamage();//damage value for object
		virtual char ObjectCharacter();//single char return for each object type

		//return x or y coordinates
		int GameObject_X();
		int GameObject_Y();

		int getHealth();//return health
		string typeID();//object ID
		bool isAlive();//Return is alive by checking health

		//Special windows function for moving our character position exactly where we need to change something
		//this avoids having to reprint stuff that doesnt need to be
		//we just print exactly only what changes
		void gotToXnY(int x, int y);

		//main class runs a Sleep command which replicates 20 frames per second
		//so we know that things can be updated 20 times a second
		//this means we can limit or increqase oibject actions per second
		//our enemy start off at one stamina which means they get one update per second.
		//we will reduce and increase player stamina depending on what he is at
		//collecting treasure gives him more while possible hitting enemy loses some
		void raiseStamina(int stamina);
		int getStamina();//set stamina

		//Passing down a int will modify different things for different sub objects. all weapons oriented
		virtual void armWeapon(int weapon);
		virtual int getWeapon();
		void setDirection(int directiono);

		string returnWeaponString();

	//Protected variables to allow child classes direct access
	protected:
		string m_typeID;
		signed int m_health;
		signed int m_x;
		signed int m_y;
		int debugger;
		bool alive;
		int m_damage;
		string m_type;
		string weapon;
		char object_char;
		int x;//Always handy have a X
		int y;//Always handy have a Y
		bool moved;
		signed int randomNumber;
		signed int randomNumberII;
		int status;//Enemy Direction for random steps in one way - Check Enemy Update
		char direction;//used for arrow

		//Games runs 20 frames per second. If you have 20 stamina you can call your update 20 times a second
		//If you have one stamina we can call your function once per second
		//Enemies will have chnagable stamina for fast they respond around the map
		//Player will always have 20 stamina unless he gets hurt
		//This is better than speed
		int m_stamina;
		int staminaCounter;//Counting game loops
};

#endif