#include "circuit.hh"

circuit::circuit() {}

void circuit::read_tournaments() {
    cin >> n_tournaments;
    string name;
    int level;
    for (int i = 0; i < n_tournaments; ++i) {
        cin >> name >> level;
        tournament tour(name, level);
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

void circuit::print_tournaments(const categories& c) const {
    std::cout << n_tournaments << std::endl;
    map<std::string, tournament>::const_iterator it = tournaments.begin();
    while (it != tournaments.end()) {
        it -> second.print_tournament(c);
        ++it;
    }
        
}

bool circuit::exists_tournament(const std::string& name) const {
    return tournaments.end() != tournaments.find(name);
}
