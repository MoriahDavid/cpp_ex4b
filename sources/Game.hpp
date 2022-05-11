#pragma once
#include <string>
#include <vector>

#include "Player.hpp"

using namespace std;


namespace coup{

    class Player;
    class Game{

        private:
            vector<Player*> players_obj;
            size_t turn_indx;

        public:
            Game();

            vector<string> players();

            string turn();

            string winner();

            void add_player(Player *p);

            void next_turn();

            bool is_started();

    };
    
}
