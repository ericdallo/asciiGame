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

Game limpaMatriz(Game game);

Game verificaFase(Game game);

Game verificaPonto(Game game);

Game andaDireita(Game game);

Game andaEsquerda(Game game);

Game andaBaixo(Game game);

Game andaCima(Game game);

Game lerAcao(Game game, int tecla);

void printSplash();
