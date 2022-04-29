/**
 * @mainpage Circuito de torneos de tenis. Arnau Granados.
  En este programa modular se ofrece una simulación de un circuito de tennis mediante el uso principal de árboles.
  Se introducen las clases <em>player<em>, <em>ranking<em> (esencialmente un gestor de jugadores), <em>torneo<em>, <em>circuito<em> (un gestor de torneos)
*/

/** @file main.cpp
    @brief Programa principal para la práctica de circuitos de tennis. Contiene la lógica básica para ejecutar los comandos especificados en el enuncidado.
*/
#include "circuit.hpp"

/** @brief Programa principal */
int main() {
    string s;
    categories cat;
    cat.read_categories();
    circuit circuit(cat);

    circuit.read_tournaments();
    circuit.read_players();
    cout << "hola" << endl;
    cin >> s;
    while (s != "fin") {
        cout << "s ->>>> " << s << endl;
        if (s == "nuevo_jugador" or s == "nj") {
            cout << "#nuevo_jugador" << endl;
            string id;
            cin >> id;
            if (not circuit.get_global_ranking().is_player_there(id)) {
                circuit.add_player(player(id));
                cout << circuit.get_global_ranking().get_number_of_players() << endl;
            }
            else
                cout << "El jugador ya existe en el circuito." << endl;
        }

        else if (s == "nuevo_torneo" or s == "nt"){
            cout << "#nuevo_torneo" << endl;
            string t;
            cin >> t;
            int c;
            cin >> c;
            if (circuit.exists_tournament(t))
                cout << "El torneo ya existe en el circuito." << endl;
            else if (1 <= c and c >= circuit.get_categories().get_max_categories())
                cout << "La categoría no está definida." << endl;
            else {
                circuit.add_tournament(tournament(t, c, cat));
                cout << circuit.get_n_tournaments() << endl;
            }
        }

        else if (s == "baja_jugador" or s == "bj") {
            cout << "#baja_jugador" << endl;
            string id;
            cin >> id;
            if (circuit.get_global_ranking().is_player_there(id)) {
                circuit.remove_player(id);
                cout << circuit.get_global_ranking().get_number_of_players() << endl;
            } else 
                cout << "El jugador no existe en el circuito." << endl;
        }

        else if (s == "baja_torneo" or s == "bj") {
            cout << "#baja_torneo" << endl;
            string t;
            cin >> t;
            if (circuit.exists_tournament(t)) {
                circuit.remove_tournament(t);
                cout << circuit.get_n_tournaments() << endl;
            } else 
                cout << "El torneo no existe en el circuito." << endl;
        }

        else if (s == "iniciar_torneo" or s == "it") {
            cout << "#iniciar_torneo" << endl;
            string t;
            cin >> t;
            circuit.get_tournament(t).start_tour(circuit.get_global_ranking());
        }

        else if (s == "finalizar_torneo" or s == "ft") {
            cout << "#finalizar_torneo" << endl;
            string t;
            cin >> t;
            circuit.get_tournament(t).end_tour(); // pendiente pautas de impresión !!!!!!!
        }

        else if (s == "listar_ranking" or s == "lr") {
            cout << "#listar_ranking" << endl;
            cout << "listando" << endl;
            circuit.get_global_ranking().print_ranking();
        }

        else if (s == "listar_jugadores" or s == "lj") {
            cout << "#listar_jugadores" << endl;
            circuit.get_global_ranking().print_players();
        }

        else if (s == "consultar_jugador" or s == "cj") {
            cout << "consultar_jugador" << endl;
            string id;
            cin >> id;
            if (circuit.get_global_ranking().is_player_there(id))
                circuit.get_global_ranking().get_player_by_name(id).print_player();
            else 
                cout << "El jugador no existe en el circuito." << endl;
        }

        else if (s == "listar_torneos" or s == "lt") {
            cout << "listar_torneos" << endl;
            circuit.print_tournaments();
        }

        else if (s == "listar_categorías" or s == "lc") {
            cout << "#listar_categorias" << endl;
            circuit.get_categories().print_categories();
        }

        cin >> s;
    }
}