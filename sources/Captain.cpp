#include <string.h>
#include <iostream>

#include "Player.hpp"
#include "Game.hpp"
#include "Captain.hpp"

namespace coup{

    void Captain::steal(Player &p){
        
        if(this->game->turn() != this->name){
            throw("this is not your turn");
        }
        if(this->game->players().size() == 1){
            throw("There is no enough player");
        }
        
        if(p.coins()>=2){
            p._coins -= 2;
            this->_coins += 2;
            this->last_steal_amount = 2;
        }
        else if(p.coins() == 1){
            p._coins -= 1;
            this->_coins += 1;
            this->last_steal_amount = 1;
        }
        else{
            this->last_steal_amount = 0;
        }

        last_steal = &p;
        this->prv_act = "steal";
        this->game->next_turn();
    }

    void Captain::reverse_last_action(){
        Player::reverse_last_action();

        if(this->prv_act == "steal"){
            this->last_steal->_coins += this->last_steal_amount;
            this->_coins -= this->last_steal_amount; 
        }
        
    }
    void Captain::block(Player& p){
        if(this->game->players().size() == 1){
            throw("There is no enough player");
        }
        if(p.prev_act() == "steal"){
            p.reverse_last_action();
        }
        else{
            throw("you cant block this player");
        }
    }
}