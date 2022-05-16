/**
 * @mainpage Circuito de torneos de tenis. Arnau Granados.
  En este programa modular se ofrece una simulación de un circuito de tennis mediante el uso principal de árboles.
  Se introducen las clases <em>player<em>, <em>ranking<em> (esencialmente un gestor de jugadores), <em>torneo<em>, <em>circuito<em> (un gestor de torneos) y <em>partido<em>, la cual se usa para gestionar los resultados de estos.
*/

/** @file program.cc
    @brief Programa principal para la práctica de circuitos de tennis. 
    
    Contiene la lógica básica para ejecutar los comandos especificados en el enunciado.
*/
#include "circuit.hh"
#include "categories.hh" // redundante
#include "ranking.hh" // redundante

/** @brief Programa principal */
int main() {
    std::string s;

    categories cat;
    cat.read_categories();
    
    circuit circuit;
    circuit.read_tournaments();

    ranking global_ranking;
    global_ranking.read_players();

    std::cin >> s;
    while (s != "fin") {
        if (s == "nuevo_jugador" or s == "nj") {
            std::string id;
            std::cin >> id;
            std::cout << "#" << s << ' ' << id << std::endl;
            if (not global_ranking.is_player_there(id)) {
                global_ranking.add_player(id);
                std::cout << global_ranking.get_number_of_players() << std::endl;
            }
            else
                std::cout << "error: ya existe un jugador con ese nombre" << std::endl;
        }

        else if (s == "nuevo_torneo" or s == "nt"){
            std::string t;
            std::cin >> t;
            int c;
            std::cin >> c;
            std::cout << "#" << s << ' ' << t << ' ' << c << std::endl;
            if (circuit.exists_tournament(t))
                std::cout << "error: ya existe un torneo con ese nombre" << std::endl;
            else if (1 > c or c > cat.get_n_categories())
                std::cout << "error: la categoria no existe" << std::endl;
            else {
                circuit.add_tournament(tournament(t, c));
                std::cout << circuit.get_n_tournaments() << std::endl;
            }
        }

        else if (s == "baja_jugador" or s == "bj") {
            std::string id;
            std::cin >> id;
            std::cout << "#" << s << ' ' << id << std::endl;
            if (global_ranking.is_player_there(id)) {
                circuit.remove_player_tour(id);
                global_ranking.remove_player(id);
                std::cout << global_ranking.get_number_of_players() << std::endl;
            } else 
                std::cout << "error: el jugador no existe" << std::endl;
        }

        else if (s == "baja_torneo" or s == "bt") {
            std::string t;
            std::cin >> t;
            std::cout << "#" << s << ' ' << t << std::endl;
            if (circuit.exists_tournament(t)) {
                circuit.remove_tournament(t, global_ranking);
                std::cout << circuit.get_n_tournaments() << std::endl;
            } else 
                std::cout << "error: el torneo no existe" << std::endl;
        }

        else if (s == "iniciar_torneo" or s == "it") {
            std::string t;
            std::cin >> t;
            std::cout << "#" << s << ' ' << t << std::endl;
            circuit.start_tour(t, global_ranking);
        }

        else if (s == "finalizar_torneo" or s == "ft") {
            std::string t;
            std::cin >> t;
            std::cout << "#" << s << ' ' << t << std::endl;
            circuit.end_tour(t, global_ranking, cat);
        }

        else if (s == "listar_ranking" or s == "lr") {
            std::cout << "#" << s << std::endl;
            global_ranking.print_ranking();
        }

        else if (s == "listar_jugadores" or s == "lj") {
            std::cout << "#" << s << std::endl;
            std::cout << global_ranking.get_number_of_players() << std::endl;
            global_ranking.print_players();
        }

        else if (s == "consultar_jugador" or s == "cj") {
            std::string id;
            std::cin >> id;
            std::cout << "#" << s << ' ' << id << std::endl;
            if (global_ranking.is_player_there(id))
                global_ranking.get_player_by_name(id).print_player();
            else 
                std::cout << "error: el jugador no existe" << std::endl;
        }

        else if (s == "listar_torneos" or s == "lt") {
            std::cout << "#" << s << std::endl;
            circuit.print_tournaments(cat);
        }

        else if (s == "listar_categorias" or s == "lc") {
            std::cout << "#" << s << std::endl;
            std::cout << cat.get_n_categories() << ' ' << cat.get_max_lvl() << std::endl;
            cat.print_categories();
        }

        std::cin >> s;
    }
}