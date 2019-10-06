#include"AutoSprite.h"
#include"acllib.h"
const int w = 640, h = 320;
int x = 0, y = 100;
int dist = 5;
const int width = 100, height = 200, mWheight = 480, mWwidth = 640;
void keyEvent(int key, int event);
void mouseEvent(int x, int u, int botton, int event);
void paint();
int d = 0;
ACL_Image img1;
AutoSprite *ap[10];
void timerEvent(int id);
int Setup() {
	initWindow("AutoSprites", 0, 0, w, h);
	loadImage("cat.jpg", &img1);
	registerKeyboardEvent(keyEvent);
	registerMouseEvent(mouseEvent);
	registerTimerEvent(timerEvent);
	startTimer(0, 50);
	startTimer(1, 500);
	paint();
	return 0;
}
void mouseEvent(int x, int y, int button, int event) {
	if (event != BUTTON_DOWN)return;
	if (button == LEFT_BUTTON)
	{
		::x = x;
		::y = y;
		paint();
	}
}
void paint() {
	beginPaint();
	clearDevice();
	putImageTransparent(&img1, x, y, width, height, WHITE);
	endPaint();
}
void keyEvent(int key, int event) {
	if (event != BUTTON_DOWN)return;
	switch (key) {
	case VK_LEFT:
		x -= dist;
		if (x <= 0)x = 0;
		break;
	case VK_RIGHT:
		x += dist;
		if (x > mWwidth - width)
			x = mWwidth - width;
		break;
	case VK_UP:
		y -= dist;
		if (y <= 0)
			y = 0;
		break;
	case VK_DOWN:
		y += dist;
		if (y >= mWheight - height)
			y = mWheight - height;
		break;
	default:break;
	}
	paint();
}
void timerEvent(int id) {
	switch (id) {
	case 0:
		if (d >= 10) return;
		ap[d] = new AutoSprite("dog.jpg", w, h);
		d++;
		break;
	case 1:
		beginPaint();
		clearDevice();
		for (int i = 0; i < d; i++) {
			ap[i]->move();
			ap[i]->drawImageScale(100, 100);

		}
		endPaint(); break;
	}
}
