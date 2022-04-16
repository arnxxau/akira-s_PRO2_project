/** @file circuit.hh
    @brief Especificaciones de circuit
*/

#ifndef AKIRA_CIRCUIT_HH
#define AKIRA_CIRCUIT_HH

#include "tournament.hh"
#include "categories.hh"

#ifndef NO_DIAGRAM
#include <list>
#endif

class circuit
{
private:
    int n_players = 0, n_tournaments = 0; // n_players -> P, n_tournaments -> T
    list<tournament> tournaments;
    ranking global_rank;
    categories cat;

public:
    circuit(categories cat);
    ~circuit();

    // tournaments

  /** @brief Operación de lectura para torneos. 

      \pre <em>cierto</em>
      \post El resultado es una lista con los torneos leídos.
  */  
    void read_tournaments();

  /** @brief Operación de añadido para torneos. 

      \pre <em>El torneo no existe en la lista</em>
      \post El resultado es la misma lista pero con n_tournaments + 1 y el nuevo torneo añadido
  */  
    void add_tournament(const tournament& tour);

  /** @brief Operación de borrado para torneos. 

      \pre <em>El torneo existe en la lista</em>
      \post El resultado es la misma lista pero con n_tournaments - 1 y sin el torneo del parámetro
  */  
    void remove_tournament(const std::string& name);

  /** @brief Operación de consulta para torneos. 

      \pre <em>El torneo existe en la lista</em>
      \post Retorna el torneo con el nombre implícito de la función
  */  
    tournament get_tournament(const std::string& name);

  /** @brief Operación de consulta. 

      \pre <em>cierto</em>
      \post Retorna el número de torneos actuales en el circuito.
  */  
    int get_n_tournaments();

  /** @brief Operación de impresión por consola. 

      \pre <em>cierto</em>
      \post Se habrán imprimido todos los torneos del circuito.
  */  
    void print_tournaments();

  /** @brief Operación de consulta para la disponibilidad de torneos. 

      \pre <em>cierto</em>
      \post Devuelve verdadero si ya existe previamente el torneo en el circuito, y en el caso contrario, falso.
  */  
    bool exists_tournament(const std::string& name);

    // players

  /** @brief Operación de añadido para jugadores. Usa esencialmente las operaciones de ranking.

      \pre <em>El jugador no existe en la lista</em>
      \post El resultado es el mismo ranking pero con el jugador nuevo añadido en la última posición y n_players + 1
  */  
    void add_player(player p);

  /** @brief Operación de borrado para jugadores. Usa esencialmente las operaciones de ranking.

      \pre <em>El jugador existe en la lista</em>
      \post El resultado es el mismo ranking pero sin el jugador implícito y n_players - 1. Consultar la clase ranking para un mayor detalle.
  */  
    void remove_player(const std::string& name);

  /** @brief Operación de consulta. 

      \pre <em>cierto</em>
      \post Retorna el ranking global del circuito.
  */  
    ranking get_global_ranking();

  /** @brief Operación de consulta. 

      \pre <em>cierto</em>
      \post Retorna las categorías del circuito.
  */  
    categories get_categories();
};

#endif