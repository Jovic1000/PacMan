#include "Game.h"
#include "Screen.h"
#include "Map.h"

void Game::Update()
{
}

void Game::Render()
{ 
	// checks to see if the game screen is open befor rendering anything in it so it dosent crash
	if(m_screen->GetIsOpen())
	{
		m_map->Render();
	}

	m_screen->Render();
}

void Game::SetGameRunning(bool isTrue)
{
	m_gameRunning = isTrue;
}

bool Game::GetGameRunning()
{
	return m_gameRunning;
}

Game::Game(const char* gameName) : m_screen(new Screen(gameName)), m_map(new Map()), m_gameRunning(true)
{
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
