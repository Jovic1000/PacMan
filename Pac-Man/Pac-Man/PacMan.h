#pragma once
#include "B_BaseEntity.h"

class PacMan : public B_BaseEntity
{
public:

	void Update() override;
	void Render() override;

	PacMan();

private:

};

