
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
    // bool has_leader = false;
    void check_Leader();
    
public:
    Team(Character* lead);
    ~Team();
    void add(Character* member);
    void print();
    size_t closest_toLeader(vector<Character*> team);
    int stillAlive();

    void attack(Team* enemies);
    vector <Character*> get_Team();
    Character* get_Leader();


};

    
}