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

Game moverIni(Game jogo){
	int posx,posy,inix,iniy;
	posx = jogo.player.posx;
	posy = jogo.player.posy;
	inix = jogo.enemy.x;
	iniy = jogo.enemy.y;

	srand (time(NULL));
	int andou = rand() % 100;

	if(inix == jogo.coin.x && iniy == jogo.coin.y)
		jogo.background = jogo.coin.name;
	else
		jogo.background = ' ';
	
	
	if(inix > posx && andou < 40 && jogo.map.valor[inix-1][iniy] != jogo.map.wall ) {
		jogo.map.valor[inix][iniy] = jogo.background;
		jogo.map.valor[inix-1][iniy] = jogo.enemy.name;
		jogo.enemy.x--;
		return jogo;
	}
	if(inix < posx && andou < 40 && jogo.map.valor[inix+1][iniy] != jogo.map.wall){
		jogo.map.valor[inix][iniy] = jogo.background;
		jogo.map.valor[inix+1][iniy] = jogo.enemy.name;
		jogo.enemy.x++;
		return jogo;
	} 
	
	if(iniy > posy && jogo.map.valor[inix][iniy-1] != jogo.map.wall){
		jogo.map.valor[inix][iniy] = jogo.background;
		jogo.map.valor[inix][iniy-1] = jogo.enemy.name;
		jogo.enemy.y--;
		return jogo;
	}
	if(iniy < posy && jogo.map.valor[inix][iniy-1] != jogo.map.wall){
		jogo.map.valor[inix][iniy] = jogo.background;
		jogo.map.valor[inix][iniy+1] = jogo.enemy.name;
		jogo.enemy.y++;
		return jogo;
	}
	
	return jogo;
}

int verificaColisao(Game jogo){
	if(jogo.player.posx == jogo.enemy.x && jogo.player.posy == jogo.enemy.y){
		return 1;
	}
	return 0;
} 
