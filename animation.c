#include "2048.h"

void clear_block(int x, int y) {
	int i, j;
	for(i=x;i<x+5;i++) {
		for(j=y;j<y+7;j++) {
			screen[i][j] = ' ';
		}
	}
}

void animation_newblock(int i, int j) {
	int x, y;
	int frame;

	x = i*5;
	y = j*7;
	
	render();
	draw();
	
	for(frame=0;frame<4;frame++) {
		int incx, incy;
		clear_block(x, y);
		switch(frame) {
			case 0:
				incx = 2;
				incy = 3;
				break;
			case 1:
				incx = 1;
				incy = 2;
				break;
			case 2:
				incx = 1;
				incy = 1;
				break;
			case 3:
				incx = 0;
				incy = 0;
				break;
		}

		screen[x+incx][y+incy] = '#';
		screen[x+incx][y+(6-incy)] = '#';
		screen[x+(4-incx)][y+(6-incy)] = '#';
		screen[x+(4-incx)][y+incy] = '#';
		draw();
		usleep(40000);
	}
}
