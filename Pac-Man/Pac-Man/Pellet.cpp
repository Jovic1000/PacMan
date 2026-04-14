#include "Pellet.h"
#include "TileSize.h"
#include "Object.h"

void Pellet::Update()
{
}

void Pellet::Render()
{
	GetMesh()->Update();
}

Pellet::Pellet() : B_BaseEntity(PELLET, new Object("Assets/EntityMesh/pellet.bmp", GetPositionX(), GetPositionY(), TileSize, TileSize, true))
{
}
