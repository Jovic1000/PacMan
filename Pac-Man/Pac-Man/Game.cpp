#include "GameUI.h"
#include "Object.h"
#include "Game.h"
#include "Screen.h"
#include "Map.h"
#include "PacMan.h"
#include "Pellet.h"
#include "TileSize.h"
#include "EntityFactory.h"
#include <fstream>

void Game::Update()
{
	m_player->Update();

	for (int i = 0; i < Num_Of_Pellets; i++)
	{
		if(m_pellets[i] != nullptr && m_pelletsEaten < Num_Of_Pellets)
		{
			if (m_player->GetMesh()->IsOverlapping(*(m_pellets[i]->GetMesh())))
			{
				delete m_pellets[i];
				m_pellets[i] = nullptr;

				m_pelletsEaten++;
				GETUI->IncreaseScore(50);
			}
		}
	}

	if (m_pelletsEaten == Num_Of_Pellets)
	{
		m_gameRunning = false;
		GETUI->SetEndScreen(true);
	}

}

void Game::Render()
{ 
	// checks to see if the game screen is open befor rendering anything in it so it dosent crash
	if(m_screen->GetIsOpen())
	{
		m_map->Render();
		GETUI->Render();
		m_player->Render();

		for (int i = 0; i < Num_Of_Pellets; i++)
		{
			if(m_pellets[i] != nullptr)
			{
				m_pellets[i]->Render();
			}
		}
	}

	m_screen->Render();
}

void Game::Init()
{
	GameUI::Init();
}

void Game::SetGameRunning(bool isTrue)
{
	m_gameRunning = isTrue;
}

bool Game::GetGameRunning()
{
	return m_gameRunning && m_screen->GetIsOpen();
}

Screen* Game::GetScreen()
{
	return m_screen;
}

Game::Game(const char* gameName) : m_screen(new Screen(gameName)), m_map(new Map()), m_player(new PacMan()), m_pellets(new B_BaseEntity*[Num_Of_Pellets]), m_gameRunning(true), m_pelletsEaten(0)
{

	EntityFactory Facto100;

	int index = 0;

	int x = 0;
	int y = 0;

	std::ifstream pelletMap;
	pelletMap.open("assets/EntityMap.txt");

	char entity;

	if (pelletMap.is_open())
	{
		while (!pelletMap.eof())
		{
			pelletMap.get(entity);

			switch (entity)
			{
			case('#'):
				// nothin
				break;

			case('.'):
				m_pellets[index] = Facto100.CreateEntity(entity);
				m_pellets[index]->SetPosition(x * TileSize, y * TileSize);
				index++;
				break;

			case('0'):
				m_pellets[index] = Facto100.CreateEntity(entity);
				m_pellets[index]->SetPosition(x * TileSize, y * TileSize);
				index++;
				break;

			case ('\n'):
				y++;
				x = 0;
				continue;

			case('C'):
				m_player->SetPosition(x * TileSize, y * TileSize);
				break;

			default:
				break;
			}

			x++;

		}
	}


	pelletMap.close();
}

Game::~Game()
{
	// checks if screen exists then deletes it on destruction
	if (m_screen)
	{
		delete m_screen;
		m_screen = nullptr;
	}
}
