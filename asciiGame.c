#include "asciiGame.h"
#include "padroes.c"
#include "fase.c"
#include "splashScreen.c"


//Aloca background necessario para a matriz e coloca um background em cada local
Game limpaMatriz(Game game){
	int x, y;

	//Alocar memoria para uma matriz
	game.map.valor = mallocc(game.map.x * sizeof(char *));
	for(x = 0; x <= game.map.x; x++){
		game.map.valor[x] = mallocc(game.map.y * sizeof(char));
		for(y = 0; y < game.map.y; y++){
				game.map.valor[x][y] = ' ';
		}
	}
	return game;
}

//Verifica se o jogador esta em cima do Coin
Game verificaPonto(Game game){
	if(game.player.posx == game.coin.x && game.player.posy == game.coin.y){
		game.coins++;
		game = insereObjeto(game);
	}
	return game;
}

//O personagem anda para direita(verificando se nao e uma parece e se ele marcou um ponto)
Game andaDireita(Game game){
	if(game.map.valor[game.player.posx][game.player.posy+1] != game.map.wall){
		game.map.valor[game.player.posx][game.player.posy] = game.background;
		game.map.valor[game.player.posx][game.player.posy+1] = game.player.name;
		game.player.posy++;
		game = verificaPonto(game);
	}
	return game;
}

//O personagem anda para esquerda(verificando se nao e uma parece e se ele marcou um ponto)
Game andaEsquerda(Game game){
	if(game.map.valor[game.player.posx][game.player.posy-1] != game.map.wall){
		game.map.valor[game.player.posx][game.player.posy] = game.background;
		game.map.valor[game.player.posx][game.player.posy-1] = game.player.name;
		game.player.posy--;
		game = verificaPonto(game);
	}
	return game;
}

//O personagem anda para baixo(verificando se nao e uma parece e se ele marcou um ponto)
Game andaBaixo(Game game){
	if(game.map.valor[game.player.posx+1][game.player.posy] != game.map.wall){
		game.map.valor[game.player.posx][game.player.posy] = game.background;
		game.map.valor[game.player.posx+1][game.player.posy] = game.player.name;
		game.player.posx++;
		game = verificaPonto(game);
	}
	return game;
}

//O personagem anda para cima(verificando se nao e uma parece e se ele marcou um ponto)
Game andaCima(Game game){
	if(game.map.valor[game.player.posx-1][game.player.posy] != game.map.wall){
		game.map.valor[game.player.posx][game.player.posy] = game.background;
		game.map.valor[game.player.posx-1][game.player.posy] = game.player.name;
		game.player.posx--;
		game = verificaPonto(game);
	}
	return game;
}

//Le acao do usuario chama a funcao que faz ele andar
Game lerAcao(Game game, int tecla){ 

	if(game.player.posx == game.enemy.x && game.player.posy == game.enemy.y)
		game.background = game.enemy.name;
	else
		game.background = ' ';
	
	if(tecla == KEY_RIGHT){
		game = andaDireita(game);

	} else if(tecla == KEY_LEFT){
		game = andaEsquerda(game);

	} else if(tecla == KEY_DOWN){
		game = andaBaixo(game);

	} else if(tecla == KEY_UP){
		game = andaCima(game);
	}

	if(game.player.posx == game.enemy.x && game.player.posy == game.enemy.y )
		game.map.valor[game.player.posx][game.player.posy] = '@';

	return game;
}	

int main(){
	Map map;
	map.wall = 'X';
	int ch = 42; //qualquer tecla
	int cont = 0;
	
	Coin coin;	
	coin.name = '#';

	Player player;
	player.posx = 1;
	player.posy = 1;
	player.life = 3;
	player.name = 'o'; 

	Enemy enemy;
	enemy.x = 10;
	enemy.y = 16;
	enemy.name = '*';
	enemy.difficulty = 0;

	Game game;
	game.map = map;
	game.player = player;
	game.coins = 0;
	game.enemy = enemy;
	game.coin = coin;
	game.background = ' ';

	initscr();					/* Start curses mode 		*/
	raw();						/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();					/* Don't echo() while we do getch */
	initCores();
	
	printSplash();
		
	game = iniciaFase1(game);

	do{
		
		
		game = update(game, ch);

		if(game.coins == 3 && cont == 0){	
			printw("Ganhou! - Vamos para level 2!\n");
			getch();
			cont++;
			refresh();
			game = iniciaFase2(game);
			game = update(game, ch);

		} else if(game.coins == 1 && cont == 0){
			//printw("Ganhou! - Vamos para level 3!\n");
			getch();
			cont++;
			refresh();
			game = iniciaFase3(game);
			game = update(game, ch);
		}
 
	}while ((ch = getch()) != 'c');

	
	endwin();			

	return 0;
}
