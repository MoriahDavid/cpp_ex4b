#include <string.h>

#include "Player.hpp"
#include "Game.hpp"

namespace coup{
    class Captain : public Player{
        using Player::Player;

        private:
            Player* last_steal;
            int last_steal_amount;

        public:
            Captain(Game &game, string name) : Player(game, name){ this->_role = "Captain";};

            void steal(Player &p);
            void reverse_last_action();
            void block(Player& p);

    };
}