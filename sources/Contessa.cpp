#include <string.h>

#include "Player.hpp"
#include "Game.hpp"
#include "Contessa.hpp"

namespace coup{

    void Contessa::block(Player& p){
        if(this->game->players().size() == 1){
            throw("There is no enough player");
        }
        if(p.prev_act() == "coup"){
            p.reverse_last_action();
        }
        else{
            throw("you cant block this player");
        }
    }

}