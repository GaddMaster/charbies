//INCLUDE GAME HEADER FILE
#include "Game.h"

//CLASS CONSTRUCTOR
Game::Game()
{
	for (loop_y = 0; loop_y; loop_y++)
		for (loop_x = 0; loop_x; loop_x++)
			gameArray[loop_y][loop_x] = ' ';
}

//CLASS DE-CONSTRUCTOR
Game::~Game(){}

//GO TO CURSOR POSITION TO ALTER THE CHARACTER THERE - NOT C++
void Game::gotToXnY(int x, int y)
{
	COORD point;
	point.X = x;
	point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

//READS GAME OVER FILE AND PRINTS TO SCREEN - GAME ENDS
void Game::gameOver()
{
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	in_gameOver.open("gameOver.txt");
	for (loop_y = 0; loop_y <= 39; loop_y++)
	{
		for (loop_x = 0; loop_x <= 79; loop_x++)
		{
			in_gameOver >> m_char;
			if (m_char == '1')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << char(254);// ■ WALLS CHARACTER ASCII EXTENDED - DIGIT 1 FROM FILE
			}
			else if (m_char == '2')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << '2';// ■ WALLS CHARACTER ASCII EXTENDED - DIGIT 1 FROM FILE
			}
			else
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) <<  ' ';//EMPTY SPACE
			}
		}
	}
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	Sleep(5100);

}

//READS GAME stroy FILE AND PRINTS TO SCREEN - GAME ENDS
void Game::passLevelOne()
{
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	in_passLevelOne.open("levelOnePass.txt");
	for (loop_y = 0; loop_y <= 39; loop_y++)
	{
		for (loop_x = 0; loop_x <= 79; loop_x++)
		{
			in_passLevelOne >> m_char;
			if (m_char == '1')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << char(254);
			}
			if (m_char == '0')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << ' ';
			}
			else
			{
				
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << m_char;
			}
		}
		cout << endl;
	}
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	Sleep(15000);
	ClearScreen();
}

//READS GAME stroy FILE AND PRINTS TO SCREEN - GAME ENDS
void Game::passLevelTwo()
{
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	in_passLevelTwo.open("levelTwoPass.txt");
	for (loop_y = 0; loop_y <= 39; loop_y++)
	{
		for (loop_x = 0; loop_x <= 79; loop_x++)
		{
			in_passLevelTwo >> m_char;
			if (m_char == '1')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << char(254);
			}
			if (m_char == '0')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << ' ';
			}
			else
			{

				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << m_char;
			}
		}
		cout << endl;
	}
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	Sleep(15000);
	ClearScreen();
}

//READS GAME stroy FILE AND PRINTS TO SCREEN - GAME ENDS
void Game::passLevelThree()
{
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	in_passLevelThree.open("levelThreePass.txt");
	for (loop_y = 0; loop_y <= 39; loop_y++)
	{
		for (loop_x = 0; loop_x <= 79; loop_x++)
		{
			in_passLevelThree >> m_char;
			if (m_char == '1')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << char(254);
			}
			if (m_char == '0')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << ' ';
			}
			else
			{

				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << m_char;
			}
		}
		cout << endl;
	}
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	Sleep(15000);
	ClearScreen();
}


//READS GAME stroy FILE AND PRINTS TO SCREEN - GAME ENDS
void Game::story()
{
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	in_story.open("story.txt");
	for (loop_y = 0; loop_y <= 39; loop_y++)
	{
		for (loop_x = 0; loop_x <= 79; loop_x++)
		{
			in_story >> m_char;
			if (m_char == '1')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << char(254);
			}
			if (m_char == '0')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << ' ';
			}
			else
			{

				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << m_char;
			}
		}
		cout << endl;
	}
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	Sleep(15000);
	ClearScreen();
}

//READS WELL DONE FROM FILE AND PRINTS TO SCREEN - LEVEL PASSED
void Game::wellDone()
{
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	in_wellDone.open("wellDone.txt");
	for (loop_y = 0; loop_y <= 39; loop_y++)
	{
		for (loop_x = 0; loop_x <= 79; loop_x++)
		{
			in_wellDone >> m_char;
			if (m_char == '1')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << char(254);// ■ WALLS CHARACTER ASCII EXTENDED - DIGIT 1 FROM FILE
			}
			else if (m_char == '2')
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << '2';// ■ WALLS CHARACTER ASCII EXTENDED - DIGIT 1 FROM FILE
			}
			else
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << ' ';//EMPTY SPACE
			}
		}
	}
	//GAME OVER MAP FILE READER /////////////////////////////////////////////////////////////////////////
	Sleep(5100);
}

