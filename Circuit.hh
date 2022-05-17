/** @file Circuit.hh
    @brief Especificaciones de Circuit
*/

#ifndef AKIRA_CIRCUIT_HH
#define AKIRA_CIRCUIT_HH

#include "Tournament.hh"

/** @class Circuit
    @brief Representa un circuito de tennis.

    Esencialmente es una lista de torneos y es la clase que engloba a todas las demás. Contiene métodos para poder manejar el conjunto de torneos de forma más sencilla. 
    Operaciones como la lectura de torneos y de jugadores se ofrecen en esta clase.
*/
class Circuit
{
private:
/** @brief Indica la cantidad de torneos que hay actualmente en el circuito. */
    int n_tournaments = 0;
/** @brief Mapa de torneos que tiene como clave el nombre de estos */
    std::map<std::string, Tournament> tournaments;

public:

/** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un circuito.
      \pre <em>cierto<em>
      \post El resultado es un circuito vacio con las categorías introducidas.
  */  
    Circuit();

    // tournaments

  /** @brief Operación de lectura para torneos. 

      \pre T es mayor o igual que 0 y la categoría está entre 1 y C.
      \post El resultado es una lista con los torneos leídos.
  */  
    void read_tournaments();

  /** @brief Operación de añadido para torneos. 

      \pre El torneo no existe en la lista.
      \post El resultado es la misma lista pero con n_tournaments + 1 y el nuevo torneo añadido.
  */  
    void add_tournament(const Tournament& tour);

  /** @brief Operación de borrado para torneos. 

      \pre El torneo existe en la lista
      \post El resultado es la misma lista pero con n_tournaments - 1 y sin el torneo del parámetro.
  */  
    void remove_tournament(const std::string& name, Ranking& global_ranking);

  /** @brief Operación de borrado de jugadores participantes en torneos. 

      \pre El jugador debe existir en el circuito.
      \post El jugador habrá sido borrado de aquellos torneos en los cuales ha participado anteriormente.
  */  
    void remove_player_tour(const std::string& name);

  /** @brief Extensión de empezar torneo. Busca el nombre del torneo existente y ejecuta su propia función interna. Para información adicional, consultar la propia función en Torneo.hh.

      \pre El torneo debe existir en el circuito.
      \post El torneo introducido habrá sido empezado.
  */  
    void start_tour(const std::string& name, Ranking& global_rank);

  /** @brief Extensión de finalizar torneo. Busca el nombre del torneo existente y ejecuta su propia función interna. Para información adicional, consultar la propia función en Torneo.hh.

      \pre El torneo debe existir en el circuito.
      \post El torneo introducido habrá sido finalizado.
  */  
    void end_tour(const std::string& name, Ranking& global_rank, const Categories& cat);

  /** @brief Operación de consulta. 

      \pre <em>cierto</em>
      \post Retorna el número de torneos actuales en el circuito.
  */  
    int get_n_tournaments() const;

  /** @brief Operación de impresión por consola. 

      \pre <em>cierto</em>
      \post Se habrán imprimido todos los torneos del circuito.
  */  
    void print_tournaments(const Categories& c) const;

  /** @brief Operación de consulta para la disponibilidad de torneos. 

      \pre <em>cierto</em>
      \post Devuelve verdadero si ya existe previamente el torneo en el circuito, y en el caso contrario, falso.
  */  
    bool exists_tournament(const std::string& name) const;
};

#endif