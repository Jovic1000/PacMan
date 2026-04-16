#pragma once

enum MOVEMENT_STATES
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	IDLE,
	DEAD,
	MAX 
};

class IEntity;
class S_MovementState;
class FSM
{
public:

	void Update();
	void Render();

	void SetState(MOVEMENT_STATES state);

	FSM(IEntity* entity);
	~FSM();

private:
	
	IEntity* m_entity;

	S_MovementState** m_states;
	MOVEMENT_STATES m_currentState;

	

};

