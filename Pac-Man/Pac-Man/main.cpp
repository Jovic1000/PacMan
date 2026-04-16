#include <Cstdlib>
#include "GameScreen.h"
#include "Game.h"

#include <iostream>

int main()
{
	Game game("Pac-Man");

	game.Init();

	bool isComplite = true;

	// checks if the game is running and will loop until it is not
	while (isComplite)
	{
		if (game.GetGameRunning())
		{
			game.Update();
			game.Render();
		}
	}

	system("pause");
	return 0;
}