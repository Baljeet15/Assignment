#include "checkers.h"
#include<iostream>
#include<vector>
using namespace std;

//Make a valid move for Player 1 to BlackBox
int test1()
{
	if(af_isValidMove(5,2,4,3))
		return 1;
	else 
		return 0;
}
//Make an invalid move for Player 1 to WhiteBox
int test2()
{
	if(!af_isValidMove(5,0,5,1))
		return 1;
	else 
		return 0;
}
//Check if a jump is possible for Player 1
int test3()
{
		if(!(af_isJumpPossible()))
			return 1;
		else
			return 0;
}
//Choose an invalid location to move from
int test4()
{
		if(!(af_isValidMove(45,1,9,7)))
			return 1;
		else
			return 0;
}
//Choose the PIECE of Player 2, when the turn is of Player 1
int test5()
{
        if(!(af_isValidMove(2,1,3,2)))
			return 1;
		else
			return 0;
}
int test6()
{
        af_movePlayer(5,2,4,3);
		af_setTurn(PLAYER2);
		af_movePlayer(2,3,3,4);
		af_setTurn(PLAYER1);
		af_movePlayer(5,6,4,7);
		af_setTurn(PLAYER2);
		if(af_isJumpPossible())
			return 1;
		else
			return 0;
}
int test7()
{
	    vector<pair<int, int>>v;
		af_release();
		af_init();
		af_setTurn(PLAYER1);
		af_movePlayer(5, 2, 4, 3);
		af_setTurn(PLAYER2);
		af_movePlayer(2, 3, 3, 4);
		af_setTurn(PLAYER1);
		af_movePlayer(5, 6, 4, 7);
		af_setTurn(PLAYER2);
		if((af_jumpUtil(3,4,5,2,&v))==JUMP)
			return 1;
		else
			return 0;
}
int test8()
{
	vector<pair<int, int>>v;
	af_release();
	af_init();
	af_setTurn(PLAYER1);
	af_movePlayer(5, 2, 4, 3);
	af_setTurn(PLAYER2);
	af_movePlayer(2, 3, 3, 4);
	af_setTurn(PLAYER1);
	af_movePlayer(5, 6, 4, 7);
	af_setTurn(PLAYER2);
		if((af_jumpUtil(3,4,4,5,&v))==INVALID)
			return 1;
		else
			return 0;
}
int main()
{
	int pass = 0;
	int fail=0;
    vector<int>indexF;
	af_init();
	af_display();
       if(test1())
                pass++;
        else
        {
                indexF.push_back(1);
                fail++;
        }
        if(test2())
                pass++;
        else
        {
                fail++;
                indexF.push_back(2);
        }
        if(test3())
                pass++;
        else
        {
                fail++;
                indexF.push_back(3);
        }
        if(test4())
                pass++;
        else
        {
                fail++;
                indexF.push_back(4);
        }
        if(test5())
                pass++;
        else
        {
                fail++;
                indexF.push_back(5);
        }
        if(test6())
                pass++;
        else
        {
                fail++;
                indexF.push_back(6);
        }
      if(test7())
                pass++;
        else
        {
                fail++;
                indexF.push_back(7);
        }
        if(test8())
                pass++;
        else
        {
                fail++;
                indexF.push_back(8);
        }
		cout << endl;
        cout<<pass<<" "<<"Test Cases Passed\n";
        cout<<fail<<" "<<"Test Cases Failed\n";
		cout << endl;
        for(int i=0;i<indexF.size();i++)
        {
                cout<<"Test Case "<<indexF[i]<<"  Failed"<<endl;
        }
		cout << endl;
		af_release();
}
