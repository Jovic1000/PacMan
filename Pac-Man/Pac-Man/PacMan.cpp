#include "PacMan.h"
#include "Object.h"
#include "TileSize.h"

void PacMan::Update()
{
}

void PacMan::Render()
{
	GetMesh()->Update();
}

PacMan::PacMan() : B_BaseEntity(PACMAN, new Object("Assets/EntityMesh/pacman.bmp", GetPositionX(), GetPositionY(), TileSize, TileSize, true))
{
}
