/** @file Match.cc
    @brief Código de la clase Match
*/

#include "Match.hh"

Match::Match(const std::string& input, int left_pos, int right_pos){
    this -> left_pos = left_pos;
    this -> right_pos = right_pos;
    this -> input = input;

    read_match();
}

Match::Match(int only) {
    left_pos = only;
    b_winner = true;
    empty = true;
}

void Match::read_set(set& s, int& i) {
    s.first = input[i] - '0';
    left_games += s.first;
    s.second = input[i + 2] - '0';
    right_games += s.second;
    i += 4;
}

void Match::read_match() {
    set s;
    bool invalid = false;
    int i = 0;
    
    while (left_sets != 2 and right_sets != 2) {
        if (i + 2 < input.size())
            read_set(s, i);
        if (s.first == 1 and s.second == 0) {
            left_sets = 2;
            invalid = true;
        }
        else if (s.first == 0 and s.second == 1) {
            right_sets = 2;
            invalid = true;
        }
        else if (s.first > s.second) ++left_sets;
        else ++right_sets;
    }

    b_winner = left_sets > right_sets;
    if (invalid) {
        left_games = 0;
        right_games = 0;
        left_sets = 0;
        right_sets = 0;
    }
}

int Match::get_winner() const{
    if (b_winner) return left_pos;
    else return right_pos;
}

int Match::get_sets(bool left) const {
    if (left) return left_sets;
    else return right_sets;
}

int Match::get_games(bool left) const {
    if (left) return left_games;
    else return right_games;
}

int Match::get_pos(bool left) const {
    if (left) return left_pos;
    else return right_pos;
}

bool Match::get_bool() const {
    return b_winner;
}

std::string Match::get_result() const {
    return input;
}

bool Match::is_empty() const {
    return empty;
}