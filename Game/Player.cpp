//INCLUDE PLAYER HEADER FILE
#include "Player.h"
#include <time.h>

//CONSTRUCTOR
Player::Player()
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437); 
	m_bow = false; 
	object_char = 'O';// O PLAYER CHARACTER
	m_type = "player";
	weapon = "NONE";
	m_damage = 10;
	
}

//DE CONSTRUCTOR 
Player::~Player(){}

//ARROW UPDATE FUCNTION - HAS ACCESS TO GAME ARRAY
int Player::update(char(&gameArray)[51][80], int player_x, int player_y, int level)
{
	if (m_bow == true)//Flicker for 1/20th of second if player has bow.Thios afffects our game loop, but by 4/1000 of a second
		for (int i = 0; i < 4; i++)
		{
			object_char = '0';
			Sleep(5);
		}
			


	//cout << "Player Stamina Counter" << staminaCounter << endl;
	//Sleep(300);

	//Game loop is 20 frames per second
	//The lower stamina a GameObject has to less times he can update a second
	//After it updates, we reset its counter back to what ever its stamina is
	//Other wise if his stamina has not reached the acces value of 20 point, we skip this update function and incremenet as exiting the function
	//As example our normal enemy has stamina 1, so he has to go through the update function 20 time, which is one second before they has execute there update
	//This means we hcan give enemies more stamina or players less
	//SO the higher your stamina is the more times you can act per second
	//Our arrow shooting keys are also found here below once the player has collected the bow
	if (staminaCounter >= 20)
	{
		input = 0;
		can_move = true;


		//Player has opertunity to use arrays 20 times persecond - 20 frames perseond
		//Windows system function. 
		//C++ does not have a time out for keyboard in
		//So we had to dig a little deeper
		//Each key press checks the place its intending at moving to
		//If there is a wall we simple play sound and not move. 
		//If there is a enemy we die and replace spot with X
		//If treasure we we replace its position while removing its character
		//If empty place we just move there.
		//We use a technique here to replace keys, including the special windows fucntion _kbhit() below
		//_kbhit() accept keys, but times out and moves on if nothing is pressed. This is a windows function, not C++
		//When we decide to move anywhere, we do a handful of things before exiting. We have passed down the game array in this virtual fucntion so all sub members have access to it
		//we first move cursor to current position and print a empty space.
		//We update array as empty here
		//We move cursor to new spot
		//we print new character there, player usually
		//we update array again 
		//We do this for any move
		if (_kbhit())
		{
			//Move player and control boundaries
			switch (input = _getch())
			{
			case KEY_UP://If up is pressed
				if (gameArray[m_y - 1][m_x] == ' ')
				{
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_y = m_y - 1;
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
				}
				else if (gameArray[m_y - 1][m_x] == char(254))
				{
					// ■ WALLS CHARACTER ASCII EXTENDED
					Beep(1000, 300);
				}
				else if (gameArray[m_y - 1][m_x] == '8')
				{
					// Ø WALLS CHARACTER ASCII EXTENDED
					Beep(1000, 300);
				}
				else if (gameArray[m_y - 1][m_x] == '~')
				{
					// ~ BOW CHARACTER ASCII EXTENDED
					Beep(1000,130);
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_y = m_y - 1;
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					gotToXnY(44 * 2, 40);//WEAPON SPOT
					cout << setw(2) << "B O W   ";
				}
				else if (gameArray[m_y - 1][m_x] == '+')
				{
					// ≡ ASCII EXTENDED TREASURE CHARACTER
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_y = m_y - 1;
					m_stamina = m_stamina + 2;//STAMINA BOOAST REWARD
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
				}
				else if (gameArray[m_y - 1][m_x] == '$')
				{
					// Ö TELEPORTERS CHARACTER ASCII EXTENDED - DIGIT 3 FROM FILE
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_y = m_y - 1;
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else if (gameArray[m_y - 1][m_x] == '#')
				{
					// ø ENEMY CHARACTER ASCII EXTENDED
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_y = m_y - 1;
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else
				{
					//Learned from this debugging that I had not considered the enemy moving onto Player Object
					cout << "PLAYER UP LEFT FAILURE" << endl;
					cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y - 1][m_x] << endl;
					cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
					Sleep(120000);
				}
				break;
			case KEY_DOWN://if down is pressed
				if (gameArray[m_y + 1][m_x] == ' ')
				{
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_y = m_y + 1;
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;

				}
				else if (gameArray[m_y + 1][m_x] == char(254))
				{
					// ■ WALLS CHARACTER ASCII EXTENDED
					Beep(1000, 300);
				}
				else if (gameArray[m_y + 1][m_x] == '~')
				{
					// ~ BOW CHARACTER ASCII EXTENDED
					Beep(1000, 130);
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_y = m_y + 1;
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					gotToXnY(44 * 2, 40);//WEAPON SPOT
					cout << setw(2) << "B O W   ";
				}
				else if (gameArray[m_y + 1][m_x] == '8')
				{
					// Ø WALLS CHARACTER ASCII EXTENDED
					Beep(1000, 300);
				}
				else if (gameArray[m_y + 1][m_x] == '+')
				{
					// ≡ ASCII EXTENDED TREASURE CHARACTER
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_y = m_y + 1;
					m_stamina = m_stamina + 2;//STAMINA BOOAST REWARD
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else if (gameArray[m_y + 1][m_x] == '$')
				{
					// Ö TELEPORTERS CHARACTER ASCII EXTENDED - DIGIT 3 FROM FILE
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_y = m_y + 1;
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else if (gameArray[m_y + 1][m_x] == '#')
				{
					// ø ENEMY CHARACTER ASCII EXTENDED
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_y = m_y + 1;
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else
				{
					//Learned from this debugging that I had not considered the enemy moving onto Player Object
					cout << "PLAYER DOWN LEFT FAILURE" << endl;
					cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y + 1][m_x] << endl;
					cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
					Sleep(120000);
				}
				break;
			case KEY_LEFT://if left is pressed
				if (gameArray[m_y][m_x - 1] == ' ')
				{
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_x = m_x - 1;
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else if (gameArray[m_y][m_x - 1] == char(254))
				{
					// ■ WALLS CHARACTER ASCII EXTENDED
					Beep(1000, 300);
				}
				else if (gameArray[m_y][m_x - 1] == '~')
				{
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_x = m_x - 1;
					gameArray[m_y][m_x] = '$';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << '$';
					gotToXnY(44 * 2, 40);//WEAPON SPOT
					cout << setw(2) << "B O W   ";
				}
				else if (gameArray[m_y][m_x - 1] == '+')
				{
					// ≡ ASCII EXTENDED TREASURE CHARACTER
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_x = m_x - 1;
					m_stamina = m_stamina + 2;//STAMINA BOOAST REWARD
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else if (gameArray[m_y][m_x - 1] == '$')
				{
					// Ö TELEPORTERS CHARACTER ASCII EXTENDED - DIGIT 3 FROM FILE
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_x = m_x - 1;
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else if (gameArray[m_y][m_x - 1] == '8')
				{
					// Ø WALLS CHARACTER ASCII EXTENDED
					Beep(1000, 300);
				}
				else if (gameArray[m_y][m_x - 1] == '#')
				{
					// ø ENEMY CHARACTER ASCII EXTENDED
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_x = m_x - 1;
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else
				{
					//Learned from this debugging that I had not considered the enemy moving onto Player Object
					cout << "PLAYER LEFT LEFT FAILURE" << endl;
					cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y][m_x - 1] << endl;
					cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
					Sleep(10000);
				}
				break;
			case KEY_RIGHT://if right is pressed
				if (gameArray[m_y][m_x + 1] == ' ')
				{
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_x = m_x + 1;
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else if (gameArray[m_y][m_x + 1] == char(254))
				{
					// ■ WALLS CHARACTER ASCII EXTENDED
					Beep(1000, 300);
				}
				else if (gameArray[m_y][m_x + 1] == '~')
				{
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_x = m_x + 1;
					gameArray[m_y][m_x] = '$';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << '$';
					gotToXnY(44 * 2, 40);//WEAPON SPOT
					cout << setw(2) << "B O W   ";
				}
				else if (gameArray[m_y][m_x + 1] == '8')
				{
					// Ø WALLS CHARACTER ASCII EXTENDED
					Beep(1000, 300);
				}
				else if (gameArray[m_y][m_x + 1] == '+')
				{
					// ≡ ASCII EXTENDED TREASURE CHARACTER
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_x = m_x + 1;
					m_stamina = m_stamina + 2;//STAMINA BOOAST REWARD
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else if (gameArray[m_y][m_x + 1] == '$')
				{
					// Ö TELEPORTERS CHARACTER ASCII EXTENDED - DIGIT 3 FROM FILE
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_x = m_x + 1;
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else if (gameArray[m_y][m_x + 1] == '#')
				{
					// ø ENEMY CHARACTER ASCII EXTENDED
					gameArray[m_y][m_x] = ' ';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << ' ';
					m_x = m_x + 1;
					gameArray[m_y][m_x] = 'O';
					gotToXnY(m_x * 2, m_y);
					cout << setw(2) << 'O';
					//gotToXnY(104 * 2, 4);
					//cout << setw(2) << "X " << m_x << " Y " << m_y;
				}
				else
				{
					//Learned from this debugging that I had not considered the enemy moving onto Player Object
					cout << "PLAYER RIGHT LEFT FAILURE" << endl;
					cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y][m_x + 1] << endl;
					cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
					Sleep(120000);
				}
				break;
			case KEY_W://If fire arrow up is pressed - successful we return 1
				if (gameArray[m_y - 1][m_x] == ' ')
				{

					return 1;//return fire arrow up

				}
				else if (gameArray[m_y - 1][m_x] == char(254))
				{
					Beep(523, 510);
				}
				else if (gameArray[m_y - 1][m_x] == '~')
				{
					Beep(520,510);//your doomed, player feedback, cant fire arrow when this close
				}
				else if (gameArray[m_y - 1][m_x] == '+')
				{
					Beep(520, 510);//cant shoot treasure
				}
				else if (gameArray[m_y - 1][m_x] == '$')
				{
					Beep(520, 510);//not even sure why this is here yet, possible bugs maybe
				}
				else
				{
					//Learned from this debugging that I had not considered the enemy moving onto Player Object
					cout << "PLAYER UP ARROW FAILURE" << endl;
					cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y - 1][m_x] << endl;
					cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
					Sleep(120000);
				}
				break;
			case KEY_S://if down is pressed
				if (gameArray[m_y + 1][m_x] == ' ')
				{

					return 3;//fire arrow down

				}
				else if (gameArray[m_y + 1][m_x] == char(254))
				{
					Beep(523, 510);//cant shoot wall
				}
				else if (gameArray[m_y + 1][m_x] == '~')
				{
					Beep(520, 510);//doomed 
				}
				else if (gameArray[m_y + 1][m_x] == '+')
				{
					Beep(520, 510);//cant shoot treasure
				}
				else if (gameArray[m_y + 1][m_x] == '$')
				{
					Beep(520, 510);//not even sure why this is here yet, possible bugs maybe
				}
				else
				{
					//Learned from this debugging that I had not considered the enemy moving onto Player Object
					cout << "PLAYER DOWN ARROW FAILURE" << endl;
					cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y + 1][m_x] << endl;
					cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
					Sleep(120000);
				}
				break;
			case KEY_A://if left is pressed
				if (gameArray[m_y][m_x - 1] == ' ')
				{
					return 4;//return shoot arrow left

				}
				else if (gameArray[m_y][m_x - 1] == char(254))
				{
					Beep(523, 510);//cant shoot wall
				}
				else if (gameArray[m_y][m_x - 1] == '~')
				{
					Beep(520, 510);//doomed
				}
				else if (gameArray[m_y][m_x - 1] == '+')
				{
					Beep(520, 510);//cant shoot treasure
				}
				else if (gameArray[m_y][m_x - 1] == '$')
				{
					Beep(520, 510);//not even sure why this is here yet, possible bugs maybe
				}
				else
				{
					//Learned from this debugging that I had not considered the enemy moving onto Player Object
					cout << "PLAYER LEFT ARROW FAILURE" << endl;
					cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y][m_x - 1] << endl;
					cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
					Sleep(10000);
				}
				break;
			case KEY_D ://if right is pressed
				if (gameArray[m_y][m_x + 1] == ' ')
				{
					return 2;

				}
				else if (gameArray[m_y][m_x + 1] == char(254))
				{
					Beep(523, 510);//cant shoot wall
				}
				else if (gameArray[m_y][m_x + 1] == '~')
				{
					Beep(520, 510);//doomed
				}
				else if (gameArray[m_y][m_x + 1] == '+')
				{
					Beep(520, 510);//cant shoot treasure
				}
				else if (gameArray[m_y][m_x + 1] == '$')
				{
					Beep(520, 510);//not even sure why this is here yet, possible bugs maybe
				}
				else
				{
					//Learned from this debugging that I had not considered the enemy moving onto Player Object
					cout << "PLAYER RIGHT ARROW FAILURE" << endl;
					cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y][m_x + 1] << endl;
					cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
					Sleep(120000);
				}
				break;
			case INFO://Player Position function
				return 6;
				break;
			case EXIT://if right is pressed
				exit(1);
				break;

			}//End of switch statement
		}
		
		
		staminaCounter = m_stamina;
	}
	staminaCounter = staminaCounter + 1;
	gotToXnY(25 * 2, 40);//X INFO SPOT
	cout << setw(2) << m_y << "   ";
	gotToXnY(31 * 2, 40);//Y INFO SPOT
	cout << setw(2) << m_x << "   ";
	return 0;
}

//RETURN PLAYER DAMAGE VALUE
int Player::giveDamage()
{
	srand(time(NULL));

	m_damage = rand() % 100;

	return m_damage;
}

////RETURNS PLAYER TYPE STRING - USED IN GAME LOOP FUNCTIONS - PARTICULARLY THE GAME UPDATE FUCNTION
string Player::objectType()
{
	return m_type;
}

//RETURNS ARROW CHARCTER
char Player::ObjectCharacter()
{
	return object_char;
}

//SET WEAPON AS ARMED
void Player::armWeapon(int weapon)
{
	if (weapon == 1)
	{
		object_char = '0'; m_bow = true;
	}
	else
	{
		object_char = char(254); bomb = true;
	}
}

//RETUNR IF PLAYER HAS BOW OR BOMB
int Player::getWeapon()
{
	if (m_bow == true)
	{
		weapon = "BOW";
		return 1;
	}
	else if (bomb == true)
	{
		weapon = "BOMB";
		return 2;
	}
	else
		return 0;
}

string Player::returnWeapon()
{
	return weapon;
}
