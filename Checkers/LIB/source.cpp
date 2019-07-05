#include "source.h"
void checkers::resertboard()
{
	for (int i = 0; i < ROW; i++)
	{
		board[i].clear();		
	}
	board.clear();
}
void checkers::initboard()
{   
	int count = 1;
	for (int i = 0; i < ROW; i++)
	{
		vector<struct index>temp;
		for (int j = 0; j < COL; j++)
		{
			struct index in;	
			if ((((i & 1) == 0) && (j & 1)) || ((i & 1) && ((j & 1) == 0)))
			{
				in.C = B;
				if (count <= PIECES)
				{
					if (i <= 2)
					{
						in.P = PLAYER2;
						in.occupied = true;
						count++;
					}
					else if (i > 2 && i < 5)
					{
						in.P = PLAYERN;
						in.occupied = false;
					}
					if (i >= 5)
					{
						in.P = PLAYER1;
						in.occupied = true;
						count++;
					}
				}
			}
			else
				in.C = W;
			temp.push_back(in);
		}
		board.push_back(temp);
		temp.clear();
		if (i == 3)
		{
			count = 1;
		}
	}
}
void checkers::printboard()
{
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "PLAYER1       1"<<endl;
	cout << "PLAYER2       2"<<endl;
	cout << "PLAYER1 KING  K"<<endl;
	cout << "PLAYER2 KING  Q"<<endl;
	cout << "WHITE CELL    W"<<endl;
	cout << "BLACK CELL    "<<(char)BLACKBOX<<endl;
	cout << endl;
	cout << endl;
	cout << endl;
	cout << "                  PLAYER 2" << endl << endl;
	cout << "            1  2  3  4  5  6  7  8  " << endl << endl;
	cout << "         -------------------------  " << endl;
	cout << "        |" << endl;
	for (int i = 0; i < ROW; i++)
	{
		cout << "      " << i + 1 << " |   ";

		for (int j = 0; j < COL; j++)
		{

			if (board[i][j].C == B)
			{
				if (board[i][j].occupied)
				{
					if (board[i][j].P == PLAYER1)
					{
						if (board[i][j].isKing)
							cout << (char)PKING << "  ";
						else
							cout << "1  ";
					}
					else
					{
						if (board[i][j].isKing)
							cout << (char)QKING << "  ";
						else
							cout << "2  ";
					}
				}
				else
					cout << (char)BLACKBOX << "  ";
			}
			else
				cout << (char)WHITEBOX << "  ";
		}
		cout << endl;
		cout << endl;
	}
	cout << "         -------------------------  " << endl;
	cout << "            1  2  3  4  5  6  7  8  " << endl << endl;
	cout << "                 PLAYER 1" << endl << endl << endl;
}
bool checkers::isValidKingMove(int x1, int y1, int x2, int y2)
{
	if (!isSafe(x1, y1) && !isSafe(x2, y2))
		return false;
	if (((x1 - x2 == 1) && (y1 - y2 == 1)) || ((x1 - x2 == -1) && (y1 - y2 == -1)) ||
		((x1 - x2 == 2) && (y1 - y2 == 2)) || ((x1 - x2 == -2) && (y1 - y2 == -2)) ||
		((x1 - x2 == 3) && (y1 - y2 == 3)) || ((x1 - x2 == -3) && (y1 - y2 == -3)) ||
		((x1 - x2 == 4) && (y1 - y2 == 4)) || ((x1 - x2 == -4) && (y1 - y2 == -4)) ||
		((x1 - x2 == 5) && (y1 - y2 == 5)) || ((x1 - x2 == -5) && (y1 - y2 == -5)) ||
		((x1 - x2 == 6) && (y1 - y2 == 6)) || ((x1 - x2 == -6) && (y1 - y2 == -6)) ||
		((x1 - x2 == 7) && (y1 - y2 == 7)) || ((x1 - x2 == -7) && (y1 - y2 == -7)) ||
		((x1 - x2 == 1) && (y1 - y2 == -1)) || ((x1 - x2 == -1) && (y1 - y2 == 1)) ||
		((x1 - x2 == 2) && (y1 - y2 == -2)) || ((x1 - x2 == -2) && (y1 - y2 == 2)) ||
		((x1 - x2 == 3) && (y1 - y2 == -3)) || ((x1 - x2 == -3) && (y1 - y2 == 3)) ||
		((x1 - x2 == 4) && (y1 - y2 == -4)) || ((x1 - x2 == -4) && (y1 - y2 == 4)) ||
		((x1 - x2 == 5) && (y1 - y2 == -5)) || ((x1 - x2 == -5) && (y1 - y2 == 5)) ||
		((x1 - x2 == 6) && (y1 - y2 == -6)) || ((x1 - x2 == -6) && (y1 - y2 == 6)) ||
		((x1 - x2 == 7) && (y1 - y2 == -7)) || ((x1 - x2 == -7) && (y1 - y2 == 7)))
		return true;
	else
		return false;
}
bool checkers::isvalidmove(int x1, int y1, int x2, int y2)
{
	bool result = false;
	if (!isSafe(x1, y1) || !isSafe(x2, y2))
		return false;
	if (board[x1][y1].C == B && board[x1][y1].P == turn && board[x2][y2].occupied == false && board[x2][y2].C == B)
	{
		if (turn == PLAYER1)
		{
			if (board[x1][y1].isKing)
			{
				if (isValidKingMove(x1,y1,x2,y2))
					return true;
				else
					return false;				
			}
			else
			{
				if ((y1 == 0 || (y1 == COL - 1)) && (x2 == (x1 - 1)))
				{
					result = true;
				}
				else if (((y2 == y1 - 1) || (y2 == y1 + 1)) && (x2 == (x1 - 1)))
				{
					result = true;
				}
				else
					result = false;
			}
		}
		else if (turn == PLAYER2)
		{
			if (board[x1][y1].isKing)
			{
				if (isValidKingMove(x1, y1, x2, y2))
					return true;
				else
					return false;
			}
			else
			{
				if ((y1 == 0 || (y1 == COL - 1)) && (x2 == (x1 + 1)))
				{
					result = true;
				}
				else if (((y2 == y1 - 1) || (y2 == y1 + 1)) && (x2 == (x1 + 1)))
				{
					result = true;
				}
				else
					result = false;
			}
		}
	}
	else
		result = false;
	return result;
}
bool checkers::isSafe(int x1, int y1)
{
	if ((x1 >= 0 && x1 < ROW) && (y1 >= 0 && y1 < COL))
		return true;
	else
		return false;
}
void checkers::movePlayer(int x1, int y1, int x2, int y2)
{
	board[x1][y1].occupied = false;
	board[x1][y1].P = PLAYERN;
	board[x2][y2].occupied = true;
	board[x2][y2].P = turn;

	if ((board[x2][y2].P == PLAYER1 && x2 == 0) || board[x1][y1].isKing)
		board[x2][y2].isKing = true;
	else if ((board[x2][y2].P == PLAYER2 && x2 == ROW - 1 )|| board[x1][y1].isKing)
		board[x2][y2].isKing = true;
	board[x1][y1].isKing = false;
}
bool checkers::checkJump(int x1, int y1,int i)
{
	bool t1 = isSafe(x1 + row[i], y1 + col[i]);
	bool t2 = isSafe(x1 + rowA[i], y1 + colA[i]);
	if (t1 && t2 && board[x1 + rowA[i]][y1 + colA[i]].canJump &&
		board[x1 + rowA[i]][y1 + colA[i]].occupied &&
		board[x1 + rowA[i]][y1 + colA[i]].P != turn &&
		!board[x1 + row[i]][y1 + col[i]].occupied)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void checkers::jumpDirection(int i,vector<int>*vecR,vector<int>*vecC)
{
	switch (i)
	{
	case 0:
		*vecR = rowU;
		*vecC = colR;
		break;
	case 1:
		*vecR = colR;
		*vecC = colR;
		break;
	case 2:
		*vecR = rowU;
		*vecC = rowU;
		break;
	case 3:
		*vecR = colR;
		*vecC = rowU;
		break;
	}
}
bool checkers::isJump(int x1, int y1, int x2, int y2,pair<int,int> *direction)
{
	bool opponentFound = false;
	int x3, y3;
	int directions = ROW / 2;
	vector<int> vecR ;
	vector<int> vecC ;
	if (!isSafe(x1, y1))
		return false;
	if (board[x1][y1].isKing)
	{
		for (int k = 0; k < directions; k++)
		{
			opponentFound = false;
			jumpDirection(k, &vecR, &vecC);
			int i;
			for (i = 0; i < rowU.size(); i++)
			{
				x3 = x1 + vecR[i];
				y3 = y1 + vecC[i];
				if (isSafe(x3, y3) && board[x3][y3].occupied && board[x3][y3].P != turn)
				{
					if (!board[x3][y3].canJump)
						break;
					else if (board[x3][y3].canJump)
					{
						opponentFound = true;
						break;
					}
				}
			}
			if (opponentFound)
			{
				int j;
				for (j = i + 1; j < rowU.size(); j++)
				{
						bool x4 = ((x1 + vecR[j]) == x2);
						bool y4 = ((y1 + vecC[j]) == y2);
						if (isSafe(x2, y2) && board[x2][y2].occupied)
							break;
						if (x4 && y4 && isSafe(x2, y2) && !board[x2][y2].occupied)
						{
							*direction = make_pair(x3,y3);
							return true;
						}
				}
			}
			opponentFound = false;
		}
	}
	for (int i = 0; i < row.size(); i++)
	{
		bool t1 = ((x1 + row[i]) == x2);
		bool t2 = ((y1 + col[i]) == y2);
		bool t3 = checkJump(x1,y1,i) ;

		if ( t1 && t2 && t3)
		{
			int nextx;
			int nexty;
			nextx = (row[i] < 0 )? (row[i] + 1) : (row[i] - 1);
			nexty = (col[i] < 0) ? (col[i] + 1) : (col[i] - 1);
			*direction = make_pair(x1+nextx, y1+nexty);
			return true;
		}
	}
	return false;
};
bool checkers::checkJumpForKing(int x1, int y1)
{
	bool opponentFound = false;
	int x2, y2;
	int directions = ROW/2;
	vector<int>vecR;
	vector<int>vecC;
	if (!isSafe(x1, y1))
		return false;
	for (int k = 0 ;k< directions; k++)
	{
		opponentFound = false;
		jumpDirection(k, &vecR, &vecC);
		int i;
		for (i = 0; i < rowU.size(); i++)
		{
			x2 = x1 + vecR[i];
			y2 = y1 + vecC[i];
			if (isSafe(x2, y2) && board[x2][y2].occupied && board[x2][y2].P != turn)
			{
				if (!board[x2][y2].canJump)
					break;
				else if (board[x2][y2].canJump)
				{
					opponentFound = true;
					break;
				}
			}
		}
		if (opponentFound)
		{
			int j;
			for (j = i + 1; j < rowU.size(); j++)
			{
				x2 = x1 + vecR[j];
				y2 = y1 + vecC[j];
				if (isSafe(x2, y2) && board[x2][y2].occupied)
					break;
				if (isSafe(x2, y2) && !board[x2][y2].occupied)
					return true;
			}			
		}
		opponentFound = false;		
	}
	return false;
}
bool checkers::isJumpPossible()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (board[i][j].P == turn)
			{
				if (board[i][j].isKing)
				{
					if (checkJumpForKing(i, j))
					{
						return true;
					}
				}
				
				for (int k = 0; k < row.size(); k++)
				{
					if (checkJump(i, j, k))
					{
							return true;
					}
				}				
			}
		}
	}
	return false;
}
pair<int, int> checkers::jump(int x1, int y1, int x2, int y2,pair<int,int>*direction)
{
	pair<int, int>coord;
	int nextx;
	int nexty;
	nextx = (direction->first);
	nexty = (direction->second);
	
	board[x2][y2].occupied = true;
	board[x2][y2].P = turn;
	board[x1][y1].occupied = false;
	board[x1][y1].P = PLAYERN;
	board[nextx][nexty].canJump = false;
	if ((board[x2][y2].P == PLAYER1 && x2 == 0) ||(board[x1][y1].isKing))
		board[x2][y2].isKing = true;
	else if ((board[x2][y2].P == PLAYER2 && x2 == ROW - 1)|| (board[x1][y1].isKing))
		board[x2][y2].isKing = true;
	coord=make_pair(nextx, nexty);
	return coord;
}
int checkers::jumpUtil(int x1, int y1, int x2, int y2, vector<pair<int, int>>* v)
{
	pair<int, int> p;
	pair<int, int> nxt;
	if (isJump(x1, y1, x2, y2, &p))
	{
		nxt = jump(x1, y1, x2, y2, &p);
		v->push_back(nxt);
		return JUMP;
	}
	else
	  return INVALID;
}
void checkers::play()
{
	char c1, c2;
	int x1, y1, x2, y2;
	bool flag = true;
	vector<pair<int, int>>del;
	while (countP1 > 0 && countP2 > 0 && quitP1 )
	{
		if (flag)
			turn = PLAYER1;
		else
			turn = PLAYER2;
		cout << "Turn of Player " << turn << endl;
		cout << "Do you want to quit(Y or N)" << endl;
		cin >> c1;
		if (c1 == 'Y')
		{
			flag = !flag;
			turn = flag ? PLAYER1 : PLAYER2;
			cout << "Player " << turn << " Do you want to quit(Y or N)" << endl;
			cin >> c2;
			if (c2 == 'Y')
			{
				quitP1 = false;
				break;
			}
			else
			{
				cout << "Player " << turn << " Doesnt want to quit" << endl;
				flag = !flag;
				turn = flag ? PLAYER1 : PLAYER2;
			}
		}

		cout << "Player "<<turn<<" Enter your move ...choose the coordinate of piece to move " << endl;
		cin >> x1 >> y1;
		cout << "Choose the destination coordinate of the chosen piece" << endl;
		cin >> x2 >> y2;
        if(isJumpPossible())
		{
			int ret ;
			ret=jumpUtil(x1-1, y1-1, x2-1, y2-1, &del);
			if (ret == INVALID)
			{
				cout << "There is a jump possible..Try Again\n";
				continue;
			}
			else if (ret == JUMP)
			{
				int x3, y3;
				bool r ;
				int r3 = JUMP;
				do
				{
					if (board[x2-1][y2-1].isKing)
					{
						r = false;
						if (checkJumpForKing(x2 - 1, y2 - 1))
						{
							r = true;
							r3 = INVALID;
						}
						while (r3 == INVALID)
						{
							printboard();
							cout << "Jump Further\n";
							cout << "Enter the coordinate to jump" << endl;
							cin >> x3 >> y3;
							r3 = jumpUtil(x2 - 1, y2 - 1, x3 - 1, y3 - 1, &del);
							if (r3 == INVALID)
							{
								cout << "Invalid Jump " << endl;
							}
							else
							{
								x2 = x3;
								y2 = y3;
							}
						}						
				    }
					else
					{
						r = false;
						for (int i = 0; i < row.size(); i++)
						{
							if (checkJump(x2 - 1, y2 - 1, i))
							{
								r = true;
								r3 = INVALID;
								break;
							}
						}
						while (r3 == INVALID)
						{
							printboard();
							cout << "Jump Further\n";
							cout << "Enter the coordinate to jump" << endl;
							cin >> x3 >> y3;
							r3 = jumpUtil(x2 - 1, y2 - 1, x3 - 1, y3 - 1, &del);
							if (r3 == INVALID)
							{
								cout << "Invalid Jump " << endl;
							}
							else
							{
								x2 = x3;
								y2 = y3;
							}
						}
					}
				} while (r);
				cout << del.size();
				for (int it = 0; it < del.size(); it++)
				{
					int x = del[it].first;
					int y = del[it].second;
					if (board[x][y].P == PLAYER1)
						countP1--;
					else
						countP2--;
					board[x][y].canJump = true;
					board[x][y].occupied = false;
					board[x][y].P = PLAYERN;
					board[x][y].isKing = false;
				}
				del.clear();
			}				
		}
		else
		{
			if (isvalidmove(x1 - 1, y1 - 1, x2 - 1, y2 - 1) == false)
			{
				cout << endl << endl;
				cout << "Invalid move\n";
				printboard();
				continue;
			}
			else
			{
				movePlayer(x1 - 1, y1 - 1, x2 - 1, y2 - 1);
			}
		}
		printboard();
		flag = !flag;
	}
	if (!quitP1)
	{
		cout << "The Players quit" << endl;
		return;
	}
	if (countP1 > 0)
		cout << "Player 1 Wins and Player 2 Looses\n";
	else if (countP2 > 0)
		cout << "Player 2 Wins and Player 1 Looses\n";
}

