#pragma once
#include <string>
#include <memory>
#include <SFML\Graphics.hpp>

class Display
{
public:
	static Display& get(std::string title);
	Display(std::string title);
	void close();
	void checkForClose();
	bool isSelect();
	const sf::Window& get();

	const static int WIDTH = 1080;
	const static int HEIGHT = 720;

private:
	std::unique_ptr<sf::RenderWindow> m_window;	
};

