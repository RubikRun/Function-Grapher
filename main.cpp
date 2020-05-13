#include <iostream>

#include "EuclideanFunction.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

#include <cmath>

float myFunction(float x)
{
	return sin(x);
}

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080, 32), "Learning SFML", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

	EuclideanFunction function(myFunction);

	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		//Clear

		window.clear();

		//Draw

		function.Graph(window);

		//Render

		window.display();
	}
	return 0;
}