#include "stdafx.h"
#include "main.h"
#include "Gamebase.h"

int main(int argc, char **argv)
{

	Gamebase gamebase;

	if (gamebase.init()) {
		fprintf(stderr, "failed to initialize frameworks!\n");
		return RET_ERR;
	}
	
	gamebase.gameLoop();

	//game.gameLoop();

	//game.exitGame();

	return 0;
}



