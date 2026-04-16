#pragma once

class B_BaseEntity;
class PacMan;
class Screen;
class Map;
class Game
{
public:

	void Update();
	void Render();

	void Init();

	// Setters - Getters
	void SetGameRunning(bool isTrue);
	bool GetGameRunning();

	Game(const char* gameName);
	~Game();

private:

	Screen* m_screen;
	Map* m_map;
	PacMan* m_player;

	B_BaseEntity** m_pellets;

	bool m_gameRunning;

};

