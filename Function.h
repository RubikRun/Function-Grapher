#pragma once

#include "SFML/Graphics.hpp"

const sf::Vector2f CENTER_DEFAULT(960.f, 540.f);
const sf::Vector2f SCALER_DEFAULT(100.f, 100.f);
const unsigned POINTSCOUNT_DEFAULT = 1920;
const sf::Color COLOR_DEFAULT = sf::Color::White;

//An abstract class that holds a mathematical function and the ability to graph it
class Function
{
	//The actual mathematical function
	protected: 

		float (*m_function)(float) = 0;

	public:

		//Graphs the function.
		//center is a point around which the function will be graphed.
		//scaler is the amount by which we want to scale the function in the x and y direction.
		//pointsCount is the number of points used for the graph, more points meaning smoother graph.
		virtual void Graph
		(
			sf::RenderWindow& window, 
			const sf::Vector2f& center,
			const sf::Vector2f scaler,
			unsigned pointsCount,
			const sf::Color& color
		) = 0;
};