#include "B_BaseTile.h"

void B_BaseTile::SetCollide(bool canCollide)
{
    m_canCollide = canCollide;
}

void B_BaseTile::SetCollisionFlags(int collisionFlags)
{
    m_collisionFlags = collisionFlags;
}

bool B_BaseTile::CanCollide(E_TYPE type)
{
    if (type & m_collisionFlags)
    {
        return true;
    }

    return false;
}

B_BaseTile::B_BaseTile() : m_canCollide(), m_collisionFlags()
{
}

B_BaseTile::~B_BaseTile()
{
}

B_BaseTile::B_BaseTile(bool canCollide, int collisionFlags) : m_canCollide(canCollide), m_collisionFlags(collisionFlags)
{
}
