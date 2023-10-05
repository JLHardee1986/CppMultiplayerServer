#include "pch.h"


Hero::Hero(std::string l_texFile)
	: m_tex()
	, m_spr(sf::Texture())
	, m_rects()
{
	m_rects.clear();

	// South anim frames
	
	m_frameW = 146;
	m_frameH = 158;
	m_numFrames = 16;
	m_currFrame = 0;
	m_animDelay = .6f;
	m_rects.insert(std::map<Dir, sf::IntRect>::value_type(Dir::South, sf::IntRect(0, 0, m_frameW, m_frameH)));

	m_currAnim = Dir::South;


	m_tex.loadFromFile(l_texFile);
	m_spr.setTexture(m_tex);
	m_spr.setTextureRect(m_rects[Dir::South]);

}