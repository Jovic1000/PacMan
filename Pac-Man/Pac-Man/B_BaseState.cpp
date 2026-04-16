#include "B_BaseState.h"

void B_BaseState::OnEnter()
{
	//do endter stuff
}

void B_BaseState::Update()
{
	//update stuff
}

void B_BaseState::OnExit()
{
	// do stuff then exit
}

B_BaseState::B_BaseState() : m_isComplete(false)
{
	// MAKE IT!
}
