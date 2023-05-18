
#include "Point.hpp"

using namespace std;
// using namespace ariel;

namespace ariel{

   Point::Point(double x1, double y1): x(x1) , y(y1){} 

    double Point::distance(const Point& other) const
    {
        double dx = this->x - other.x;
        double dy = this->y - other.y;
        return sqrt(pow(dx,2) + pow(dy, 2));

    }
   
   Point Point::moveTowards(const Point& source, const Point& dest, double dist)
   {    
        if (dist < 0)
        {
            throw invalid_argument("dist has to be greater or equal to 0\n");
        }
        
        double dx = dest.x - source.x;
        double dy = dest.y - source.y;
        double length = source.distance(dest);

        if (length <= dist) 
        {
            return dest;  
        } 
        else
        {
            double ratio = dist / length;
            double closestX = source.x + ratio * dx;
            double closestY = source.y + ratio * dy;
            return Point(closestX, closestY);  
        }

    }

    string Point::print(){
        string str ="";
        str += ( "(" + to_string(this->x) +", "+to_string(this->y)+")"+"\n" );
        return str;
    }

    double Point::getX(){
        return this->x;
    }

    double Point::getY(){
        return this->y;
    }
}