//CREATES GAME THAT ACCEPTS A PARAMETER AS LEVEL
Game::Game(int level) {
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	//Game Constructor has a Level Parameter
	m_level = level;
	m_time = 0;
	lastDash = 3;//LAST STAMINA BOOASTING IN LEVEL 3

	//Every Game only has one Player
	P_Player = new Player();

	//One bow per level
	bow = new Bow();

	//movement controls
	movement = 0;

	//Switch case for our 3 levels
	//We generate a set number of enemies using our enemey Generator in the INIT FUNCTION
	switch (m_level) 
	{

	    case 1:enemies_count = 10; treasureCount = 10; treasure = treasureCount; break;//Five Enemies for Level One

		case 2:enemies_count = 15; treasureCount = 10; treasure = treasureCount; break;//Ten Enemies for Level Two

		case 3:enemies_count = 25; treasureCount = 6; treasure = treasureCount; break;//Four Enemies for Level Three

		default:break;

	}

}

//Display player position to user
void Game::playerPosition()
{
	//Print arrow  along both axis to Players position
	for (loop_y = 0; loop_y < 40; loop_y++)
	{
		for (loop_x = 0; loop_x < 80; loop_x++)
		{
			if (loop_y == P_Player->GameObject_Y() && loop_x < P_Player->GameObject_X())
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << '>';
			}
			else if (loop_y == P_Player->GameObject_Y() && loop_x > P_Player->GameObject_X())
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << '<';
			}
			else if (loop_x == P_Player->GameObject_X() && loop_y < P_Player->GameObject_Y())
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << 'v';
			}
			else if (loop_x == P_Player->GameObject_X() && loop_y > P_Player->GameObject_Y())
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << '^';
			}
		}
	}

	Sleep(1000);

	//Print back our array after done
	for (loop_y = 0; loop_y < 40; loop_y++)
	{
		for (loop_x = 0; loop_x < 80; loop_x++)
		{
			if (loop_y == P_Player->GameObject_Y() && loop_x < P_Player->GameObject_X())
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << gameArray[loop_y][loop_x];
			}
			else if (loop_y == P_Player->GameObject_Y() && loop_x > P_Player->GameObject_X())
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << gameArray[loop_y][loop_x];
			}
			else if (loop_x == P_Player->GameObject_X() && loop_y < P_Player->GameObject_Y())
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << gameArray[loop_y][loop_x];
			}
			else if (loop_x == P_Player->GameObject_X() && loop_y > P_Player->GameObject_Y())
			{
				gotToXnY(loop_x * 2, loop_y);
				cout << setw(2) << gameArray[loop_y][loop_x];
			}
		}
	}

}

