
#include "Ninja.hpp"

using namespace std;

namespace ariel{

Ninja::Ninja(const char* name, Point Location) :Character::Character(name, Location){
    this->type = 'N';
}

void Ninja::slash(Character* enemy){
    if(this->isAlive() && this->distance(enemy) <= 1){
        enemy->hit(40);
    }
}


void Ninja::move(Character* enemy){

    if(! this->isAlive()) return;

    if(this->distance(enemy) <= this->speed){
       this->location = Point::moveTowards(this->location, enemy->getLocation(), this->distance(enemy));
    }

    else
    {
        this->location = Point::moveTowards(this->location, enemy->getLocation(), this->speed);
    }
    
}

 string Ninja::print() {
    string str = "";
    if (this->isAlive())
    {
        str +=("N "+this->getName()+"\n");
        str +=("Life points: "+to_string(this->hit_Points));
        str +="\n";

    }
    else
    {
        str+= ("(" +this->getName() + ")" +"\n");
    }
    str+=location.print();
    str+="\n";
    return str;
 }










}

