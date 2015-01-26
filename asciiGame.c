#include "asciiGame.h"
#include "padroes.c"
#include "fase.c"
#include "splashScreen.c"


//Aloca espaco necessario para a matriz e coloca um espaco em cada local
game limpaMatriz(game jogo){
	int x, y;

	//Alocar memoria para uma matriz
	jogo.campo.valor = mallocc(jogo.campo.x * sizeof(char *));
	for(x = 0; x <= jogo.campo.x; x++){
		jogo.campo.valor[x] = mallocc(jogo.campo.y * sizeof(char));
		for(y = 0; y < jogo.campo.y; y++){
				jogo.campo.valor[x][y] = ' ';
		}
	}
	return jogo;
}

//Verifica se o jogador esta em cima do objeto
game verificaPonto(game jogo){
	if(jogo.pl.posx == jogo.obj.x && jogo.pl.posy == jogo.obj.y){
		jogo.pontos++;
		jogo = insereObjeto(jogo);
	}
	return jogo;
}

//O personagem anda para direita(verificando se nao e uma parece e se ele marcou um ponto)
game andaDireita(game jogo){
	if(jogo.campo.valor[jogo.pl.posx][jogo.pl.posy+1] != jogo.campo.parede){
		jogo.campo.valor[jogo.pl.posx][jogo.pl.posy] = jogo.espaco;
		jogo.campo.valor[jogo.pl.posx][jogo.pl.posy+1] = jogo.pl.name;
		jogo.pl.posy++;
		jogo = verificaPonto(jogo);
	}
	return jogo;
}

//O personagem anda para esquerda(verificando se nao e uma parece e se ele marcou um ponto)
game andaEsquerda(game jogo){
	if(jogo.campo.valor[jogo.pl.posx][jogo.pl.posy-1] != jogo.campo.parede){
		jogo.campo.valor[jogo.pl.posx][jogo.pl.posy] = jogo.espaco;
		jogo.campo.valor[jogo.pl.posx][jogo.pl.posy-1] = jogo.pl.name;
		jogo.pl.posy--;
		jogo = verificaPonto(jogo);
	}
	return jogo;
}

//O personagem anda para baixo(verificando se nao e uma parece e se ele marcou um ponto)
game andaBaixo(game jogo){
	if(jogo.campo.valor[jogo.pl.posx+1][jogo.pl.posy] != jogo.campo.parede){
		jogo.campo.valor[jogo.pl.posx][jogo.pl.posy] = jogo.espaco;
		jogo.campo.valor[jogo.pl.posx+1][jogo.pl.posy] = jogo.pl.name;
		jogo.pl.posx++;
		jogo = verificaPonto(jogo);
	}
	return jogo;
}

//O personagem anda para cima(verificando se nao e uma parece e se ele marcou um ponto)
game andaCima(game jogo){
	if(jogo.campo.valor[jogo.pl.posx-1][jogo.pl.posy] != jogo.campo.parede){
		jogo.campo.valor[jogo.pl.posx][jogo.pl.posy] = jogo.espaco;
		jogo.campo.valor[jogo.pl.posx-1][jogo.pl.posy] = jogo.pl.name;
		jogo.pl.posx--;
		jogo = verificaPonto(jogo);
	}
	return jogo;
}

//Le acao do usuario chama a funcao que faz ele andar
game lerAcao(game jogo, int tecla){ 

	if(jogo.pl.posx == jogo.bot.x && jogo.pl.posy == jogo.bot.y)
		jogo.espaco = jogo.bot.name;
	else
		jogo.espaco = ' ';
	
	if(tecla == KEY_RIGHT){
		jogo = andaDireita(jogo);

	} else if(tecla == KEY_LEFT){
		jogo = andaEsquerda(jogo);

	} else if(tecla == KEY_DOWN){
		jogo = andaBaixo(jogo);

	} else if(tecla == KEY_UP){
		jogo = andaCima(jogo);
	}

	if(jogo.pl.posx == jogo.bot.x && jogo.pl.posy == jogo.bot.y )
		jogo.campo.valor[jogo.pl.posx][jogo.pl.posy] = '@';

	return jogo;
}	

int main(){
	mapa campo;
	campo.parede = 'X';
	int ch = 42; //qualquer tecla
	int cont = 0;
	
	objeto obj;	
	obj.name = '#';

	player one;
	one.posx = 1;
	one.posy = 1;
	one.life = 3;
	one.name = 'o'; 

	ini bot;
	bot.x = 10;
	bot.y = 16;
	bot.name = '*';
	bot.dificuldade = 0;

	game jogo;
	jogo.campo = campo;
	jogo.pl = one;
	jogo.pontos = 0;
	jogo.bot = bot;
	jogo.obj = obj;
	jogo.espaco = ' ';

	initscr();					/* Start curses mode 		*/
	raw();						/* Line buffering disabled	*/
	keypad(stdscr, TRUE);		/* We get F1, F2 etc..		*/
	noecho();					/* Don't echo() while we do getch */
	initCores();
	
	printSplash();
		
	jogo = iniciaFase1(jogo);

	do{
		
		
		jogo = update(jogo, ch);

		if(jogo.pontos == 3 && cont == 0){	
			printw("Ganhou! - Vamos para fase 2!\n");
			getch();
			cont++;
			refresh();
			jogo = iniciaFase2(jogo);
			jogo = update(jogo, ch);

		} else if(jogo.pontos == 1 && cont == 0){
			//printw("Ganhou! - Vamos para fase 3!\n");
			getch();
			cont++;
			refresh();
			jogo = iniciaFase3(jogo);
			jogo = update(jogo, ch);
		}
 
	}while ((ch = getch()) != 'c');

	
	endwin();			

	return 0;
}