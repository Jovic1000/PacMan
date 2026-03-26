#pragma once

enum E_TYPE;
class ITile
{
public:

	virtual bool CanCollide(E_TYPE type) = 0;

	virtual ~ITile() {};

private:

};