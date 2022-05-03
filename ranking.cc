#include "ranking.hh"

ranking::ranking(std::vector<player> players) {
    int v_size = players.size();
    for (int i = 0; i < v_size; ++i)
        add_player(players[i]);
}

ranking::ranking(){}

int ranking::linear_search(const std::string& name) const {
    for (int i = 0; i < number_of_players; ++i) {
        if (rank[i].first == name)
            return i;
    }
    return -1;
}

void ranking::add_player(player p) {
    std::string s = p.get_name();
    p.modify_rank_position(number_of_players + 1);
    rank.push_back(std::make_pair(s, p.get_rank_position()));
    ++number_of_players;
    players_map.insert(std::make_pair(p.get_name(), p));
}

void ranking::read_players() {
    std::cin >> number_of_players;
    std::string name;
    for (int i = 0; i < number_of_players; ++i) {
        std::cin >> name;
    rank.push_back(std::make_pair(name, i + 1));
    players_map.insert(std::make_pair(name, player(name, i + 1)));
    }
}

void ranking::sort_rank() {
    sort(rank.begin(), rank.end(), order);
}

bool ranking::order(const std::pair<std::string, int >& p1, const std::pair<std::string, int >& p2) {
    return p1.second < p2.second;
}

void ranking::remove_player(const std::string& name) {
    players_map.erase(name);
    int pos = linear_search(name); 
    int v_size = rank.size();
    for (int i = pos + 1; i < v_size; ++i) {
        rank[i - 1] = rank[i];
        players_map.find(rank[i].first) -> second.modify_rank_position(i);
    }
    rank.pop_back();
    --number_of_players;
}

int ranking::get_number_of_players() const{
    return number_of_players;
}

player ranking::get_player_by_name(const std::string& name) {
    return players_map.find(name) -> second;
}

player ranking::get_player_by_pos(int position) {
    return players_map.find(rank[position - 1].first) -> second;
}


std::string ranking::get_player_name_by_pos(int position) const{
    return rank[position - 1].first;
}


bool ranking::is_player_there(const std::string& name) const {
    return players_map.end() != players_map.find(name);
}

void ranking::print_ranking() const {
    for (int i = 0; i < number_of_players; ++i)
        std::cout << i + 1 << ' ' << rank[i].first<< ' ' << players_map.find(rank[i].first) -> second.get_total_points() << std::endl;
}

void ranking::print_players() const {
    std::map<std::string, player>::const_iterator it = players_map.begin();
    while (it != players_map.end()) {
        it -> second.print_player();
        ++it;
    }
}
