/** @file Circuit.cc
    @brief Código de la clase Circuit 
*/

#include "Circuit.hh"

Circuit::Circuit() {}

void Circuit::read_tournaments() {
    std::cin >> n_tournaments;
    std::string name;
    int level;
    for (int i = 0; i < n_tournaments; ++i) {
        std::cin >> name >> level;
        Tournament tour(name, level);
        tournaments.insert(make_pair(name, tour));
    }
}

void Circuit::add_tournament(const Tournament& tour) {
    tournaments.insert(make_pair(tour.get_name(), tour));
    ++n_tournaments;
}

void Circuit::remove_tournament(const std::string& name, Ranking& global_ranking) {
    tournaments.find(name) -> second.remove_points(global_ranking);
    global_ranking.sort_rank();
    tournaments.erase(name);
    --n_tournaments;
}

void Circuit::remove_player_tour(const std::string& name) {
    std::map<std::string, Tournament>::iterator it = tournaments.begin();
    while (it != tournaments.end()) {
        it -> second.remove_player(name);
        ++it;
    }   
}

void Circuit::start_tour(const std::string& name, Ranking& global_rank) {
    tournaments.find(name) -> second.start_tour(global_rank);
}

void Circuit::end_tour(const std::string& name, Ranking& global_rank, const Categories& c) {
    tournaments.find(name) -> second.end_tour(c, global_rank);
}

int Circuit::get_n_tournaments() const {
    return n_tournaments;
}

void Circuit::print_tournaments(const Categories& c) const {
    std::cout << n_tournaments << std::endl;
    std::map<std::string, Tournament>::const_iterator it = tournaments.begin();
    while (it != tournaments.end()) {
        it -> second.print_tournament(c);
        ++it;
    }
}

bool Circuit::exists_tournament(const std::string& name) const {
    return tournaments.end() != tournaments.find(name);
}