#include <iostream>

#include <string>

#include "Player.hpp"
#include "Game.hpp"

using namespace std;

namespace coup{

    Player::Player(Game &game, const string &name){
        if(game.players().size() == max_players_on_game){
            throw logic_error("Too many players");
        }
        if(game.is_started()){
            throw("The game already started");
        }
        this->name = name;
        this->game = &game;
        this->game->add_player(this);
        this->_coins = 0;
        this->in_game = true;
        this->last_coup = nullptr;
    }

    void Player::income(){
        if(this->game->turn() != this->name){
            throw("this is not your turn");
        }
        if(this->game->players().size() == 1){
            throw("There is no enough player");
        }
        this->_coins++;
        this->game->next_turn();
        this->prv_act = "income";
    }

    void Player::foreign_aid(){
        if(this->game->turn() != this->name){
            throw("this is not your turn");
        }
        if(this->game->players().size() == 1){
            throw("There is no enough player");
        }
        if(this->_coins >= max_coins_val){
            throw("should coup");
        }

        this->_coins = _coins+2;
        this->game->next_turn();
        this->prv_act = "foreign_aid";
    }

    void Player::coup(Player& p){
        if(this->game->players().size() == 1){
            throw("There is no enough player");
        }
        if(this->_coins < regular_coup_cost){
            throw("dont have money");
        }
        if(!p.in_game){
            throw("player not in game");
        }
        this->_coins = _coins-regular_coup_cost;
        p.in_game = false;
        this->last_coup = &p;
        this->prv_act = "coup";
        this->game->next_turn();
    }

    string Player::role(){
        return this->_role;
    }

    int Player::coins() const{
        return this->_coins;
    }

    void Player::block(Player& p){

    }

    string Player::prev_act(){
        return prv_act;
    }

    void Player::reverse_last_action(){
        if(this->prv_act == "coup"){
            this->last_coup->in_game = true;
        }
        else if(this->prv_act == "foreign_aid"){
            this->_coins = this->_coins - 2;
        }
    }

}