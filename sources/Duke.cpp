#include <string.h>

#include "Player.hpp"
#include "Game.hpp"
#include "Duke.hpp"

namespace coup{
    
    void Duke::tax(){

        if(this->game->turn() != this->name){
            throw("this is not your turn");
        }
        if(this->game->players().size() == 1){
            throw("There is no enough player");
        }

        this->_coins = this->_coins + 3;  
        this->game->next_turn();
        this->prv_act = "tax";
        
    }

    void Duke::block(Player& p){
        if(this->game->players().size() == 1){
            throw("There is no enough player");
        }
        
        if(p.prev_act() == "foreign_aid"){
            p._coins = p._coins - 2;
        }
        else{
            throw("you cant block this player");
        }
    }

}