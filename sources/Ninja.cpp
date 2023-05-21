
#include "Ninja.hpp"

using namespace std;

namespace ariel{

Ninja::Ninja(const char* name, Point Location) :Character::Character(name, Location){
    this->type = 'N';
}

void Ninja::slash(Character* enemy){
    if (! this->isAlive() || ! enemy->isAlive())
    {
        throw runtime_error("Dead characters cannot attack and characters cannot attack a dead enemy\n");
    }
    else if(this == enemy)
    {
        throw runtime_error("no self harm\n");
    }
    else if(this->distance(enemy) <= 1){
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

