#pragma once
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

using namespace std;
namespace ariel{

class Point
{
private:
    double x;
    double y;
public:
    Point(double x, double y);
    double distance(const Point& other) const;
    static Point moveTowards(const Point& source, const Point& dest, double dist);
    string print();
    double getX();
    double getY();
    bool operator == (const Point other) const;

};



}