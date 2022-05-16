#ifndef AKIRA_MATCH_HH
#define AKIRA_MATCH_HH

#ifndef NO_DIAGRAM
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#endif
class match
{
    
private:
    typedef std::pair<int, int> set;
    bool b_winner;
    int left_pos, right_pos;
    int left_sets = 0, right_sets = 0;
    int left_games = 0, right_games = 0;
    bool empty = false;
    std::string input;

    int determine_set_winner(set s);
    void read_set(set& s, int& i);
public:
    match(const std::string& input, int left_pos, int right_pos);

    match(int only);

    void read_match();

    int get_winner() const;

    int get_sets(bool left) const;

    int get_games(bool left) const;

    int get_pos(bool left) const;

    bool get_bool() const;

    std::string get_result() const;
    
    bool is_empty() const;
};


#endif
