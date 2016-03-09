void printSplash(){
	srand (time(NULL));
	int aleatorio = rand() % 100;
	printw("\t\t\t\bBem vindo ao...\n");
	attron(COLOR_PAIR(3));
	if(aleatorio >= 0 && aleatorio < 10){
		printw("\n  _____    _____     ___   _______  _______                                    ");
		printw("\n (_____)  (_____)  _(___)_(_______)(_______)                                   ");
		printw("\n(_)___(_)(_)___   (_)   (_)  (_)      (_)        ____   ____   __   __   (____)");
		printw("\n(_______)  (___)_ (_)    _   (_)      (_)       (____) (____) (__)_(__) (_)_(_)");
		printw("\n(_)   (_)  ____(_)(_)___(_)__(_)__  __(_)__    ( )_(_)( )_( )(_) (_) (_)(__)__ ");
		printw("\n(_)   (_) (_____)   (___) (_______)(_______)    (____) (__)_)(_) (_) (_) (____)");
		printw("\n                                               (_)_(_)                         ");
		printw("\n                                                (___)                          ");
	}else if(aleatorio >= 10 && aleatorio < 20){
		printw("\n    _    __    ___  _____ _____                              ");
		printw("\n   /_\\  / _\\  / __\\ \\_   \\\\_   \\   __ _  __ _ _ __ ___   ___ ");
		printw("\n  //_\\\\ \\ \\  / /     / /\\/ / /\\/  / _` |/ _` | '_ ` _ \\ / _ \\");
		printw("\n /  _  \\_\\ \\/ /___/\\/ /_/\\/ /_   | (_| | (_| | | | | | |  __/");
		printw("\n \\_/ \\_/\\__/\\____/\\____/\\____/    \\__, |\\__,_|_| |_| |_|\\___|");
		printw("\n                                  |___/                      ");
	}else if(aleatorio >= 20 && aleatorio < 30){
		printw("\n  _____ _____ _____ _____ _____                      ");
		printw("\n |  _  |   __|     |     |     |   ___ ___ _____ ___ ");
		printw("\n |     |__   |   --|-   -|-   -|  | . | .'|     | -_|");
		printw("\n |__|__|_____|_____|_____|_____|  |_  |__,|_|_|_|___|");
        printw("\n                                  |___|              ");
	}else if(aleatorio >= 30 && aleatorio < 40){
		printw("\n  _______  ______ _______ _ _                            ");     
		printw("\n (_______)/ _____|_______) | |                           ");
		printw("\n  _______( (____  _      | | |    ____ _____ ____  _____ ");
		printw("\n |  ___  |\\____ \\| |     | | |   / _  (____ |    \\| ___ |");
		printw("\n | |   | |_____) ) |_____| | |  ( (_| / ___ | | | | ____|");
		printw("\n |_|   |_(______/ \\______)_|_|   \\___ \\_____|_|_|_|_____)");
		printw("\n                                (_____|                  ");
	}else if(aleatorio >= 40 && aleatorio < 50){
		printw("\n    .aMMMb  .dMMMb  .aMMMb  dMP dMP        .aMMMMP .aMMMb  dMMMMMMMMb dMMMMMP  ");
		printw("\n   dMP\"dMP dMP\" VP dMP\"VMP amr amr        dMP\"    dMP\"dMP dMP\"dMP\"dMPdMP");
		printw("\n  dMMMMMP  VMMMb  dMP     dMP dMP        dMP MMP\"dMMMMMP dMP dMP dMPdMMMP     ");
		printw("\n dMP dMP dP .dMP dMP.aMP dMP dMP        dMP.dMP dMP dMP dMP dMP dMPdMP         ");
		printw("\ndMP dMP  VMMMP\"  VMMMP\" dMP dMP         VMMMP\" dMP dMP dMP dMP dMPdMMMMMP   ");
	}else if(aleatorio >= 50 && aleatorio < 60){
		printw("\n  __   ___   __  __  __     __   __   __  __  ___ ");
		printw("\n (  ) / __) / _)(  )(  )   / _) (  ) (  \\/  )(  _)");
		printw("\n /__\\ \\__ \\( (_  )(  )(   ( (/\\ /__\\  )    (  ) _)");
		printw("\n(_)(_)(___/ \\__)(__)(__)   \\__/(_)(_)(_/\\/\\_)(___)");
	}else if(aleatorio >= 60 && aleatorio < 70){
		printw("\n    \\     ___|   ___|_ _|_ _|                           ");
		printw("\n   _ \\  \\___ \\  |      |   |     _` |  _` | __ `__ \\   _ \\");
		printw("\n  ___ \\       | |      |   |    (   | (   | |   |   |  __/");
		printw("\n_/    _\\_____/ \\____|___|___|  \\__, |\\__,_|_|  _|  _|\\___|");
		printw("\n                               |___/                      ");
	}else if(aleatorio >= 70 && aleatorio < 80){
		printw("\n    ___       ___       ___       ___       ___   ");
		printw("\n   /\\  \\     /\\  \\     /\\  \\     /\\  \\     /\\  \\  ");
		printw("\n  /::\\  \\   /::\\  \\   /::\\  \\   _\\:\\  \\   _\\:\\  \\ ");
		printw("\n /::\\:\\__\\ /\\:\\:\\__\\ /:/\\:\\__\\ /\\/::\\__\\ /\\/::\\__\\");
		printw("\n \\/\\::/  / \\:\\:\\/__/ \\:\\ \\/__/ \\::/\\/__/ \\::/\\/__/");
		printw("\n   /:/  /   \\::/  /   \\:\\__\\    \\:\\__\\    \\:\\__\\  ");
		printw("\n   \\/__/     \\/__/     \\/__/     \\/__/     \\/__/  ");
		printw("\n    ___       ___       ___       ___             ");
		printw("\n   /\\  \\     /\\  \\     /\\__\\     /\\  \\            ");
		printw("\n  /::\\  \\   /::\\  \\   /::L_L_   /::\\  \\           ");
		printw("\n /:/\\:\\__\\ /::\\:\\__\\ /:/L:\\__\\ /::\\:\\__\\          ");
		printw("\n \\:\\:\\/__/ \\/\\::/  / \\/_/:/  / \\:\\:\\/  /          ");
		printw("\n  \\::/  /    /:/  /    /:/  /   \\:\\/  /           ");
		printw("\n   \\/__/     \\/__/     \\/__/     \\/__/            ");
	}else if(aleatorio >= 80 && aleatorio < 90){
		printw("\n     ___           _______.  ______  __   __ ");
		printw("\n    /   \\         /       | /      ||  | |  |");
		printw("\n   /  ^  \\       |   (----`|  ,----'|  | |  |");
		printw("\n  /  /_\\  \\       \\   \\    |  |     |  | |  |");
		printw("\n /  _____  \\  .----)   |   |  `----.|  | |  |");
		printw("\n/__/     \\__\\ |_______/     \\______||__| |__|");
		printw("\n                                             ");
		printw("\n  _______      ___      .___  ___.  _______  ");
		printw("\n /  _____|    /   \\     |   \\/   | |   ____| ");
		printw("\n|  |  __     /  ^  \\    |  \\  /  | |  |__    ");
		printw("\n|  | |_ |   /  /_\\  \\   |  |\\/|  | |   __|   ");
		printw("\n|  |__| |  /  _____  \\  |  |  |  | |  |____  ");
		printw("\n \\______| /__/     \\__\\ |__|  |__| |_______| ");
	}else{
		printw("\n  A)aa    S)ssss    C)ccc  I)iiii I)iiii                                       ");
		printw("\n A)  aa  S)    ss  C)   cc   I)     I)                                         ");
		printw("\nA)    aa  S)ss    C)         I)     I)       g)GGG  a)AAAA   m)MM MMM  e)EEEEE ");
		printw("\nA)aaaaaa      S)  C)         I)     I)      g)   GG  a)AAA  m)  MM  MM e)EEEE  ");
		printw("\nA)    aa S)    ss  C)   cc   I)     I)      g)   GG a)   A  m)  MM  MM e)      ");
		printw("\nA)    aa  S)ssss    C)ccc  I)iiii I)iiii     g)GGGG  a)AAAA m)      MM  e)EEEE ");
		printw("\n                                                 GG                            ");
		printw("\n                                            g)GGGG                             ");
	}

	attroff(COLOR_PAIR(3));
	printw("\n\n\tPressione qualquer tecla para começar...");
	getch();
}
