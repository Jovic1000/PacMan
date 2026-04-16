#include "FSM.h"
#include "S_MovementState.h"
#include "input.h"

void FSM::Update()
{
	Input input;
	m_states[m_currentState]->Update();

	
	if (input.GetKeyUp('w') && m_currentState != UP)
	{
		m_states[m_currentState]->OnExit();
		m_currentState = UP;
		m_states[m_currentState]->OnEnter();
	}
	if (input.GetKeyUp('a') && m_currentState != LEFT)
	{
		m_states[m_currentState]->OnExit();
		m_currentState = LEFT;
		m_states[m_currentState]->OnEnter();
	}
	if (input.GetKeyUp('s') && m_currentState != DOWN)
	{
		m_states[m_currentState]->OnExit();
		m_currentState = DOWN;
		m_states[m_currentState]->OnEnter();
	}
	if (input.GetKeyUp('d') && m_currentState != RIGHT)
	{
		m_states[m_currentState]->OnExit();
		m_currentState = RIGHT;
		m_states[m_currentState]->OnEnter();
	}
}


void FSM::Render()
{
	m_states[m_currentState]->Render();
}

void FSM::SetState(MOVEMENT_STATES state)
{
	m_currentState = state;
}

FSM::FSM(IEntity* entity) : m_entity(entity), m_currentState(IDLE), m_states(new S_MovementState*[MAX])
{
	
	m_states[UP] = new S_MovementState(1, 270, entity);
	m_states[RIGHT] = new S_MovementState(1, 0, entity);
	m_states[DOWN] = new S_MovementState(1, 90, entity);
	m_states[LEFT] = new S_MovementState(1, 180, entity);
	m_states[IDLE] = new S_MovementState(1, 1, entity);
	m_states[DEAD] = new S_MovementState(1, 1, entity);
	
}

FSM::~FSM()
{
}
