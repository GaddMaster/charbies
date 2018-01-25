		// Eight total combinations possible _ We picl one for each PathFinder Additions
		if (optimal_directions[0] == 1 && optimal_directions[1] == 3 && optimal_directions[2] == 4 && optimal_directions[3] == 2)
		{
			cout << "1 Set" << endl;
			//Check First Direction
			// 1 = UP
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y - 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "First Set - 1.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					//cout << "1 -> Skipp 1" << endl;
					//end_Iter == false;
					if (listOfCoordinates.empty())
					{
						m_y--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 1.1" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
							{
								//end_Iter = true;//We can edn iterator now, save processing
								cout << "First Set - 1.2 = HIT" << endl;
								skip == true;
							}
							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y--;
								moved = true;
								cout << "First Set - 1.3 = MOVED" << endl;
							}

						}
					}
				}
			}


			//Check Second Direction
			// 3 = LEFT
			if (moved != true)
			{
				skip == false;
				//end_Iter = false;
				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x - 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
									 //end_Iter = true;
						cout << "First Set - 2.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 1.2" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
							{
								//end_Iter = true;//We can edn iterator now, save processing
								cout << "First Set - 2.2 = HIT" << endl;
								skip = true;
							}
							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x--;
								moved = true;
								cout << "First Set 2.3 = MOVED" << endl;
							}

						}
					}
				}
			}


			//Check Third Direction
			// 4 = RIGHT
			if (moved != true)
			{
				skip == false;
				//end_Iter = false;
				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x + 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
									 //end_Iter = true;
						cout << "First Set - 3.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 1.3" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
							{
								//end_Iter = true;//We can edn iterator now, save processing
								cout << "First Set - 3.2 = HIT" << endl;
								skip = true;
							}
							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x++;
								moved = true;
								cout << "First Set- 3.1 = MOVED" << endl;
							}

						}
					}
				}
			}


			//Check First Direction
			// 2 = DOWN
			if (moved != true)
			{
				skip == false;
				//end_Iter = false;
				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y + 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
									 //end_Iter = true;
						cout << "First Set - 4.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 1.4" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
							{
								//end_Iter = true;//We can edn iterator now, save processing
								cout << "First Set - 4.2 = HIT" << endl;
								skip = true;
							}
							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y++;
								moved = true;
								cout << "First Set - 4.3 = MOVED" << endl;
							}

						}
					}
				}
			}

		}
		else if (optimal_directions[0] == 1 && optimal_directions[1] == 4 && optimal_directions[2] == 3 && optimal_directions[3] == 2)
		{
			cout << "2 Set" << endl;
			//Check First Direction
			// 1 = UP
			if (moved != true)
			{
				skip == false;
				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y - 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Second Set - 1.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the point we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 2.1" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
							{
								cout << "Second Set - 1.2 = HIT" << endl;
								skip == true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y--;
								moved = true;
								cout << "Second Set - 1.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check Third Direction
			// 4 = RIGHT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x + 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Second Set - 2.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 2.2" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
							{
								skip = true;
								cout << "Second Set - 2.2 = HIT" << endl;
							}
							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x++;
								moved = true;
								cout << "Second Set - 2.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check Second Direction
			// 3 = LEFT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x - 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Second Set - 3.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 2.3" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
							{
								skip = true;
								cout << "Second Set - 3.2 = HIT" << endl;
							}
							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x--;
								moved = true;
								cout << "Second Set - 3.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check First Direction
			// 2 = DOWN
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y + 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Second Set - 4.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 2.4" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
							{
								skip = true;
								cout << "Second Set - 4.2 = HIT" << endl;
							}
							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) & skip != true)
							{
								m_y++;
								moved = true;
								cout << "Second Set - 4.3 = MOVED" << endl;
							}

						}
					}
				}
			}

		}
		else if (optimal_directions[0] == 2 && optimal_directions[1] == 4 && optimal_directions[2] == 3 && optimal_directions[3] == 1)
		{
			cout << "3 Set" << endl;
			//Check First Direction
			// 2 = DOWN
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y + 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder

						cout << "Third Set - 1.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 3.1" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
							{

								skip = true;
								cout << "Third Set - 1.2 = HIT" << endl;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y++;
								moved = true;
								cout << "Third Set - 1.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check Third Direction
			// 4 = RIGHT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x + 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder

						cout << "Third Set - 2.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 3.2" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
							{
								skip = true;
								cout << "Third Set - 2.2 = HIT" << endl;
							}
							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x++;
								moved = true;
								cout << "Third Set - 2.3 = MOVED" << endl;
							}

						}

					}
				}
			}

			//Check Second Direction
			// 3 = LEFT
			if (moved != true)
			{
				skip == false;
				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x - 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Third Set - 3.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 3.3" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
							{
								skip = true;
								cout << "Third Set - 3.2 = HIT" << endl;
							}
							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x--;
								moved = true;
								cout << "Third Set - 3.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check First Direction
			// 1 = UP
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y - 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Third Set - 4.1 = HIT" << endl;

					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 3.4" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
							{
								cout << "Third Set - 4.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y--;
								moved = true;
								cout << "Third Set - 4.3 = MOVED" << endl;
							}

						}
					}
				}
			}

		}
		else if (optimal_directions[0] == 2 && optimal_directions[1] == 3 && optimal_directions[2] == 4 && optimal_directions[3] == 1)
		{
			cout << "4 Set" << endl;
			//Check First Direction
			// 2 = DOWN
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y + 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Forth Set - 1.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 4.1" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
							{
								cout << "Forth Set - 1.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y++;
								moved = true;
								cout << "Forth Set - 1.3 = Moved" << endl;
							}

						}
					}
				}
			}

			//Check Second Direction
			// 3 = LEFT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x - 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Forth Set - 2.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 4.2" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
							{

								cout << "Forth Set - 2.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x--;
								moved = true;
								cout << "Forth Set - 2.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check Third Direction
			// 4 = RIGHT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x + 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder

						cout << "Forth Set - 3.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 4.3" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
							{

								cout << "Forth Set - 3.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x++;
								moved = true;
								cout << "Forth Set - 3.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check First Direction
			// 1 = UP
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y - 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Forth Set - 4.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 4.4" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
							{
								skip = true;
								cout << "Forth Set - 4.2 = HIT" << endl;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y--;
								moved = true;
								cout << "Forth Set - 4.3 = MOVED" << endl;
							}

						}
					}
				}
			}
		}
		else if (optimal_directions[0] == 3 && optimal_directions[1] == 2 && optimal_directions[2] == 1 && optimal_directions[3] == 4)
		{
			cout << "5 Set" << endl;
			//Check Second Direction
			// 3 = LEFT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x - 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder

						cout << "Fifth Set - 1.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 5.1" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
							{

								cout << "Fifth Set - 1.2 = HIT" << endl;
								skip = true;
							}
							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x--;
								moved = true;
								cout << "Fifth Set - 1.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check First Direction
			// 2 = DOWN
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y + 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder

						cout << "Fifth Set - 2.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 5.2" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
							{

								cout << "Fifth Set - 2.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y++;
								moved = true;
								cout << "Fifth Set - 2.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check First Direction
			// 1 = UP
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y - 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder

						cout << "Fifth Set - 3.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 5.3" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
							{

								cout << "Fifth Set - 3.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y--;
								moved = true;
								cout << "Fifth Set - 3.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check Third Direction
			// 4 = RIGHT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x + 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Fifth Set - 4.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 5.4" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
							{
								cout << "Fifth Set - 4.2 = HIT" << endl;
								skip = true;

							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x++;
								moved = true;
								cout << "Fifth Set - 4.3 = MOVED" << endl;
							}

						}
					}
				}
			}
		}
		else if (optimal_directions[0] == 3 && optimal_directions[1] == 1 && optimal_directions[2] == 2 && optimal_directions[3] == 4)
		{
			cout << "6 Set" << endl;
			//Check Second Direction
			// 3 = LEFT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x - 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Sixth Set - 1.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 6.1" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
							{
								cout << "Sixth Set - 1.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x--;
								moved = true;
								cout << "Sixth Set - 1.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check First Direction
			// 1 = UP
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y - 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Sixth Set - 2.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 6.2" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
							{
								cout << "Sixth Set - 2.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) & skip != true)
							{
								m_y--;
								moved = true;
								cout << "Sixth Set - 2.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check First Direction
			// 2 = DOWN
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y + 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Sixth Set - 3.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 6.3" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
							{
								cout << "Sixth Set - 3.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y++;
								cout << "Sixth Set - 3.3 = MOVED" << endl;
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
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x + 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Sixth Set - 4.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 6.4" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
							{
								cout << "Sixth Set - 4.2 = HIT" << endl;
								skip = true;
							}
							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x++;
								moved = true;
								cout << "Sixth Set - 4.2 = MOVED" << endl;
							}

						}
					}
				}
			}
		}
		else if (optimal_directions[0] == 4 && optimal_directions[1] == 2 && optimal_directions[2] == 1 && optimal_directions[3] == 3)
		{
			cout << "7 Set" << endl;
			//Check Third Direction
			// 4 = RIGHT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x + 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Seventh Set - 1.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 7.1" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
							{
								cout << "Seventh Set - 1.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x++;
								moved = true;
								cout << "Seventh Set - 1.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check First Direction
			// 2 = DOWN
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y + 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder

						cout << "Seventh Set - 2.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 7.2" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
							{

								cout << "Seventh Set - 2.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y++;
								moved = true;
								cout << "Seventh Set - 2.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check First Direction
			// 1 = UP
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y - 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Seventh Set - 3.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 7.3" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
							{
								skip = true;
								cout << "Seventh Set - 3.2 = HIT" << endl;

							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y--;
								moved = true;
								cout << "Seventh Set - 3.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check Second Direction
			// 3 = LEFT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x - 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Seventh Set - 4.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 7.4" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
							{
								cout << "Seventh Set - 4.2 = HIT" << endl;
								skip = true;

							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x--;
								moved = true;
								cout << "Seventh Set - 4.3 = MOVED" << endl;
							}

						}
					}
				}
			}
		}
		else if (optimal_directions[0] == 4 && optimal_directions[1] == 1 && optimal_directions[2] == 2 && optimal_directions[3] == 3)
		{
			cout << "8 Set" << endl;
			//Check Third Direction
			// 4 = RIGHT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x + 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Eight Set - 12.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 8.1" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x + 1) && ((*coor_iter)->get_y() == m_y))
							{
								cout << "Eight Set - 2.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x++;
								moved = true;
								cout << "Eight Set - 2.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check First Direction
			// 1 = UP
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y - 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Eight Set - 2.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 8.2" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y - 1) && ((*coor_iter)->get_x() == m_x))
							{
								cout << "Eight Set - 2.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y--;
								moved = true;
								cout << "Eight Set - 2.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check First Direction
			// 2 = DOWN
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_Y() == m_y + 1) && ((*iter)->GameObject_X() == m_x))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Eight Set - 3.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_y++;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 8.3" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_y() == m_y + 1) && ((*coor_iter)->get_x() == m_x))
							{
								cout << "Eight Set - 3.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_y++;
								moved = true;
								cout << "Eight Set - 3.3 = MOVED" << endl;
							}

						}
					}
				}
			}

			//Check Second Direction
			// 3 = LEFT
			if (moved != true)
			{
				skip == false;

				//Check if any our objects are on the point we want to add
				for (iter = listOfObjects.begin(); iter != listOfObjects.end(); iter++)
				{
					if (((*iter)->GameObject_X() == m_x - 1) && ((*iter)->GameObject_Y() == m_y))
					{
						skip == true;//Found object in our way - No need check Pathfinder
						cout << "Eight Set - 4.1 = HIT" << endl;
					}
				}

				//Check if our paths is on the pojt we want to move to
				if (skip != true)
				{
					if (listOfCoordinates.empty())
					{
						m_x--;
						moved = true;
						cout << "COORDINATES EMTPY - MOVED 8.4" << endl;
					}
					else
					{
						for (coor_iter = listOfCoordinates.begin(); coor_iter != listOfCoordinates.end(); coor_iter++)
						{
							if (((*coor_iter)->get_x() == m_x - 1) && ((*coor_iter)->get_y() == m_y))
							{
								cout << "Eight Set - 4.2 = HIT" << endl;
								skip = true;
							}

							else if ((coor_iter != listOfCoordinates.end()) && (next(coor_iter) == listOfCoordinates.end()) && skip != true)
							{
								m_x--;
								moved = true;
								cout << "Eight Set - 4.3 = Moved" << endl;
							}

						}
					}
				}
			}
		}
