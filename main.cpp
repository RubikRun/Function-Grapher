#include <iostream>
#include <cmath>

#include "Grapher.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Function Grapher", sf::Style::Fullscreen);
	window.setFramerateLimit(60);

    Grapher grapher(
        [](Vector2f p) { Vector2f r = {
			cos(p.x) * p.y,
			sin(p.x) * p.y
		}; return r; },
		{(float)window.getSize().x / 2, (float)window.getSize().y / 2},
        {1000, 1000},
        &window
    );

	float t = 0;

	while (window.isOpen())
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			window.close();
		}

		//Clear

		window.clear();

		//Draw

        grapher.Graph([=](float x) { return sin(x * t); }, {0, 100}, 2000);

		t += 0.00005;

		//Render

		window.display();
	}

	return 0;
}