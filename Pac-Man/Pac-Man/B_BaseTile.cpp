#include "B_BaseTile.h"

bool B_BaseTile::CanCollide(E_TYPE type)
{
    if (type & m_collisionFlags)
    {
        return true;
    }

    return false;
}

B_BaseTile::~B_BaseTile() {}

void B_BaseTile::SetCollide(bool canCollide)
{
    m_canCollide = canCollide;
}

B_BaseTile::B_BaseTile(bool canCollide, int collisionFlags) : m_canCollide(canCollide), m_collisionFlags(collisionFlags)
{
}
