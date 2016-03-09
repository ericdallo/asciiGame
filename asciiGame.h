#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

typedef struct Coin{
	char name;
	int x;
	int y;
}Coin;

typedef struct Player{
	char name;
	int life;
	int posx;
	int posy;
}Player;

typedef struct Enemy{
	char name;
	int difficulty;
	int x;
	int y;
}Enemy;

typedef struct Map{
	char **valor;
	char wall;
	int x;
	int y;
}Map;

typedef struct Game{
	Map map;
	Player player;
	Enemy enemy;
	Coin coin;
	int coins;
	int level;
	char background;
}Game;
/* ---------------------------------------------------

 -> MANTENHA SEMPRE ATUALIZADO <-

*/

Game limpaMatriz(Game jogo);

Game verificaFase(Game jogo);

Game verificaPonto(Game jogo);

Game andaDireita(Game jogo);

Game andaEsquerda(Game jogo);

Game andaBaixo(Game jogo);

Game andaCima(Game jogo);

Game lerAcao(Game jogo, int tecla);

void printSplash();
