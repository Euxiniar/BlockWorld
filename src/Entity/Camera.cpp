#include "Camera.h"
#include "../Maths/Noise_Generator.h"
#include <cmath>
#include <SFML\Window\Keyboard.hpp>
#include <SFML\Window\Mouse.hpp>
#include <iostream>

Camera::Camera()
{
	sf::Mouse::setPosition(sf::Vector2i{ centerX, centerY }, Display::get().getWindow());

	rotation.x = 0;
	rotation.y = 0;
	rotation.z = 0;
	position.y = 500;
}

void Camera::input(float dt)
{
	Vector3 change;
	static bool isFalling=false;
	static bool fly = false;
	float speed = 6;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
	{
		change.x -= cos(glm::radians(rotation.y + 90)) * speed; //0 initialement
		change.z -= sin(glm::radians(rotation.y + 90)) * speed; //-speed initialement
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		change.x += cos(glm::radians(rotation.y + 90)) * speed;
		change.z += sin(glm::radians(rotation.y + 90)) * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q))
	{
		change.x -= cos(glm::radians(rotation.y)) * speed;
		change.z -= sin(glm::radians(rotation.y)) * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		change.x += cos(glm::radians(rotation.y)) * speed;
		change.z += sin(glm::radians(rotation.y)) * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::LShift))
	{
		change.y -= sin(glm::radians(90.0f)) * speed;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		change.y += sin(glm::radians(90.0f)) * speed;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::F))
	{
			fly = !fly;
	}
	position += change * dt;

	if (static_cast<int>(position.y - 3) > static_cast<int>(-Noise::Generator::get().getValue((int)position.x, (int)position.z, 1, 1)) && !fly)
	{
		if (isFalling == false)
		{
			isFalling = true;
			m_clock.restart();
		}
		//position.y -= dt*10;
		//1/2*rho*v^2*surface*1  1.125
		float elapsedTime = (float)m_clock.getElapsedTime().asSeconds();
		position.y += (float)(-(5.8 * pow(elapsedTime, 2)) / 2)+(1/2*1.125*pow((-5.8*elapsedTime),2));
		//-1/2*gt^2 
	}
	else
		isFalling = false;
	float dtMouse = 0.18f;

	mouseInput(dtMouse);
}

void Camera::mouseInput(float dtMouse)
{
	static sf::Vector2i lastMousePosition = sf::Mouse::getPosition();
	auto mouseChange = sf::Mouse::getPosition() - lastMousePosition;

	rotation.y += mouseChange.x * dtMouse;
	rotation.x += mouseChange.y * dtMouse;

	if (rotation.x > 80)
	{
		rotation.x = 80;
	}
	else if (rotation.x < -80)
	{
		rotation.x = -80;
	}
	if (rotation.y < 0)
	{
		rotation.y = 360;
	}
	else if (rotation.y > 360)
	{
		rotation.y = 0;
	}

	sf::Mouse::setPosition(sf::Vector2i{ centerX, centerY }, Display::get().getWindow());

	lastMousePosition = sf::Mouse::getPosition();
}
