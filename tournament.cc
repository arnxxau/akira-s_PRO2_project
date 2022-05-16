/** @file tournament.cc
    @brief Código de la clase tournament 
*/

#include "tournament.hh"

tournament::tournament(const std::string& name, int difficulty) {
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

BinTree<int> tournament::create_pairing_chart(int n_players, int m, int root) const {
    if (n_players < m + 1 - root) return BinTree<int>(root);
    else return BinTree<int>(root, create_pairing_chart(n_players, m * 2, root), 
                                    create_pairing_chart(n_players, m * 2, m + 1 - root));
}

BinTree<match> tournament::compute_results(const BinTree<int>& pairing, int level,
        const categories& c, ranking& global_rank) {
    std::string results;
    std::cin >> results;
    if (results.length() != 1) {
        BinTree<match> left = compute_results(pairing.left(), level + 1, c, global_rank);
        BinTree<match> right = compute_results(pairing.right(), level + 1, c, global_rank);
        match m = match(results, left.value().get_winner(), right.value().get_winner());
        update_stats(m, level, c, global_rank);
        return BinTree<match>(m, left, right);
    }
    return BinTree<match>(match(pairing.value()));
}

void tournament::print_pairing_chart(const BinTree<int>& tree) const {
    if (tree.left().empty() and tree.right().empty()) std::cout << tree.value() << '.' << names_with_points[tree.value() - 1].first;
    else {
        std::cout << '(';
        print_pairing_chart(tree.left());
        std::cout << ' ';
        print_pairing_chart(tree.right());
        std::cout << ')';
    }
}

void tournament::print_results(const BinTree<match>& tree) const {
    if (not tree.value().is_empty()) {
        std::cout << '(';
        print_match(tree.value());
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
    pairing_chart = create_pairing_chart(names_with_points.size(), 2, 1);
    print_pairing_chart(pairing_chart);
    std::cout << std::endl;
}

void tournament::end_tour(const categories& c, ranking& global_ranking) {
    results = compute_results(pairing_chart, 1, c, global_ranking);
    print_results(results);
    std::cout << std::endl;

    remove_points(global_ranking);
    int v_size = names_with_points.size();
    for (int i = 0; i < v_size; ++i) {
        global_ranking.increase_player_tours(names_with_points[i].first);
        if (names_with_points[i].second != 0)
            std::cout << i + 1 << '.' << names_with_points[i].first 
                        << ' '<< names_with_points[i].second << std::endl;
    }
    played = true;
    history = names_with_points;
    global_ranking.sort_rank();
}

void tournament::print_match(const match& m) const {
    std::cout << m.get_pos(1) << '.' << names_with_points[m.get_pos(1) - 1].first << " vs "
        << m.get_pos(0) << '.' << names_with_points[m.get_pos(0) - 1].first << ' '
        << m.get_result();
}

void tournament::remove_player(const std::string& name) {
    bool found = false;
    int i = 0;
    int v_size = history.size();
    while (played and not found and i < v_size) {
        if (history[i].first == name) {
            history.erase(history.begin() + i);
            found = true;
        }
        ++i;
    }
}

void tournament::update_stats(const match& m, int level, const categories& c, ranking& global_rank) {
    int left_p , right_p;

    if (level != 1) {
        if (m.get_bool()) {
            left_p = 0;
            right_p = c.get_points(difficulty, level + 1);
        }
        else {
            left_p = c.get_points(difficulty, level + 1);
            right_p = 0;
        }
    } else {
        if (m.get_bool()) {
            left_p = c.get_points(difficulty, level);
            right_p = c.get_points(difficulty, level + 1);
        }
        else {
            left_p = c.get_points(difficulty, level + 1);
            right_p = c.get_points(difficulty, level);
        }
    }

    names_with_points[m.get_pos(1) - 1].second += left_p;
    names_with_points[m.get_pos(0) - 1].second += right_p;

    std::string l = names_with_points[m.get_pos(1) - 1].first;
    std::string r = names_with_points[m.get_pos(0) - 1].first;
    // left player
    global_rank.modify_stats(l, left_p, m.get_bool(), not m.get_bool(), 
                m.get_sets(1), m.get_sets(0), m.get_games(1), m.get_games(0));
    // right player
    global_rank.modify_stats(r, right_p, not m.get_bool(), m.get_bool(), 
            m.get_sets(0), m.get_sets(1), m.get_games(0), m.get_games(1));
}

std::string tournament::get_name() const {
    return name;
}

void tournament::print_tournament(const categories& c) const {
    std::cout << name << ' ' << c.get_name(difficulty) << std::endl;
}