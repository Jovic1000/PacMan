#include <fstream>
#include <iostream>
#include "Map.h"
#include "B_BaseTile.h"
#include "IEntity.h"
#include "TileSize.h"

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

	int index = 0;

	int x = 0;
	int y = 0;

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


			m_mapParts[index] = new B_BaseTile();

			switch (tile)
			{
			case('#'):
				m_mapParts[index]->Init("assets/MapTiles/wall.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(true);
				m_mapParts[index]->SetCollisionFlags(GHOST | PACMAN);
				break;

			case('-'):
				m_mapParts[index]->Init("assets/MapTiles/pathD.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(false);
				break;

			case('|'):
				m_mapParts[index]->Init("assets/MapTiles/pathV.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(false);
				break;

			case('{'):
				m_mapParts[index]->Init("assets/MapTiles/cornerTL.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(false);
				break;

			case('}'):
				m_mapParts[index]->Init("assets/MapTiles/cornerTR.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(false);
				break;

			case('\\'):
				m_mapParts[index]->Init("assets/MapTiles/cornerBL.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(false);
				break;

			case('/'):
				m_mapParts[index]->Init("assets/MapTiles/cornerBR.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(false);
				break;

			case('<'):
				m_mapParts[index]->Init("assets/MapTiles/crossoverL.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(false);
				break;

			case('>'):
				m_mapParts[index]->Init("assets/MapTiles/crossoverR.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(false);
				break;

			case('^'):
				m_mapParts[index]->Init("assets/MapTiles/crossoverT.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(false);
				break;

			case('!'):
				m_mapParts[index]->Init("assets/MapTiles/crossoverB.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(false);
				break;

			case('E'):
				m_mapParts[index]->Init("assets/MapTiles/empty.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(true);
				m_mapParts[index]->SetCollisionFlags(PACMAN);
				break;

			case('D'):
				m_mapParts[index]->Init("assets/MapTiles/Door.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(true);
				m_mapParts[index]->SetCollisionFlags(PACMAN);
				break;

			case '\n':
				y++;
				x = 0;
				continue;

			default:
				std::cout << "Failed To Locate Tile" << std::endl;
				m_mapParts[index]->Init("assets/MapTiles/TestBlock.bmp", x * TileSize, y * TileSize, TileSize, TileSize, true);
				m_mapParts[index]->SetCollide(true);
				m_mapParts[index]->SetCollisionFlags(GHOST | PACMAN);
				break;
			}

			x++;
			index++;
		}
	}

	bitmap.close();

}

Map::~Map()
{
}
