#include "player.hh"

player::player(const std::string name, const int& rank_pos) {
    this -> name = name;
    this -> rank_pos = rank_pos;
}

std::string player::get_name() const {
    return name;
}

int player::get_rank_position() const {
    return rank_pos;
}

player::stadistics player::get_stadistics() const {
    return player_stats;
}

int player::get_total_points() const {
    return total_points;
}

void player::modify_rank_position(int rank_pos) {
    this -> rank_pos = rank_pos;
}

void player::modify_total_points(int points) {
    total_points += points;
}

void player::modify_stats(int points, int wm, int lm, int ws, int ls, int wg, int lg) {
    total_points += points;

    player_stats.matches_won_lost.first += wm;
    player_stats.matches_won_lost.second += lm;

    player_stats.sets_won_lost.first += ws;
    player_stats.sets_won_lost.second += ls;

    player_stats.games_won_lost.first += wg;
    player_stats.games_won_lost.second += lg;
}

void player::increase_tour() {
    ++player_stats.played_tours;
}

void player::print_player() const {
    std::cout << name << " Rk:" << rank_pos << " Ps:" << total_points 
    << " Ts:" << player_stats.played_tours << " WM:" << player_stats.matches_won_lost.first
    << " LM:" << player_stats.matches_won_lost.second << " WS:" << player_stats.sets_won_lost.first 
    << " LS:" << player_stats.sets_won_lost.second << " WG:" << player_stats.games_won_lost.first 
    << " LG:" << player_stats.games_won_lost.second << std::endl;
}