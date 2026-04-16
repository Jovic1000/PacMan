#include "EntityFactory.h"
#include "Pellet.h"
#include "PacMan.h"
#include "PowerPellet.h"
#include "B_BaseEntity.h"



B_BaseEntity* EntityFactory::CreateEntity(char tile)
{
	switch (tile)
	{
	case('.'):
		return new Pellet();
		break;

	case('0'):
		return new PowerPellet();
		break;

	case('C'):
		return new PacMan();
		break;

	default:
		break;
	}
}

EntityFactory::EntityFactory()
{
}
