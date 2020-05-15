#pragma once

#include "SFML/Graphics.hpp"
#include "Constants.h"

//An abstract class used to graph a mathematical function f : R -> R
class Grapher
{
protected:

	//The function that we want to graph
	float (*m_function)(float);

	//The window to which the function will be graphed
	sf::RenderWindow* m_window;
	//The point (in pixel coordinates) around which the function will be graphed
	sf::Vector2f m_center;
	//The amount by which the function will be scaled (real -> pixel)
	sf::Vector2f m_scaler;

public: 

	//Creates a default grapher
	Grapher();
	
	//Graphs the given interval of the function, using the number of points specified
	virtual void Graph(unsigned pointsCount, sf::Vector2f xInterval) = 0;

	//Returns the center of the grapher
	sf::Vector2f GetCenter();

	//Sets the center of the grapher
	void SetCenter(sf::Vector2f center);

	//Returns the scaler of the grapher
	sf::Vector2f GetScaler();

	//Sets the scaler of the grapher
	void SetScaler(sf::Vector2f scaler);
};