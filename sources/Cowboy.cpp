
#include "Cowboy.hpp"

using namespace std;

namespace ariel{

    Cowboy::Cowboy(const char* name, Point Location): Character::Character(name, Location){
        this->type = 'C';
        this->hit_Points = 110;
        this->boolets = 6;
    }

    bool Cowboy::hasboolets(){
        return this->boolets > 0;
    }

    void Cowboy::shoot(Character* enemy){
    if (! this->isAlive() || ! enemy->isAlive())
    {
        throw runtime_error("Dead characters cannot attack and characters cannot attack a dead enemy\n");
    }
    else if(this == enemy)
    {
        throw runtime_error("no self harm\n");
    }

    else if(this->hasboolets()){
        enemy->hit(10);
        this->boolets -=1;
    }
        
    }
    void Cowboy::reload(){
        if(! this->isAlive()){
            throw runtime_error("Dead cowboy can not reload\n");
        }

        this->boolets = 6;
    }
    string Cowboy::print(){
        string str = "";
        if (this->isAlive())
        {
            str +=("C "+this->getName()+", ");
            str +=("Life points: "+to_string(this->hit_Points));
            str +=", ";

        }
        else
        {
            str+= ("C (" +this->getName() + ")" +", ");
        }
        str+=location.print();
        str+="\n";
        return str;

    }






}