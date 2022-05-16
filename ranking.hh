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
    /** @brief Vector que contiene los jugadores del ranking en forma de iterador */
    std::vector<std::map<std::string, player>::iterator > rank;
    /** @brief Mapa de jugadores que tiene como clave el nombre de estos */
    std::map<std::string, player> players_map;
    
    /** @brief Entero que representa el número de jugadores actuales en el ranking  */
    int number_of_players = 0;

  /** @brief Función booleana para ordenar el ranking por orden decreciente de puntos, si estos coincidieran, se ordenaría entonces por orden de ranking anterior.
      \pre El vector debe contener iteradores de mapas de jugadores.
      \post Retorna verdadero si los puntos de p1 son mayores que los de p2. En el caso de ser estos iguales, solo retornaria verdadero si el ranking anterior de p1 es mayor a p2.
            Si no se cumple nada de lo anterior, devolvería falso.
  */
    static bool order(const std::map<std::string, player>::iterator& p1, 
        const std::map<std::string, player>::iterator& p2);

public:


/** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un ranking.
      \pre <em>cierto</em>
      \post El resultado es un ranking con 0 jugadores.
  */  
    ranking();
    
  /** @brief Operación de lectura. 

      \pre <em>cierto</em>
      \post El resultado es un ranking con sus jugadores ordenados por orden de ranking global.
  */  
    void read();

  /** @brief Operación de ordenación. 

      \pre <em>cierto</em>
      \post El resultado es el mismo ranking pero reordenado por los puntos totales de cada jugador en ese momento, en orden decreciente. 
          Si los puntos fueran equivalentes entre jugadores, se ordenaría por orden creciente del ranking anterior.
  */  
    void sort_rank();

  /** @brief Añade un jugador. 

      \pre El jugador no debe estar dentro del ranking.
      \post El resultado es el mismo ranking pero con el nuevo jugador en la última posición y con 0 puntos.
  */  
    void add_player(const std::string& name);

  /** @brief Lee el conjunto inicial de jugadores. 

      \pre El nombre de los jugadores deben ser únicos.
      \post El resultado es el ranking con los nuevos jugadores a 0 puntos y en el orden en el que han sido introducidos por consola.
  */  
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

  /** @brief Modificadora de las estadísticas de un jugador del ranking.
   *    Cada parámetro corresponde a una estadísticas, la lista de correspondencias es la siguiente:
   *    points -> puntos totales jugador, wm -> partidos ganados, lm -> partidos perdidos, 
   *    ws -> sets ganados, ls -> sets perdidos, wg -> juegos ganados, lg -> juegos perdidos

      \pre El nombre debe ser un jugador existente en el ranking. Los enteros deben ser positivos.
      \post El jugador del ranking habrá sido actualizado con las nuevas estadísticas.
  */
    void modify_stats(const std::string& name, int points, 
        int wm, int lm, int ws, int ls, int wg, int lg);


  /** @brief Modificadora de los torneos jugados de un jugador del ranking.

      \pre El nombre debe ser de un jugador existente del ranking.
      \post Los torneos jugados del jugador habrán incrementado en una unidad.
  */
    void increase_player_tours(const std::string& name);


  /** @brief Modificadora de los puntos de un jugador del ranking.

      \pre El nombre debe ser de un jugador existente del ranking. Los puntos a restar no deben ser mayores a los actuales.
      \post Los puntos del jugador se habrán reducido 
  */
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