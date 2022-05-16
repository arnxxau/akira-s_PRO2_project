/** @file categories.cc
    @brief Código de la clase categories 
*/

#include "categories.hh"

categories::categories(){}

void categories::read_categories() {
    std::cin >> n_categories >> max_lvl;
    std::vector<std::string> names(n_categories);
    std::vector<std::vector<int> > points_per_level (n_categories, std::vector<int>(max_lvl));

    for (int i = 0; i < n_categories; ++i)
        std::cin >> names[i];

    for (int i = 0; i < n_categories; ++i)
        for (int j = 0; j < max_lvl; ++j)
            std::cin >> points_per_level[i][j];

    this -> names = names;
    this -> points_per_level = points_per_level;
}

int categories::get_points(int category, int level) const {
    return points_per_level[category - 1][level - 1];
}

std::string categories::get_name(int category) const {
    return names[category - 1];
}

int categories::get_level(const std::string name) const {
    for (int i = 0; i < n_categories; ++i)
        if (name == names[i]) return i;
    return -1;
}

int categories::get_n_categories() const {
    return n_categories;
}

int categories::get_max_lvl() const {
    return max_lvl;
}

void categories::print_categories() const{
    for (int i = 0; i < n_categories; ++i) {
         std::cout << names[i];
         for (int j = 0; j < max_lvl; ++j)
            std::cout << ' ' << points_per_level[i][j];
        std::cout << std::endl; 
    }
}