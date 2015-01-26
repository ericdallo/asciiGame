#include "fase.h"

game insereJogador(game jogo){
	jogo.campo.valor[jogo.pl.posx][jogo.pl.posy] = jogo.pl.name;


	return jogo;
}

game desenhaFase1(game jogo, int x, int y){

	if(x == 0 || y == (jogo.campo.y-1) || x == (jogo.campo.x-1) || y == 0) //PAREDES
		jogo.campo.valor[x][y] = jogo.campo.parede;

	return jogo;
}

game desenhaFase2(game jogo, int x, int y){

	if(y == (jogo.campo.y / 2) - x || x == (jogo.campo.x-1) || y == (jogo.campo.y / 2) + x) //PAREDES
		jogo.campo.valor[x][y] = jogo.campo.parede;

	return jogo;
}

game desenhaFase3(game jogo, int x, int y){

	desenhaFase1(jogo, x, y);//Desenha o limite do campo
	//MAIOR IF DO MUNDO!!!!!
	if((y == 5 && x < 17) || (y == 10 && (x >= 5 || x <= 2)) || (x == 10 && (y >= 15 && y <= 20)) || (y == 20 && (x < 15 && x > 10)) || 
		(x == 15 && (y >= 15 && y <= 20)) || (y == 15 && x > 15 ) || (x == 5 && y > 18) || (y == 18 && (x <= 5 && x > 2)) ||
		(y == 20 && x < 3) || (y == 23 && (x <= 12 && x >= 2)) || (y == 26 && x < 3) || ((y > 7 && y < 13) && x == 12) ||
		(x == 3 && (y > 2 && y < 7)) || (x == 16 && (y > 2 && y < 8)) || (y == 15 && x < 7) || (x == 8 && y < 3)) //Labirinto
		jogo.campo.valor[x][y] = jogo.campo.parede;

	

	return jogo;
}

//Desenha o campo com o personagem e as paredes
//x = linha 
//y = coluna
game desenhaCampo(game jogo){
	int x, y;

	for(x = 0; x < jogo.campo.x; x++){
		for(y = 0; y < jogo.campo.y; y++){	
			attron(COLOR_PAIR(2));

			if(jogo.campo.valor[x][y] == jogo.campo.parede){
				attron(COLOR_PAIR(4));
				if(x != 0)
					printw("%c ", jogo.campo.valor[x][y]);
				else
					printw("%c ", jogo.campo.valor[x][y]);
				attroff(COLOR_PAIR(4));
			}else
				printw("%c ", jogo.campo.valor[x][y]);


			if(jogo.fase == 1)
				jogo = desenhaFase1(jogo, x, y);

			if(jogo.fase == 2)
				jogo = desenhaFase2(jogo, x, y);

			if(jogo.fase == 3)
				jogo = desenhaFase3(jogo, x, y);

		}
		printw("\n");
	}

	return jogo;
}



//insere o objeto dentro do mapa em uma posicao aleatoria
// c + l >= 21 && c - l <= 19  
//TO - DO : falta verificar este caso: l < ? && l >= 2
//c <= 38 && c >= 2
game insereObjeto(game jogo){
	int x, y;

	if(jogo.fase == 1){

		do{
			srand (time(NULL));
			x = (rand() % (jogo.campo.x-2)) + 1;//coluna
			y = (rand() % (jogo.campo.y-2)) + 1;//linha

		} while (jogo.pl.posx == x && jogo.pl.posy == y);

	} else if(jogo.fase == 2){

		do{
			srand (time(NULL));
			x = (rand() % (jogo.campo.x-2)) + 2;//coluna
			y = (rand() % (jogo.campo.y-2)) + 1;//linha

		} while (x + y < 21 || x - y > 20);

	} else if(jogo.fase == 3){

		do{
			srand (time(NULL));
			x = (rand() % (jogo.campo.x-2)) + 2;//coluna
			y = (rand() % (jogo.campo.y-2)) + 1;//linha

		} while (x + y < 21 || x - y > 20);
	}
	
	jogo.obj.x = x;
	jogo.obj.y = y;

	jogo.campo.valor[x][y] = jogo.obj.name;
	return jogo;
}

game iniciaFase1(game jogo){
	jogo.campo.x = 20;
	jogo.campo.y = 30;
	jogo.fase = 1;
	jogo.pl.posx = 1;
	jogo.pl.posy = 1;

	clear();

	jogo = limpaMatriz(jogo);
	jogo = insereObjeto(jogo);
	jogo = desenhaCampo(jogo);

	return jogo;
}

game iniciaFase2(game jogo){
	jogo.campo.x = 21;
	jogo.campo.y = 40;
	jogo.fase = 2;
	jogo.pl.posx = 10;
	jogo.pl.posy = 20;

	clear();

	jogo = limpaMatriz(jogo);
	jogo = insereObjeto(jogo);
	jogo = desenhaCampo(jogo);

	return jogo;
}

game iniciaFase3(game jogo){
	jogo.campo.x = 20;
	jogo.campo.y = 30;
	jogo.fase = 3;
	jogo.pl.posx = 2;
	jogo.pl.posy = 2;

	clear();

	jogo = limpaMatriz(jogo);
	jogo = insereObjeto(jogo);
	jogo = desenhaCampo(jogo);

	return jogo;
}


void desenhaCabecalho(game jogo){
	attron(COLOR_PAIR(1));
	printw("\t\t\tPontuacao = %d\n", jogo.pontos);
	attroff(COLOR_PAIR(1));
	desenhaLife(jogo.pl.life);
}

game update(game jogo, int ch){
	jogo.bot.dificuldade = 0;
	
	clear();
	desenhaCabecalho(jogo);

	jogo = insereJogador(jogo);
	

	if(jogo.bot.dificuldade < 70)
		jogo = moverIni(jogo);
	

	jogo = lerAcao(jogo, ch);
	jogo = desenhaCampo(jogo);

	//TO - DO : criar funcao que modifica estas varaintes do bot
	srand (time(NULL));
	jogo.bot.dificuldade = rand() % 100;

	if(verificaColisao(jogo)){
		jogo.pl.life--;
		if(jogo.pl.life == -1){
			printw("\n\t\t\tGAME OVER...");
			getch();
			endwin();
			exit(EXIT_FAILURE);
		}
	}
	
	refresh();

	return jogo;
}