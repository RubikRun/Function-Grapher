#pragma once

#include "Grapher.h"
#include "Constants.h"

class PolarGrapher : public Grapher
{
public:

	//Creates a polar grapher that graphs the given function to the given window
	PolarGrapher(float (*function)(float), sf::RenderWindow* window);

	//Graphs the function in polar coordinates
	void Graph(unsigned pointsCount = POINTSCOUNT_DEFAULT,
		sf::Vector2f xInterval = INTERVAL_DEFAULT) override;

private:

	//Converts a real point to a pixel, using the center and the scaler
	sf::Vector2f GetPixel(sf::Vector2f point);
};