/**
 * @mainpage Práctica PRO2
 .........
*/

/** @file main.cpp
    @brief Programa principal para Akira's PRO2 Project
*/
#include "circuit.hh"

#ifndef NO_DIAGRAM
#include <iostream>
#endif

/** @brief Programa principal */
int main() {
    string s;
    categories cat;
    cat.read_categories();
    circuit circuit(cat);
    while (s != "fin") {
        if (s == "nuevo_jugador" or s == "nj") {
            string id;
            cin >> id;
            if (not circuit.get_global_ranking().is_player_there(id)) {
                circuit.add_player(player(id));
                cout << circuit.get_global_ranking().get_number_of_players() << endl;
            }
            else
                cout << "El jugador ya existe en el circuito" << endl;
        }
        else if (s == "nuevo_torneo" or s == "nt"){
            string t;
            cin >> t;
            int c;
            cin >> c;
            if (circuit.exists_tournament(t))
                cout << "El torneo ya existe en el circuito" << endl;
            else if (1 <= c and c >= circuit.get_categories().get_max_categories())
                cout << "La categoría no está definida" << endl;
            else {
                circuit.add_tournament(tournament(t, c, cat));
                cout << circuit.get_n_tournaments() << endl;
            }
        }
        else if (s == "baja_jugador" or s == "bj") {
            string id;
            cin >> id;
            if (circuit.get_global_ranking().is_player_there(id)) {
                circuit.remove_player(id);
                cout << circuit.get_global_ranking().get_number_of_players() << endl;
            } else 
                cout << "El jugador no existe en el circuito" << endl;
        }
        else if (s == "baja_torneo" or "bj") {
            string t;
            cin >> t;
            if (circuit.exists_tournament(t)) {
                circuit.remove_tournament(t);
                cout << circuit.get_n_tournaments() << endl;
            } else 
                cout << "El torneo no existe en el circuito" << endl;
        }
        else if (s == "inciar_torneo" or s == "it") {
            string t;
            cin >> t;
            circuit.get_tournament(t).init_tour();
            circuit.get_tournament(t).start_tour(); // formato escritura ?????
        }
        else if (s == "finalizar_torneo" or s == "ft") {
            string t;
            cin >> t;
            circuit.get_tournament(t).end_tour(); // pendiente pautas de impresión !!!!!!!
        }
        else if (s == "listar_ranking" or s == "lr") {
            circuit.get_global_ranking().print_ranking();
        }
        else if (s == "listar_jugadores" or s == "lj") {
            circuit.get_global_ranking().print_players();
        }
        else if (s == "consutar_jugador" or s == "cj") {
            string id;
            cin >> id;
            if (circuit.get_global_ranking().is_player_there(id))
                circuit.get_global_ranking().get_player_by_name(id).print_player();
            else 
                cout << "El jugador no existe en el circuito" << endl;
        }
        else if (s == "listar_torneos" or s == "lt") {
            circuit.print_tournaments();
        }
        else if (s == "listar_categorías" or s == "lc") {
            circuit.get_categories().print_categories();
        }

    }
}