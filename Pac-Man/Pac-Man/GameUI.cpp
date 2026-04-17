#include "GameUI.h"
#include "TextObject.h"
#include <iostream>

GameUI* GameUI::m_gameUI = nullptr;

void GameUI::Init()
{
	// checks to see if a instance already exists then sends a messege to console if it dose
	// if not it will create a new instance
	if (m_gameUI == nullptr)
	{
		m_gameUI = new GameUI();
	}
	else
	{
		std::cout << "Failed To Init : A GameUI Instance Already Exists!!!" << std::endl;
	}
}

void GameUI::DeInit()
{
	// checks to see if theres a instance befor deleting it
	if (m_gameUI)
	{
		delete m_gameUI;
		m_gameUI = nullptr;
	}
	else
	{
		std::cout << "There Is No Instance Of GameUI To DeInitialise" << std::endl;
	}
}

GameUI* GameUI::GetInst()
{
	return m_gameUI;
}

void GameUI::SetEndScreen(bool isTrue)
{
	m_endScreen = isTrue;
}

void GameUI::Render()
{

	m_scoreTextNum->SetText(std::to_string(m_score).c_str());

	if (m_endScreen)
	{
		m_endText->Update();
	}

	m_livesText->Update();
	m_scoreText->Update();
	m_scoreTextNum->Update();


	

}

void GameUI::IncreaseScore(int score)
{
	m_score += score;
}


GameUI::GameUI() : m_nuberOfLives(3), m_score(0)
{
	Colour textColour {255,255,255};

	m_scoreTextNum = new TextObject(std::to_string(m_score).c_str(), "Assets/Roboto-Regular.ttf", 20, 470, 610, textColour, true);
	m_livesText = new TextObject("Lives: ", "Assets/Roboto-Regular.ttf", 20, 20, 610, textColour, true);
	m_scoreText = new TextObject("Score: ", "Assets/Roboto-Regular.ttf", 20, 400, 610, textColour, true);
	m_endText = new TextObject("GAMEOVER", "Assets/Roboto-Regular.ttf", 100, 0, 300, textColour, true);
}