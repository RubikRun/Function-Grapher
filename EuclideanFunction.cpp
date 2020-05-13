#pragma once

#include "EuclideanFunction.h"
#include "SFML/Graphics.hpp"
#include <SFML/Window.hpp>

EuclideanFunction::EuclideanFunction(float(*function)(float))
{
	this->m_function = function;
}

float EuclideanFunction::PixelFunction(float pixelX, const sf::Vector2f& center, const sf::Vector2f scaler)
{
	//The euclidean point corresponding to the pixel
	sf::Vector2f point;
	//Find the point's x
	point.x = (pixelX - center.x) / scaler.x;
	//Apply the function to the point's x to get the point's y
	point.y = -(*this->m_function)(point.x);
	//Find the pixel's y corresponding to that point's y
	float pointY = point.y * scaler.y + center.y;

	return pointY;
}

void EuclideanFunction::Graph(sf::RenderWindow& window, const sf::Vector2f& center,
	const sf::Vector2f scaler, unsigned pointsCount, const sf::Color& color)
{
	//Calculate the horizontal distance between two points on the graph
	const float pointDist = window.getSize().x / (float)(pointsCount - 1);
	//Create a vertex array for all the points of the graph
	sf::VertexArray points(sf::LinesStrip, pointsCount);

	//Find points
	for (int i = 0; i < (int)pointsCount; i++)
	{
		sf::Vector2f point;
		//Find point's x
		point.x = i * pointDist;
		//Apply the function to get get point's y
		point.y = this->PixelFunction(point.x, center, scaler);

		points[i] = point;
	}

	//Draw the graph by connecting all the points with lines
	window.draw(points);
}