#pragma once

enum E_TYPE
{
	PACMAN = 1,
	GHOST = 2,
	PELLET = 4,
	POWER_PELLET =8
};

class IEntity
{
public:

	virtual E_TYPE GetType() = 0;

	virtual void Update() = 0;
	virtual void Render() = 0;

	// virtual Getters
	virtual int GetPositionX() = 0;
	virtual int GetPositionY() = 0;

	virtual ~IEntity() = 0;

private:

};