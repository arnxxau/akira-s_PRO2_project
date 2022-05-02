/**
 * @mainpage Circuito de torneos de tenis. Arnau Granados.
  En este programa modular se ofrece una simulación de un circuito de tennis mediante el uso principal de árboles.
  Se introducen las clases <em>player<em>, <em>ranking<em> (esencialmente un gestor de jugadores), <em>torneo<em>, <em>circuito<em> (un gestor de torneos)
*/

/** @file main.cpp
    @brief Programa principal para la práctica de circuitos de tennis. Contiene la lógica básica para ejecutar los comandos especificados en el enuncidado.
*/
#include "circuit.hh"

/** @brief Programa principal */
int main() {
    string s;
    categories cat;
    cat.read_categories();
    circuit circuit(cat);

    circuit.read_tournaments();
    circuit.read_players();
    // cout << "hola" << endl;
    cin >> s;
    while (s != "fin") {
        // cout << "s ->>>> " << s << endl;
        if (s == "nuevo_jugador" or s == "nj") {
            string id;
            cin >> id;
            cout << "#" << s << ' ' << id << endl;
            if (not circuit.get_global_ranking().is_player_there(id)) {
                circuit.add_player(player(id));
                cout << circuit.get_global_ranking().get_number_of_players() << endl;
            }
            else
                cout << "error: ya existe un jugador con ese nombre" << endl;
        }

        else if (s == "nuevo_torneo" or s == "nt"){
            string t;
            cin >> t;
            int c;
            cin >> c;
            cout << "#" << s << ' ' << t << ' ' << c << endl;
            if (circuit.exists_tournament(t))
                cout << "error: ya existe un torneo con ese nombre" << endl;
            else if (1 > c or c > circuit.get_categories().get_max_categories())
                cout << "error: la categoria no existe" << endl;
            else {
                circuit.add_tournament(tournament(t, c, cat));
                cout << circuit.get_n_tournaments() << endl;
            }
        }

        else if (s == "baja_jugador" or s == "bj") {
            string id;
            cin >> id;
            cout << "#" << s << ' ' << id << endl;
            if (circuit.get_global_ranking().is_player_there(id)) {
                circuit.remove_player(id);
                cout << circuit.get_global_ranking().get_number_of_players() << endl;
            } else 
                cout << "error: el jugador no existe" << endl;
        }

        else if (s == "baja_torneo" or s == "bt") {
            string t;
            cin >> t;
            cout << "#" << s << ' ' << t << endl;
            if (circuit.exists_tournament(t)) {
                circuit.remove_tournament(t);
                cout << circuit.get_n_tournaments() << endl;
            } else 
                cout << "error: el torneo no existe" << endl;
        }

        else if (s == "iniciar_torneo" or s == "it") {
            string t;
            cin >> t;
            cout << "#" << s << ' ' << t << endl;
            circuit.get_tournament(t).start_tour(circuit.get_global_ranking());
        }

        else if (s == "finalizar_torneo" or s == "ft") {
            cout << "#" << s << endl;
            string t;
            cin >> t;
            circuit.get_tournament(t).end_tour(); // pendiente pautas de impresión !!!!!!!
        }

        else if (s == "listar_ranking" or s == "lr") {
            cout << "#" << s << endl;
            // cout << "listando" << endl;
            circuit.get_global_ranking().print_ranking();
        }

        else if (s == "listar_jugadores" or s == "lj") {
            cout << "#" << s << endl;
            cout << circuit.get_global_ranking().get_number_of_players() << endl;
            circuit.get_global_ranking().print_players();
        }

        else if (s == "consultar_jugador" or s == "cj") {
            string id;
            cin >> id;
            cout << "#" << s << ' ' << id << endl;
            if (circuit.get_global_ranking().is_player_there(id))
                circuit.get_global_ranking().get_player_by_name(id).print_player();
            else 
                cout << "error: el jugador no existe" << endl;
        }

        else if (s == "listar_torneos" or s == "lt") {
            cout << "#" << s << endl;
            circuit.print_tournaments();
        }

        else if (s == "listar_categorias" or s == "lc") {
            cout << "#" << s << endl;
            cout << circuit.get_categories().get_max_categories() << ' ' << circuit.get_categories().get_max_lvl() << endl;
            circuit.get_categories().print_categories();
        }

        cin >> s;
    }
}