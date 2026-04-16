#pragma once
#define GETUI GameUI::GetInst()

class TextObject;
class GameUI
{
public:

	static void Init();
	static void DeInit();
	
	void Render();
	void IncreaseScore(int score);

	// Getters - Setters
	static GameUI* GetInst();


private:

	GameUI();
	GameUI(const GameUI&) = delete;

	int m_nuberOfLives;
	int m_score;

	TextObject* m_scoreText;
	TextObject* m_livesText;

	static GameUI* m_gameUI;

};

