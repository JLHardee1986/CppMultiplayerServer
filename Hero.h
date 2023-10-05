#pragma once

#include <SFML/Graphics.hpp>
#include <string>
#include <map>
class Hero
{
public:

	enum class Dir
	{
		North = 0, South, East, West, NorthWest, NorthEast, SouthWest, SouthEast
	};



private:

	
public:
	std::map<Dir, sf::IntRect> m_rects;
	sf::Texture m_tex;
	sf::Sprite m_spr;
	int m_xpos{ 40 };
	int m_ypos{ 400 };
	int m_frameH{ 0 };
	int m_frameW{ 0 };
	Dir m_dir{ Dir::South };
	int m_numFrames{ 0 };
	int m_currFrame{ 0 };
	Dir m_currAnim{ Dir::South };
	float m_animDelay{ 0.f };

	Hero(std::string l_texFile);
	
};