#include "Player.h"
//#include "Enemy.h"
#include "Warrior.h"
#include "Barbarian.h"

#include <string>
using namespace std;

Barbarian::Barbarian(){
    this->ability_name1 = "Burning Blades";
    this->ability_cost = 30;
    this->burn_damage = 5;
    this->burn_duration = 2; //2 rounds
}

Barbarian::Barbarian(string name){
    this->name = name;
    this->AC = 13;
    this->health = 70;
    this->base_damage = 7;
    this->whirlwind_damage = 7;
    this->speed = 4;
    this->chance_to_hit = 3;
    this->stamina = 100;
    this->weapon = "Daggers";
    this->subclass = "Barbarian";

    this->ability_name1 = "Burning Blades";
    this-> ability1_cost = 30;

    this->ability_name2 = "Fury";
    this->ability2_cost = 20;

    this->ability_name1 = "Whirlwind";
    this->ability3_cost = 40;
    
    this->burn_damage = 5;
    this->burn_duration = 2; //2 rounds

    this->burn_counter = 0;
    this->stun_counter = 0;
}

void Barbarian::ability1(Player* opponent, int cost){
    if (does_it_hit(opponent) == true){
        opponent->set_burnCounter(2);
        opponent->take_damage(base_damage + burn_damage);
        opponent->is_poisoned(1); //sets poisoned boolean to true
        this->set_stamina((stamina - cost));
        cout << this->name << " jabs " << opponent->get_name() << " with a burning blade for " << (burn_damage+base_damage) << " damage!" << endl;
        cout << opponent->get_name() << " is burning!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

void Barbarian::ability2(Player* opponent, int cost){
    this->AC = (AC - 2);
    this->base_damage = (base_damage + 4);
    this->set_stamina(stamina-cost);
    cout << this->name << " reduces defence by 2! Gains 4 extra damage for next round!" << endl;
}

void Barbarian::ability3(Player* opponent, int cost){
    if (does_it_hit(opponent) == true){
        this->set_stamina((stamina - cost));
        opponent->take_damage(whirlwind_damage);
        cout << this->name << " hits " << opponent->get_name() << " for " << (whirlwind_damage) << " damage!" << endl;
        cout << this->name << " hits " << opponent->get_name() << " again for " << (whirlwind_damage) << " damage!" << endl;
    } else {
        cout << this->name << "'s "<< this->get_ability1() << " missed its target!" << endl;
        this->set_stamina((stamina - cost));
    }
}

//GETTERS

int Barbarian::get_burnDamage(){
    return burn_damage;
}
int Barbarian::get_burnDuration(){
    return burn_duration;
}

//SETTERS