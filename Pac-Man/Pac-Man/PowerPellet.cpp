#include "PowerPellet.h"
#include "Object.h"
#include "TileSize.h"

void PowerPellet::Update()
{
}

void PowerPellet::Render()
{
	GetMesh()->Update();
}

PowerPellet::PowerPellet() : B_BaseEntity(POWER_PELLET, E_NONE, new Object("Assets/EntityMesh/sprite-2-2.bmp", GetPositionX(), GetPositionY(), TileSize, TileSize, true))
{
}

PowerPellet::~PowerPellet()
{
}
