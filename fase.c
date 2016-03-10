#include "fase.h"

Game insereJogador(Game game){
	game.map.valor[game.player.posx][game.player.posy] = game.player.name;


	return game;
}

Game desenhaFase1(Game game, int x, int y){

	if(x == 0 || y == (game.map.y-1) || x == (game.map.x-1) || y == 0) //PAREDES
		game.map.valor[x][y] = game.map.wall;

	return game;
}

Game desenhaFase2(Game game, int x, int y){

	if(y == (game.map.y / 2) - x || x == (game.map.x-1) || y == (game.map.y / 2) + x) //PAREDES
		game.map.valor[x][y] = game.map.wall;

	return game;
}

Game desenhaFase3(Game game, int x, int y){

	desenhaFase1(game, x, y);//Desenha o limite do map
	//MAIOR IF DO MUNDO!!!!!
	if((y == 5 && x < 17) || (y == 10 && (x >= 5 || x <= 2)) || (x == 10 && (y >= 15 && y <= 20)) || (y == 20 && (x < 15 && x > 10)) || 
		(x == 15 && (y >= 15 && y <= 20)) || (y == 15 && x > 15 ) || (x == 5 && y > 18) || (y == 18 && (x <= 5 && x > 2)) ||
		(y == 20 && x < 3) || (y == 23 && (x <= 12 && x >= 2)) || (y == 26 && x < 3) || ((y > 7 && y < 13) && x == 12) ||
		(x == 3 && (y > 2 && y < 7)) || (x == 16 && (y > 2 && y < 8)) || (y == 15 && x < 7) || (x == 8 && y < 3)) //Labirinto
		game.map.valor[x][y] = game.map.wall;

	

	return game;
}

//Desenha o map com o personagem e as walls
//x = linha 
//y = coluna
Game desenhaCampo(Game game){
	int x, y;

	for(x = 0; x < game.map.x; x++){
		for(y = 0; y < game.map.y; y++){	
			attron(COLOR_PAIR(2));

			if(game.map.valor[x][y] == game.map.wall){
				attron(COLOR_PAIR(4));
				if(x != 0)
					printw("%c ", game.map.valor[x][y]);
				else
					printw("%c ", game.map.valor[x][y]);
				attroff(COLOR_PAIR(4));
			}else
				printw("%c ", game.map.valor[x][y]);


			if(game.level == 1)
				game = desenhaFase1(game, x, y);

			if(game.level == 2)
				game = desenhaFase2(game, x, y);

			if(game.level == 3)
				game = desenhaFase3(game, x, y);

		}
		printw("\n");
	}

	return game;
}



//insere o Coin dentro do Map em uma posicao aleatoria
// c + l >= 21 && c - l <= 19  
//TO - DO : falta verificar este caso: l < ? && l >= 2
//c <= 38 && c >= 2
Game insereObjeto(Game game){
	int x, y;

	if(game.level == 1){

		do{
			srand (time(NULL));
			x = (rand() % (game.map.x-2)) + 1;//coluna
			y = (rand() % (game.map.y-2)) + 1;//linha

		} while (game.player.posx == x && game.player.posy == y);

	} else if(game.level == 2){

		do{
			srand (time(NULL));
			x = (rand() % (game.map.x-2)) + 2;//coluna
			y = (rand() % (game.map.y-2)) + 1;//linha

		} while (x + y < 21 || x - y > 20);

	} else if(game.level == 3){

		do{
			srand (time(NULL));
			x = (rand() % (game.map.x-2)) + 2;//coluna
			y = (rand() % (game.map.y-2)) + 1;//linha

		} while (x + y < 21 || x - y > 20);
	}
	
	game.coin.x = x;
	game.coin.y = y;

	game.map.valor[x][y] = game.coin.name;
	return game;
}

Game iniciaFase1(Game game){
	game.map.x = 20;
	game.map.y = 30;
	game.level = 1;
	game.player.posx = 1;
	game.player.posy = 1;

	clear();

	game = limpaMatriz(game);
	game = insereObjeto(game);
	game = desenhaCampo(game);

	return game;
}

Game iniciaFase2(Game game){
	game.map.x = 21;
	game.map.y = 40;
	game.level = 2;
	game.player.posx = 10;
	game.player.posy = 20;

	clear();

	game = limpaMatriz(game);
	game = insereObjeto(game);
	game = desenhaCampo(game);

	return game;
}

Game iniciaFase3(Game game){
	game.map.x = 20;
	game.map.y = 30;
	game.level = 3;
	game.player.posx = 2;
	game.player.posy = 2;

	clear();

	game = limpaMatriz(game);
	game = insereObjeto(game);
	game = desenhaCampo(game);

	return game;
}


void desenhaCabecalho(Game game){
	attron(COLOR_PAIR(1));
	printw("\t\t\tPontuacao = %d\n", game.coins);
	attroff(COLOR_PAIR(1));
	desenhaLife(game.player.life);
}

Game update(Game game, int ch){
	game.enemy.difficulty = 0;
	
	clear();
	desenhaCabecalho(game);

	game = insereJogador(game);
	

	if(game.enemy.difficulty < 70)
		game = moverIni(game);
	

	game = lerAcao(game, ch);
	game = desenhaCampo(game);

	//TO - DO : criar funcao que modifica estas varaintes do enemy
	srand (time(NULL));
	game.enemy.difficulty = rand() % 100;

	if(verificaColisao(game)){
		game.player.life--;
		if(game.player.life == -1){
			printw("\n\t\t\tGAME OVER...");
			getch();
			endwin();
			exit(EXIT_FAILURE);
		}
	}
	
	refresh();

	return game;
}
