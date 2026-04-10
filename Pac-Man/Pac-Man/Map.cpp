#include <fstream>
#include <iostream>
#include "Map.h"
#include "B_BaseTile.h"
#include "IEntity.h"

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

Map::Map() : m_mapParts(new B_BaseTile*[NUM_OF_MAP_OBJECTS])
{

	const int blockSize = 40;
	int index = 0;

	int x = 1;
	int y = 1;

	char tile;

	std::ifstream bitmap;
	bitmap.open("assets/mapLayout.txt");


	// news each object that is inside of the object array
	// then assignes a possition to the screen by reading from a txt file
	if(bitmap.is_open())
	{
		while (!bitmap.eof())
		{
			bitmap.get(tile);

			if(tile != '\n')
			{
				m_mapParts[index] = new B_BaseTile();

				switch (tile)
				{
				case('#'):
					m_mapParts[index]->Init("assets/MapTiles/wall.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(true);
					m_mapParts[index]->SetCollisionFlags(GHOST | PACMAN);
					break;

				case('-'):
					m_mapParts[index]->Init("assets/MapTiles/pathD.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(false);
					break;

				case('|'):
					m_mapParts[index]->Init("assets/MapTiles/pathV.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(false);
					break;

				case('{'):
					m_mapParts[index]->Init("assets/MapTiles/cornerTL.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(false);
					break;

				case('}'):
					m_mapParts[index]->Init("assets/MapTiles/cornerTR.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(false);
					break;

				case('\\'):
					m_mapParts[index]->Init("assets/MapTiles/cornerBL.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(false);
					break;

				case('/'):
					m_mapParts[index]->Init("assets/MapTiles/cornerBR.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(false);
					break;

				case('<'):
					m_mapParts[index]->Init("assets/MapTiles/crossoverL.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(false);
					break;

				case('>'):
					m_mapParts[index]->Init("assets/MapTiles/crossoverR.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(false);
					break;

				case('^'):
					m_mapParts[index]->Init("assets/MapTiles/crossoverT.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(false);
					break;

				case('!'):
					m_mapParts[index]->Init("assets/MapTiles/crossoverB.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(false);
					break;

				case('E'):
					m_mapParts[index]->Init("assets/MapTiles/empty.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(true);
					m_mapParts[index]->SetCollisionFlags(PACMAN);
					break;

				case('D'):
					m_mapParts[index]->Init("assets/MapTiles/Door.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(true);
					m_mapParts[index]->SetCollisionFlags(PACMAN);
					break;

				default:
					std::cout << "Failed To Locate Tile" << std::endl;
					m_mapParts[index]->Init("assets/MapTiles/TestBlock.bmp", x * blockSize, y * blockSize, blockSize, blockSize, true);
					m_mapParts[index]->SetCollide(true);
					m_mapParts[index]->SetCollisionFlags(GHOST | PACMAN);
					break;
				}

				x++;
				index++;
			}

			if (tile == '\n')
			{
				y++;
				x = 1;
			}
		}
	}

	bitmap.close();
	
}

Map::~Map()
{
}
