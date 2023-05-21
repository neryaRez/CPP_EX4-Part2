
#pragma once
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
#include "OldNinja.hpp"
#include "Cowboy.hpp"

namespace ariel{

class Team
{
private:
    vector <Character*> my_team;
    Character* leader;
    
public:
    Team(Character* lead);
    ~Team();
    void add(Character* member);

    virtual void print();
    virtual size_t closest_to_Member(Character* member, Team* group);
    virtual void attack(Team* enemies);
    
    int stillAlive();
    vector <Character*> get_Team();
    Character* get_Leader();
    void check_Leader();

};

    
}