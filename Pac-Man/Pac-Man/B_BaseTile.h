#pragma once
#include "ITile.h"
#include "Object.h"

class B_BaseTile : public Object, public ITile
{
public:

	// Inherited via ITile
	// Getters - Setters
	void SetCollide(bool canCollide);
	virtual bool CanCollide(E_TYPE type) override;

	B_BaseTile(bool canCollide, int collisionFlags);
	~B_BaseTile();

private:

	bool m_canCollide;
	int m_collisionFlags;

};

