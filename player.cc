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

void player::modifiy_games(int won, int lost) {
    player_stats.games_won_lost.first = won;
    player_stats.games_won_lost.second = lost;
}

void player::modifiy_matches(int won, int lost) {
    player_stats.matches_won_lost.first = won;
    player_stats.matches_won_lost.second = lost;
}

void player::modifiy_sets(int won, int lost) {
    player_stats.sets_won_lost.first = won;
    player_stats.sets_won_lost.second = lost;
}

void player::modify_rank_position(int rank_pos) {
    this -> rank_pos = rank_pos;
}

void player::modify_total_points(int points) {
    total_points += points;
}

void player::print_player() const {
    std::cout << name << " Rk:" << rank_pos << " Ps:" << total_points 
    << " Ts:" << player_stats.played_tours << " WM:" << player_stats.matches_won_lost.first
    << " LM:" << player_stats.matches_won_lost.second << " WS:" << player_stats.sets_won_lost.first 
    << " LS:" << player_stats.sets_won_lost.second << " WG:" << player_stats.games_won_lost.first 
    << " LG:" << player_stats.games_won_lost.second << std::endl;
}