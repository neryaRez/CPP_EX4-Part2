#pragma once
#include "Ninja.hpp"

namespace ariel{

class TrainedNinja : public Ninja
{
private:
    
public:
    TrainedNinja(const char* name, Point Location): Ninja::Ninja(name, Location){
        this->hit_Points = 120;
        this->speed = 12;
    } 
    
};


}