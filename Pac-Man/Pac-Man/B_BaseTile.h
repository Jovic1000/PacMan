#pragma once
#include "ITile.h"
#include "Object.h"

class B_BaseTile : public Object, public ITile
{
public:

	// Getters - Setters
	void SetCollide(bool canCollide);
	void SetCollisionFlags(int collisionFlags);

	virtual bool CanCollide(E_TYPE type) override;


	// empty constructor
	B_BaseTile();

	// constructor that adds collision on creation
	B_BaseTile(bool canCollide, int collisionFlags);
	~B_BaseTile();

private:

	bool m_canCollide;
	int m_collisionFlags;

};

