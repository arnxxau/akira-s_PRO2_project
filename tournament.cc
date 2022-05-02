#include "tournament.hh"
#include <list>
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

BinTree<int> tournament::arborescence(int n_players, int m, int root) {
    if (n_players < m + 1 - root) return BinTree<int>(root);
    else return BinTree<int>(root, arborescence(n_players, m * 2, root),  arborescence(n_players, m * 2, m + 1 - root));
}

void tournament::preorder_print(BinTree<int> tree) {
    if (tree.left().empty() and tree.right().empty()) cout << tree.value() << '.' << local_rank.get_player_by_pos(tree.value()).get_name();
    else {
        cout << '(';
        preorder_print(tree.left());
        cout << ' ';
        preorder_print(tree.right());
        cout << ')';
    }
}

void tournament::start_tour(ranking global_ranking) {
    init_tour(global_ranking);
    // cout << "inicializado" << endl;
    local_rank.sort_rank();
    // cout << "sorteado" << endl;
    pairing_chart = arborescence(local_rank.get_number_of_players(), 2, 1);
    
    preorder_print(pairing_chart);
    cout << endl;
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