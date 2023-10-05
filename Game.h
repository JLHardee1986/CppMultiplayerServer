#pragma once
namespace sf
{
	class RenderWindow;
	class Time;
	class Clock;
}
class Tilemap;
class Hero;

class Game
{
	bool m_updateDraw{ false };
public:

	sf::Time* m_gameTime;
	sf::RenderWindow* m_wnd;
	sf::Clock* m_frameTimer;
	sf::Time* m_elapsedTime;
	sf::Time* m_60FPS_inSeconds;

	// Tilemap
	Tilemap* m_tilemap;
	Hero* m_thisPlayer;
	Hero* m_otherPlayer;


	Game();
	~Game();

	void handle_Input();
	void handle_Events();
	void update_GameFrame();
	void draw_GameFrame();

	void Init();


};