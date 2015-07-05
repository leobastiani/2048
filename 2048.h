#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

//---------------------------------------
// VARIABLES
//---------------------------------------
#define KEY_RIGHT	1
#define KEY_UP		2
#define KEY_LEFT	3
#define KEY_DOWN	4
#define KEY_ESC		27

extern char screen[20][71];

struct Game {
	int tabuleiro[4][4];
	int score;
	char win;
	int turn;
};

extern struct Game game;
extern struct Game undo[20];

extern char combinated[4][4];

extern char borders[11];
extern int numborders;

//---------------------------------------
// SCREEN
//---------------------------------------
int log_base2(int num);
void write_str(int x, int y, char *str);
void render_border(int x, int y, char border);
void render_number(int x, int y, int number);
void render_line(int x);
void clear();
void render_game();
void render_score();
void draw();
void render();
//---------------------------------------
// ANIMATION
//---------------------------------------
void clear_block(int x, int y);
void animation_newblock(int x, int y);
//---------------------------------------
// INPUT
//---------------------------------------
int button();
//---------------------------------------
// LOGIC
//---------------------------------------
int new_block(int create);
int move_block(int i, int j, int x, int y, int execute);
void clear_combinated();
void set_line_col(int line[], int col[], int x, int y);
int move(int dir, int execute);
void undo_move();
int endgame();
