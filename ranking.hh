/** @file ranking.hh
    @brief Especificaciones de ranking
*/

#ifndef AKIRA_RANK_HH
#define AKIRA_RANK_HH

#include "player.hh"

#ifndef NO_DIAGRAM
#include <vector>
#endif

class ranking
{
private:
    std::vector<std::pair<player, int > > rank;
    std::vector<player> players; // lista ordenada con los jugadores ordenados por órden lexográfico para buscar de forma más eficiente

    int eff_search(const std::string& name);
public:
    ranking(std::vector<player> players);
    ranking();
    ~ranking();

  /** @brief Operación de lectura. 

      \pre <em>cierto</em>
      \post El resultado es un ranking con sus jugadores ordenados por orden de ranking global.
  */  
    void read();

  /** @brief Operación de ordenación. 

      \pre <em>cierto</em>
      \post El resultado es el mismo ranking pero reordenado por los puntos totales de cada jugador en ese momento, en orden creciente.
  */  
    void sort_rank();

  /** @brief Añade un jugador. 

      \pre <em>cierto</em>
      \post El resultado es el mismo ranking pero reordenado por los puntos totales de cada jugador en ese momento, en orden creciente.
  */  
    void add_player();

  /** @brief Elimina un jugador. 

      \pre <em>cierto</em>
      \post El resultado es el ranking sin el jugador, y los jugadores de r + 1 a P mejoran en una posición.
  */  
    void remove_player();

  /** @brief Consulta un jugador del ranking por su nombre

      \pre El jugador existe en el ranking
      \post Retorna el jugador
  */
    player get_player_by_name(const std::string name);

  /** @brief Consulta un jugador del ranking por su posición en el ranking.

      \pre El jugador existe en el ranking
      \post Retorna el jugador
  */
    player get_player_by_pos(int position);

  /** @brief Consulta si un jugador está en el ranking.

      \pre El string name tiene que ser un identificador de un jugador válido
      \post Retorna verdadero si el jugador está en el ranking y falso si no lo está
  */
    bool is_player_there(const std::string& name);

  /** @brief Imprime en el orden del ranking, la posición de los jugadores, los nombres y los puntos.

      \pre <em>cierto</em>
      \post ...
  */  
    void print_ranking();

  /** @brief Imprime cada jugador en orden lexográfico creciente.

      \pre <em>cierto</em>
      \post ...
  */  
    void print_players();

  /** @brief Consulta el número de jugadores.

      \pre <em>cierto</em>
      \post Retorna el númeoro de jugadores del ranking actual.
  */  
    int get_number_of_players();
};


#endif