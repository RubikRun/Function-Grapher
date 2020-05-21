#include "Grapher.hpp"

Grapher::Grapher(const function<Vector2f(Vector2f)>& coordSys, Vector2f center, Vector2f sclFtr, RenderWindow* window)
{
    m_coordSys = coordSys;
    m_center = center;
    m_sclFtr = sclFtr;
    m_window = window;
}

void Grapher::Graph(const function<float(float)>& func, Vector2f interval, unsigned pointsCnt)
{
    float intervalLen = interval.y - interval.x;
    //The difference between two consecutive points on the interval in real space (R^2)
    float xDifInR = intervalLen / (pointsCnt - 1);

    //The points on the graph that we will use to draw it
    //We will connect every two consecutive points with a line
    VertexArray points(LinesStrip, pointsCnt);

    //Find the points
    for (int i = 0; i < (int)pointsCnt; i++)
    {
        //Find point in real space
        Vector2f pointInR;
        pointInR.x = interval.x + i * xDifInR;
        pointInR.y = func(pointInR.x); //Apply the function to find y coordinate of the point in real space

        //Find the corresponding pixel
        points[i] = this->GetPixel(pointInR);
    }

    //Draw the graph
    m_window->draw(points);
}

Vector2f Grapher::GetPixel(Vector2f pointInR)
{
    //Find point in the custom coordinate system
    Vector2f pointInCS = m_coordSys(pointInR);
    //Find the point in pixel space (find the corresponding pixel)
    Vector2f pointInP(m_center.x + pointInCS.x * m_sclFtr.x,
        m_center.y - pointInCS.y * m_sclFtr.y);

    return pointInP;
}

void Grapher::Scale(Vector2f factor)
{
    m_sclFtr.x *= factor.x;
    m_sclFtr.y *= factor.y;
}

void Grapher::SetCenter(Vector2f center)
{
    m_center = center;
}

void Grapher::MoveCenter(Vector2f delta)
{
    m_center += delta;
}