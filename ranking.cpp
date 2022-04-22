#include "ranking.hh";

ranking::ranking(std::vector<player> players) {
    int v_size = players.size();
    for (int i = 0; i < v_size; ++i)
        add_player(players[i]);
}

int ranking::eff_search(const std::string& name) const {
    int left = 0, right = players.size() - 1;
    int middle = (left + right) / 2;
    while (left <= right) {
        if (players[middle].get_name() > name) right = middle - 1;
        else if (players[middle].get_name() < name) left = middle + 1;
        else return middle;
    }
    return left;
}

void ranking::add_player(const player& p) {
    rank.push_back(std::make_pair(p, 0));
    ++number_of_players;
    std::string s = p.get_name();
    players_map.insert(std::make_pair(p.get_name(), 
                std::make_pair(p, number_of_players - 1)));
}

void ranking::sort_rank() {
    sort(rank.begin(), rank.end(), order);
}

bool ranking::order(const player& p1, const player& p2) const{
    return p1.get_name() > p2.get_name();
}

void ranking::remove_player(const std::string& name) {
    players_map.erase(name);
    int pos = players_map.find(name) -> second.second;
    int v_size = players.size();
    for (int i = v_size - 1; i >= v_size; --i) {
        players[i - 1] = players[i];
    }
    players.pop_back();
    --number_of_players;
}

int ranking::get_number_of_players() const{
    return number_of_players;
}

player ranking::get_player_by_name(const std::string& name) {
    return players_map.find(name) -> second.first;
}

player ranking::get_player_by_pos(int position) {
    return rank[position - 1].first;
}

bool ranking::is_player_there(const std::string& name) const {
    return players_map.end() != players_map.find(name);
}

void ranking::print_ranking() {
    for (int i = 0; i < number_of_players; ++i)
        rank[i].first.print_player();
}

void ranking::print_players() {
    std::map<std::string, std::pair<player, int>>::iterator it = players_map.begin();
    while (it != players_map.end()) {
        it -> second.first.print_player();
        ++it;
    }
}
