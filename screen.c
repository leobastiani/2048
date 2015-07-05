#include "2048.h"

int log_base2(int num) {
	int i = 0;
	while(num != 0) {
		num /= 2; 
		i++;
	}
	return i-1;
}

void write_str(int x, int y, char *str) {
	while(*str) {
		screen[x][y++] = *str++;
	}
}

void render_border(int x, int y, char border) {
	int i, j;
	i = x;
	j = y;

	for(j=y; j<y+7; j++) {
		screen[i][j] = border;
	}
	i++;

	j = y;
	while(i<=x+3) {
		screen[i][j] = border;
		screen[i][j+6] = border;
		i++;
	}

	for(j=y; j<y+7; j++) {
		screen[i][j] = border;
	}
}

void render_block(int x, int y, int number) {
	char str[5];
	char border;
	int i, j;


	if(number) {
		border = borders[(log_base2(number)-1) % numborders];
		sprintf(str, "%d", number);

		i = x+2;
		j = y+2;
		write_str(i, j, str);
	} else {
		border = '.';
	}

	render_border(x, y, border);
}

void render_line(int i) {
	int j;
	for(j=0; j<4; j++) {
		render_block(i*5, j*7, game.tabuleiro[i][j]);
	}
}


void clear() {
	int i, j;
	for(i = 0; i < 20; i++) {
		for(j = 0; j < 70; j++) {
			screen[i][j] = ' ';
		}
		screen[i][j] = '\n';
	}
	screen[i][j] = '\0';
}

void render_game() {
	int i;
	for(i=0;i<4;i++) {
		render_line(i);
	}
}

void render_score() {
	char str[9];
	sprintf(str, "%d", game.score);
	write_str(5, 40, "SCORE");
	write_str(6, 40, str);
}

void draw() {
	system("clear");
	printf("%s", (char *) screen);
}

void render() {
	clear();
	render_game();
	render_score();
}
