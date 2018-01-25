		//First atempt at Pathfinder Algorithm - I think I have better idea - Is above
		//Came up with simple idea I think above
		//This would work thought

		//At end of this statment our enemy object has moved 
		if (slope < 1)
		{//Attempt adding X Axis next step point List (Path Finder)

			if (left == true)
			{
				skip == false;
				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end() || end_Iter != true; iter++)
				{
					if (((*iter)->GameObject_X() == m_x - 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						end_Iter = true;
					}
				}

				if (skip != true)
				{
					end_Iter == false;
					for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end() || end_Iter != true; coor_iter++)
					{
						if (!((*coor_iter)->get_x() == m_x - 1) && !((*coor_iter)->get_y() == m_y))
						{
							end_Iter = true;//We can edn iterator now, save processing
							m_x--;
							moved = true;
						}

					}
				}
			}
			else if(right == true)
			{
				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end() || end_Iter != true; iter++)
				{
					if (!((*iter)->GameObject_X() == m_x + 1) && !((*iter)->GameObject_Y() == m_y))
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (!((*coor_iter)->get_x() == m_x + 1) && !((*coor_iter)->get_y() == m_y))
							{
								end_Iter = true;//We can edn iterator now, save processing
								m_x++;
								moved = true;
							}

						}
					}
				}
			}

			if (moved == false)
			{
				while(moved == false)
				if (up == true)
				{
					//Check if any our objects are on the point we want to add
					for (iter = listOfObjects.begin(); iter != listOfObjects.end() || end_Iter != true; iter++)
					{
						if (!((*iter)->GameObject_Y() == m_y - 1) && !((*iter)->GameObject_X() == m_x))
						{
							for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
							{
								if (((*coor_iter)->get_y() == m_x - 1) && ((*coor_iter)->get_x() == m_x))
								{
									end_Iter = true;//We can edn iterator now, save processing
									m_y--;
									moved = true;
								}

							}
						}
					}

					//Last check to see if the only way we can possible move is also blocked, 
					//then we need to delete everthing if path so far and start again
					//Dead Lock Error handling
					if (moved == false)
					{
						for (iter = listOfObjects.begin(); iter != listOfObjects.end() || end_Iter != true; iter++)
						{
							if (!((*iter)->GameObject_Y() == m_y + 1) && !((*iter)->GameObject_X() == m_x))
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
									{
										//This means our path finder is screwed and has to restarts
										//To do so we just empty the entire list and start again
										for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
										{
											iter = listOfObjects.erase(iter);
										}
									}
									else
									{
										m_y++;//Last possible option
										moved = true;
									}
								}
							}
						}
					}
				}
				else
				{
					//Check if any our objects are on the point we want to add
					for (iter = listOfObjects.begin(); iter != listOfObjects.end() || end_Iter != true; iter++)
					{
						if (!((*iter)->GameObject_Y() == m_y + 1) && !((*iter)->GameObject_Y() == m_x))
						{
							for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
							{
								if (!((*coor_iter)->get_y() == m_x + 1) && !((*coor_iter)->get_x() == m_x))
								{
									end_Iter = true;//We can edn iterator now, save processing
									m_y++;
									moved = true;
								}

							}
						}
					}


					//Last check to see if the only way we can possible move is also blocked, 
					//then we need to delete everthing if path so far and start again
					//Dead Lock Error handling
					if (moved == false)
					{
						for (iter = listOfObjects.begin(); iter != listOfObjects.end() || end_Iter != true; iter++)
						{
							if (!((*iter)->GameObject_Y() == m_y - 1) && !((*iter)->GameObject_Y() == m_x))
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (!((*coor_iter)->get_y() == m_y - 1) && !((*coor_iter)->get_x() == m_x))
									{
										//This means our path finder is screwed and has to restarts
										//To do so we just empty the entire list and start again
										for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
										{
											iter = listOfObjects.erase(iter);
										}
									}
									else
									{
										m_y--;//Last possible option
										moved = true;
									}
								}
							}
						}
					}
				}
			}
		}
		else if (slope >=1)
		{//Attempt adding Y Axis next step point List (Path Finder)

			if (up == true)
			{
				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end() || end_Iter != true; iter++)
				{
					if (!((*iter)->GameObject_Y() == m_y - 1) && !((*iter)->GameObject_X() == m_x))
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (!((*coor_iter)->get_y() == m_x - 1) && !((*coor_iter)->get_x() == m_x))
							{
								end_Iter = true;//We can edn iterator now, save processing
								m_y--;
								moved = true;
							}

						}
					}
				}
			}
			else if(down == true)
			{
				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end() || end_Iter != true; iter++)
				{
					if (!((*iter)->GameObject_Y() == m_y + 1) && !((*iter)->GameObject_Y() == m_x))
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (!((*coor_iter)->get_y() == m_x + 1) && !((*coor_iter)->get_x() == m_x))
							{
								end_Iter = true;//We can edn iterator now, save processing
								m_y++;
								moved = true;
							}

						}
					}
				}
			}

			if (moved == false)
			{
				if (left == true)
				{
					//Check if any our objects are on the point we want to add
					for (iter = listOfObjects.begin(); iter != listOfObjects.end() || end_Iter != true; iter++)
					{
						if (!((*iter)->GameObject_X() == m_x - 1) && !((*iter)->GameObject_Y() == m_y))
						{
							for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
							{
								if (!((*coor_iter)->get_x() == m_x - 1) && !((*coor_iter)->get_y() == m_y))
								{
									end_Iter = true;//We can edn iterator now, save processing
									m_x--;
									moved = true;
								}

							}
						}
					}
					//Last check to see if the only way we can possible move is also blocked, 
					//then we need to delete everthing if path so far and start again
					//Dead Lock Error handling
					if (moved == false)
					{
						for (iter = listOfObjects.begin(); iter != listOfObjects.end() || end_Iter != true; iter++)
						{
							if (!((*iter)->GameObject_Y() == m_y - 1) && !((*iter)->GameObject_Y() == m_x))
							{
								for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
								{
									if (!((*coor_iter)->get_y() == m_y - 1) && !((*coor_iter)->get_x() == m_x))
									{
										//This means our path finder is screwed and has to restarts
										//To do so we just empty the entire list and start again
										for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
										{
											iter = listOfObjects.erase(iter);
										}
									}
									else
									{
										m_x++;//Last possible option
										moved = true;
									}
								}
							}
							else
								end_Iter = true;
						}
					}
				}
				else
				{
					//Check if any our objects are on the point we want to add
					for (iter = listOfObjects.begin(); iter != listOfObjects.end() || end_Iter != true; iter++)
					{
						if (!((*iter)->GameObject_X() == m_x + 1) && !((*iter)->GameObject_Y() == m_y))
						{
							for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
							{
								if (!((*coor_iter)->get_x() == m_x + 1) && !((*coor_iter)->get_y() == m_y))
								{
									end_Iter = true;//We can edn iterator now, save processing
									m_x++;
									moved = true;
								}

							}
						}
					}
					m_x--;//Last possible option
				}

			}
		}
