#include"checkers.h"

checkers *obj=NULL;
extern "C" void af_init()
{
	if(!obj)
	{
		obj=new checkers();
	}
}
extern "C" void af_play()
{
	if(obj)
	{
		obj->play();
	}
}
extern "C" void af_display()
{
	if (obj)
	{
		obj->printboard();
	}
}
extern "C" bool af_isValidMove(int x1,int y1,int x2,int y2)
{
	bool ret = false;
	if(obj)
	{
		ret = obj->isvalidmove(x1,y1,x2,y2);
	}
	return ret;
}
extern "C" void af_movePlayer(int x1, int y1, int x2, int y2)
{
	if (obj)
	{
		obj->movePlayer(x1, y1, x2, y2);
	}
	
}
extern "C" bool af_isJumpPossible()
{
	bool ret = false;
	if(obj)
	{
		ret = obj->isJumpPossible();
	}
	return ret;
}
extern "C" int af_jumpUtil(int x1,int y1,int x2,int y2, vector<pair<int, int>>* v)
{
	int ret =0;
	if (obj)
	{
		ret = obj->jumpUtil(x1,y1,x2,y2,v);
	}
	return ret;
}
extern "C" void af_setTurn(Player i)
{	
	if(obj)
	{
		obj->turn=i;
	}
}
extern "C" void af_release()
{
	if(obj)
	{
		delete obj;
		obj=NULL;
	}
}

