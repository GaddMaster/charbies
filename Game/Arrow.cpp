//INCLUDE ARROW HEADER FILE
#include "Arrow.h"

//CONSTRUCTOR
Arrow::Arrow()
{
	colors[0] = 0x1A;
	colors[1] = 0x2B;
	colors[2] = 0x3C;
	colors[3] = 0x4D;
	colors[4] = 0x5E;
	colors[5] = 0x6F;
	colors[6] = 0xA1;
	colors[7] = 0xB2;
	colors[8] = 0xC3;
	colors[9] = 0xD4;
	colors[10] = 0xE5;
	colors[11] = 0xF6;

	SetConsoleCP(437);
	SetConsoleOutputCP(437);
}

//DE CONSTRUCTOR 
Arrow::~Arrow()
{
}

//CONSTRUCTOR WITH INT PARAMETER - GIVES ARROW DIFFERENT CHARACTER TO MATCH ITS DIRECTION
Arrow::Arrow(int direction)
{
	//deciding which way the arrow fires
	switch (direction)
	{
	case 1:object_char = '^'; break;// ^ ARROW UP ASCII CODE
	case 2:object_char = char(175); break;// » ARROW RIGHT CHARACTER ASCII EXTENDED
	case 3:object_char = 'v'; break;// v ASCII ARROW DOWN ASCII CODE
	case 4:object_char = char(176); break;// « ARROW LEFT CHARACTER ASCII EXTENDED
	default:object_char = char(251); break;//DEFAULT DOT
	}
}

//RETURNS ARROW CHARCTER
char Arrow::ObjectCharacter()
{
	return object_char;
}

//RETURNS ARRAW TYPE STRING - USED IN GAME LOOP FUNCTIONS - PARTICULARLY THE GAME UPDATE FUCNTION
string Arrow::objectType()
{
	m_type = "arrow";
	return m_type;
}

//WE MAY NOT USE THIS FUNCTION FOR THIS OBJECT
void Arrow::armWeapon(int weapon)
{
}

//WE MAY NOT USE THIS FUNCTION FOR THIS OBJECT
int Arrow::getWeapon()
{
	return 0;
}

string Arrow::returnWeaponString()
{
	return string();
}


