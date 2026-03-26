#pragma once
#include "IEntity.h"

class Pellet : public IEntity
{
public:
	E_TYPE GetType() override { return PELLET; }
};

