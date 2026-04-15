#pragma once
#include "IEntity.h"

class Object;
class B_BaseEntity : public IEntity
{
public:

	virtual void Update() override;
	virtual void Render() override;

	// collision
	bool CanCollide(E_TYPE type) override;
	void SetCollision(int collisionFlags) override;

	// Getters
	E_TYPE GetType() override;
	Object* GetMesh() override;
	int GetPositionX() override;
	int GetPositionY() override;

	// Setters
	void SetPosition(int positionX, int positionY) override;


	B_BaseEntity(E_TYPE type, int collisionFlags, Object* mesh);

private:

	E_TYPE m_type;
	Object* m_mesh;

	// location
	int m_x;
	int m_y;

	int m_collisionFlags;

};

