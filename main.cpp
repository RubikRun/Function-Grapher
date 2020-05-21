#include <iostream>
#include <cmath>

#include "Grapher.hpp"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

using namespace std;
using namespace sf;

const float ZOOM_IN_FACTOR = 1.05;
const float ZOOM_OUT_FACTOR = 0.95;

int main()
{
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "Function Grapher", sf::Style::Fullscreen);
	window.setFramerateLimit(60);
	//window.setMouseCursorVisible(false);

    Grapher grapher(
        [](Vector2f p) { Vector2f r = {
			cos(p.x) * p.y,
			sin(p.x) * p.y
		}; return r; },
		{(float)window.getSize().x / 2, (float)window.getSize().y / 2},
        {600, 600},
        &window
    );

	float t = 1;

	bool moveMode = false;
	Vector2f lastPoint;

	Event event;
	while (window.isOpen())
	{
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			window.close();
		}
		while (window.pollEvent(event))
		{
			if (event.type == Event::MouseWheelMoved)
			{
				float wheel = (float) event.mouseWheel.delta;
				float zoomFactor = (wheel > 0) ? ZOOM_IN_FACTOR : ZOOM_OUT_FACTOR;
				Vector2f sclFactor(zoomFactor, zoomFactor);
				grapher.Scale(sclFactor);
			}
		}

		//Clear

		window.clear();

		//Update

		if (Mouse::isButtonPressed(Mouse::Left))
		{
			if (moveMode)
			{
				Vector2f mouse = (Vector2f)Mouse::getPosition();
				Vector2f delta = mouse - lastPoint;

				grapher.MoveCenter(delta);

				lastPoint = mouse;
			}
			else
			{
				moveMode = true;
				lastPoint = (Vector2f)Mouse::getPosition();
			}
		}
		else
		{
			moveMode = false;
		}

		t += 0.0001;

		//Draw

        grapher.Graph([=](float x) { return sin(x * t); }, {0, 100}, 4000);

		//Render

		window.display();
	}

	return 0;
}