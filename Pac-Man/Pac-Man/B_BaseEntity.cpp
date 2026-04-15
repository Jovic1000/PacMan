#include "B_BaseEntity.h"
#include "Object.h"

void B_BaseEntity::Update()
{
    // do stuff
}

void B_BaseEntity::Render()
{
    // render stuff
}

E_TYPE B_BaseEntity::GetType()
{
    return m_type;
}

Object* B_BaseEntity::GetMesh()
{
    return m_mesh;
}


int B_BaseEntity::GetPositionX()
{
    return m_x;
}

int B_BaseEntity::GetPositionY()
{
    return m_y;
}

B_BaseEntity::B_BaseEntity(E_TYPE type, int collisionFlags, Object* mesh) : m_type(type), m_mesh(mesh), m_x(0), m_y(0), m_collisionFlags(collisionFlags)
{
}

bool B_BaseEntity::CanCollide(E_TYPE type)
{
    if (type & m_collisionFlags)
    {
        return true;
    }
    return false;
}

void B_BaseEntity::SetCollision(int collisionFlags)
{
    m_collisionFlags = collisionFlags;
}

void B_BaseEntity::SetPosition(int positionX, int positionY)
{
    m_mesh->SetPosition(positionX, positionY);
}

