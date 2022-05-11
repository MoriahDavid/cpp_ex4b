#include <string.h>
#include <iostream>

#include "Player.hpp"
#include "Game.hpp"
#include "Ambassador.hpp"

namespace coup{
    
    void Ambassador::transfer(Player& p1, Player& p2){ //p1 gives p2 1 coin
        if(this->game->turn() != this->name){
            throw("this is not your turn");
        }
        if(p1.coins() < 1){
            throw("p2 has no coins");
        }
        p1._coins = p1._coins - 1;
        p2._coins = p2._coins + 1;
        this->game->next_turn();
    }
    void Ambassador::block(Player &p){
        if(p.prev_act() == "steal"){
            p.reverse_last_action();
        }
        else{
            throw("you cant block this player");
        }
    }
}