//INIT FUNCTION has 3 Level options - The Level parameter Decides
void Game::init()      
{

	srand(time(NULL));//Used for Random Bumber Generator
	serialID = 1;//Used For Enemy Genberator

	switch (m_level)
	{
		case 1://Design our first Level 
		{

			//GAME MAP FILE READER /////////////////////////////////////////////////////////////////////////////
			fileInput.open("levelOne.txt");
			for (loop_y = 0; loop_y < 51; loop_y++)
			{
				for (loop_x = 0; loop_x < 80; loop_x++)
				{
					fileInput >> m_char;
					if (m_char == '1')
						gameArray[loop_y][loop_x] = char(254);// ■ WALLS CHARACTER ASCII EXTENDED - DIGIT 1 FROM FILE
					else if (m_char == '2')
						gameArray[loop_y][loop_x] = '8';// 8 SHIPS CHARACTER - DIGIT 2 FROM FILE
					else if (m_char == '3')
						gameArray[loop_y][loop_x] = '$';// Ö TELEPORTERS CHARACTER ASCII EXTENDED - DIGIT 3 FROM FILE
					else if (m_char == '0')
						gameArray[loop_y][loop_x] = ' ';//EMPTY SPACE
					else
						gameArray[loop_y][loop_x] = m_char;
				}
			}
			//GAME MAP FILE READER /////////////////////////////////////////////////////////////////////////////


			//PLAYER GENERATOR/////////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL I Player IN" << endl;//Debugging
			//Assign Player Random unique Coordinates
			serialID = 1;//Reset Serial ID when we need to use it
			do
			{
				//Our X & Y class variables are given random coordinates between 0 and 30
				y = (rand() % 39);
				x = (rand() % 79);
			} while (gameArray[y][x] != ' ');//Keep Trying until we hit a empty space
			P_Player->spawn(P_Player->objectType() + " <> " + to_string(serialID), 160, 1, x, y, 20);//Spawn Player
			listOfObjects.push_back(P_Player);//Push Player onto Game Object List
			gameArray[y][x] = P_Player->ObjectCharacter();//Set Player Character Once Off
			//cout << "INIT  LEVEL I Player OUT" << endl;//Debugging
			//PLAYER GENERATOR//////////////////////////////////////////////////////////////////////////////////



			//ENEMY GENERATOR///////////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL I Enemy IN" << endl;//Debugging
			//Dynamic Object Generator - Uses Serial ID for Unique Key
			//Enemy Count is five for Level One
			serialID = 1;
			for (loop_x = 0; loop_x < enemies_count; loop_x++)
			{

				//This do while loop generates random coordinates. It keeps trying till finds empty space
				do
				{
					//Our X & Y class variables are given random coordinates between 0 and 30
					y = (rand() % 39);
					x = (rand() % 79);
				} while (gameArray[y][x] != ' ');//While not empty
				enemy_ID = "Enemy " + to_string(serialID);//Generates Unique Enemy name ID
				GameObject* enemy_ID = new Enemy();//Creates new Enemy Object with Unique name
				randomInt = (rand() % 4) + 1;
				enemy_ID->spawn(enemy_ID->objectType() + " <> " + to_string(serialID), 100, 1, x, y, randomInt);//Spawn Enemy
				serialID++;//Count - Naming
				listOfObjects.push_back(enemy_ID);//Push to Game Object List
				gameArray[y][x] = enemy_ID->ObjectCharacter();//One time assign Object character to map
			}
			//cout << "INIT  LEVEL I Enemy OUT" << endl;//Debugging
			//ENEMY GENERATOR////////////////////////////////////////////////////////////////////////////


			//TREASURE GENERATOR/////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL I Enemy IN" << endl;//Debugging
			//Dynamic Object Generator - Uses Serial ID for Unique Key
			//Enemy Count is five for Level One
			serialID = 1;
			for (loop_x = 0; loop_x < treasureCount; loop_x++)
			{

				//This do while loop generates random coordinates. It keeps trying till finds empty space
				do
				{
					//Our X & Y class variables are given random coordinates between 0 and 30
					y = (rand() % 39);
					x = (rand() % 79);
				} while (gameArray[y][x] != ' ');//While not empty
				treasure_ID = "Treasure " + to_string(serialID);//Generates Unique Enemy name ID
				GameObject* treasure_ID = new Treasure();//Creates new Treasure Object with Unique name
				randomInt = (rand() % 4) + 1;
				treasure_ID->spawn(treasure_ID->objectType() + " <> " + to_string(serialID), 100, 1, x, y, randomInt);//Spawn Enemy
				serialID++;//Count - Naming
				listOfObjects.push_back(treasure_ID);//Push to Game Object List
				gameArray[y][x] = treasure_ID->ObjectCharacter();//One time assign Object character to map
			}
			//cout << "INIT  LEVEL I Enemy OUT" << endl;//Debugging
			//TREASURE GENERATOR/////////////////////////////////////////////////////////////////////////


			//BOW GENERATOR//////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL I Bow IN" << endl;//Debugging
			serialID = 1;//Reset Serial ID when we need to use it
			do
			{
				//Our X & Y class variables are given random coordinates between 0 and 30
				y = (rand() % 39);
				x = (rand() % 79);
			} while (gameArray[y][x] != ' ');//Keep Trying until we hit a empty space
			bow->spawn(bow->objectType() + " <> " + to_string(serialID), 10, 1, x, y, 1);//Spawn Bow
			listOfObjects.push_back(bow);//Push Bow onto Game Object List
			gameArray[y][x] = bow->ObjectCharacter();//Set Player Character Once Off
			//cout << "INIT  LEVEL I Bow OUT" << endl;//Debugging
			//BOW GENERATOR//////////////////////////////////////////////////////////////////////////////


			//MAP GENERATOR//////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL I PRINT MAP OUT" << endl;//Debugging
			//Draw map with all objects on it
			for (y = 0; y < 51; ++y)
			{
				for (x = 0; x < 80; ++x)
				{
					std::cout << setw(2) << gameArray[y][x];
				}
				cout <<  endl;

			}

			//cout << "INIT  LEVEL I PRINT MAP OUT" << endl;//Debugging
			//MAP GENERATOR//////////////////////////////////////////////////////////////////////////////


			//PRINT OUT USER INFORMATION AT BOTTOM INITIALY/////////////////////////////////////////////
			gotToXnY(12 * 2, 40);//TREASURE INFO SPOT
			cout << setw(2) << treasure << " ";

			gotToXnY(26 * 2, 40);//X INFO SPOT
			cout << setw(2) << P_Player->GameObject_X() << " ";

			gotToXnY(32 * 2, 40);//Y INFO SPOT
			cout << setw(2) << P_Player->GameObject_Y() << " ";

			gotToXnY(44 * 2, 40);//WEAPON SPOT
			cout << setw(2) << "N O N E";

			gotToXnY(59 * 2, 40);//WEAPON SPOT
			cout << setw(2) << m_level;

			gotToXnY(68 * 2, 40);//WEAPON SPOT
			cout << setw(2) << m_time;
			//PRINT OUT USER INFORMATION AT BOTTOM INITIALY/////////////////////////////////////////////
		}
			break;
		case 2://Design our first Level 
		{
			listOfObjects.clear();//CLEAN OUT FOR NEXT LEVEL

			//GAME MAP FILE READER /////////////////////////////////////////////////////////////////////////////
			fileInput.open("levelTwo.txt");
			for (loop_y = 0; loop_y < 51; loop_y++)
			{
				for (loop_x = 0; loop_x < 80; loop_x++)
				{
					fileInput >> m_char;
					if (m_char == '1')
						gameArray[loop_y][loop_x] = char(254);// ■ WALLS CHARACTER ASCII EXTENDED - DIGIT 1 FROM FILE
					else if (m_char == '2')
						gameArray[loop_y][loop_x] = '8';// 8 SHIPS CHARACTER - DIGIT 2 FROM FILE
					else if (m_char == '3')
						gameArray[loop_y][loop_x] = '$';// Ö TELEPORTERS CHARACTER ASCII EXTENDED - DIGIT 3 FROM FILE
					else if (m_char == '0')
						gameArray[loop_y][loop_x] = ' ';//EMPTY SPACE
					else
						gameArray[loop_y][loop_x] = m_char;
				}
			}
			//GAME MAP FILE READER /////////////////////////////////////////////////////////////////////////////


			//PLAYER GENERATOR/////////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL Ii Player IN" << endl;//Debugging
			//Assign Player Random unique Coordinates
			serialID = 1;//Reset Serial ID when we need to use it
			do
			{
				//Our X & Y class variables are given random coordinates between 0 and 30
				y = (rand() % 39);
				x = (rand() % 79);
			} while (gameArray[y][x] != ' ');//Keep Trying until we hit a empty space
			P_Player->spawn(P_Player->objectType() + " <> " + to_string(serialID), 160, 1, x, y, 20);//Spawn Player
			listOfObjects.push_back(P_Player);//Push Player onto Game Object List
			gameArray[y][x] = P_Player->ObjectCharacter();//Set Player Character Once Off
			//cout << "INIT  LEVEL Ii Player OUT" << endl;//Debugging
			//PLAYER GENERATOR//////////////////////////////////////////////////////////////////////////////////


			//ENEMY GENERATOR///////////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL Ii Enemy IN" << endl;//Debugging
			//Dynamic Object Generator - Uses Serial ID for Unique Key
			//Enemy Count is five for Level tWO
			serialID = 1;
			for (loop_x = 0; loop_x < enemies_count; loop_x++)
			{

				//This do while loop generates random coordinates. It keeps trying till finds empty space
				do
				{
					//Our X & Y class variables are given random coordinates between 0 and 30
					y = (rand() % 39);
					x = (rand() % 79);
				} while (gameArray[y][x] != ' ');//While not empty
				enemy_ID = "Enemy " + to_string(serialID);//Generates Unique Enemy name ID
				GameObject* enemy_ID = new Enemy();//Creates new Enemy Object with Unique name
				randomInt = (rand() % 2) + 1;
				enemy_ID->spawn(enemy_ID->objectType() + " <> " + to_string(serialID), 100, 1, x, y, randomInt);//Spawn Enemy
				serialID++;//Count - Naming
				listOfObjects.push_back(enemy_ID);//Push to Game Object List
				gameArray[y][x] = enemy_ID->ObjectCharacter();//One time assign Object character to map
			}
			//cout << "INIT  LEVEL I Enemy OUT" << endl;//Debugging
			//ENEMY GENERATOR////////////////////////////////////////////////////////////////////////////


			//TREASURE GENERATOR/////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL II Enemy IN" << endl;//Debugging
			//Dynamic Object Generator - Uses Serial ID for Unique Key
			//Enemy Count is five for Level Two
			serialID = 1;
			for (loop_x = 0; loop_x < treasureCount; loop_x++)
			{

				//This do while loop generates random coordinates. It keeps trying till finds empty space
				do
				{
					//Our X & Y class variables are given random coordinates between 0 and 30
					y = (rand() % 39);
					x = (rand() % 79);
				} while (gameArray[y][x] != ' ');//While not empty
				treasure_ID = "Treasure " + to_string(serialID);//Generates Unique Enemy name ID
				GameObject* treasure_ID = new Treasure();//Creates new Treasure Object with Unique name
				randomInt = (rand() % 4) + 1;
				treasure_ID->spawn(treasure_ID->objectType() + " <> " + to_string(serialID), 100, 1, x, y, randomInt);//Spawn Enemy
				serialID++;//Count - Naming
				listOfObjects.push_back(treasure_ID);//Push to Game Object List
				gameArray[y][x] = treasure_ID->ObjectCharacter();//One time assign Object character to map
			}
			//cout << "INIT  LEVEL II Enemy OUT" << endl;//Debugging
			//TREASURE GENERATOR/////////////////////////////////////////////////////////////////////////


			//BOW GENERATOR//////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL I Bow IN" << endl;//Debugging
			serialID = 1;//Reset Serial ID when we need to use it
			do
			{
				//Our X & Y class variables are given random coordinates between 0 and 30
				y = (rand() % 39);
				x = (rand() % 79);
			} while (gameArray[y][x] != ' ');//Keep Trying until we hit a empty space
			bow->spawn(bow->objectType() + " <> " + to_string(serialID), 10, 1, x, y, 1);//Spawn Bow
			listOfObjects.push_back(bow);//Push Bow onto Game Object List
			gameArray[y][x] = bow->ObjectCharacter();//Set Player Character Once Off
			//cout << "INIT  LEVEL I Bow OUT" << endl;//Debugging
			//BOW GENERATOR//////////////////////////////////////////////////////////////////////////////


			//MAP GENERATOR//////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL I PRINT MAP OUT" << endl;//Debugging
			//Draw map with all objects on it
			for (y = 0; y < 51; ++y)
			{
				for (x = 0; x < 80; ++x)
				{
					std::cout << setw(2) << gameArray[y][x];
				}
				cout << endl;

			}

			//cout << "INIT  LEVEL I PRINT MAP OUT" << endl;//Debugging
			//MAP GENERATOR//////////////////////////////////////////////////////////////////////////////


			//PRINT OUT USER INFORMATION AT BOTTOM INITIALY/////////////////////////////////////////////
			gotToXnY(12 * 2, 40);//TREASURE INFO SPOT
			cout << setw(2) << treasure << " ";

			gotToXnY(26 * 2, 40);//X INFO SPOT
			cout << setw(2) << P_Player->GameObject_X() << " ";

			gotToXnY(32 * 2, 40);//Y INFO SPOT
			cout << setw(2) << P_Player->GameObject_Y() << " ";

			gotToXnY(44 * 2, 40);//WEAPON SPOT
			cout << setw(2) << "N O N E";

			gotToXnY(59 * 2, 40);//WEAPON SPOT
			cout << setw(2) << m_level;

			gotToXnY(68 * 2, 40);//WEAPON SPOT
			cout << setw(2) << m_time;
			//PRINT OUT USER INFORMATION AT BOTTOM INITIALY/////////////////////////////////////////////
		}
		break;
		case 3://Design our first Level 
		{
			listOfObjects.clear();//CLEAN OUT FOR NEXT LEVEL

			//GAME MAP FILE READER /////////////////////////////////////////////////////////////////////////////
			fileInput.open("levelThree.txt");
			for (loop_y = 0; loop_y < 51; loop_y++)
			{
				for (loop_x = 0; loop_x < 80; loop_x++)
				{
					fileInput >> m_char;
					if (m_char == '1')
						gameArray[loop_y][loop_x] = char(254);// ■ WALLS CHARACTER ASCII EXTENDED - DIGIT 1 FROM FILE
					else if (m_char == '2')
						gameArray[loop_y][loop_x] = '8';// 8 SHIPS CHARACTER - DIGIT 2 FROM FILE
					else if (m_char == '3')
						gameArray[loop_y][loop_x] = '$';// Ö TELEPORTERS CHARACTER ASCII EXTENDED - DIGIT 3 FROM FILE
					else if (m_char == '0')
						gameArray[loop_y][loop_x] = ' ';//EMPTY SPACE
					else
						gameArray[loop_y][loop_x] = m_char;
				}
			}
			//GAME MAP FILE READER /////////////////////////////////////////////////////////////////////////////


			//PLAYER GENERATOR/////////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL Ii Player IN" << endl;//Debugging
			//Assign Player Random unique Coordinates
			serialID = 1;//Reset Serial ID when we need to use it
			do
			{
				//Our X & Y class variables are given random coordinates between 0 and 30
				y = (rand() % 39);
				x = (rand() % 79);
			} while (gameArray[y][x] != ' ');//Keep Trying until we hit a empty space
			P_Player->spawn(P_Player->objectType() + " <> " + to_string(serialID), 160, 1, x, y, 20);//Spawn Player
			listOfObjects.push_back(P_Player);//Push Player onto Game Object List
			gameArray[y][x] = P_Player->ObjectCharacter();//Set Player Character Once Off
			//cout << "INIT  LEVEL Ii Player OUT" << endl;//Debugging
			//PLAYER GENERATOR//////////////////////////////////////////////////////////////////////////////////



			//ENEMY GENERATOR///////////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL III Enemy IN" << endl;//Debugging
			//Dynamic Object Generator - Uses Serial ID for Unique Key
			//Enemy Count is five for Level Three
			serialID = 1;
			for (loop_x = 0; loop_x < enemies_count; loop_x++)
			{

				//This do while loop generates random coordinates. It keeps trying till finds empty space
				do
				{
					//Our X & Y class variables are given random coordinates between 0 and 30
					y = (rand() % 39);
					x = (rand() % 79);
				} while (gameArray[y][x] != ' ');//While not empty
				enemy_ID = "Enemy " + to_string(serialID);//Generates Unique Enemy name ID
				GameObject* enemy_ID = new Enemy();//Creates new Enemy Object with Unique name
				randomInt = (rand() % 4) + 1;
				enemy_ID->spawn(enemy_ID->objectType() + " <> " + to_string(serialID), 100, 1, x, y, randomInt);//Spawn Enemy
				serialID++;//Count - Naming
				listOfObjects.push_back(enemy_ID);//Push to Game Object List
				gameArray[y][x] = enemy_ID->ObjectCharacter();//One time assign Object character to map
			}
			//cout << "INIT  LEVEL I Enemy OUT" << endl;//Debugging
			//ENEMY GENERATOR////////////////////////////////////////////////////////////////////////////


			//TREASURE GENERATOR/////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL II Enemy IN" << endl;//Debugging
			//Dynamic Object Generator - Uses Serial ID for Unique Key
			//Enemy Count is five for Level Two
			serialID = 1;
			for (loop_x = 0; loop_x < treasureCount; loop_x++)
			{

				//This do while loop generates random coordinates. It keeps trying till finds empty space
				do
				{
					//Our X & Y class variables are given random coordinates between 0 and 30
					y = (rand() % 39);
					x = (rand() % 79);
				} while (gameArray[y][x] != ' ');//While not empty
				treasure_ID = "Treasure " + to_string(serialID);//Generates Unique Enemy name ID
				GameObject* treasure_ID = new Treasure();//Creates new Treasure Object with Unique name
				randomInt = (rand() % 4) + 1;
				treasure_ID->spawn(treasure_ID->objectType() + " <> " + to_string(serialID), 100, 1, x, y, randomInt);//Spawn Enemy
				serialID++;//Count - Naming
				listOfObjects.push_back(treasure_ID);//Push to Game Object List
				gameArray[y][x] = treasure_ID->ObjectCharacter();//One time assign Object character to map
			}
			//cout << "INIT  LEVEL II Enemy OUT" << endl;//Debugging
			//TREASURE GENERATOR/////////////////////////////////////////////////////////////////////////


			//BOW GENERATOR//////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL I Bow IN" << endl;//Debugging
			serialID = 1;//Reset Serial ID when we need to use it
			do
			{
				//Our X & Y class variables are given random coordinates between 0 and 30
				y = (rand() % 39);
				x = (rand() % 79);
			} while (gameArray[y][x] != ' ');//Keep Trying until we hit a empty space
			bow->spawn(bow->objectType() + " <> " + to_string(serialID), 10, 1, x, y, 1);//Spawn Bow
			listOfObjects.push_back(bow);//Push Bow onto Game Object List
			gameArray[y][x] = bow->ObjectCharacter();//Set Player Character Once Off
			//cout << "INIT  LEVEL I Bow OUT" << endl;//Debugging
			//BOW GENERATOR//////////////////////////////////////////////////////////////////////////////


			//MAP GENERATOR//////////////////////////////////////////////////////////////////////////////
			//cout << "INIT  LEVEL I PRINT MAP OUT" << endl;//Debugging
			//Draw map with all objects on it
			for (y = 0; y < 51; ++y)
			{
				for (x = 0; x < 80; ++x)
				{
					std::cout << setw(2) << gameArray[y][x];
				}
				cout << endl;

			}

			//cout << "INIT  LEVEL I PRINT MAP OUT" << endl;//Debugging
			//MAP GENERATOR//////////////////////////////////////////////////////////////////////////////


			//PRINT OUT USER INFORMATION AT BOTTOM INITIALY/////////////////////////////////////////////
			gotToXnY(12 * 2, 40);//TREASURE INFO SPOT
			cout << setw(2) << treasure << " ";

			gotToXnY(26 * 2, 40);//X INFO SPOT
			cout << setw(2) << P_Player->GameObject_X() << " ";

			gotToXnY(32 * 2, 40);//Y INFO SPOT
			cout << setw(2) << P_Player->GameObject_Y() << " ";

			gotToXnY(44 * 2, 40);//WEAPON SPOT
			cout << setw(2) << "N O N E";

			gotToXnY(59 * 2, 40);//WEAPON SPOT
			cout << setw(2) << m_level;

			gotToXnY(68 * 2, 40);//WEAPON SPOT
			cout << setw(2) << m_time;
			//PRINT OUT USER INFORMATION AT BOTTOM INITIALY/////////////////////////////////////////////
		}
		break;
		default:
			break;
	}
}

