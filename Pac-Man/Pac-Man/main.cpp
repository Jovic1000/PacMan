#include <Cstdlib>
#include "GameScreen.h"
#include "TextObject.h"
#include "Game.h"
#include "Input.h"

#include <iostream>

int main()
{
	Input input;
	Game* game = new Game("Pac-Man");

	game->Init();

	TextObject restartText("Restart? [Y]/[N]", "Assets/Roboto-Regular.ttf", 50, 200, 600, { 255, 255, 255 }, true);
	bool isComplite = false;
	
	// checks if the game is running and will loop until it is not
	while (!isComplite)
	{
		if (game->GetGameRunning())
		{
			game->Update();
		}
		if (!game->GetGameRunning())
		{
			restartText.Update();
			if (input.GetKeyDown('y'))
			{
				game->SetGameRunning(true);
				game->Init();
			}
			if (input.GetKeyDown('n'))
			{
				isComplite = true;
			}
		}

		game->Render();

	}
	return 0;
}