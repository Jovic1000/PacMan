#pragma once

const int NUM_OF_MAP_OBJECTS = (15 * 15);

class B_BaseTile;
class Map
{
public:

	void Update();
	void Render();

	Map();
	~Map();

private:

	// pointer to a array of object pointers
	B_BaseTile** m_mapParts;

};

