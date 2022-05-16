#include "ranking.hh"

ranking::ranking(){}

void ranking::add_player(const std::string& name) {
    player p (name, ++number_of_players);
    players_map.insert(std::make_pair(name, p));
    rank.push_back(players_map.find(name));
}

void ranking::read_players() {
    std::cin >> number_of_players;
    std::string name;
    for (int i = 0; i < number_of_players; ++i) {
        std::cin >> name;
        players_map.insert(std::make_pair(name, player(name, i + 1)));
    }

    std::map<std::string, player>::iterator it =  players_map.begin();
    std::vector<std::map<std::string, player>::iterator > r (number_of_players);
    while (it != players_map.end()) {
        r[it -> second.get_rank_position() - 1] = it;
        ++it;
    }
    rank = r;
}

void ranking::sort_rank() {
    sort(rank.begin(), rank.end(), order);
    int v_size = rank.size();
    for (int i = 0; i < v_size; ++i) {
        rank[i] -> second.modify_rank_position(i + 1);
    }
}

void ranking::increase_player_tours(const std::string& name) {
    players_map.find(name) -> second.increase_tour();
}

bool ranking::order(const std::map<std::string, player>::iterator& p1, 
        const std::map<std::string, player>::iterator& p2) {
    if (p1 -> second.get_total_points() != p2 -> second.get_total_points()) 
        return p1 -> second.get_total_points() > p2 -> second.get_total_points();
    else 
        return p1 -> second.get_rank_position() < p2 -> second.get_rank_position();
}

void ranking::remove_player(const std::string& name) {
    std::map<std::string, player>::iterator it =  players_map.find(name);
    int pos = it -> second.get_rank_position();
    rank.erase(rank.begin() + pos - 1);
    players_map.erase(it);
    int v_size = rank.size();

    for (int i = pos - 1; i < v_size; ++i) 
        rank[i] -> second.modify_rank_position(i + 1);

    --number_of_players;
}

int ranking::get_number_of_players() const{
    return number_of_players;
}

void ranking::modify_stats(const std::string& name, int points, 
        int wm, int lm, int ws, int ls, int wg, int lg) {
    players_map.find(name) -> second.modify_stats(points, wm, lm, ws, ls, wg, lg);
}

void ranking::remove_points(const std::string& name, int points) {
    players_map.find(name) -> second.modify_total_points(points * -1);
}

player ranking::get_player_by_name(const std::string& name) const {
    return players_map.find(name) -> second;
}

player ranking::get_player_by_pos(int position) const{
    return rank[position - 1] -> second;
}

bool ranking::is_player_there(const std::string& name) const {
    return players_map.end() != players_map.find(name);
}

void ranking::print_ranking() const {
    for (int i = 0; i < number_of_players; ++i)
        std::cout << i + 1 << ' ' << rank[i] -> second.get_name() 
                << ' ' << rank[i] -> second.get_total_points() << std::endl;
}

void ranking::print_players() const {
    std::map<std::string, player>::const_iterator it = players_map.begin();
    while (it != players_map.end()) {
        it -> second.print_player();
        ++it;
    }
}