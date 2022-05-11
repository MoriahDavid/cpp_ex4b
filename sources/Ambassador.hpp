#include <string.h>

#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    
    class Ambassador : public Player{
        using Player::Player;

        private:

        public:
            Ambassador(Game &game, string name) : Player(game, name){ this->_role = "Ambassador";};

            void transfer(Player& p1, Player& p2);
            void static block(Player& p);
    };
}