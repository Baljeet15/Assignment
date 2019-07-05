#include "source.h"
extern "C"
{
void af_init();
void af_play();
void af_release();
bool af_isValidMove(int x1, int y1, int x2, int y2);
bool af_isJumpPossible();
void af_setTurn(Player i);
void af_movePlayer(int x1, int y1, int x2, int y2);
int af_jumpUtil(int x1, int y1, int x2, int y2, vector<pair<int, int>>* v);
void af_display();
}
