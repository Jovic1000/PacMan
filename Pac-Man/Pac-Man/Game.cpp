#include "GameUI.h"
#include "Game.h"
#include "Screen.h"
#include "Map.h"
#include "PacMan.h"
#include "Pellet.h"
#include "TileSize.h"
#include <fstream>
#include <iostream>

void Game::Update()
{
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
			m_pellets[i]->Render();
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
	return m_gameRunning;
}

Game::Game(const char* gameName) : m_screen(new Screen(gameName)), m_map(new Map()), m_player(new PacMan()), m_pellets(new Pellet*[Num_Of_Pellets]), m_gameRunning(true)
{

	int index = 0;

	int x = 0;
	int y = 0;

	std::ifstream pelletMap;
	pelletMap.open("assets/EntityMap.txt");

	char pellet;

	if (pelletMap.is_open())
	{
		while (!pelletMap.eof())
		{
			pelletMap.get(pellet);

			switch (pellet)
			{
			case('#'):
				// nothin
				break;

			case('.'):
				m_pellets[index] = new Pellet();
				m_pellets[index]->SetPosition(x * TileSize, y * TileSize);

				if (index >= Num_Of_Pellets)
				{
					std::cerr << "Pellet Error!" << std::endl; 
				}

				index++;
				break;

			case('0'):
				//temp nothin
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
