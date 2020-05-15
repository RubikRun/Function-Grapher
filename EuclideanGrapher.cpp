#include "EuclideanGrapher.h"

EuclideanGrapher::EuclideanGrapher(float (*function)(float), sf::RenderWindow* window)
{
	m_function = function;
	m_window = window;
}

void EuclideanGrapher::Graph(unsigned pointsCount, sf::Vector2f xInterval)
{
	//If no x interval is specified, we want to cover the whole width of the window
	if (xInterval == INTERVAL_INVALID)
	{
		xInterval = this->GetCoveringInterval();
	}
	//Find the horizontal real distance between two points on the graph,
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

sf::Vector2f EuclideanGrapher::GetPixel(sf::Vector2f point)
{
	return sf::Vector2f(
		point.x * m_scaler.x + m_center.x,
		point.y * m_scaler.y + m_center.y
	);
}

sf::Vector2f EuclideanGrapher::GetCoveringInterval()
{
	return sf::Vector2f(
		(0 - m_center.x) * m_scaler.x,
		(m_window->getSize().x - 1 - m_center.x) * m_scaler.x
	);
}