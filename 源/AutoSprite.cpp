#include "AutoSprite.h"
AutoSprite::AutoSprite(AutoSprite &a) {
	x = a.x;
	width = a.width;
	y = a.y;
	height = a.height;
	dx = a.dx;
	dy = a.dy;
	strcpy_s(name, a.name);
	loadImage(name, &img);
}
AutoSprite::AutoSprite(const char n[20], int w, int h) {
	strcpy_s(name, n);
	loadImage(name, &img);
	width = w;
	height = h;
	x = rand() % w;
	dx = rand() % 30+10;
	y = rand() % h;
	dy = rand() % 30+10;
}
void AutoSprite::move() {
	x += dx;
	y += dy;
	if (x<0 || x>width - 100)
		dx *= -1;
	if (y<0 || y>height - 100)
		dy *= -1;
}
void AutoSprite::drawImageScale(int w, int h) {
	putImageScale(&img, x, y, w, h);
}