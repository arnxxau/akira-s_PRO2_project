#include "match.hh"

match::match(const std::string input, int left_pos, int right_pos){
    this -> left_pos = left_pos;
    this -> right_pos = right_pos;
    this -> input = input;
    read_match();
}

match::match(int only) {
    winner = only;
    empty = true;
}

void match::read_set(set& s) {
    s.first = input[0] - '0';
    left_games += s.first;
    s.second = input[2] - '0';
    right_games += s.second;
    input.erase(input.begin(), input.begin() + 3);
    sets.push_back(s);
}

void match::read_match() {
    int won_left = 0, won_right = 0;
    set s;

    bool invalid = false;
    while (won_left != 2 and won_right != 2) {
        read_set(s);
        
        if (s.first == 1 and s.second == 0) {
            won_left = 2;
            invalid = true;
        }
        else if (s.first == 0 and s.second == 1) {
            won_right = 2;
            invalid = true;
        }
        else if (s.first > s.second) ++won_left;
        else ++won_right;

        if (not input.empty())
            input.erase(input.begin());
    }


    if (invalid) {
        left_games = 0;
        right_games = 0;
    } else {
        left_sets = won_left;
        right_sets = won_right;
    }

    if (won_left > won_right) {
        winner = left_pos;
        loser = right_pos;
    }
    else {
        winner = right_pos;
        loser = left_pos;
    }
}

int match::get_winner() const{
    return winner;
}

void match::print_match(const std::vector<std::pair<std::string, int > >& names) const {
    std::cout << left_pos << '.' << names[left_pos - 1].first << " vs "
        << right_pos << '.' << names[right_pos - 1].first << ' ';

    int v_size = sets.size();
    for (int i = 0; i < v_size - 1; ++i) {
        std::cout << sets[i].first << '-' << sets[i].second << ',';
    }
    std::cout << sets[v_size - 1].first << '-' << sets[v_size - 1].second;
}


bool match::is_empty() const {
    return empty;
}

void match::update_stats(int level, int c, const categories& cat, 
        std::vector<std::pair<std::string, int > >& names, ranking& global_ranking) {
    std::string l = names[left_pos - 1].first;
    std::string r = names[right_pos - 1].first;

    int left_p = cat.get_points(c, level + 1);
    int right_p = cat.get_points(c, level + 1);
    if (level != 1) {
        if (left_pos == winner) left_p = 0;
        else right_p = 0;
    } else {
        left_p = cat.get_points(c, level);
        right_p = cat.get_points(c, level);
        if (left_pos == winner) right_p = cat.get_points(c, level + 1);
        else left_p = cat.get_points(c, level + 1);
    }

    names[left_pos - 1].second += left_p;
    names[right_pos - 1].second += right_p;

    // left player
    global_ranking.modify_stats(l, left_p, winner == left_pos, loser == left_pos, 
                left_sets, right_sets, left_games, right_games);
    // right player
    global_ranking.modify_stats(r, right_p, winner == right_pos, loser == right_pos, 
            right_sets, left_sets, right_games, left_games);
}