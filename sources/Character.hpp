#pragma once
#include "Point.hpp"

using namespace std;

namespace ariel{

class Character
{
private:
    string name;
    
protected:
    Point location;
    int hit_Points;
    bool part_of;
    bool is_leader;
    char type;

public:
    Character(string Name, Point Location);
    Point getLocation();
    string getName();

    bool isAlive();
    double distance(Character* other);
    void hit(int h);

    virtual string print() = 0;
    virtual ~Character();
    

    bool is_Partof();
    bool isLeader();
    char getType();
    void setPart_of();
    void make_leader();
    // bool equals(const Character* other) const;


   
};



}