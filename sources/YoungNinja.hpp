#pragma once
#include "Ninja.hpp"

namespace ariel{

class YoungNinja : public Ninja
{
private:
    
public:
    YoungNinja(const char* name, Point Location): Ninja::Ninja(name, Location){
        this->hit_Points = 100;
        this->speed = 14;
    } 
    
};


}