//ARROW UPDATE FUCNTION
//If a arrow has been created, it already has a position and direction value
//we simple move it along that course until it hits object
//then the collision function in the game class will deal with it
int Arrow::update(char(&gameArray)[51][80], int player_x, int player_y, int level)
{
	hstdin = GetStdHandle(STD_INPUT_HANDLE);
	hstdout = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleScreenBufferInfo(hstdout, &csbi);

	switch (direction)
	{
	case 1://arrow is shooting up
		 if(gameArray[m_y - 1][m_x] == ' ')
		{
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			m_y = m_y - 1;
			gameArray[m_y][m_x] = '^';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << '^';
		}
		else if (gameArray[m_y - 1][m_x] == char(254))
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ■ WALLS CHARACTER ASCII EXTENDED
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y - 1][m_x] == '~')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ~ BOW CHARACTER ASCII EXTENDED - POSSIBLE MANY BOWS ON MAP AT LATER STAGE
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y - 1][m_x] == '+')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ≡ ASCII EXTENDED TREASURE CHARACTER
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y - 1][m_x] == '#')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ≡ ASCII EXTENDED TREASURE CHARACTER
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			m_y = m_y - 1;
			SetConsoleTextAttribute(hstdout, 0x4D);
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			FlushConsoleInputBuffer(hstdin);
			SetConsoleTextAttribute(hstdout, csbi.wAttributes);
			return 5;
		}
		else if (gameArray[m_y - 1][m_x] == '8')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			Beep(1000, 200);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y - 1][m_x] == '$')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			Beep(1000, 200);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else
		{
			//Learned from this debugging that I had not considered the enemy moving onto Player Object
			gotToXnY(0,51);
			cout << "ARROW UP FAILURE" << endl;
			cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y - 1][m_x] << endl;
			cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
			Sleep(120000);
		}
		break;
	case 3://arrow is shooting down
		 if (gameArray[m_y + 1][m_x] == ' ')
		{
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			m_y = m_y + 1;
			gameArray[m_y][m_x] = 'v';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << 'v';
		}
		else if (gameArray[m_y + 1][m_x] == char(254))
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ■ WALLS CHARACTER ASCII EXTENDED
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y + 1][m_x] == '~')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ~ BOW CHARACTER ASCII EXTENDED - POSSIBLE MANY BOWS ON MAP AT LATER STAGE
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y + 1][m_x] == '+')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ≡ ASCII EXTENDED TREASURE CHARACTER
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y + 1][m_x] == '#')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ≡ ASCII EXTENDED TREASURE CHARACTER
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			m_y = m_y + 1;
			SetConsoleTextAttribute(hstdout, 0x4D);
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			FlushConsoleInputBuffer(hstdin);
			SetConsoleTextAttribute(hstdout, csbi.wAttributes);
			return 5;
		}
		else if (gameArray[m_y + 1][m_x] == '8')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			Beep(1000, 200);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y + 1][m_x] == '$')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			Beep(1000, 200);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else
		{
			//Learned from this debugging that I had not considered the enemy moving onto Player Object
			cout << "ARROW DOWN  FAILURE" << endl;
			cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y + 1][m_x] << endl;
			cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
			Sleep(120000);
		}
		break;
	case 4://arrow is shooting left
		 if (gameArray[m_y][m_x - 1] == ' ')
		{
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			m_x = m_x - 1;
			gameArray[m_y][m_x] = char(174);
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << char(174);
		}
		else if (gameArray[m_y][m_x - 1] == char(254))
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ■ WALLS CHARACTER ASCII EXTENDED
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y][m_x - 1] == '~')
		{
			Beep(510, 510);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			m_x = m_x - 1;
			gameArray[m_y][m_x] = '$';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << '$';
		}
		else if (gameArray[m_y][m_x - 1] == '+')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ≡ ASCII EXTENDED TREASURE CHARACTER
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y][m_x - 1] == '#')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ≡ ASCII EXTENDED TREASURE CHARACTER
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			m_x = m_x - 1;
			SetConsoleTextAttribute(hstdout, 0x4D);
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			FlushConsoleInputBuffer(hstdin);
			SetConsoleTextAttribute(hstdout, csbi.wAttributes);
			return 5;
		}
		else if (gameArray[m_y][m_x - 1] == '8')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			Beep(1000, 200);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y][m_x - 1] == '$')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			Beep(1000, 200);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else
		{
			//Learned from this debugging that I had not considered the enemy moving onto Player Object
			cout << "ARROW LEFT FAILURE" << endl;
			cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y][m_x - 1] << endl;
			cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
			Sleep(10000);
		}
		break;
	case 2://arrow is shooting right
		 if (gameArray[m_y][m_x + 1] == ' ')
		{
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			m_x = m_x + 1;
			gameArray[m_y][m_x] = char(175);
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << char(175);
		}
		else if (gameArray[m_y][m_x + 1] == char(254))
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ■ WALLS CHARACTER ASCII EXTENDED
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
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
			Beep(510,510);
		}
		else if (gameArray[m_y][m_x + 1] == '+')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ≡ ASCII EXTENDED TREASURE CHARACTER
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y][m_x + 1] == '#')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			// ≡ ASCII EXTENDED TREASURE CHARACTER
			Beep(3000, 120);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			m_x = m_x + 1;
			SetConsoleTextAttribute(hstdout, 0x4D);
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			FlushConsoleInputBuffer(hstdin);
			SetConsoleTextAttribute(hstdout, csbi.wAttributes);
			return 5;
		}
		else if (gameArray[m_y][m_x + 1] == '8')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			Beep(1000, 200);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else if (gameArray[m_y][m_x + 1] == '$')
		{
			//WE PLAY SOUND AND RETURN INT 5 TO GAME UPDATE FUNCTION WHICH SETS ARROW HEALTH TO 0 - ITS THEN CLEANED UP IN THE GAME CLEAN FUCNTION
			Beep(1000, 200);
			gameArray[m_y][m_x] = ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			gotToXnY(m_x * 2, m_y);
			cout << setw(2) << ' ';
			return 5;
		}
		else
		{
			//Learned from this debugging that I had not considered the enemy moving onto Player Object
			cout << "ARROW RIGHT FAILURE" << endl;
			cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y][m_x + 1] << endl;
			cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
			Sleep(120000);
		}
		break;
	default:
		gotToXnY(0, 51);
		cout << "ARROW SWITCH TOTAL FAILURE - SLEEPING 5 SECONDS" << endl;
		Sleep(5100);
		return 0;
		break;
	}


	return 0;
}