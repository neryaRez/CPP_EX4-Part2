#include "Character.hpp"


using namespace std;

namespace ariel{

Character::Character(const char* Name, Point Location): name(Name), location(Location) { 
   this->part_of = false;
   this->is_leader = false;
}

 Point Character::getLocation(){
    return this->location;
 }

 string Character::getName(){
    return this->name;
 }

 bool Character::isAlive(){
    return this->hit_Points > 0;
 }

 double Character::distance(Character* other){
    return this->location.distance(other->location);
 }

 void Character::hit(int h){
    this->hit_Points -= h;
 }
 
   Character::~Character() {
        
 }

   char Character::getType(){
      return this->type;
 }

   bool Character::is_Partof(){
      return this->part_of;
 }

   void Character::setPart_of(){
      this->part_of = true;
 }
   void Character::make_leader(){
      this->is_leader = true;
 }
   bool Character::isLeader(){
         return this->is_leader;
 }


   
 








}