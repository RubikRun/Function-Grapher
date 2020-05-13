#pragma once

#include "Function.h"
#include "SFML/Graphics.hpp"
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class EuclideanFunction : public Function
{
	private:

		//Applies the function on a pixel level.
		//Finds pixel's y for a given pixel's x and returns it.
		float PixelFunction(float pixelX, const sf::Vector2f& center, const sf::Vector2f scaler);


	public:

		//Creates an EuclideanFunction object for the given mathematical function
		EuclideanFunction(float (*function)(float));

		virtual void Graph
		(
			sf::RenderWindow& window,
			const sf::Vector2f& center = CENTER_DEFAULT,
			const sf::Vector2f scaler = SCALER_DEFAULT,
			unsigned pointsCount = POINTSCOUNT_DEFAULT,
			const sf::Color& color = COLOR_DEFAULT
		);
};