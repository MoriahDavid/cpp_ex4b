#include <string.h>

#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    
    class Duke : public Player{
        using Player::Player;

        private:
        public:
            void tax();
            void block(Player& p);
            Duke(Game &game, string name) : Player(game, name){ this->_role = "Duke";};
    };
}