//UPDATE FUCNTION IS VIRTUAL FUCNTION FOR ALL INHERITIED OBJECTS FROM GAME OBJECT CALSS
//RETURN VALUES ARE RESERVED SUCK AS 1,2,3 AND 4 FOR ARROW DIRECTION - 5 FOR ARROW DESTROYED OR 6 FOR CALLING DISPLAYER PLAYER POSITION. WE CAN ALSO BUILD ON THIS METHOD FOR EXPANDING THE GAME FURTHER
void Game::update()
{
	//Call all objects update fucntion by jumping past virtual GameObject jumping function
	for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
	{
		//We call GameObjects Update function and also pass down our current map and player x and y coordinates

		if ((*iter)->objectType() == "player")
		{
			updateReturn = (*iter)->update(gameArray, P_Player->GameObject_X(), P_Player->GameObject_Y(), m_level);

			if (updateReturn == 6)
			{
				//DISPLAY PLAYER POSITION - CALL GAME PLAYER POSITION FUNCTION
				playerPosition();
				updateReturn = 0;//RESET UPDATE VALUE
			}
		}
		else if ((*iter)->objectType() == "arrow")
		{
			updateReturn = (*iter)->update(gameArray, P_Player->GameObject_X(), P_Player->GameObject_Y(), m_level);

			if (updateReturn == 5)
			{
				//GameObject reutrn value 5 is for our arrow to be cleaned up
				(*iter)->setHealth(0);
			}
		}
			else
				(*iter)->update(gameArray, P_Player->GameObject_X(), P_Player->GameObject_Y(), m_level);
	

		if (P_Player->getWeapon() == 1)
		{
			//We know if a update returns 1,2,3 or 4 its create a arrow and fire it the correct way
			//We also know only a player returns these values and we also know the players coordinates as its iter-x and iter-y
			//1 means fire the arrow up, 2 means fire the arrow right, 3 means fire the arrow down and 4 means fire the arrow left
			if (updateReturn == 1)//if return from update is confirmed player arrow
			{

				//We know if a update returns 1,2,3 or 4 its create a arrow and fire it the correct way
				GameObject* arrow = new Arrow(updateReturn);
				//we position it at right side of player as player has confirmed its free by its update retrun value
				arrow->spawn("Arrow", 10, 1, P_Player->GameObject_X(), P_Player->GameObject_Y() - 1, 8);//20 stamina means it will 5 times a second, that means move five places a second
				arrow->setDirection(1);
				//But we can still access it directly now and set it along the right course along with set it up
				gameArray[arrow->GameObject_Y()][arrow->GameObject_X()] = arrow->ObjectCharacter();//Our object constructor will create thge right pointing character above, 5 lines up
				gotToXnY(arrow->GameObject_X() * 2, arrow->GameObject_Y());
				cout << setw(2) << arrow->ObjectCharacter();
				listOfObjects.push_back(arrow);//We can push it onto our list as the update function we control it after we are finished here setting it up
				//So our arrow has been created. 
				//it was created by a retunr from update having value 1, means came from player and player requested a arrow goes up
				//player already validated that there is space one place up
				updateReturn = 0;
			}
			else if (updateReturn == 2)//if return from update is confirmed player arrow
			{

				//We know if a update returns 1,2,3 or 4 its create a arrow and fire it the correct way
				GameObject* arrow = new Arrow(updateReturn);
				//we position it at right side of player as player has confirmed its free by its update retrun value
				arrow->spawn("Arrow", 10, 1, P_Player->GameObject_X() + 1, P_Player->GameObject_Y(), 8);//20 stamina means it will 5 times a second, that means move five places a second
				arrow->setDirection(2);
				//But we can still access it directly now and set it along the right course along with set it up
				gameArray[arrow->GameObject_Y()][arrow->GameObject_X()] = arrow->ObjectCharacter();//Our object constructor will create thge right pointing character above, 5 lines up
				gotToXnY(arrow->GameObject_X() * 2, arrow->GameObject_Y());
				cout << setw(2) << arrow->ObjectCharacter();
				listOfObjects.push_back(arrow);//We can push it onto our list as the update function we control it after we are finished here setting it up
				//So our arrow has been created. 
				//it was created by a retunr from update having value 1, means came from player and player requested a arrow goes up
				//player already validated that there is space one place up
				updateReturn = 0;
			}
			else if (updateReturn == 3)//if return from update is confirmed player arrow
			{

				//We know if a update returns 1,2,3 or 4 its create a arrow and fire it the correct way
				GameObject* arrow = new Arrow(updateReturn);
				//we position it at right side of player as player has confirmed its free by its update retrun value
				arrow->spawn("Arrow", 10, 1, P_Player->GameObject_X(), P_Player->GameObject_Y() + 1, 8);//20 stamina means it will 5 times a second, that means move five places a second
				arrow->setDirection(3);
				//But we can still access it directly now and set it along the right course along with set it up
				gameArray[arrow->GameObject_Y()][arrow->GameObject_X()] = arrow->ObjectCharacter();//Our object constructor will create thge right pointing character above, 5 lines up
				gotToXnY(arrow->GameObject_X() * 2, arrow->GameObject_Y());
				cout << setw(2) << arrow->ObjectCharacter();
				listOfObjects.push_back(arrow);//We can push it onto our list as the update function we control it after we are finished here setting it up
				//So our arrow has been created. 
				//it was created by a retunr from update having value 1, means came from player and player requested a arrow goes up
				//player already validated that there is space one place up
				updateReturn = 0;
			}
			else if (updateReturn == 4)//if return from update is confirmed player arrow
			{

				//We know if a update returns 1,2,3 or 4 its create a arrow and fire it the correct way
				GameObject* arrow = new Arrow(updateReturn);
				//we position it at right side of player as player has confirmed its free by its update retrun value
				arrow->spawn("Arrow", 10, 1, P_Player->GameObject_X() - 1, P_Player->GameObject_Y(), 8);//20 stamina means it will 5 times a second, that means move five places a second
				arrow->setDirection(4);
				//But we can still access it directly now and set it along the right course along with set it up
				gameArray[arrow->GameObject_Y()][arrow->GameObject_X()] = arrow->ObjectCharacter();//Our object constructor will create thge right pointing character above, 5 lines up
				gotToXnY(arrow->GameObject_X() * 2, arrow->GameObject_Y());
				cout << setw(2) << arrow->ObjectCharacter();
				listOfObjects.push_back(arrow);//We can push it onto our list as the update function we control it after we are finished here setting it up
				//So our arrow has been created. 
				//it was created by a retunr from update having value 1, means came from player and player requested a arrow goes up
				//player already validated that there is space one place up
				updateReturn = 0;
			}
		}
	}
}

