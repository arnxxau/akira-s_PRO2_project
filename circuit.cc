#include "circuit.hh"

circuit::circuit() {}

void circuit::read_tournaments() {
    std::cin >> n_tournaments;
    std::string name;
    int level;
    for (int i = 0; i < n_tournaments; ++i) {
        std::cin >> name >> level;
        tournament tour(name, level);
        tournaments.insert(make_pair(name, tour));
    }
}

void circuit::add_tournament(const tournament& tour) {
    tournaments.insert(make_pair(tour.get_name(), tour));
    ++n_tournaments;
}

void circuit::remove_tournament(const std::string& name, ranking& global_ranking) {
    tournaments.find(name) -> second.remove_points(global_ranking);
    global_ranking.sort_rank();
    tournaments.erase(name);
    --n_tournaments;
}

void circuit::remove_player_tour(const std::string& name) {
    std::map<std::string, tournament>::iterator it = tournaments.begin();
    while (it != tournaments.end()) {
        it -> second.remove_player(name);
        ++it;
    }   
}

void circuit::start_tour(const std::string& name, ranking& global_rank) {
    tournaments.find(name) -> second.start_tour(global_rank);
}

void circuit::end_tour(const std::string& name, ranking& global_rank, const categories& c) {
    tournaments.find(name) -> second.end_tour(c, global_rank);
}

int circuit::get_n_tournaments() const {
    return n_tournaments;
}

void circuit::print_tournaments(const categories& c) const {
    std::cout << n_tournaments << std::endl;
    std::map<std::string, tournament>::const_iterator it = tournaments.begin();
    while (it != tournaments.end()) {
        it -> second.print_tournament(c);
        ++it;
    }
}

bool circuit::exists_tournament(const std::string& name) const {
    return tournaments.end() != tournaments.find(name);
}