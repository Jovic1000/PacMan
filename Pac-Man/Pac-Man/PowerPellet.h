#pragma once
#include "B_BaseEntity.h"

class PowerPellet : public B_BaseEntity
{
public:

	void Update() override;
	void Render() override;

	PowerPellet();
	~PowerPellet();

private:

};

