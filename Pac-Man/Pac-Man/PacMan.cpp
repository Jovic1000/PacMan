#include "PacMan.h"
#include "Object.h"
#include "TileSize.h"
#include "FSM.h"

void PacMan::Update()
{
	Movement();
}

void PacMan::Render()
{
	GetMesh()->Update();
}

void PacMan::Movement()
{
	m_movementFSM->Update();
}

PacMan::PacMan() : B_BaseEntity(PACMAN, (PELLET | POWER_PELLET | GHOST), new Object("Assets/EntityMesh/pacman.bmp", GetPositionX(), GetPositionY(), TileSize, TileSize, true)), m_movementFSM(new FSM(this))
{
}
