#include <string.h>

#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    class Assassin : public Player{
        using Player::Player;

        public:
            Assassin(Game &game, string name) : Player(game, name){ this->_role = "Assassin";};
            void coup(Player& p);
            void block(Player& p);
        
    };
}