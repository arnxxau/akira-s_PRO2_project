#include "tournament.hpp"

tournament::tournament(std::string name, int difficulty, categories cat) {
    this -> name = name;
    this -> difficulty = difficulty;
    this -> cat = cat;
}


void tournament::init_tour(ranking global_rank) {
    int n_players;
    cin >> n_players;
    int position;
    for (int i = 0; i < n_players; ++i) {
        cin >> position;
        local_rank.add_player(global_rank.get_player_by_pos(position));
    }
}

BinTree<int> tournament::arborescence(const BinTree<int>& tree, int n_players, int level, int a) {
    cout << "ÁRBOLITO ARBOLÓN" << " level -> "<< level << " ----- a -> " << a << " //// b -> " << level + 1 - a << endl;
    if (n_players < level) return tree;
    else return BinTree<int>(a, arborescence(BinTree<int>(a), n_players, level * level, a), 
                                    arborescence(BinTree<int>(level + 1 - a), n_players, level * level, level + 1 - a));
}

void tournament::preorder_print(BinTree<int> tree) {
    if (not tree.empty()) {
        preorder_print(tree.left());
        cout << tree.value() << endl;
        preorder_print(tree.right());
        cout << tree.value() << endl;
    }
}

void tournament::start_tour(ranking global_ranking) {
    init_tour(global_ranking);
    cout << "inicializado" << endl;
    local_rank.sort_rank();
    cout << "sorteado" << endl;
    pairing_chart = arborescence(BinTree<int>(), local_rank.get_number_of_players(), 2, 1);
    preorder_print(pairing_chart);
}

bool tournament::already_played() const {
    return played;
}

void tournament::end_tour() {
    std::cout << "test" << std::endl;
}

std::string tournament::get_name() const {
    return name;
}

void tournament::print_tournament() const {
    std::cout << name << ' ' << cat.get_name(difficulty) << endl;
}