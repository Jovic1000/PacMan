#include <Cstdlib>
#include "GameScreen.h"
#include "TextObject.h"
#include "Game.h"

#include <iostream>

int main()
{
	Game game("Pac-Man");

	game.Init();

	bool isComplite = true;
	TextObject endText("GAMEOVER", "Assets/Roboto-Regular.ttf", 300, 300, {255, 255, 255}, true);

	// checks if the game is running and will loop until it is not
	while (isComplite)
	{
		if (game.GetGameRunning())
		{
			game.Update();
			game.Render();
		}
		else if (game.GetGameRunning() == false)
		{
			game.Render();
			
		}
	}

	system("pause");
	return 0;
}