#pragma once

#include "Grapher.h"
#include "Constants.h"

class EuclideanGrapher : public Grapher
{
public:

	//Creates an euclidean grapher that graphs the given function to the given window
	EuclideanGrapher(float (*function)(float), sf::RenderWindow* window);

	//Graphs the function in euclidean coordinates
	void Graph(unsigned pointsCount = POINTSCOUNT_DEFAULT,
		sf::Vector2f xInterval = INTERVAL_INVALID) override;

private:

	//Converts a real point to a pixel, using the center and the scaler
	sf::Vector2f GetPixel(sf::Vector2f point);

	//Returns a real x interval that corresponds to the width of the window
	sf::Vector2f GetCoveringInterval();
};