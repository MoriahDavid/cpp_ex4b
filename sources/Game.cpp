#include <string>

#include "Game.hpp"
// #include "Player.hpp"

using namespace std;

namespace coup{


    Game::Game(){
        this->turn_indx = 0;
    }

    vector<string> Game::players(){
        vector<string> a;

        for(size_t i = 0; i < this->players_obj.size(); i++){
            if(players_obj[i]->in_game){
                a.push_back(players_obj[i]->name);
            }
        }
        return a;

    }

    string Game::turn(){
        return this->players_obj[turn_indx]->name;
    }

    string Game::winner(){
        if(!this->is_started()){
            throw("The game not started");
        }
        
        int count = 0;
        Player * win = nullptr;
        for(size_t i=0; i<this->players_obj.size(); i++){
            if(this->players_obj[i]->in_game){
                count++;
                win = this->players_obj[i];
            }
        }
        if(count == 1){
            return win->name;
        }
        throw("there is no winner");
    }
    
    void Game::add_player(Player *p){
        this->players_obj.push_back(p);
    }

    void Game::next_turn(){

        do{
            if(this->players_obj.size() == this->turn_indx+1){
                this->turn_indx = 0;
            }
            else{
                this->turn_indx++;
            }
        }
        while(!this->players_obj[this->turn_indx]->in_game);
    }

    bool Game::is_started(){
        if(this->players_obj.size() > 1){
            if(!this->players_obj[0]->prev_act().empty()){
                return true;
            }
        }
        return false;
    }
    
}