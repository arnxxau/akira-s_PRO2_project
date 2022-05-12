#include "match.hh"
int main() {
    match m ("6-4,4-6,4-6", 8, 9);
    cout << m.get_winner() << endl;
}
// 6-4,4-6,4-6 left: 8 right: 9 winner:
