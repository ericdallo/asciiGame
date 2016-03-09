#include "fase.h"

Game insereJogador(Game jogo){
	jogo.map.valor[jogo.player.posx][jogo.player.posy] = jogo.player.name;


	return jogo;
}

Game desenhaFase1(Game jogo, int x, int y){

	if(x == 0 || y == (jogo.map.y-1) || x == (jogo.map.x-1) || y == 0) //PAREDES
		jogo.map.valor[x][y] = jogo.map.wall;

	return jogo;
}

Game desenhaFase2(Game jogo, int x, int y){

	if(y == (jogo.map.y / 2) - x || x == (jogo.map.x-1) || y == (jogo.map.y / 2) + x) //PAREDES
		jogo.map.valor[x][y] = jogo.map.wall;

	return jogo;
}

Game desenhaFase3(Game jogo, int x, int y){

	desenhaFase1(jogo, x, y);//Desenha o limite do map
	//MAIOR IF DO MUNDO!!!!!
	if((y == 5 && x < 17) || (y == 10 && (x >= 5 || x <= 2)) || (x == 10 && (y >= 15 && y <= 20)) || (y == 20 && (x < 15 && x > 10)) || 
		(x == 15 && (y >= 15 && y <= 20)) || (y == 15 && x > 15 ) || (x == 5 && y > 18) || (y == 18 && (x <= 5 && x > 2)) ||
		(y == 20 && x < 3) || (y == 23 && (x <= 12 && x >= 2)) || (y == 26 && x < 3) || ((y > 7 && y < 13) && x == 12) ||
		(x == 3 && (y > 2 && y < 7)) || (x == 16 && (y > 2 && y < 8)) || (y == 15 && x < 7) || (x == 8 && y < 3)) //Labirinto
		jogo.map.valor[x][y] = jogo.map.wall;

	

	return jogo;
}

//Desenha o map com o personagem e as walls
//x = linha 
//y = coluna
Game desenhaCampo(Game jogo){
	int x, y;

	for(x = 0; x < jogo.map.x; x++){
		for(y = 0; y < jogo.map.y; y++){	
			attron(COLOR_PAIR(2));

			if(jogo.map.valor[x][y] == jogo.map.wall){
				attron(COLOR_PAIR(4));
				if(x != 0)
					printw("%c ", jogo.map.valor[x][y]);
				else
					printw("%c ", jogo.map.valor[x][y]);
				attroff(COLOR_PAIR(4));
			}else
				printw("%c ", jogo.map.valor[x][y]);


			if(jogo.level == 1)
				jogo = desenhaFase1(jogo, x, y);

			if(jogo.level == 2)
				jogo = desenhaFase2(jogo, x, y);

			if(jogo.level == 3)
				jogo = desenhaFase3(jogo, x, y);

		}
		printw("\n");
	}

	return jogo;
}



//insere o Coin dentro do Map em uma posicao aleatoria
// c + l >= 21 && c - l <= 19  
//TO - DO : falta verificar este caso: l < ? && l >= 2
//c <= 38 && c >= 2
Game insereObjeto(Game jogo){
	int x, y;

	if(jogo.level == 1){

		do{
			srand (time(NULL));
			x = (rand() % (jogo.map.x-2)) + 1;//coluna
			y = (rand() % (jogo.map.y-2)) + 1;//linha

		} while (jogo.player.posx == x && jogo.player.posy == y);

	} else if(jogo.level == 2){

		do{
			srand (time(NULL));
			x = (rand() % (jogo.map.x-2)) + 2;//coluna
			y = (rand() % (jogo.map.y-2)) + 1;//linha

		} while (x + y < 21 || x - y > 20);

	} else if(jogo.level == 3){

		do{
			srand (time(NULL));
			x = (rand() % (jogo.map.x-2)) + 2;//coluna
			y = (rand() % (jogo.map.y-2)) + 1;//linha

		} while (x + y < 21 || x - y > 20);
	}
	
	jogo.coin.x = x;
	jogo.coin.y = y;

	jogo.map.valor[x][y] = jogo.coin.name;
	return jogo;
}

Game iniciaFase1(Game jogo){
	jogo.map.x = 20;
	jogo.map.y = 30;
	jogo.level = 1;
	jogo.player.posx = 1;
	jogo.player.posy = 1;

	clear();

	jogo = limpaMatriz(jogo);
	jogo = insereObjeto(jogo);
	jogo = desenhaCampo(jogo);

	return jogo;
}

Game iniciaFase2(Game jogo){
	jogo.map.x = 21;
	jogo.map.y = 40;
	jogo.level = 2;
	jogo.player.posx = 10;
	jogo.player.posy = 20;

	clear();

	jogo = limpaMatriz(jogo);
	jogo = insereObjeto(jogo);
	jogo = desenhaCampo(jogo);

	return jogo;
}

Game iniciaFase3(Game jogo){
	jogo.map.x = 20;
	jogo.map.y = 30;
	jogo.level = 3;
	jogo.player.posx = 2;
	jogo.player.posy = 2;

	clear();

	jogo = limpaMatriz(jogo);
	jogo = insereObjeto(jogo);
	jogo = desenhaCampo(jogo);

	return jogo;
}


void desenhaCabecalho(Game jogo){
	attron(COLOR_PAIR(1));
	printw("\t\t\tPontuacao = %d\n", jogo.coins);
	attroff(COLOR_PAIR(1));
	desenhaLife(jogo.player.life);
}

Game update(Game jogo, int ch){
	jogo.enemy.difficulty = 0;
	
	clear();
	desenhaCabecalho(jogo);

	jogo = insereJogador(jogo);
	

	if(jogo.enemy.difficulty < 70)
		jogo = moverIni(jogo);
	

	jogo = lerAcao(jogo, ch);
	jogo = desenhaCampo(jogo);

	//TO - DO : criar funcao que modifica estas varaintes do enemy
	srand (time(NULL));
	jogo.enemy.difficulty = rand() % 100;

	if(verificaColisao(jogo)){
		jogo.player.life--;
		if(jogo.player.life == -1){
			printw("\n\t\t\tGAME OVER...");
			getch();
			endwin();
			exit(EXIT_FAILURE);
		}
	}
	
	refresh();

	return jogo;
}
