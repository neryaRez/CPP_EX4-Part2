
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
        if(this->isAlive()&& this->hasboolets()){
            enemy->hit(10);
        }
    }
    void Cowboy::reload(){
        this->boolets = 6;
    }
    string Cowboy::print(){
        string str = "";
        if (this->isAlive())
        {
            str +=("C "+this->getName()+"\n");
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