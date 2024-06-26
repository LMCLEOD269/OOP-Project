#ifndef BLACKMAGE_H
#define BLACKMAGE_H

#include "Wizard.h"
#include "Player.h"
#include <string>
using namespace std;

class BlackMage : public Wizard {
    public:
    int dark_bolt_damage;
    int dark_storm_damage;
    int creeping_death_damage;
    int shadow_counter;
    int shadow_duration;

    BlackMage();
    BlackMage(string name);

    void ability1 (Player* player, int cost);
    void ability2 (Player* player, int cost);
    void ability3 (Player* player, int cost);
    //void ability4 (Enemy* opponent, int cost);

    int get_shadow_duration();
    
    virtual void set_subclass_attributes();
    virtual void get_subclass_attributes();
    

};

#endif