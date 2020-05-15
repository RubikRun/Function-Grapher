#include "PolarGrapher.h"

#include "cmath"

PolarGrapher::PolarGrapher(float (*function)(float), sf::RenderWindow* window)
{
	m_function = function;
	m_window = window;
}

void PolarGrapher::Graph(unsigned pointsCount, sf::Vector2f xInterval)
{
	//Find the angle (distance) between two points on the graph,
	//assuming the points will be evenly spaced
	float intervalLength = xInterval.y - xInterval.x;
	float pointDist = intervalLength / (pointsCount - 1);

	//Create a vertex for the pixels correspoding to points on the graph
	sf::VertexArray pixels(sf::LinesStrip, pointsCount);
	//Find pixels
	for (int i = 0; i < (int)pointsCount; i++)
	{
		sf::Vector2f point;
		//Find the x of the i-th point
		point.x = xInterval.x + pointDist * i;
		//Apply the function to find the y
		point.y = (*m_function)(point.x);

		//Find the pixel corresponding to that point, and add it to pixels
		sf::Vector2f pixel = this->GetPixel(point);
		pixels[i] = pixel;
	}

	//Draw the graph by connecting all the pixels with lines
	m_window->draw(pixels);
}

sf::Vector2f PolarGrapher::GetPixel(sf::Vector2f point)
{
	double angle = (double)point.x * (double)m_scaler.x;
	double radius = (double)point.y * (double)m_scaler.y;

	return sf::Vector2f(
		cos(angle) * radius + m_center.x,
		sin(angle) * radius + m_center.y
	);
}