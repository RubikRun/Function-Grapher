#include <functional>

#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

//A class used to graph functions in a custom coordinate system
class Grapher
{
    //The coordinate system.
    //Takes in a point and returns the corresponding point in the coordinate system
    function<Vector2f(Vector2f)> m_coordSys;

    //The center of the coordinate system in pixel coordinates
    Vector2f m_center;

    //The factor by which we want to stretch in the x and y direction
    //before applying the coordinate system
    Vector2f m_sclFtr;

    //The window to which the function's graph will be rendered
    RenderWindow* m_window;

    public:

        //Creates a grapher for the given coordinate system with the given scale factor
        Grapher(const function<Vector2f(Vector2f)>& coordSys, Vector2f center, Vector2f sclFtr, RenderWindow* window);

        //Graphs the interval of the function using evenly spaced points
        void Graph(const function<float(float)>& func, Vector2f interval, unsigned pointsCnt);

        //Multiplies the scaling factor by a given factor
        void Scale(Vector2f factor);

        //Assigns the center a new value
        void SetCenter(Vector2f center);

        //Moves the center by the given delta
        void MoveCenter(Vector2f delta);

    private:

        //Returns the pixel corresponding to the given point in real space
        Vector2f GetPixel(Vector2f pointInR);
};