#include "Map.h"
#include "Object.h"

void Map::Update()
{

}

void Map::Render()
{
	// outputs sections of the map
	for (int i = 0; i < NUM_OF_MAP_OBJECTS; i++)
	{
		m_mapParts[i]->Update();
	}
}

Map::Map() : m_mapParts(new Object*[NUM_OF_MAP_OBJECTS])
{
	int LocationX = 0; // <- test

	// news each object that is inside of the object array
	for (int i = 0; i < NUM_OF_MAP_OBJECTS; i++)
	{
		m_mapParts[i] = new Object();
		int blockSize = 50;

		m_mapParts[i]->Init("Assets/TestBlock.bmp", (LocationX += blockSize), 50, blockSize, blockSize, true);//  <- test
	}

	
}

Map::~Map()
{
}
