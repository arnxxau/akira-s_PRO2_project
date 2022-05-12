/** @file ranking.hh
    @brief Especificaciones de ranking
*/

#ifndef AKIRA_RANK_HH
#define AKIRA_RANK_HH

#include "player.hh"

#ifndef NO_DIAGRAM
#include <vector>
#include <map>
#include <algorithm>
#endif

/** @class ranking
    @brief Representa un ranking de jugades de tennis.

    Es la segunda unidad más básica del circuito. Esencialmente es una lista de jugadores con la que se pueden ejecutar diversos métodos para su manejo;
    como ordenar todo el ranking o bien imprimir cada jugador con cada una de sus propiedades.
*/
class ranking
{
private:
    std::vector<std::map<std::string, player>::iterator > rank;
    std::map<std::string, player> players_map;
    
    int number_of_players = 0;

    // int linear_search(const std::string& name) const;
    static bool order(const std::map<std::string, player>::iterator& p1, const std::map<std::string, player>::iterator& p2);

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
    void add_player(player p);


    void read_players();

  /** @brief Elimina un jugador. 

      \pre El jugador tiene que estar dentro del ranking.
      \post El resultado es el ranking sin el jugador, y los jugadores de r + 1 a P mejoran en una posición.
  */  
    void remove_player(const std::string& name);

  /** @brief Consulta un jugador del ranking por su nombre.

      \pre El jugador existe en el ranking.
      \post Retorna al jugador.
  */
    player get_player_by_name(const std::string& name) const;

  /** @brief Consulta un jugador del ranking por su posición en el ranking.

      \pre El entero es una posición válida del ranking.
      \post Retorna al jugador.
  */
    player get_player_by_pos(int position) const;

    void modify_stats(const std::string& name, int points, 
        int wm, int lm, int ws, int ls, int wg, int lg);

    void increase_player_tours(const std::string& name);

    void remove_points(const std::string& name, int points);

  /** @brief Consulta si un jugador está en el ranking.

      \pre El string name tiene que ser un identificador de un jugador válido.
      \post Retorna verdadero si el jugador está en el ranking y falso si no lo está.
  */
    bool is_player_there(const std::string& name) const;

  /** @brief Imprime en el orden del ranking, la posición de los jugadores, los nombres y los puntos.

      \pre <em>cierto</em>
      \post Los datos se habrán imprimido por pantalla.
  */  
    void print_ranking() const;

  /** @brief Imprime cada jugador en orden lexográfico creciente.

      \pre <em>cierto</em>
      \post Los datos se habrán imprimido por pantalla.
  */  
    void print_players() const;

  /** @brief Consulta el número de jugadores.

      \pre <em>cierto</em>
      \post Retorna el número de jugadores del ranking actual.
  */  
    int get_number_of_players() const;
};


#endif