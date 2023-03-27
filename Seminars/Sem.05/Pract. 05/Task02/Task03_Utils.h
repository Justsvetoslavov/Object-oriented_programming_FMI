#pragma once
#include "Task03_Game.h"

void myStrCpy(char *, const char *);
int myStrLen(const char *);
void resize(char *&, const int);
void resize(Game *&, const int, const int, bool);
bool myStrCmp(const char *, const char *);
void gamesCpy(Game *, const Game *, int);
int strToInt(const char *);
