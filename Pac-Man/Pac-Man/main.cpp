#include <Cstdlib>
#include "GameScreen.h"
#include "Game.h"

#include "B_BaseTile.h"
#include "IEntity.h"

#include <iostream>

int main()
{
	Game game("Test_0.3");

	// Factory???
	B_BaseTile tile(true, PELLET|GHOST );

	if (tile.CanCollide(GHOST))
	{
		std::cout << "GHOST COLLIDED\n";
	}
	
	if (tile.CanCollide(PACMAN))
	{
		std::cout << "PACMAN COLLIDED\n";
	}

	if (tile.CanCollide(PELLET))
	{
		std::cout << "PELLET COLLIDED\n";
	}

	// checks if the game is running and will loop until it is not
	while (game.GetGameRunning())
	{
		game.Update();
		game.Render();
	}

	system("pause");
	return 0;
}