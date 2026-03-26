#pragma once

const int NUM_OF_MAP_OBJECTS = (32 * 32);

class Object;
class Map
{
public:

	void Update();
	void Render();

	Map();
	~Map();

private:

	// pointer to a array of object pointers
	Object** m_mapParts;

};

