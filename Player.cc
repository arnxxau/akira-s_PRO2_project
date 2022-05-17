/** @file Player.cc
    @brief Código de la clase Player 
*/

#include "Player.hh"

Player::Player(const std::string name, int rank_pos) {
    this -> name = name;
    this -> rank_pos = rank_pos;
}

std::string Player::get_name() const {
    return name;
}

int Player::get_rank_position() const {
    return rank_pos;
}

int Player::get_total_points() const {
    return total_points;
}

void Player::modify_rank_position(int rank_pos) {
    this -> rank_pos = rank_pos;
}

void Player::modify_total_points(int points) {
    total_points += points;
}

void Player::modify_stats(int points, int wm, int lm, int ws, int ls, int wg, int lg) {
    total_points += points;

    matches_won_lost.first += wm;
    matches_won_lost.second += lm;

    sets_won_lost.first += ws;
    sets_won_lost.second += ls;

    games_won_lost.first += wg;
    games_won_lost.second += lg;
}

void Player::increase_tour() {
    ++played_tours;
}

void Player::print_player() const {
    std::cout << name << " Rk:" << rank_pos << " Ps:" << total_points 
    << " Ts:" << played_tours << " WM:" << matches_won_lost.first
    << " LM:" << matches_won_lost.second << " WS:" << sets_won_lost.first 
    << " LS:" << sets_won_lost.second << " WG:" << games_won_lost.first 
    << " LG:" << games_won_lost.second << std::endl;
}