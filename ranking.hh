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

    int eff_search(const std::string& name) const;
public:


/** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un ranking.
      \pre <em>cierto</em>
      \post El resultado es un ranking con 0 jugadores.
  */  
    ranking();
    
    /** @brief Creadora opcional. 

      Se ejecuta al pasar como parámetro un vector de jugadores.
      \pre Los jugadores del vector deben ser únicos.
      \post El resultado es un ranking con todos los jugadores que contenía el vector implícito.
  */  
    ranking(std::vector<player> players);
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

      \pre El jugador no debe estar dentro del ranking.
      \post El resultado es el mismo ranking pero con el nuevo jugador en la última posición.
  */  
    void add_player(const player& p);

  /** @brief Elimina un jugador. 

      \pre El jugador tiene que estar dentro del ranking.
      \post El resultado es el ranking sin el jugador, y los jugadores de r + 1 a P mejoran en una posición.
  */  
    void remove_player(const std::string name);

  /** @brief Consulta un jugador del ranking por su nombre.

      \pre El jugador existe en el ranking.
      \post Retorna al jugador.
  */
    player get_player_by_name(const std::string name);

  /** @brief Consulta un jugador del ranking por su posición en el ranking.

      \pre El entero es una posición válida del ranking.
      \post Retorna al jugador.
  */
    player get_player_by_pos(int position);

  /** @brief Consulta si un jugador está en el ranking.

      \pre El string name tiene que ser un identificador de un jugador válido.
      \post Retorna verdadero si el jugador está en el ranking y falso si no lo está.
  */
    bool is_player_there(const std::string& name) const;

  /** @brief Imprime en el orden del ranking, la posición de los jugadores, los nombres y los puntos.

      \pre <em>cierto</em>
      \post Los datos se habrán imprimido por pantalla.
  */  
    void print_ranking();

  /** @brief Imprime cada jugador en orden lexográfico creciente.

      \pre <em>cierto</em>
      \post Los datos se habrán imprimido por pantalla.
  */  
    void print_players();

  /** @brief Consulta el número de jugadores.

      \pre <em>cierto</em>
      \post Retorna el número de jugadores del ranking actual.
  */  
    int get_number_of_players() const;
};


#endif