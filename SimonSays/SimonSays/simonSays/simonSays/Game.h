/// <summary>
/// author EmmaMcdonald
/// you need to change the above line or lose marks
/// </summary>
#ifndef GAME_HPP
#define GAME_HPP
/// <summary>
/// include guards used so we don't process this file twice
/// same as #pragma once
/// Don't forget the endif at the bottom
/// </summary>
#include <SFML/Graphics.hpp>

const sf::Color RED{ 180,0,0,255 };
const sf::Color BLUE{ 0,0,180,255 };
const sf::Color YELLOW{180,180,0,255};
const sf::Color GREEN{0,180,0,255};

enum class GameModes
{
	Starting  ,
	Showing,
	Recieving ,
	GameOver

};

class Game
{
public:
	Game();
	~Game();
	/// <summary>
	/// main method for game
	/// </summary>
	void run();

private:

	void processEvents();
	void processKeys(sf::Event t_event);
	void update(sf::Time t_deltaTime);
	void render();
	
	void setupFontAndText();

	void RectangleShape();

	sf::RenderWindow m_window; // main SFML window
	sf::Font m_ArialBlackfont; // font used by message
	sf::Text m_welcomeMessage; // text used for message on screen
	sf::Text m_redText;
	sf::Text m_greenText;
	sf::Text m_yellowText;
	sf::Text m_blueText;
	sf::Texture m_logoTexture; // texture used for sfml logo
	
	sf::RectangleShape m_RectangleShapeYellow;//rectangle shape for button 
	sf::RectangleShape m_RectangleShapeBlue;
	sf::RectangleShape m_RectangleShapeRed;
	sf::RectangleShape m_RectangleShapeGreen;
	
	bool m_exitGame; // control exiting game

	GameModes m_activeGameModes = GameModes::Starting;
};

#endif // !GAME_HPP

