void* mallocc(size_t size){
	void *backgroundDeMemoria;
	backgroundDeMemoria = malloc(size);

	if(backgroundDeMemoria == NULL){
		printf("Erro Malloc\n");
		printw("Erro Malloc\n");
		exit(EXIT_FAILURE);
	}

	return backgroundDeMemoria;
}

void initCores(){
	start_color(); //Esta função torna possível o uso das cores
	init_pair(1,COLOR_WHITE,COLOR_BLACK); //Texto(Branco) | Fundo(Azul)
	init_pair(2,COLOR_WHITE,COLOR_GREEN);  //Texto(Vermelho) | Fundo(Branco)
	init_pair(3,COLOR_RED,COLOR_BLACK);
	init_pair(4,COLOR_RED,COLOR_GREEN);
	bkgd(COLOR_PAIR(1));
}

void desenhaLife(int vidas){
	int vez = vidas;
	attron(COLOR_PAIR(1));
	printw("\t\t\tLIFE: ");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(3));

	while(vez != 0){
		printw("<> ");
		vez--;   
	}
	
	attroff(COLOR_PAIR(3));
	printw("\n\n");
}

Game moverIni(Game game){
	int posx,posy,inix,iniy;
	posx = game.player.posx;
	posy = game.player.posy;
	inix = game.enemy.x;
	iniy = game.enemy.y;

	srand (time(NULL));
	int andou = rand() % 100;

	if(inix == game.coin.x && iniy == game.coin.y)
		game.background = game.coin.name;
	else
		game.background = ' ';
	
	
	if(inix > posx && andou < 40 && game.map.valor[inix-1][iniy] != game.map.wall ) {
		game.map.valor[inix][iniy] = game.background;
		game.map.valor[inix-1][iniy] = game.enemy.name;
		game.enemy.x--;
		return game;
	}
	if(inix < posx && andou < 40 && game.map.valor[inix+1][iniy] != game.map.wall){
		game.map.valor[inix][iniy] = game.background;
		game.map.valor[inix+1][iniy] = game.enemy.name;
		game.enemy.x++;
		return game;
	} 
	
	if(iniy > posy && game.map.valor[inix][iniy-1] != game.map.wall){
		game.map.valor[inix][iniy] = game.background;
		game.map.valor[inix][iniy-1] = game.enemy.name;
		game.enemy.y--;
		return game;
	}
	if(iniy < posy && game.map.valor[inix][iniy-1] != game.map.wall){
		game.map.valor[inix][iniy] = game.background;
		game.map.valor[inix][iniy+1] = game.enemy.name;
		game.enemy.y++;
		return game;
	}
	
	return game;
}

int verificaColisao(Game game){
	if(game.player.posx == game.enemy.x && game.player.posy == game.enemy.y){
		return 1;
	}
	return 0;
} 
