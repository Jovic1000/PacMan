#include "Screen.h"
#include "GameScreen.h"

void Screen::Update()
{

}

void Screen::Render()
{
	// checks to see if the window is open before updating
	if (GetIsOpen())
	{
		m_gameScreen->Update();
	}
}

bool Screen::GetIsOpen()
{
	return m_gameScreen->IsRunning();
}

Screen::Screen(const char* windowName) : m_gameScreen(new GameScreen())
{
	// creates a game screen on object creation
	if (m_gameScreen->CreateScreen(windowName, 600, 650));
	{
		m_gameScreen->SetBackgroundRGB(0, 0, 0);
	}
}

Screen::~Screen()
{
	// closes the window before deleting the object itself
	if (m_gameScreen)
	{
		m_gameScreen->CloseScreen();
		delete m_gameScreen;
	}
}