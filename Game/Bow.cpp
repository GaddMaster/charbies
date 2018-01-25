#include "Bow.h"

Bow::Bow()
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	object_char = '~';// ~ BOW CHARACTER ASCII EXTENDED
}

Bow::~Bow()
{
}

//RETURN BOW CHARACTER
char Bow::ObjectCharacter()
{
	return object_char;
}

//RETURN OBJECT STRING TYPE
string Bow::objectType()
{
	m_type = "bow";
	return m_type;
}

//ARMED WEAPON FUNCTION NOT USED HERE
void Bow::armWeapon(int weapon)
{
}

//GET WEAPON FUNCTION NOT USED HERE
int Bow::getWeapon()
{
	return 0;
}

string Bow::returnWeaponString()
{
	return string();
}

//TREASURE UPDATE FUNCTION - VIRTUAL - NOT USED HERE
int Bow::update(char(&gameArray)[51][80], int player_x, int player_y, int level)
{
	return 0;
}