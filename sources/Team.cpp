
#include "Team.hpp"

namespace ariel{

    Team::Team(Character* lead){
        // if(this->has_leader){
        //     throw runtime_error("the group already has a leader\n ");
        // }
          this->add(lead);
          this->leader = lead;  
          
        //   has_leader = true; 
           this->leader->make_leader(); 
        
    }

    void Team::check_Leader(){
        if (! this->leader->isAlive()){
             this->leader = this->my_team[this->closest_to_Member(this->leader,this)];
             this->leader->make_leader();
        }
        
    }

    void Team::attack(Team* enemies){

        if(enemies == nullptr) throw invalid_argument("nul_ptr\n");
        
        else if (this->stillAlive() == 0 || enemies->stillAlive() == 0)
        {
            return;
        }
         
        this->check_Leader();

        Character* enemy = enemies->get_Team()[this->closest_to_Member(this->leader, enemies)];

        for (size_t j = 0; j < 2; j++)
        {
            for (size_t i = 0; i < this->my_team.size(); i++)
            {
                if(this->stillAlive() == 0 || enemies->stillAlive() == 0) return;
                
                else if( ! this->my_team[i]->isAlive()) continue;

                else if (! enemy->isAlive())
                {
                    enemy = enemies->get_Team()[this->closest_to_Member(this->leader, enemies)];
                }
                
                if (this->my_team[i]->getType() == 'C' && j ==0)
                {
                    Cowboy* my_cowboy = dynamic_cast<Cowboy*>(this->my_team[i]);
                    
                    if( my_cowboy->hasboolets() ) my_cowboy->shoot(enemy);

                    else my_cowboy->reload();
                    
                }
                
                else if(this->my_team[i]->getType() == 'N' && j == 1){

                    Ninja* my_Ninja = dynamic_cast<Ninja*>(this->my_team[i]);

                    if(my_Ninja->distance(enemy) <= 1) my_Ninja->slash(enemy);

                    else my_Ninja->move(enemy);
                }
            }
        }

    }

    size_t Team::closest_to_Member(Character* member, Team* group){
            double min_dist = numeric_limits<double>::max(), temp_min;
            size_t min_index = 0;

            for (size_t j = 0; j < 2; j++)
            {
                for (size_t i = 0; i < group->get_Team().size(); i++)
                {
                    if(! group->get_Team()[i]->isAlive()) continue;

                    else if (j == 0 && group->get_Team()[i]->getType() =='N' || j == 1 && group->get_Team()[i]->getType() == 'C')
                    continue;
                    
                    else if(group->get_Team()[i]->equals(member)) continue;
                      
                    temp_min = member->distance(group->get_Team()[i]);

                    if (temp_min < min_dist)
                    {
                        min_dist = temp_min;
                        min_index = i; 
                    } 
                }                
            }
        return min_index;
    }

    int Team::stillAlive(){

        int lives = 0;
        for (size_t i = 0; i < this->my_team.size(); i++)
        {
            if(this->my_team[i]->isAlive()) lives++;
        }
        return lives;
        
    }

    void Team::add(Character* member){
        if(member->is_Partof()){
            throw runtime_error("this member is alrady part of a Group\n");
        }
        else if(this->my_team.size() == 10){
            throw runtime_error("there should be at most 10 members\n");
        }
            this->my_team.push_back(member);
            member->setPart_of();   
    }

    void Team::print(){

        cout <<"The Group Members are:\n";

        for (size_t j = 0; j < 2; j++)
        {

            for (size_t i = 0; i <this->my_team.size(); i++)
            {
                if (j == 0 && this->my_team[i]->getType() == 'C')
                {
                    cout <<this->my_team[i]->print();
                }
                else if(j == 1 && this->my_team[i]->getType() == 'N')
                {
                    cout <<this->my_team[i]->print();
                }
             
            }
            
           
        }
        
    }

    // void Team::print2(Team* group){
    //     for (size_t i = 0; i < group->get_Team().size(); i++)
    //     {
    //         cout <<group->get_Team()[i]->print();
    //     }
        
    // }

    // void Team::call_print2(){
    //     print2(this);
    // }

    Team::~Team(){

        
        for (size_t i = 0; i < this->my_team.size(); i++)
        {
            delete (this->my_team[i]);
        }
        
    }
    

    vector <Character*> Team::get_Team(){
        return this->my_team;
    }

    Character* Team::get_Leader(){
        return this->leader;
    }






}