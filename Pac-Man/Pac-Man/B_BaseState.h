#pragma once
#include "IState.h"

class B_BaseState : public IState
{
public:

	void OnEnter() override;
	void Update() override;
	void OnExit() override;

	B_BaseState();

private:
	
	bool m_isComplete;

};