//If objects hold the same ground call damage function and modify objects health
int Game::Collide()
{
	trap = true;
	for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
	{
		for (iter2 = listOfObjects.begin(); iter2 != listOfObjects.end(); iter2++)
		{
			if ((*iter)->objectType() != (*iter2)->objectType())
			{
				if ((*iter)->GameObject_X() == (*iter2)->GameObject_X() && (*iter)->GameObject_Y() == (*iter2)->GameObject_Y())
				{
					if ((*iter)->objectType() == "treasure" && (*iter2)->objectType() == "player" || (*iter2)->objectType() == "treasure" && (*iter)->objectType() == "player")
					{
						if ((*iter)->objectType() == "treasure")
							(*iter)->setHealth(0);
						else
							(*iter2)->setHealth(0);

							treasure--;
							gotToXnY(12 * 2, 40);//TREASURE INFO SPOT
							cout << setw(2) << treasure << " ";

							P_Player->raiseStamina(P_Player->getStamina() + 2);//Increase stamina after each collection of treasure

						//gotToXnY(36 * 2, 3);
						//cout << setw(2) << treasure << " " << endl;

						if (treasure <= 0)
							return 2;//Return all treasure is found
						else
							return 4;
					}
					else if ((*iter)->objectType() == "bow" && (*iter2)->objectType() == "player" || (*iter2)->objectType() == "bow" && (*iter)->objectType() == "player")
					{
						if ((*iter)->objectType() == "bow")
							(*iter)->setHealth(0);
						else
							(*iter2)->setHealth(0);

						P_Player->armWeapon(1);
					}
					else if (((*iter)->objectType() == "enemy" && (*iter2)->objectType() == "arrow")||((*iter)->objectType() == "arrow" && (*iter2)->objectType() == "enemy"))
					{
						(*iter)->setHealth(0);
						(*iter2)->setHealth(0);
						return 0;//Return all good
					}
					else
						return 1;//Return your dead
					
				}
			}
		}
	}

	return 0;//Return all good
}

//If any objects have less than 1 health , they are removed from list
void Game::clean()
{
	for (iter = listOfObjects.begin(); iter != listOfObjects.end();)
	{
		if (((*iter)->isAlive()) == false)
		{
			iter = listOfObjects.erase(iter);
		}
		else
			++iter;
	}
}

//CLEAR SCREEN-BUFFER FUNCTION AVAILABLE
void Game::ClearScreen()
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