#pragma once

class Screen;
class Map;
class Game
{
public:

	void Update();
	void Render();

	// Setters - Getters
	void SetGameRunning(bool isTrue);

	bool GetGameRunning();

	Game(const char* gameName);
	~Game();

private:

	Screen* m_screen;
	Map* m_map;

	bool m_gameRunning;

};

