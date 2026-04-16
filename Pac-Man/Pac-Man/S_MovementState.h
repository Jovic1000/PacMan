#pragma once
#include "B_BaseState.h"

struct Direction
{
	int m_xSpeed;
	int m_ySpeed;
};

class IEntity;
class S_MovementState : public B_BaseState
{
public:

	void OnEnter() override;
	void OnExit() override;

	void Update() override;
	void Render();

	// getters
	void GetSpeed();
	void GetRotation();

	S_MovementState(float speed, float rotation, IEntity* entity);
	~S_MovementState();

private:

	float m_speed;
	float m_rotation;

	IEntity* m_entity;
	Direction m_direction;

};

