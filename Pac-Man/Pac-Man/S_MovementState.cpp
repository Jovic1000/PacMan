#include "S_MovementState.h"
#include "IEntity.h"
#include "Object.h"

void S_MovementState::OnEnter()
{
	m_entity->GetMesh()->SetRotation(m_rotation);
}

void S_MovementState::OnExit()
{
}

void S_MovementState::Update()
{
	m_entity->SetPosition(m_entity->GetPositionX() + m_direction.m_xSpeed, m_entity->GetPositionY() + m_direction.m_ySpeed);
}

void S_MovementState::Render()
{
}

void S_MovementState::GetSpeed()
{
}

void S_MovementState::GetRotation()
{
}

S_MovementState::S_MovementState(float speed, float rotation, IEntity* entity) : m_rotation(rotation), m_speed(speed), m_entity(entity), m_direction()
{ 
	
	switch ((int)rotation)
	{
	case(90):
		m_direction.m_xSpeed = 0;
		m_direction.m_ySpeed = speed;
		break;

	case(180):
		m_direction.m_xSpeed = -speed;
		m_direction.m_ySpeed = 0;
		break;

	case(270):
		m_direction.m_xSpeed = 0;
		m_direction.m_ySpeed = -speed;
		break;

	case(0):
		m_direction.m_xSpeed = speed;
		m_direction.m_ySpeed = 0;
		break;

	default:
		m_direction.m_xSpeed = 0;
		m_direction.m_ySpeed = 0;
		break;
	}

}

S_MovementState::~S_MovementState()
{
}
