#pragma once
#include"acllib.h"
#include<string.h>
#include<iostream>
class AutoSprite
{
	ACL_Image img;
	int x, y;
	int dx,dy;
	int width, height;
	char name[20];
public:
	AutoSprite();
	AutoSprite(AutoSprite& a);
	AutoSprite(const char n[20],int w, int h);
	~AutoSprite();
	void move();
	void drawImageScale(int w, int h);
};


