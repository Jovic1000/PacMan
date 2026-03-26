#pragma once

class GameScreen;
class Screen
{
public:

	void Update();
	void Render();

	//getters - Setters
	bool GetIsOpen();

	Screen(const char* windowName);
	~Screen();

private:

	GameScreen* m_gameScreen;

};

