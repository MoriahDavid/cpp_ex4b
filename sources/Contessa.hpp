#include <string.h>

#include "Player.hpp"
#include "Game.hpp"

namespace coup{

    class Contessa : public Player{
        using Player::Player;

        public:
            Contessa(Game &game, string name) : Player(game, name){ this->_role = "Contessa";};
            void block(Player& p);
    };
}