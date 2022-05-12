#ifndef AKIRA_MATCH_HH
#define AKIRA_MATCH_HH

#include "ranking.hh"
#include "categories.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#endif
class match
{
    
private:
    typedef std::pair<int, int> set;
    int winner;
    int loser;
    std::vector<set> sets;
    int left_pos, right_pos;
    int left_sets = 0, right_sets = 0;
    int left_games = 0, right_games = 0;
    bool empty = false;
    std::string input;
    int determine_set_winner(set s);
    void read_set(set& s);
public:
    match(const std::string input, int left_pos, int right_pos);

    match(int only);

    void read_match();

    int get_winner() const;

    void print_match(const std::vector<std::pair<std::string, int > >& names) const;

    bool is_empty() const;

    void update_stats(int level, int c, const categories& cat, 
        std::vector<std::pair<std::string, int > >& names, ranking& global_rank);
};


#endif
