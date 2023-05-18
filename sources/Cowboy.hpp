#pragma once
#include "Character.hpp"

using namespace std;

namespace ariel{

class Cowboy : public Character
{
private:
    int boolets;
public:
    Cowboy(const char* name, Point Location);
    void shoot(Character* enemy);
    bool hasboolets();
    void reload();
    string print() override;
    // ~Cowboy() override{
    //     delete this;
    // }
    
};






}