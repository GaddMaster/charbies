//Include GameObject Header
#include "GameObject.h"

//Using namespace std
using namespace std;

GameObject::GameObject()
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	debugger = 3;
}

GameObject::~GameObject()
{
}

//Spawn function gives object a set of needed variable values
void GameObject::spawn(string typeID, int health, int speed,  int x, int y, int stamina)
{
	m_typeID = typeID;
	m_health = health;
	m_x = x;
	m_y = y;
	m_stamina = stamina;
	staminaCounter = m_stamina;
	status = true;
};

//Return X value for object
int GameObject::GameObject_X()
{
	return m_x;
};

//return y value for object
int GameObject::GameObject_Y()
{
	return m_y;
};

//Set x value for game object
void GameObject::setGameObject_X(int x)
{
	m_x = x;
};

//Set y value for game object
void GameObject::setGameObject_Y(int y)
{
	m_y = y;
};

//Retun objects health
int GameObject::getHealth()
{
	return m_health;
}

//Virtual function to give damage when on same coordinates
int GameObject::giveDamage()
{
	return 0;
}

//Set objects health
void GameObject::setHealth(int health)
{
	m_health = health;
}

//Return object ID 
string GameObject::typeID()
{
	return m_typeID;
}

//Virtual function for controlling enemy and player movements
//Passes down map and player coordinates for computing pathfinder and movement boundaries in relation to our map
int GameObject::update(char(&gameArray)[51][80], int player_x, int player_y, int level)
{
	cout << "GameObject Virtual Update Function" << endl;
	return 0;
}

//Return enemy type , virtual function
string GameObject::objectType()
{
	return string();
};

//Checks health and returns alive or dead
bool GameObject::isAlive()
{
	if (m_health>0)
		return true;
	else
		return false;
};

char GameObject::ObjectCharacter()
{
	char nullo = ' ';
	cout << "Object Character Virtual Function" << endl;
	return nullo;
}

//Go to cursor position - Windows library - NOT C++
void GameObject::gotToXnY(int x, int y)
{
	COORD point;
	point.X = x;
	point.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void GameObject::raiseStamina(int stamina)
{
	m_stamina = m_stamina + stamina;
}

int GameObject::getStamina()
{
	return m_stamina;
}

void GameObject::armWeapon(int weapon)
{

}

int GameObject::getWeapon()
{
	return 0;
}

void GameObject::setDirection(int directiono)
{
	direction = directiono;
}


string GameObject::returnWeaponString()
{
	return string();
}
