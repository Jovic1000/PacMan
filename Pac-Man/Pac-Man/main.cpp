#include <Cstdlib>
#include "GameScreen.h"
#include "Game.h"

#include <iostream>

int main()
{
	Game game("Test_0.3");

	// checks if the game is running and will loop until it is not
	while (game.GetGameRunning())
	{
		game.Update();
		game.Render();
	}

	system("pause");
	return 0;
}