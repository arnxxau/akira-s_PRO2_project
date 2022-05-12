#include "tournament.hh"

tournament::tournament(std::string name, int difficulty) {
    this -> name = name;
    this -> difficulty = difficulty;
}


void tournament::init_tour(ranking& global_rank) {
    int n_players;
    std::cin >> n_players;
    int position;
    std::vector<std::pair<std::string, int > > v(n_players);
    for (int i = 0; i < n_players; ++i) {
        std::cin >> position;
        std::string s = global_rank.get_player_by_pos(position).get_name();
        v[i] = std::make_pair(s, 0);
    }
    names_with_points = v;
}

BinTree<int> tournament::arborescence(int n_players, int m, int root) const {
    if (n_players < m + 1 - root) return BinTree<int>(root);
    else return BinTree<int>(root, arborescence(n_players, m * 2, root),  arborescence(n_players, m * 2, m + 1 - root));
}

void tournament::print_pairing_chart(const BinTree<int>& tree) {
    if (tree.left().empty() and tree.right().empty()) std::cout << tree.value() << '.' << names_with_points[tree.value() - 1].first;
    else {
        std::cout << '(';
        print_pairing_chart(tree.left());
        std::cout << ' ';
        print_pairing_chart(tree.right());
        std::cout << ')';
    }
}

void tournament::print_results(const BinTree<match>& tree) {
    if (not tree.value().is_empty()) {
        std::cout << '(';
        tree.value().print_match(names_with_points);
        print_results(tree.left());
        print_results(tree.right());
        std::cout << ')';
    }
}

void tournament::remove_points(ranking& global_ranking) {
    int i = 0;
    int v_size = history.size();
    while (played and i < v_size) {
        std::string n =  history[i].first;
        global_ranking.remove_points(n, history[i].second);
        ++i;
    }
}

void tournament::start_tour(ranking& global_ranking) {
    init_tour(global_ranking);
    pairing_chart = arborescence(names_with_points.size(), 2, 1);
    print_pairing_chart(pairing_chart);
    std::cout << std::endl;
    played = true;
}


BinTree<match> tournament::winner_arborescence(BinTree<int> pairing_copy, int level,
        const categories& cat, ranking& global_ranking) {
    std::string results;
    std::cin >> results;
    if (results.length() != 1) {
        BinTree<match> left = winner_arborescence(pairing_copy.left(), level + 1, cat, global_ranking), 
                        right = winner_arborescence(pairing_copy.right(), level + 1, cat, global_ranking);
        match m = match(results, left.value().get_winner(), right.value().get_winner());
        m.update_stats(level, difficulty, cat, names_with_points, global_ranking);
        return BinTree<match>(m, left, right);
    }
    return BinTree<match>(match(pairing_copy.value()));
}

void tournament::end_tour(const categories& cat, ranking& global_ranking) {
    results = winner_arborescence(pairing_chart, 1, cat, global_ranking);
    print_results(results);
    std::cout << std:: endl;

    remove_points(global_ranking);
    int v_size = names_with_points.size();
    for (int i = 0; i < v_size; ++i) {
        global_ranking.increase_player_tours(names_with_points[i].first);
        if (names_with_points[i].second != 0)
            std::cout << i + 1 << '.' << names_with_points[i].first << ' '<< names_with_points[i].second << std::endl;
    }
    history = names_with_points;
    global_ranking.sort_rank();
}

void tournament::remove_player(const std::string name) {
    bool found = false;
    int i = 0;
    int v_size = history.size();
    while (played and not found and i < v_size) {
        std::string n =  history[i].first;
        if (n == name) {
            history.erase(history.begin() + i);
            found = true;
        }
        ++i;
    }
}

bool tournament::order(const std::pair<std::string, int >& p1, 
          const std::pair<std::string, int >& p2) {
    return p1.second > p2.second;
}

std::string tournament::get_name() const {
    return name;
}

void tournament::print_tournament(const categories& c) const {
    std::cout << name << ' ' << c.get_name(difficulty) << std::endl;
}