#include "2048.h"

int button() {
	char letter;
	char result = 0;
	while(!result) {
		letter = toupper(getchar()); // toupper pra deixar em maíscula
		switch(letter) {
			case 'D':
				result = KEY_RIGHT;
				break;
			case 'W':
				result = KEY_UP;
				break;
			case 'A':
				result = KEY_LEFT;
				break;
			case 'S':
				result = KEY_DOWN;
				break;
			case 'U':
				undo_move();
				break;
			case KEY_ESC:
				exit(0);
		}
	}
	return result;
}
