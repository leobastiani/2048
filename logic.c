#include "2048.h"

int new_block(int create) {
	int i, j;
	int numzeros = 0;
	int pos;
	int value; // valor do bloco

	for(i=0; i < 4; i++) {
		for(j=0; j < 4; j++) {
			if(game.tabuleiro[i][j] == 0) numzeros++;
		}
	}

	if(!numzeros || !create) return numzeros;
	
	pos = rand() % numzeros;
	value = (rand() % 10) ? 2 : 4; // 10% de chance de cair um 4

	int count_zeros = 0;
	i = 0;
	while(count_zeros != pos || game.tabuleiro[i/4][i%4] != 0) {
		if(game.tabuleiro[i/4][i%4] == 0) count_zeros++;
		i++;
	}
	
	game.tabuleiro[i/4][i%4] = value;

	animation_newblock(i/4, i%4);

	return numzeros;
}

void win() {
	game.win = 1;
	system("clear");
	puts("Parabens!!\n");
	getchar();
}

int move_block(int i, int j, int x, int y, int execute) {
	int newi, newj;

	newi = i+y;
	newj = j+x;

	if(newi < 0 || newi >= 4) return 0; // nao pode escapar do tabuleiro
	if(newj < 0 || newj >= 4) return 0;

	if(game.tabuleiro[newi][newj] == 0) {
		if(!execute) return 1;
		game.tabuleiro[newi][newj] = game.tabuleiro[i][j];
		game.tabuleiro[i][j] = 0;
		move_block(newi, newj, x, y, execute);
		return 1;
	} else if(game.tabuleiro[newi][newj] == game.tabuleiro[i][j]) {
		if(combinated[newi][newj]) { // combina duas vezes
			return 0;
		} else if(!execute) {
			return 1;
		}
		combinated[newi][newj] = 1;
		game.tabuleiro[newi][newj] = 2*game.tabuleiro[i][j];
		game.score += game.tabuleiro[newi][newj];
		game.tabuleiro[i][j] = 0;
		if(game.tabuleiro[newi][newj] == 2048 && game.win == 0) {
			win();
		}
		return 1;
	}

	return 0;
}

void clear_combinated() {
	int i, j;
	for(i=0;i<4;i++) {
		for(j=0;j<4;j++) {
			combinated[i][j] = 0;
		}
	}
}

void set_line_col(int line[], int col[], int x, int y) {
	int i;
	if(y == 1) { // de baixo para cima
		for(i=4; i>0; i--) line[4-i] = i-1;
	} else { // de cima para baixo
		for(i=0; i<4; i++) line[i] = i;
	}
	
	if(x == 1) { // da direita para a esquerda
		for(i=4; i>0; i--) col[4-i] = i-1;
	} else { // da esquerda para a direita
		for(i=0; i<4; i++) col[i] = i;
	}
}

int move(int dir, int execute) {
	int x = 0, y = 0, i, j; // coordenadas para andar
	int line[4], col[4];
	int nummoves = 0;
	switch(dir) {
		case KEY_RIGHT:
			x = 1;
			break;
		case KEY_LEFT:
			x = -1;
			break;
		case KEY_UP:
			y = -1;
			break;
		case KEY_DOWN:
			y = 1;
			break;
	}
	
	clear_combinated();
	set_line_col(line, col, x, y);
	
	for(i=0; i<4; i++) {
		int li;
		int co;
		for(j=0; j<4; j++) {
			li = line[i];
			co = col[j];
			if(game.tabuleiro[li][co]) {
				nummoves += move_block(li, co, x, y, execute); // retorna se mveu
			}
		}
	}

	return nummoves;
}

void undo_move() {
	if(game.turn > 0) {
		game = undo[(game.turn-1) % 20];
	}
	render();
	draw();
}

int endgame() {
	return	!( move(KEY_LEFT	, 0)
		|| move(KEY_UP		, 0)
		|| move(KEY_RIGHT	, 0)
		|| move(KEY_DOWN	, 0));
}
