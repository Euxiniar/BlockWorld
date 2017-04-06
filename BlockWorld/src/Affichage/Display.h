#pragma once
#include <string>
#include <memory>
#include <SFML/Graphics.hpp>

class Display
{
public:
	static Display& get();
	Display();
	void setTitle(std::string title);

	void close();
	void clear();
	void update();

	void checkForClose();
	bool isOpen();
	bool isSelect();
	const sf::Window& getWindow();
	

	const static int WIDTH = 1080;
	const static int HEIGHT = 720;

private:
	std::unique_ptr<sf::RenderWindow> m_window;	
};

