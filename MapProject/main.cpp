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

	//game.exitGame();

	return 0;
}

void log_msg(ostringstream* txt) {

	fprintf(stderr, txt->str().c_str());	// out to debug window
}

void log_msgc(const char* txt) {

	fprintf(stderr, txt);	// out to debug window
}


