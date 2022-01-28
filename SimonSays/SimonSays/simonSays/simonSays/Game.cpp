/// <summary>
/// @author EmmaMcdonald
/// @date 21 jan
///
/// you need to change the above lines or lose marks
/// </summary>

#include "Game.h"
#include <iostream>



/// <summary>
/// default constructor
/// setup the window properties
/// load and setup the text 
/// load and setup thne image
/// </summary>
Game::Game() :
	m_window{ sf::VideoMode{ 800U, 600U, 32U }, "SFML Game" },
	m_exitGame{false} //when true game will exit
{
	setupFontAndText(); // load font 
	
	RectangleShape();//shape rect
}

/// <summary>
/// default destructor we didn't dynamically allocate anything
/// so we don't need to free it, but mthod needs to be here
/// </summary>
Game::~Game()
{
}


/// <summary>
/// main game loop
/// update 60 times per second,
/// process update as often as possible and at least 60 times per second
/// draw as often as possible but only updates are on time
/// if updates run slow then don't render frames
/// </summary>
void Game::run()
{	
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	const float fps{ 60.0f };
	sf::Time timePerFrame = sf::seconds(1.0f / fps); // 60 fps
	while (m_window.isOpen())
	{
		processEvents(); // as many as possible
		timeSinceLastUpdate += clock.restart();
		while (timeSinceLastUpdate > timePerFrame)
		{
			timeSinceLastUpdate -= timePerFrame;
			processEvents(); // at least 60 fps
			update(timePerFrame); //60 fps
		}
		render(); // as many as possible
	}
}
/// <summary>
/// handle user and system events/ input
/// get key presses/ mouse moves etc. from OS
/// and user :: Don't do game update here
/// </summary>
void Game::processEvents()
{
	sf::Event newEvent;
	while (m_window.pollEvent(newEvent))
	{
		if ( sf::Event::Closed == newEvent.type) // window message
		{
			m_exitGame = true;
		}
		if (sf::Event::KeyPressed == newEvent.type) //user pressed a key
		{
			processKeys(newEvent);
		}
	}
}


/// <summary>
/// deal with key presses from the user
/// </summary>
/// <param name="t_event">key press event</param>
void Game::processKeys(sf::Event t_event)
{
	if (sf::Keyboard::Escape == t_event.key.code)
	{
		m_exitGame = true;
	}
}

/// <summary>
/// Update the game world
/// </summary>
/// <param name="t_deltaTime">time interval per frame</param>
void Game::update(sf::Time t_deltaTime)
{
	if (m_exitGame)
	{
		m_window.close();
	}
}

/// <summary>
/// draw the frame and then switch buffers
/// </summary>
void Game::render()
{
	m_window.clear(sf::Color::Black);
	m_window.draw(m_welcomeMessage);
	m_window.draw(m_redText);
	m_window.draw(m_greenText);
	m_window.draw(m_yellowText);
	m_window.draw(m_blueText);
	
	m_window.draw(m_RectangleShapeRed);
	m_window.draw(m_RectangleShapeBlue);
	m_window.draw(m_RectangleShapeGreen);
	m_window.draw(m_RectangleShapeYellow);
	m_window.display();
	
}

/// <summary>
/// load the font and setup the text message for screen
/// </summary>
void Game::setupFontAndText()
{
	if (!m_ArialBlackfont.loadFromFile("ASSETS\\FONTS\\ariblk.ttf"))
	{
		std::cout << "problem loading arial black font" << std::endl;
	}
	m_welcomeMessage.setFont(m_ArialBlackfont);
	m_welcomeMessage.setString("Simon\nSays");
	m_welcomeMessage.setStyle(sf::Text::Underlined | sf::Text::Italic | sf::Text::Bold);
	m_welcomeMessage.setPosition(40.0f, 40.0f);
	m_welcomeMessage.setCharacterSize(45U);
	m_welcomeMessage.setOutlineColor(sf::Color::White);
	m_welcomeMessage.setFillColor(sf::Color::Black);
	m_welcomeMessage.setOutlineThickness(3.0f);

	m_greenText.setFont(m_ArialBlackfont);
	m_greenText.setCharacterSize(30U);
	m_greenText.setString("Press Green \nEasy Game");
	m_greenText.setPosition(50.0f,195.0f);
	m_greenText.setFillColor(GREEN);


	m_yellowText.setFont(m_ArialBlackfont);
	m_yellowText.setCharacterSize(30U);
	m_yellowText.setString("Press Yellow for\nMedium Game  ");
	m_yellowText.setPosition(50.0f, 290.0f);
	m_yellowText.setFillColor(YELLOW);

	 

	m_redText.setFont(m_ArialBlackfont);
	m_redText.setCharacterSize(30U);
	m_redText.setString("Press Red for\nHard Game ");
	m_redText.setPosition(50.0f,385.0f);
	m_redText.setFillColor(RED);


	m_blueText.setFont(m_ArialBlackfont);
	m_blueText.setCharacterSize(30U);
	m_blueText.setString("Press Blue for\nExit Game ");
	m_blueText.setPosition(50.0f, 480.0f);
	m_blueText.setFillColor(BLUE);


}


void Game::RectangleShape()
{
	m_RectangleShapeRed.setFillColor(sf::Color{ RED});
	m_RectangleShapeRed.setSize(sf::Vector2f(200, 200));
	m_RectangleShapeRed.setPosition(sf::Vector2f(555, 30));

	m_RectangleShapeBlue.setFillColor(sf::Color{ BLUE });
    m_RectangleShapeBlue.setSize(sf::Vector2f(200, 200));
	m_RectangleShapeBlue.setPosition(sf::Vector2f(555,250));

	m_RectangleShapeGreen.setFillColor(sf::Color{ GREEN });
	m_RectangleShapeGreen.setSize(sf::Vector2f(200, 200));
	m_RectangleShapeGreen.setPosition(sf::Vector2f(335, 30));

	m_RectangleShapeYellow.setFillColor(sf::Color{ YELLOW });
	m_RectangleShapeYellow.setSize(sf::Vector2f(200, 200));
	m_RectangleShapeYellow.setPosition(sf::Vector2f(335, 250));


}


