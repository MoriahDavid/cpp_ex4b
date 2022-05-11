#include <string.h>

#include "Player.hpp"
#include "Game.hpp"
#include "Assassin.hpp"

namespace coup{
        
    void Assassin::coup(Player& p){
        if(this->game->players().size() == 1){
            throw("There is no enough player");
        }

        if(this->_coins < 3){
            throw("dont have money");
        }
        if(!p.in_game){
            throw("player not in game");
        }
    
        p.in_game = false;
        this->last_coup = &p;
        if(this->_coins >= regular_coup_cost){
            this->_coins = _coins-regular_coup_cost;
            this->prv_act = "nb-coup";
        }
        else{
            this->_coins = _coins-3;
            this->prv_act = "coup";
        }
        this->game->next_turn();
        
    }
    void Assassin::block(Player& p){
        if(this->game->players().size() == 1){
            throw("There is no enough player");
        }
        
        throw("you cant block this player");
    }
}