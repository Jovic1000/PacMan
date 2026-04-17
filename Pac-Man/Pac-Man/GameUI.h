#pragma once
#define GETUI GameUI::GetInst()

class FontID;
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
	void SetEndScreen(bool isTrue);


private:

	GameUI();
	GameUI(const GameUI&) = delete;

	int m_nuberOfLives;
	int m_score;

	bool m_endScreen;

	TextObject* m_scoreTextNum;
	TextObject* m_scoreText;
	TextObject* m_livesText;
	TextObject* m_endText;

	static GameUI* m_gameUI;

};

