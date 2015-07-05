char screen[20][71];

struct Game {
	int tabuleiro[4][4];
	int score;
	char win;
	int turn;
};

struct Game game = {
	.tabuleiro = {
		0,	0,	0,	0,
		0,	0,	0,	0,
		0,	0,	0,	0,
		0,	0,	0,	0
	},
	.score = 0,
	.win = 0,
	.turn = 0
};
struct Game undo[20];

char combinated[4][4];

char borders[] = {'_', '#', '*', '%', '+', '\'', 'o', '^', '"', '-', '$'};
int numborders = 11;
