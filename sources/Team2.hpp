#pragma once

#include "Team.hpp"

using namespace std;

namespace ariel{

    class Team2 : public Team
    {
    private:
        
    public:
        Team2(Character* lead);

        void print() override;
        void attack(Team* enemies) override;
        size_t closest_to_Member(Character* member, Team* group) override;

        
    };
    
}