
#include "Team2.hpp"

using namespace std;

namespace ariel{

    Team2::Team2(Character* lead): Team::Team(lead){}

    void Team2::print(){

        cout <<"The Group Members are:\n";
        for (size_t i = 0; i < this->get_Team().size(); i++)
        {
            cout <<this->get_Team()[i]->print();
        }

    }





    // size_t Team2::closest_toLeader( vector <Character*> team){
    //     double min_dist = numeric_limits<double>::max(), temp_min;
    //     size_t min_index = 0;
    //             for (size_t i = 0; i < team.size(); i++)
    //             {
    //                 // if(j == 0 && team[i]->getType() =='N' || j == 1 && team[i]->getType() == 'C') continue;
    //                  if (! team[i]->isAlive()) continue;                
    //                 else if(team[i]->isLeader()) continue;                  
    //                 temp_min = this->get_Leader()->distance(team[i]);
    //                 if (temp_min < min_dist)
    //                 {
    //                     min_dist = temp_min;
    //                     min_index = i; 
    //                 } 
    //             }  
    //     return min_index;
    // }

    // void Team2::attack(Team* enemies){
    //     if (this->stillAlive() == 0 || enemies->stillAlive() == 0)
    //     {
    //         return;
    //     }   
    //     this->check_Leader();
    //     Character* enemy = enemies->get_Team()[this->closest_toLeader(enemies->get_Team())];
    //     for (size_t i = 0; i < this->get_Team().size(); i++)
    //         {
    //             if (! enemy->isAlive())
    //             {
    //                 enemy = enemies->get_Team()[this->closest_toLeader(enemies->get_Team())];
    //             }
    //             else if( ! this->get_Team()[i]->isAlive()) continue;             
    //             if (this->get_Team()[i]->getType() == 'C' )
    //             {
    //                 Cowboy* my_cowboy = dynamic_cast<Cowboy*>(this->get_Team()[i]);                   
    //                 if( ! my_cowboy->hasboolets() ) my_cowboy->reload();
    //                 else my_cowboy->shoot(enemy);                   
    //             }               
    //             else if(this->get_Team()[i]->getType() == 'N'){
    //                 Ninja* my_Ninja = dynamic_cast<Ninja*>(this->get_Team()[i]);
    //                 if(my_Ninja->distance(enemy) <= 1) my_Ninja->slash(enemy);
    //                 else my_Ninja->move(enemy);
    //             }
    //         }
    // }

    size_t Team2::closest_to_Member(Character* member, Team* group){
    
    double min_dist = numeric_limits<double>::max(), temp_min;
    size_t min_index = 0;   

      for (size_t i = 0; i < group->get_Team().size(); i++)
      {
         if(! group->get_Team()[i]->isAlive()) continue;

         else if(group->get_Team()[i] == member) continue;
                        
         temp_min = member->distance(group->get_Team()[i]);

         if (temp_min < min_dist)
         {
            min_dist = temp_min;
            min_index = i; 
         } 
      }  
      return min_index;

    }

    void Team2::attack(Team* enemies){

        if(enemies == nullptr) throw invalid_argument("nul_ptr\n");

        else if (this->stillAlive() == 0 || enemies->stillAlive() == 0)
        {
            throw runtime_error("dead enemies can not be attacked.\n dead group should not attack\n");
        }

        this->check_Leader();

        Character* enemy = enemies->get_Team()[this->closest_to_Member(this->get_Leader(), enemies)];

        for (size_t i = 0; i < this->get_Team().size(); i++)
        {
            if(this->stillAlive() == 0 || enemies->stillAlive() == 0) return;
                
            else if( ! this->get_Team()[i]->isAlive()) continue;

            else if (! enemy->isAlive())
            {
                enemy = enemies->get_Team()[this->closest_to_Member(this->get_Leader(), enemies)];
            }
                
            if (this->get_Team()[i]->getType() == 'C')
            {
                Cowboy* my_cowboy = dynamic_cast<Cowboy*>(this->get_Team()[i]);
                    
                if( my_cowboy->hasboolets() ) my_cowboy->shoot(enemy);

                else my_cowboy->reload();
                    
            }
                
            else if(this->get_Team()[i]->getType() == 'N')
            {

                Ninja* my_Ninja = dynamic_cast<Ninja*>(this->get_Team()[i]);

                if(my_Ninja->distance(enemy) <= 1) my_Ninja->slash(enemy);

                else my_Ninja->move(enemy);
            }
        }       
    }


}