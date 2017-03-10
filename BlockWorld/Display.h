#pragma once
#include <string>
#include <memory>
#include <SFML\Graphics.hpp>

class Display
{
public:
	Display(std::string title);
	~Display();
	void close();
	void checkForClose();
	bool isSelect();

private:
	std::unique_ptr<sf::RenderWindow> window;
	const int WIDTH = 1080;
	const int HEIGHT = 720;
};

