#include "circuit.hpp"

circuit::circuit(categories cat) {
    this -> cat = cat;
}

void circuit::read_tournaments() {
    cin >> n_tournaments;
    string name;
    int level;
    for (int i = 0; i < n_tournaments; ++i) {
        cin >> name >> level;
        tournament tour(name, level, cat);
        tournaments.insert(make_pair(name, tour));
    }
}

void circuit::add_tournament(const tournament& tour) {
    tournaments.insert(make_pair(tour.get_name(), tour));
    ++n_tournaments;
}

void circuit::remove_tournament(const std::string& name) {
    tournaments.erase(name);
    --n_tournaments;
}

tournament circuit::get_tournament(const std::string& name) {
    return tournaments.find(name) -> second; 
}

int circuit::get_n_tournaments() const {
    return n_tournaments;
}

void circuit::print_tournaments() {
    std::cout << n_tournaments << std::endl;
    map<std::string, tournament>::const_iterator it = tournaments.begin();
    while (it != tournaments.end()) {
        it -> second.print_tournament();
        ++it;
    }
        
}

bool circuit::exists_tournament(const std::string& name) const {
    return tournaments.end() != tournaments.find(name);
}

void circuit::read_players() {
    cin >> n_players;
    string name;
    for (int i = 0; i < n_players; ++i) {
        cin >> name;
        global_rank.add_player(player(name));
    }
}

void circuit::add_player(const player& p) {
    global_rank.add_player(p);
    ++n_players;
}

void circuit::remove_player(const std::string& name) {
    global_rank.remove_player(name);
}

ranking circuit::get_global_ranking() {
    return global_rank;
}

categories circuit::get_categories() {
    return cat;
}