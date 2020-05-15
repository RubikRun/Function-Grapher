#include "Grapher.h"

Grapher::Grapher()
{
	//Set center and scaler to default
	m_center = CENTER_DEFAULT;
	m_scaler = SCALER_DEFAULT;
	//Set function and window to null
	m_function = nullptr;
	m_window = nullptr;
}

//Returns the center of the grapher
sf::Vector2f Grapher::GetCenter()
{
	return m_center;
}

//Sets the center of the grapher
void Grapher::SetCenter(sf::Vector2f center)
{
	m_center = center;
}

//Returns the scaler of the grapher
sf::Vector2f Grapher::GetScaler()
{
	return m_scaler;
}

//Sets the scaler of the grapher
void Grapher::SetScaler(sf::Vector2f scaler)
{
	m_scaler = scaler;
}