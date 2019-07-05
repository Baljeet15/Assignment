#include<iostream>
#include<vector>
#define ROW 8
#define COL 8
#define PIECES 12
#define BLACKBOX 220
#define WHITEBOX 87
#define PKING 75
#define QKING 81
#define JUMP 2
#define INVALID 3
using namespace std;
enum Player
{
	PLAYERN,
	PLAYER1,
	PLAYER2
};
enum COLOR
{
	None,
	B,
	W
};
struct index
{
	bool occupied;
	Player P;
	COLOR C;
	bool canJump;
	bool isKing;
	index()
	{
		occupied = false;
		P = PLAYERN;
		C = None;
		canJump = true;
		isKing = false;
	}
};
class checkers
{
private:
	int countP1;
	int countP2;
	bool quitP1;
	vector<vector<struct index>>board;
	vector<int>row = { -2,-2,2,2 };
	vector<int>col = { -2,2,-2,2 };
	vector<int>rowA = { -1,-1,1,1 };
	vector<int>colA = { -1,1,-1,1 };
	vector<int>rowU = { -1,-2,-3,-4,-5,-6,-7 };
	vector<int>colR = { 1, 2, 3, 4, 5, 6, 7 };
public:
	checkers()
	{
		countP1 = PIECES;
		countP2 = PIECES;
		quitP1 = true;
		turn = PLAYER1;
		initboard();
	}
	Player turn;
	void resertboard();
	void initboard();
	void printboard();
	void play();
	bool isvalidmove(int x1, int y1, int x2, int y2);
	void movePlayer(int x1, int y1, int x2, int y2);
	bool isSafe(int x1, int y1);
	bool isJumpPossible();
	bool isValidKingMove(int x1, int y1, int x2, int y2);
	bool checkJumpForKing(int x1, int y1);
	bool checkJump(int x1, int y1, int i);
	bool isJump(int x1, int y1, int x2, int y2,pair<int,int>*direction);
	pair<int, int> jump(int x1, int y1, int x2, int y2, pair<int, int>* direction);
	int jumpUtil(int x1,int y1,int x2,int y2,vector<pair<int,int>>*v);	
	void jumpDirection(int i, vector<int>*Row, vector<int>*Col);
};

