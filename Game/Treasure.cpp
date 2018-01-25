//Header Included
#include "Treasure.h"

//Constructor
Treasure::Treasure()
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
}


//De Constructor
Treasure::~Treasure()
{
}


//Returns Treasure Character
char Treasure::ObjectCharacter()
{
	object_char = '+';// ≡ ASCII EXTENDED TREASURE CHARACTER
	return object_char;
}


//Return player object type - Treasure
string Treasure::objectType()
{
	m_type = "treasure";
	return m_type;
}

void Treasure::armWeapon(int weapon)
{
}

int Treasure::getWeapon()
{
	return 0;
}

string Treasure::returnWeaponString()
{
	return string();
}


//Treasure update Function - Virtual
int Treasure::update(char(&gameArray)[51][80], int player_x, int player_y, int level)
{
	return 0;
}