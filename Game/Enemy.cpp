//INCLUDE ENEMY HEADER FILE
#include "Enemy.h"

//CONSTRUCTOR
Enemy::Enemy() 
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	m_stamina = 1;
	y_same = false;
	x_same = false;;
	up = false;;
	down = false;;
	left = false;;
	right = false;;
	moved = false;;
	skip = false;;
	path_found = false;;
	gridlock = false;;
}

//DE CONSTRUCTOR 
Enemy::~Enemy() {}

//EMENY UPDATE FUCNTION - CONTROLS THE ENEMY MOVEMENT AND AI
int Enemy::update(char(&gameArray)[51][80], int player_x, int player_y, int level)
{
	SetConsoleCP(437);
	SetConsoleOutputCP(437);
	//cout << "ENEMY Stamina Counter" << staminaCounter << endl;
	//Sleep(300);
	//Game loop is 20 frames per second
	//The lower stamina a GameObject has to less times he can update a second
	//After it updates, we reset its counter back to what ever its stamina is
	//Other wise if his stamina has not reached the use point, we incremenet after this statement 
	//SO the higher your stamina is the more times you can act per second
	if (staminaCounter >= 20)
	{
		moved = false;
		path_found = false;


		if (level == 1)
		{
			srand(time(NULL));
			randomNumber = (rand() % 4) + 1;
			while (moved != true)
			{
				//Move player and control boundaries
				switch (randomNumber)
				{
				case 1://UP
					if (gameArray[m_y - 1][m_x] == ' ')
					{
						//EMPTY SPACE
						gameArray[m_y][m_x] = ' ';
						gotToXnY(m_x * 2, m_y);
						cout << setw(2) << ' ';
						m_y = m_y - 1;
						gameArray[m_y][m_x] = '#';
						gotToXnY(m_x * 2, m_y);
						cout << setw(2) << '#';
						moved = true;
					}
					else if (gameArray[m_y - 1][m_x] == char(254))
					{
						// ■ WALLS CHARACTER ASCII EXTENDED
						moved = true;
					}
					else if (gameArray[m_y - 1][m_x] == '#')
					{
						// ø ENEMY CHARACTER ASCII EXTENDED
						moved = true;
					}
					else if (gameArray[m_y - 1][m_x] == '8')
					{
						// Ø ENEMY CHARACTER ASCII EXTENDED
						moved = true;
					}
					else if (gameArray[m_y - 1][m_x] == 'O')
					{
						// © PLAYER CHARACTER ASCII EXTENDED
						Beep(1400,120);
						m_y = m_y - 1;
						gameArray[m_y][m_x] = '#';
						cout << setw(2) << '#';
						moved = true;
					}
					else if (gameArray[m_y - 1][m_x] == '+')
					{
						// ≡ ASCII EXTENDED TREASURE CHARACTER
						moved = true;
					}
					else if (gameArray[m_y - 1][m_x] == '$')
					{
						// Ö TELEPORTERS CHARACTER ASCII EXTENDED - DIGIT 3 FROM FILE
						moved = true;
					}
					else if (gameArray[m_y - 1][m_x] == '~')
					{
						// ~ BOW CHARACTER ASCII EXTENDED
						moved = true;
					}
					else
					{
						//Learned from this debugging that I had not considered the enemy moving onto Player Object
						gotToXnY(0,51);
						cout << "UP FAILURE" << endl;
						cout << "Random Number" << randomNumber << endl;
						cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y][m_x - 1] << endl;
						cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
						Sleep(120000);
					}
					break;
				case 3://DOWN
					if (gameArray[m_y + 1][m_x] == ' ')
					{
						//EMPTY SPACE
						gameArray[m_y][m_x] = ' ';
						gotToXnY(m_x * 2, m_y);
						cout << setw(2) << ' ';
						m_y = m_y + 1;
						gameArray[m_y][m_x] = '#';
						gotToXnY(m_x * 2, m_y);
						cout << setw(2) << '#';
						moved = true;
					}
					else if (gameArray[m_y + 1][m_x] == char(254))
					{
						// ø ENEMY CHARACTER ASCII EXTENDED
						moved = true;
					}
					else if (gameArray[m_y + 1][m_x] == '#')
					{
						moved = true;
					}
					else if (gameArray[m_y + 1][m_x] == '8')
					{
						// Ø ENEMY CHARACTER ASCII EXTENDED
						moved = true;
					}
					else if (gameArray[m_y + 1][m_x] == 'O')
					{
						Beep(1400, 120);
						m_y = m_y + 1;
						gameArray[m_y][m_x] = '#';
						cout << setw(2) << '#';
						moved = true;
						status = false;
					}
					else if (gameArray[m_y + 1][m_x] == '+')
					{
						moved = true;
					}
					else if (gameArray[m_y + 1][m_x] == '$')
					{
						// Ö TELEPORTERS CHARACTER ASCII EXTENDED - DIGIT 3 FROM FILE
						moved = true;
					}
					else if (gameArray[m_y + 1][m_x] == '~')
					{
						moved = true;
					}
					else
					{
						//Learned from this debugging that I had not considered the enemy moving onto Player Object
						gotToXnY(0, 51);
						cout << "DOWN FAILURE" << endl;
						cout << "Random Number" << randomNumber << endl;
						cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y][m_x - 1] << endl;
						cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
						Sleep(120000);
					}
					break;
				case 4://LEFT
					if (gameArray[m_y][m_x - 1] == ' ')
					{
						//EMPTY SPACE
						gameArray[m_y][m_x] = ' ';
						gotToXnY(m_x * 2, m_y);
						cout << setw(2) << ' ';
						m_x = m_x - 1;
						gameArray[m_y][m_x] = '#';
						gotToXnY(m_x * 2, m_y);
						cout << setw(2) << '#';
						moved = true;
					}
					else if (gameArray[m_y][m_x - 1] == char(254))
					{
						moved = true;
					}
					else if (gameArray[m_y][m_x - 1] == '#')
					{
						moved = true;
					}
					else if (gameArray[m_y][m_x - 1] == '8')
					{
						// Ø ENEMY CHARACTER ASCII EXTENDED
						moved = true;
					}
					else if (gameArray[m_y][m_x - 1] == 'O')
					{
						Beep(1400, 120);
						m_x = m_x - 1;
						gameArray[m_y][m_x] = '#';
						cout << setw(2) << '#';
						moved = true;
					}
					else if (gameArray[m_y][m_x - 1] == '+')
					{
						moved = true;
					}
					else if (gameArray[m_y][m_x - 1] == '$')
					{
						moved = true;
					}
					else if (gameArray[m_y][m_x - 1] == '~')
					{
						moved = true;
					}
					else
					{
						//Learned from this debugging that I had not considered the enemy moving onto Player Object
						gotToXnY(0, 51);
						cout << "LEFT FAILURE" << endl;
						cout << "Random Number" << randomNumber << endl;
						cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y][m_x - 1] << endl;
						cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
						moved = true;
					}
					break;
				case 2://RIGHT
					if (gameArray[m_y][m_x + 1] == ' ')
					{
						//EMPTY SPACE
						gameArray[m_y][m_x] = ' ';
						gotToXnY(m_x * 2, m_y);
						cout << setw(2) << ' ';
						m_x = m_x + 1;
						gameArray[m_y][m_x] = '#';
						gotToXnY(m_x * 2, m_y);
						cout << setw(2) << '#';
						moved = true;
					}
					else if (gameArray[m_y][m_x + 1] == char(254))
					{
						moved = true;
					}
					else if (gameArray[m_y][m_x + 1] == '#')
					{
						moved = true;
					}
					else if (gameArray[m_y][m_x + 1] == '8')
					{
						// Ø ENEMY CHARACTER ASCII EXTENDED
						moved = true;
					}
					else if (gameArray[m_y][m_x + 1] == 'O')
					{
						Beep(1400, 120);
						m_x = m_x + 1;
						gameArray[m_y][m_x] = '#';
						cout << setw(2) << '#';
						moved = true;
					}
					else if (gameArray[m_y][m_x + 1] == '+')
					{
						moved = true;
					}
					else if (gameArray[m_y][m_x + 1] == '$')
					{
						moved = true;
					}
					else if (gameArray[m_y][m_x + 1] == '~')
					{
						moved = true;
					}
					else
					{
						//Learned from this debugging that I had not considered the enemy moving onto Player Object
						gotToXnY(0, 51);
						cout << "RIGHT FAILURE" << endl;
						cout << "Random Number" << randomNumber << endl;
						cout << "gameArray[m_y][m_x - 1] " << gameArray[m_y][m_x - 1] << endl;
						cout << "gameArray[m_y][m_x] " << gameArray[m_y][m_x] << endl;
						Sleep(120000);
					}
					break;
				}//End of switch statement
			}
		}
		else if (level == 2 || level == 3)
		{

			//PATHFINDER ALGORITHM - BONUS FUNCTION - LEVEL THREE - HARD SETTING
			//Algorithm for pathfinder to player position for each Enemy Object
			//Creates list of X & Y Coordinates using the Coordinates Object
			//List leads to Player Objects Position
			//Each Game Loop, Each Enemy Object finds a path to the Player Object
			//Then moves one place towards Player using the list
			//Then deletes the list

			origCoorX = m_x;//Need to save origional X coordinate
			origCoorY = m_y;//Need to save origional Y coordinate

			while (path_found != true)
			{
				y_same = false;
				x_same = false;
				up = false;
				down = false;
				left = false;
				right = false;


				//Decide which direction would be best TRY (Note TRY!)
				//We create a array of best directions to take in hierarchical order
				//Up = 1 ---- Down = 2 ---- Left = 3 ---- Right = 4
				if (m_y == player_y) { 
					y_same = true; 
					//cout << "Y SAME " << y_same << endl;
				}
				else if (m_y < player_y) {
					down = true; 
					//cout << "DOWN " << down << endl;
				}
				else { 
					up = true; 
					//cout << "UP " << up << endl;
				}

				if (m_x == player_x) 
				{
					x_same = true; 
					//cout << "X SAME " << x_same << endl;
				}
				else if (m_x < player_x) {
					right = true; 
					//cout << "RIGHT " << right << endl;
				}
				else { 
					left = true; 
					//cout << "LEFT " << left << endl;
				}

				slope = (float(m_y) - float(player_y)) / (float(m_x) - float(player_x));
				if (slope < 0) { slope = -1*(slope); }
				//cout << "SLOPE " << slope << endl;
				//cout << "ENEMY X " << m_x << "  ENEMY Y " << m_y << "	PLAYER X " << player_x << "    PLAYER Y " << player_y << endl;
				//cout << "UP " << up << "   DOWN " << down << "   LEFT " << left << "   RIGHT " << right << endl;
				//We have created a best direction in hierarchical order here
				if ((slope < 1.0) && (left == true))//Have to move on X Axis 
				{
					optimal_directions[0] = 3;

					if (down == true)
					{
						optimal_directions[1] = 2;
						optimal_directions[2] = 1;
					}
					else
					{
						optimal_directions[1] = 1;
						optimal_directions[2] = 2;
					}


					optimal_directions[3] = 4;//Best directions to try in order completed
											  ////cout << "First Check" << endl;
				}
				else if ((slope < 1.0) && (right == true))
				{
					optimal_directions[0] = 4;

					if (down == true)
					{
						optimal_directions[1] = 2;
						optimal_directions[2] = 1;
					}
					else
					{
						optimal_directions[1] = 1;
						optimal_directions[2] = 2;
					}


					optimal_directions[3] = 3;//Best directions to try in order completed
											  ////cout << "Second Check" << endl;
				}
				else if ((slope >= 1.0) && (up == true))
				{
					optimal_directions[0] = 1;

					if (left == true)
					{
						optimal_directions[1] = 3;
						optimal_directions[2] = 4;
					}
					else
					{
						optimal_directions[1] = 4;
						optimal_directions[2] = 3;
					}

					optimal_directions[3] = 2;//Best directions to try in order completed
											  ////cout << "Third Check" << endl;
				}
				else if ((slope >= 1.0) && (down == true))
				{
					optimal_directions[0] = 2;

					if (left == true)
					{
						optimal_directions[1] = 3;
						optimal_directions[2] = 4;
					}
					else
					{
						optimal_directions[1] = 4;
						optimal_directions[2] = 3;
					}

					optimal_directions[3] = 1;//Best directions to try in order completed
											  ////cout << "Forth Check" << endl;
				}
				////gotToXnY(0 * 2, 32);
				//cout << "Array " << optimal_directions[0] << " " << optimal_directions[1] << " " << optimal_directions[2] << " " << optimal_directions[3] << endl;
				//Sleep(3000);
				moved = false;
				//Sleep(100);
				// Eight total combinations possible _ We picl one for each PathFinder Additions
				if (optimal_directions[0] == 1 && optimal_directions[1] == 3 && optimal_directions[2] == 4 && optimal_directions[3] == 2)
				{
					//cout << "1 Set" << endl;
					//Check First Direction
					// 1 = UP
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if(gameArray[m_y - 1][m_x] == char(254) || gameArray[m_y - 1][m_x] == '+' || gameArray[m_y - 1][m_x] == '#' || gameArray[m_y - 1][m_x] == '8' || gameArray[m_y - 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "First Set - 1.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							////cout << "1 -> Skipp 1" << endl;
							//end_Iter == false;
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 1.1" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
									{
										//end_Iter = true;//We can edn iterator now, save processing
										//cout << "First Set - 1.2 = HIT" << endl;
										skip = true;
									}
									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y--;
										
										
										
										moved = true;
										//cout << "First Set - 1.3 = MOVED" << endl;
									}

								}
							}
						}
					}


					//Check Second Direction
					// 3 = LEFT
					if (moved != true)
					{
						skip = false;
						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x - 1] == char(254) || gameArray[m_y][m_x - 1] == '+' || gameArray[m_y][m_x - 1] == '#' || gameArray[m_y][m_x - 1] == '8' || gameArray[m_y][m_x - 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "First Set - 2.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 1.2" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
									{
										//cout << "First Set - 2.2 = HIT" << endl;
										skip = true;
									}
									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x--;
										
										
										
										moved = true;
										//cout << "First Set 2.3 = MOVED" << endl;
									}

								}
							}
						}
					}


					//Check Third Direction
					// 4 = RIGHT
					if (moved != true)
					{
						skip = false;
						//end_Iter = false;
						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x + 1] == char(254) || gameArray[m_y][m_x + 1] == '+' || gameArray[m_y][m_x + 1] == '#' || gameArray[m_y][m_x + 1] == '8' || gameArray[m_y][m_x + 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
											 //end_Iter = true;
								//cout << "First Set - 3.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 1.3" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
									{
										//end_Iter = true;//We can edn iterator now, save processing
										//cout << "First Set - 3.2 = HIT" << endl;
										skip = true;
									}
									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										m_x++;
										moved = true;
										//cout << "First Set- 3.1 = MOVED" << endl;
									}

								}
							}
						}
					}


					//Check First Direction
					// 2 = DOWN
					if (moved != true)
					{
						skip = false;
						//Check if any our objects are on the point we want to add
						if (gameArray[m_y + 1][m_x] == char(254) || gameArray[m_y + 1][m_x] == '+' || gameArray[m_y + 1][m_x] == '#' || gameArray[m_y + 1][m_x] == '8' || gameArray[m_y + 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "First Set - 4.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 1.4" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
									{
										//end_Iter = true;//We can edn iterator now, save processing
										//cout << "First Set - 4.2 = HIT" << endl;
										skip = true;
									}
									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y++;
										
										
										moved = true;
										//cout << "First Set - 4.3 = MOVED" << endl;
									}

								}
							}
						}
					}

				}
				else if (optimal_directions[0] == 1 && optimal_directions[1] == 4 && optimal_directions[2] == 3 && optimal_directions[3] == 2)
				{
					//cout << "2 Set" << endl;
					//Check First Direction
					// 1 = UP
					if (moved != true)
					{
						skip = false;
						//Check if any our objects are on the point we want to add
						if (gameArray[m_y - 1][m_x] == char(254) || gameArray[m_y - 1][m_x] == '+' || gameArray[m_y - 1][m_x] == '#' || gameArray[m_y - 1][m_x] == '8' || gameArray[m_y - 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Second Set - 1.1 = HIT" << endl;
						}

						//Check if our paths is on the point we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 2.1" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
									{
										//cout << "Second Set - 1.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y--;
										
										
										
										moved = true;
										//cout << "Second Set - 1.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check Third Direction
					// 4 = RIGHT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x + 1] == char(254) || gameArray[m_y][m_x + 1] == '+' || gameArray[m_y][m_x + 1] == '#' || gameArray[m_y][m_x + 1] == '8' || gameArray[m_y][m_x + 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Second Set - 2.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 2.2" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
									{
										skip = true;
										//cout << "Second Set - 2.2 = HIT" << endl;
									}
									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x++;
										
										
										
										moved = true;
										//cout << "Second Set - 2.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check Second Direction
					// 3 = LEFT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x - 1] == char(254) || gameArray[m_y][m_x - 1] == '+' || gameArray[m_y][m_x - 1] == '#' || gameArray[m_y][m_x - 1] == '8' || gameArray[m_y][m_x - 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Second Set - 3.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 2.3" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
									{
										skip = true;
										//cout << "Second Set - 3.2 = HIT" << endl;
									}
									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x--;
										
										
										
										moved = true;
										//cout << "Second Set - 3.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check First Direction
					// 2 = DOWN
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y + 1][m_x] == char(254) || gameArray[m_y + 1][m_x] == '+' || gameArray[m_y + 1][m_x] == '#' || gameArray[m_y + 1][m_x] == '8' || gameArray[m_y + 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Second Set - 4.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								//If our coordinates do not occupy this area We can move here.
								//Otherwise we have to skip to next direction in this combination set
								//Draw empty in old spot wheile drawing enemy in new spot
								//Update our array at same time
								
								
								
								m_y++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 2.4" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
									{
										skip = true;
										//cout << "Second Set - 4.2 = HIT" << endl;
									}
									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y++;
										
										
										
										moved = true;
										//cout << "Second Set - 4.3 = MOVED" << endl;
									}

								}
							}
						}
					}

				}
				else if (optimal_directions[0] == 2 && optimal_directions[1] == 4 && optimal_directions[2] == 3 && optimal_directions[3] == 1)
				{
					//cout << "3 Set" << endl;
					//Check First Direction
					// 2 = DOWN
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y + 1][m_x] == char(254) || gameArray[m_y + 1][m_x] == '+' || gameArray[m_y + 1][m_x] == '#' || gameArray[m_y + 1][m_x] == '8' || gameArray[m_y + 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder

								//cout << "Third Set - 1.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 3.1" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
									{

										skip = true;
										//cout << "Third Set - 1.2 = HIT" << endl;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y++;
										
										
										
										moved = true;
										//cout << "Third Set - 1.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check Third Direction
					// 4 = RIGHT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x + 1] == char(254) || gameArray[m_y][m_x + 1] == '+' || gameArray[m_y][m_x + 1] == '#' || gameArray[m_y][m_x + 1] == '8' || gameArray[m_y][m_x + 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder

								//cout << "Third Set - 2.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								//Draw empty in old spot wheile drawing enemy in new spot
								//Update our array at same time
								
								
								
								m_x++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 3.2" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
									{
										skip = true;
										//cout << "Third Set - 2.2 = HIT" << endl;
									}
									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x++;
										
										
										
										moved = true;
										//cout << "Third Set - 2.3 = MOVED" << endl;
									}

								}

							}
						}
					}

					//Check Second Direction
					// 3 = LEFT
					if (moved != true)
					{
						skip = false;
						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x - 1] == char(254) || gameArray[m_y][m_x - 1] == '+' || gameArray[m_y][m_x - 1] == '#' || gameArray[m_y][m_x - 1] == '8' || gameArray[m_y][m_x - 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Third Set - 3.1 = HIT" << endl;
						}

						//If our coordinates do not occupy this area We can move here.
						//Otherwise we have to skip to next direction in this combination set
						//Draw empty in old spot wheile drawing enemy in new spot
						//Update our array at same time
						if (skip != true)
						{
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 3.3" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
									{
										skip = true;
										//cout << "Third Set - 3.2 = HIT" << endl;
									}
									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x--;
										
										
										
										moved = true;
										//cout << "Third Set - 3.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check First Direction
					// 1 = UP
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y - 1][m_x] == char(254) || gameArray[m_y - 1][m_x] == '+' || gameArray[m_y - 1][m_x] == '#' || gameArray[m_y - 1][m_x] == '8' || gameArray[m_y - 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Third Set - 4.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 3.4" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
									{
										//cout << "Third Set - 4.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true )
									{
										
										
										
										m_y--;
										
										
										
										moved = true;
										//cout << "Third Set - 4.3 = MOVED" << endl;
									}

								}
							}
						}
					}

				}
				else if (optimal_directions[0] == 2 && optimal_directions[1] == 3 && optimal_directions[2] == 4 && optimal_directions[3] == 1)
				{
					//cout << "4 Set" << endl;
					//Check First Direction
					// 2 = DOWN
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y + 1][m_x] == char(254) || gameArray[m_y + 1][m_x] == '+' || gameArray[m_y + 1][m_x] == '#' || gameArray[m_y + 1][m_x] == '8' || gameArray[m_y + 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Forth Set - 1.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 4.1" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
									{
										//cout << "Forth Set - 1.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y++;
										
										
										
										moved = true;
										//cout << "Forth Set - 1.3 = Moved" << endl;
									}

								}
							}
						}
					}

					//Check Second Direction
					// 3 = LEFT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x - 1] == char(254) || gameArray[m_y][m_x - 1] == '+' || gameArray[m_y][m_x - 1] == '#' || gameArray[m_y][m_x - 1] == '8' || gameArray[m_y][m_x - 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Forth Set - 2.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 4.2" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
									{

										//cout << "Forth Set - 2.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x--;
										
										
										
										moved = true;
										//cout << "Forth Set - 2.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check Third Direction
					// 4 = RIGHT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x + 1] == char(254) || gameArray[m_y][m_x + 1] == '+' || gameArray[m_y][m_x + 1] == '#' || gameArray[m_y][m_x + 1] == '8' || gameArray[m_y][m_x + 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder

								//cout << "Forth Set - 3.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 4.3" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
									{

										//cout << "Forth Set - 3.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x++;
										
										
										
										moved = true;
										//cout << "Forth Set - 3.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check First Direction
					// 1 = UP
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y - 1][m_x] == char(254) || gameArray[m_y - 1][m_x] == '+' || gameArray[m_y - 1][m_x] == '#' || gameArray[m_y - 1][m_x] == '8' || gameArray[m_y - 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Forth Set - 4.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 4.4" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
									{
										skip = true;
										//cout << "Forth Set - 4.2 = HIT" << endl;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y--;
										
										
										
										moved = true;
										//cout << "Forth Set - 4.3 = MOVED" << endl;
									}

								}
							}
						}
					}
				}
				else if (optimal_directions[0] == 3 && optimal_directions[1] == 2 && optimal_directions[2] == 1 && optimal_directions[3] == 4)
				{
					//cout << "5 Set" << endl;
					//Check Second Direction
					// 3 = LEFT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x - 1] == char(254) || gameArray[m_y][m_x - 1] == '+' || gameArray[m_y][m_x - 1] == '#' || gameArray[m_y][m_x - 1] == '8' || gameArray[m_y][m_x - 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder

								//cout << "Fifth Set - 1.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 5.1" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
									{

										//cout << "Fifth Set - 1.2 = HIT" << endl;
										skip = true;
									}
									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x--;
										
										
										
										moved = true;
										//cout << "Fifth Set - 1.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check First Direction
					// 2 = DOWN
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y + 1][m_x] == char(254) || gameArray[m_y + 1][m_x] == '+' || gameArray[m_y + 1][m_x] == '#' || gameArray[m_y + 1][m_x] == '8' || gameArray[m_y + 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder

								//cout << "Fifth Set - 2.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 5.2" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
									{

										//cout << "Fifth Set - 2.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y++;
										
										
										
										moved = true;
										//cout << "Fifth Set - 2.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check First Direction
					// 1 = UP
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y - 1][m_x] == char(254) || gameArray[m_y - 1][m_x] == '+' || gameArray[m_y - 1][m_x] == '#' || gameArray[m_y - 1][m_x] == '8' || gameArray[m_y - 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder

								//cout << "Fifth Set - 3.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y--;
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 5.3" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
									{

										//cout << "Fifth Set - 3.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y--;
										
										
										
										moved = true;
										//cout << "Fifth Set - 3.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check Third Direction
					// 4 = RIGHT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x + 1] == char(254) || gameArray[m_y][m_x + 1] == '+' || gameArray[m_y][m_x + 1] == '#' || gameArray[m_y][m_x + 1] == '8' || gameArray[m_y][m_x + 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Fifth Set - 4.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 5.4" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
									{
										//cout << "Fifth Set - 4.2 = HIT" << endl;
										skip = true;

									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x++;
										
										
										
										moved = true;
										//cout << "Fifth Set - 4.3 = MOVED" << endl;
									}

								}
							}
						}
					}
				}
				else if (optimal_directions[0] == 3 && optimal_directions[1] == 1 && optimal_directions[2] == 2 && optimal_directions[3] == 4)
				{
					//cout << "6 Set" << endl;
					//Check Second Direction
					// 3 = LEFT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x - 1] == char(254) || gameArray[m_y][m_x - 1] == '+' || gameArray[m_y][m_x - 1] == '#' || gameArray[m_y][m_x - 1] == '8' || gameArray[m_y][m_x - 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Sixth Set - 1.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 6.1" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
									{
										//cout << "Sixth Set - 1.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x--;
										
										
										
										moved = true;
										//cout << "Sixth Set - 1.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check First Direction
					// 1 = UP
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y - 1][m_x] == char(254) || gameArray[m_y - 1][m_x] == '+' || gameArray[m_y - 1][m_x] == '#' || gameArray[m_y - 1][m_x] == '8' || gameArray[m_y - 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Sixth Set - 2.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 6.2" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
									{
										//cout << "Sixth Set - 2.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end())&& skip != true)
									{
										
										
										
										m_y--;
										
										
										
										moved = true;
										//cout << "Sixth Set - 2.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check First Direction
					// 2 = DOWN
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y + 1][m_x] == char(254) || gameArray[m_y + 1][m_x] == '+' || gameArray[m_y + 1][m_x] == '#' || gameArray[m_y + 1][m_x] == '8' || gameArray[m_y + 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Sixth Set - 3.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 6.3" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
									{
										//cout << "Sixth Set - 3.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y++;
										
										
										
										//cout << "Sixth Set - 3.3 = MOVED" << endl;
										moved = true;
									}

								}
							}
						}
					}

					//Check Third Direction
					// 4 = RIGHT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x + 1] == char(254) || gameArray[m_y][m_x + 1] == '+' || gameArray[m_y][m_x + 1] == '#' || gameArray[m_y][m_x + 1] == '8' || gameArray[m_y][m_x + 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Sixth Set - 4.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 6.4" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
									{
										//cout << "Sixth Set - 4.2 = HIT" << endl;
										skip = true;
									}
									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x++;
										
										
										
										moved = true;
										//cout << "Sixth Set - 4.2 = MOVED" << endl;
									}

								}
							}
						}
					}
				}
				else if (optimal_directions[0] == 4 && optimal_directions[1] == 2 && optimal_directions[2] == 1 && optimal_directions[3] == 3)
				{
					//cout << "7 Set" << endl;
					//Check Third Direction
					// 4 = RIGHT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x + 1] == char(254) || gameArray[m_y][m_x + 1] == '+' || gameArray[m_y][m_x + 1] == '#' || gameArray[m_y][m_x + 1] == '8' || gameArray[m_y][m_x + 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Seventh Set - 1.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 7.1" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
									{
										//cout << "Seventh Set - 1.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x++;
										
										
										
										moved = true;
										//cout << "Seventh Set - 1.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check First Direction
					// 2 = DOWN
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y + 1][m_x] == char(254) || gameArray[m_y + 1][m_x] == '+' || gameArray[m_y + 1][m_x] == '#' || gameArray[m_y + 1][m_x] == '8' || gameArray[m_y + 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder

								//cout << "Seventh Set - 2.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 7.2" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
									{

										//cout << "Seventh Set - 2.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y++;
										
										
										
										moved = true;
										//cout << "Seventh Set - 2.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check First Direction
					// 1 = UP
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y - 1][m_x] == char(254) || gameArray[m_y - 1][m_x] == '+' || gameArray[m_y - 1][m_x] == '#' || gameArray[m_y - 1][m_x] == '8' || gameArray[m_y - 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Seventh Set - 3.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 7.3" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
									{
										skip = true;
										//cout << "Seventh Set - 3.2 = HIT" << endl;

									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y--;
										
										
										
										moved = true;
										//cout << "Seventh Set - 3.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check Second Direction
					// 3 = LEFT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x - 1] == char(254) || gameArray[m_y][m_x - 1] == '+' || gameArray[m_y][m_x - 1] == '#' || gameArray[m_y][m_x - 1] == '8' || gameArray[m_y][m_x - 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Seventh Set - 4.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 7.4" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
									{
										//cout << "Seventh Set - 4.2 = HIT" << endl;
										skip = true;

									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x--;
										
										
										
										moved = true;
										//cout << "Seventh Set - 4.3 = MOVED" << endl;
									}

								}
							}
						}
					}
				}
				else if (optimal_directions[0] == 4 && optimal_directions[1] == 1 && optimal_directions[2] == 2 && optimal_directions[3] == 3)
				{
					//cout << "8 Set" << endl;
					//Check Third Direction
					// 4 = RIGHT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x + 1] == char(254) || gameArray[m_y][m_x + 1] == '+' || gameArray[m_y][m_x + 1] == '#' || gameArray[m_y][m_x + 1] == '8' || gameArray[m_y][m_x + 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Eight Set - 12.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 8.1" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
									{
										//cout << "Eight Set - 2.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x++;
										
										
										
										moved = true;
										//cout << "Eight Set - 2.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check First Direction
					// 1 = UP
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y - 1][m_x] == char(254) || gameArray[m_y - 1][m_x] == '+' || gameArray[m_y - 1][m_x] == '#' || gameArray[m_y - 1][m_x] == '8' || gameArray[m_y - 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Eight Set - 2.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 8.2" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
									{
										//cout << "Eight Set - 2.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y--;
										
										
										
										moved = true;
										//cout << "Eight Set - 2.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check First Direction
					// 2 = DOWN
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y + 1][m_x] == char(254) || gameArray[m_y + 1][m_x] == '+' || gameArray[m_y + 1][m_x] == '#' || gameArray[m_y + 1][m_x] == '8' || gameArray[m_y + 1][m_x] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Eight Set - 3.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_y++;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 8.3" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
									{
										//cout << "Eight Set - 3.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_y++;
										
										
										
										moved = true;
										//cout << "Eight Set - 3.3 = MOVED" << endl;
									}

								}
							}
						}
					}

					//Check Second Direction
					// 3 = LEFT
					if (moved != true)
					{
						skip = false;

						//Check if any our objects are on the point we want to add
						if (gameArray[m_y][m_x - 1] == char(254) || gameArray[m_y][m_x - 1] == '+' || gameArray[m_y][m_x - 1] == '#' || gameArray[m_y][m_x - 1] == '8' || gameArray[m_y][m_x - 1] == '$')
						{
								skip = true;//Found object in our way - No need check Pathfinder
								//cout << "Eight Set - 4.1 = HIT" << endl;
						}

						//Check if our paths is on the pojt we want to move to
						if (skip != true)
						{
							//If our coordinates do not occupy this area We can move here.
							//Otherwise we have to skip to next direction in this combination set
							//Draw empty in old spot wheile drawing enemy in new spot
							//Update our array at same time
							if (listOfCoordinates.empty())
							{
								
								
								
								m_x--;
								
								
								
								moved = true;
								//cout << "COORDINATES EMTPY - MOVED 8.4" << endl;
							}
							else
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
									{
										//cout << "Eight Set - 4.2 = HIT" << endl;
										skip = true;
									}

									else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
									{
										
										
										
										m_x--;
										
										
										
										moved = true;
										//cout << "Eight Set - 4.3 = Moved" << endl;
									}

								}
							}
						}
					}
				}
				//Sleep(60000);
				if (m_y == player_y && m_x == player_x || listOfCoordinates.size() > 100)//Path Found
					path_found = true;
				
				//Sleep(100);
				//cout << "ENEMY X " << m_x << "  ENEMY Y " << m_y << "	PLAYER X " << player_x << "    PLAYER Y " << player_y << endl;
				//We have got a full list of coordinates to our player
				//cout << "Path Finder Begin -> " << path_found << endl;
				//Each point we add we use the enmy to move around, while making use of his X & Y values to create a Coordinate Object
				coordinate_name = "Point " + to_string(serialID);
				////gotToXnY(32 * 2, 32);
				//cout << "BEFORE POINT - COORDINATES X " << m_x << " " << " COORDINATES Y " << " " << m_y << endl;
				Coordinates* coordinate_name = new Coordinates(m_x, m_y);
				serialID++;
				listOfCoordinates.push_back(coordinate_name);
				////gotToXnY(0 * 2, 32);
				//cout << "COORDINATES X " << coordinate_name->get_x() << "  " << " COORDINATES Y " << coordinate_name->get_y() << "  " << endl;
				//Sleep(1000);
				//cout << "COORDINATES X " << m_x << "  " << " COORDINATES Y " << m_y << "  " << endl;
				//Sleep(1000);
				//Sleep(100);
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			gameArray[origCoorY][origCoorX] = ' ';
			gotToXnY(origCoorX * 2, origCoorY);
			cout << setw(2) << ' ';
			for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
			{
				m_x = (*coor_iter)->get_x();
				m_y = (*coor_iter)->get_y();
				break;
			}
			gotToXnY(m_x*2, m_y);
			cout << setw(2) << '#';
			gameArray[m_y][m_x] = '#';
			listOfCoordinates.clear();
			//Emtpy my path for next time
			//if (listOfCoordinates.empty())
			//cout << "EMPTY LIST" << endl;
			//Sleep(200);
			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		}

		staminaCounter = m_stamina;
	}

	staminaCounter = staminaCounter + 1;
	return 0;
}

//RETURN ENEMY DAMAGE VALUE
int Enemy::giveDamage()
{
	srand(time(NULL));

	m_damage = rand() % 51;

	return m_damage;
}

//RETURNS ENEMY TYPE STRING - USED IN GAME LOOP FUNCTIONS - PARTICULARLY THE GAME UPDATE FUCNTION
string Enemy::objectType()
{
	m_type = "enemy";
	return m_type;
}

//RETURNS EMENY CHARCTER
char Enemy::ObjectCharacter()
{
	object_char = '#';// ø ENEMY CHARACTER ASCII EXTENDED
	return object_char;
}

//WE MAY NOT USE THIS FUNCTION FOR THIS OBJECT
void Enemy::armWeapon(int weapon)
{
}

//WE MAY NOT USE THIS FUNCTION FOR THIS OBJECT
int Enemy::getWeapon()
{
	return 0;
}

string Enemy::returnWeaponString()
{
	return string();
}
