//Included libraries
#include "GameObject.h"
#include "Enemy.h"
#include "Player.h"
#include "Game.h"
#include <iostream>
#include <windows.h>
#include <conio.h>
#include <stdio.h> 
#include <time.h>
#include <string>





// Move Cursor to position X and Y
void gotToXnY(int x, int y)
{
	COORD point;
	point.X = x;
	point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}


//Hide cursor visability
void hideCursor(void)
{
	CONSOLE_CURSOR_INFO info;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
	info.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

#define _WIN32_WINNT 0x0510

//Clear console function Called after each movement
void ClearScreen()
{
	HANDLE                     hStdOut;
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	DWORD                      count;
	DWORD                      cellCount;
	COORD                      homeCoords = { 0, 0 };

	hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE) return;

	/* Get the number of cells in the current buffer */
	if (!GetConsoleScreenBufferInfo(hStdOut, &csbi)) return;
	cellCount = csbi.dwSize.X *csbi.dwSize.Y;

	/* Fill the entire buffer with spaces */
	if (!FillConsoleOutputCharacter(
		hStdOut,
		(TCHAR) ' ',
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Fill the entire buffer with the current colors and attributes */
	if (!FillConsoleOutputAttribute(
		hStdOut,
		csbi.wAttributes,
		cellCount,
		homeCoords,
		&count
	)) return;

	/* Move the cursor home */
	SetConsoleCursorPosition(hStdOut, homeCoords);
}

//Using namespace std
using namespace std;

void fullscreen()
{
	keybd_event(VK_MENU, 0x38, 0, 0);
	keybd_event(VK_RETURN, 0x1c, 0, 0);
	keybd_event(VK_RETURN, 0x1c, KEYEVENTF_KEYUP, 0);
	keybd_event(VK_MENU, 0x38, KEYEVENTF_KEYUP, 0);
}

//Start to main function
int main()
{

	int milli_time = 0;
	int sec_time = 0;

	//Make window a specific size
	SMALL_RECT rect;
	COORD coord;
	coord.X = 161; // Defining our X and
	coord.Y = 52;  // Y size for buffer.
	rect.Top = 0;
	rect.Left = 0;
	rect.Bottom = coord.Y - 1; // height for window
	rect.Right = coord.X - 1;  // width for window
	HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE); // get handle
	SetConsoleScreenBufferSize(handle, coord);       // set buffer size
	SetConsoleWindowInfo(handle, TRUE, &rect);       // set window size
	//SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);


	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	//fullscreen();
	int collide = 0;//Collide Results for collision function in Game
	hideCursor();//Hide Cursor


	///////////////////LEVEL ONE/////////////////////////
	//Set up first level
	Game levelOne(1);//Input level parameter
	levelOne.story();
	levelOne.init();//Call Init function
	levelOne.playerPosition();//Shows player position
	
	//Level One Game Loop
	while (collide != 1 && collide != 2)
	{
		levelOne.update();
		collide = levelOne.Collide();
		levelOne.clean();
		Sleep(51);

		milli_time++;

		if (milli_time >= 20)
		{
			milli_time = 0;
			sec_time++;
			gotToXnY(68 * 2, 40);//WEAPON SPOT
			cout << setw(2) << sec_time;
		}
	}

	//Check Level One Result
	if (collide == 1)//Game Over
	{
		ClearScreen();
		//cout << "Game Over Screen Loading..." << endl;
		levelOne.gameOver();
		return 0;
	}
	else if (collide == 2)//Level Passed
	{
		ClearScreen();
		levelOne.wellDone();
		ClearScreen();

	}
	else//Fatal Error
	{
		ClearScreen();
		cout << "Something Went Wrong - Game FLow I" << endl;
	}
	///////////////////LEVEL ONE/////////////////////////


	///////////////////LEVEL TWO/////////////////////////
	//Create Game COnstructor for level two
	Game levelTwo(2);
	levelTwo.passLevelOne();
	levelTwo.init();
	levelTwo.playerPosition();
	//Collide Results for collision function in Game
	collide = 0;

	//Level Two Game Loop
	while (collide != 1 && collide != 2)
	{
		levelTwo.update();
		collide = levelTwo.Collide();
		levelTwo.clean();
		Sleep(51);
	}

	//Check Level Two Result
	if (collide == 1)//Game Over
	{
		ClearScreen();
		levelTwo.gameOver();
		return 0;
	}
	else if (collide == 2)//Level Passed
	{
		ClearScreen();
		levelTwo.wellDone();
		ClearScreen();
	}
	else//Fatal Error
	{
		ClearScreen();
		cout << "Something Went Wrong - Game FLow II" << endl;
	}
	///////////////////LEVEL TWO/////////////////////////



	///////////////////LEVEL THREE/////////////////////////
	//Create Game COnstructor for level two
	Game levelThree(3);
	levelThree.passLevelTwo();
	levelThree.init();
	levelThree.playerPosition();
	//Collide Results for collision function in Game
	collide = 0;

	//Level Two Game Loop
	while (collide != 1 && collide != 2)
	{
		levelThree.update();
		collide = levelThree.Collide();
		levelThree.clean();
		Sleep(51);
	}

	//Check Level Two Result
	if (collide == 1)//Game Over
	{
		ClearScreen();
		levelThree.gameOver();
		return 0;
	}
	else if (collide == 2)//Level Passed
	{
		ClearScreen();
		levelThree.wellDone();
		ClearScreen();
	}
	else//Fatal Error
	{
		ClearScreen();
		cout << "Something Went Wrong - Game FLow II" << endl;
	}
	///////////////////LEVEL THREE/////////////////////////

	levelThree.passLevelThree();
	return 0;
}


