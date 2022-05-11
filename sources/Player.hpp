#pragma once
#include <string>

#include "Game.hpp"

using namespace std;


namespace coup{

    class Game;

    class Player{

        protected:
            Game *game;
            string prv_act;
            string _role;
            Player *last_coup;

        public:
            Player(Game &game, const string &name);

            string name;
            int _coins;
            bool in_game;
            void income();
            void foreign_aid();
            void coup(Player &p);
            string role();
            int coins() const;
            void block(Player& p);
            string prev_act();
            virtual void reverse_last_action();
            const int regular_coup_cost = 7;
            const int max_players_on_game = 6;
            const int max_coins_val = 10;
    };
    
}
