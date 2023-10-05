#pragma once
#include <SFML/Graphics.hpp>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>

class Tile : public sf::Sprite
{
public:
	Tile()
		: sf::Sprite({ sf::Texture() })
	{
	}
};

class Tileset
{
	int m_totalTiles;
	int m_tileW;
	int m_tileH;
	int m_cols;
	int m_rows;
	std::vector<Tile> m_tiles;
	sf::Texture m_tilesheetTexture;
	void loadTiles()
	{
		for (int y = 0; y < m_rows; y++)
		{
			for (int x = 0; x < m_cols; x++)
			{
				Tile aTile;
				aTile.setTexture(this->m_tilesheetTexture);
				aTile.setTextureRect(sf::IntRect(x * m_tileW, y * m_tileH, m_tileW, m_tileH));
				m_tiles.push_back(aTile);
				
			}
		}
	}
public:
	Tileset(std::string l_tilesheet, std::string l_tilesheetInfo) 
		: m_tiles()
	{
		m_tiles.clear();
		std::ifstream infile(l_tilesheetInfo);
		infile >> m_tileW;
		infile >> m_tileH;
		infile >> m_cols;
		infile >> m_rows;
		m_totalTiles = m_cols * m_rows;
		m_tilesheetTexture.loadFromFile(l_tilesheet);
		loadTiles();
	}
	int numTiles(){	return m_totalTiles; }
	int numRows() { return m_totalTiles; }
	int numCols() { return m_totalTiles; }
	int tileW() { return m_totalTiles; }
	int tileH() { return m_tileH; }
	const std::vector<Tile>& getTiles() const { return m_tiles; }
	Tile getTile(int row, int col) { return m_tiles[row * m_cols + col]; }
	Tile getTile(int tileNum) { return m_tiles[tileNum]; }
};

class Tilemap
{
	Tileset m_tileset;
	sf::RenderWindow& r_wnd;
	std::vector<Tile> m_tilemap;

	int m_cols{0};
	int m_rows{ 0 };
	int m_tileW{ 0 };
	int m_tileH{ 0 };
	int m_totalTiles{ 0 };

public:
	Tilemap(sf::RenderWindow& l_wnd)
		: m_tileset("assets/textures/tilesets/outdoor_with_water/outdoor_with_water.png", "assets/info/tilesets/outdoor_with_water.dat")
		, r_wnd(l_wnd)
		, m_tilemap()
	{
		m_tilemap.clear();
		m_cols = 40;
		m_rows = 30;
		m_tileW = m_tileset.tileW();
		m_tileH = m_tileset.tileH();
		m_totalTiles = m_cols * m_rows;
		for (int y = 0; y < m_rows; y++)
		{
			for (int x = 0; x < m_cols; x++)
			{
				m_tilemap.push_back(m_tileset.getTile(1,0));
				m_tilemap[y * m_cols + x].setPosition(float(x * m_tileW), float(y * m_tileH));
			}
		}
	}

	void draw(int offsetX = 0, int offsetY = 0)
	{
		for (int y = 0; y < m_rows; y++)
		{
			for (int x = 0; x < m_cols; x++)
			{
				r_wnd.draw(m_tilemap[y * m_cols + x]);
			}
		}
	}

};