#pragma once
#include "B_BaseEntity.h"
#include "input.h"

class FSM;

class PacMan : public B_BaseEntity
{
public:

	void Update() override;
	void Render() override;

	void Movement();

	PacMan();

private:

	FSM* m_movementFSM;
};

