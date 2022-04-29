#include "player.hpp"

player::player(std::string name) {
    this -> name = name;
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

void player::print_player() {
    std::cout << name << ' ' << rank_pos << total_points << std::endl;

    std::cout << "games won and lost -> " << player_stats.games_won_lost.first 
                << player_stats.games_won_lost.second << std::endl;
    std::cout << "sets won and lost -> " << player_stats.sets_won_lost.first 
            << player_stats.sets_won_lost.second << std::endl;
    std::cout << "matches won and lost -> " << player_stats.matches_won_lost.first 
                << player_stats.matches_won_lost.second << std::endl;       
}