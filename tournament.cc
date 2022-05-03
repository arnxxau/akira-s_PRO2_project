#include "tournament.hh"

tournament::tournament(std::string name, int difficulty) {
    this -> name = name;
    this -> difficulty = difficulty;
}


void tournament::init_tour(const ranking& global_rank) {
    int n_players;
    std::cin >> n_players;
    int position;
    for (int i = 0; i < n_players; ++i) {
        std::cin >> position;
        std::string s = global_rank.get_player_name_by_pos(position);
        names_with_points.push_back(std::make_pair(s, 0));
    }
}

BinTree<int> tournament::arborescence(int n_players, int m, int root) const {
    if (n_players < m + 1 - root) return BinTree<int>(root);
    else return BinTree<int>(root, arborescence(n_players, m * 2, root),  arborescence(n_players, m * 2, m + 1 - root));
}

void tournament::preorder_print(const BinTree<int>& tree) {
    if (tree.left().empty() and tree.right().empty()) std::cout << tree.value() << '.' << names_with_points[tree.value() - 1].first;
    else {
        std::cout << '(';
        preorder_print(tree.left());
        std::cout << ' ';
        preorder_print(tree.right());
        std::cout << ')';
    }
}

void tournament::start_tour(const ranking& global_ranking) {
    init_tour(global_ranking);
    pairing_chart = arborescence(names_with_points.size(), 2, 1);
    preorder_print(pairing_chart);
    std::cout << std::endl;
}

bool tournament::already_played() const {
    return played;
}

void tournament::end_tour() {
    std::cout << "to be done" << std::endl;
}

std::string tournament::get_name() const {
    return name;
}

void tournament::print_tournament(const categories& c) const {
    std::cout << name << ' ' << c.get_name(difficulty) << std::endl;
}