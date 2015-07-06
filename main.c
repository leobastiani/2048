#include "2048.h"

int main() {

	srand(time(0));
	
	setBufferedInput(false);

	// manual
	clearScreen();
	printf("Utilize para W, A, S e D para mover.\n");
	printf("Aperte U para voltar uma jogada.\n");
	printf("Aperte ESC para sair.\n");
	button();

	new_block(1); // cria um novo bloco
	while(!endgame()) { // enquanto não é o fim do jogo, faça
		new_block(1);
		render(); // renderiza o jogo
		draw(); // imprime o jogo

		undo[(game.turn) % 20] = game; // cópia de game em undo
		
		//insiste enquanto não moveu e é possível criar um novo bloco
		while(!move(button(), 1) && new_block(0)) {
			// nao faz nada
		}
		game.turn++;
	}

	// derrota
	render();
	draw();
	puts("Fim de jogo!");
	while(button()); // espero apertar o botao esc
	
	return 0;
}
