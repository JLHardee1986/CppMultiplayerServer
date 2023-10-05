#include "pch.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/VideoMode.hpp>
#include <SFML/System/Time.hpp>
#include <SFML/System/Clock.hpp>

Game::Game()
	: m_gameTime(nullptr)
	, m_wnd(nullptr)
	, m_frameTimer(nullptr)
	, m_elapsedTime(nullptr)
	, m_60FPS_inSeconds(nullptr)
	, m_thisPlayer(nullptr)
	, m_otherPlayer(nullptr)
{
	m_gameTime = new sf::Time(sf::Time::Zero);
	m_wnd = new sf::RenderWindow(sf::VideoMode(1280U, 960U, 32U), "Athena an Cid's Game Online", sf::Style::Titlebar | sf::Style::Close);
	m_frameTimer = new sf::Clock();
	m_elapsedTime = new sf::Time(sf::Time::Zero);
	m_60FPS_inSeconds = new sf::Time(sf::seconds(1.f / 60.f));

	Init();
}

void Game::Init()
{
	m_tilemap = new Tilemap(*m_wnd);

	m_thisPlayer = new Hero("assets/textures/hero/hero_idle_sheet.png");
	m_otherPlayer = new Hero("assets/textures/hero/hero_idle_sheet.png");

	m_thisPlayer->m_xpos = 100;
	m_thisPlayer->m_ypos = 500;
	m_thisPlayer->m_spr.setPosition((float)m_thisPlayer->m_xpos, (float)m_thisPlayer->m_ypos);

	m_otherPlayer->m_xpos = 1000;
	m_otherPlayer->m_ypos = 500;
	m_otherPlayer->m_spr.setPosition((float)m_otherPlayer->m_xpos, (float)m_otherPlayer->m_ypos);

}




Game::~Game()
{
	delete m_thisPlayer;
	delete m_otherPlayer;
	delete m_gameTime;
	delete m_wnd;
	delete m_frameTimer;
	delete m_elapsedTime;
	delete m_60FPS_inSeconds;
}

void Game::draw_GameFrame()
{
	if (m_updateDraw == true)
	{
		m_wnd->clear(sf::Color(47, 147, 247, 255));

		// render frame of game here
		m_tilemap->draw();
		m_wnd->draw(m_thisPlayer->m_spr);
		m_wnd->draw(m_otherPlayer->m_spr);

		m_wnd->display();
	}
}

void Game::handle_Events()
{
	sf::Event e;
	while (m_wnd->pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::KeyReleased:
			if (e.key.code == sf::Keyboard::Escape)
			{
				m_wnd->close();
			}
			break;
		case sf::Event::Closed:
			m_wnd->close();
			break;
		default:
			break;
		}
	}
}

void Game::handle_Input()
{
	// Up pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{

	}

	// Left pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
	{

	}

	// Right pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
	{

	}

	// Down pressed
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{

	}
}

void Game::update_GameFrame()
{
	m_updateDraw = false;
	*this->m_elapsedTime += this->m_frameTimer->restart();
	if (*this->m_elapsedTime >= *this->m_60FPS_inSeconds)
	{
		*this->m_elapsedTime = sf::Time::Zero;
		m_updateDraw = true;
		// frame updates go here
	}
}
