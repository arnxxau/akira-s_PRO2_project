/** @file player.hh
    @brief Especificaciones de player
*/

#ifndef AKIRA_PLAYER_HH
#define AKIRA_PLAYER_HH

#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#endif

/** @class player
    @brief Representa un jugador de tennis.

    Es la unidad más básica del circuito de tennis. Contiene el nombre del jugador y las estadísticas de éste.
*/
class player
{
private:
    std::string name;
    int rank_pos;
    int total_points;
    struct stadistics
  { 
    int played_matches = 0;
    std::pair <int, int> matches_won_lost = {0, 0};
    std::pair <int, int> sets_won_lost = {0, 0};
    std::pair <int, int> games_won_lost = {0, 0};
  };
    stadistics player_stats;
    
public:
  /** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un jugador.
      \pre <em>cierto</em>
      \post El resultado es un jugador con 0 puntos iniciales, todas las estadísticas a 0 junto con su correspondiente nombre.
  */  
    player(std::string name);
    ~player();


  /** @brief Modificadora de posición en el rango global. 

      \pre <em>cierto</em>
      \post El resultado es el jugador con la nueva posición asignada.
  */  
    void modify_rank_position(int rank_pos);

  /** @brief Modificadora de puntos totales del jugador. 

      \pre El entero points tiene que ser más grande o igual a -total_points.
      \post El resultado es el jugador con los nuevos puntos sumados.
  */  
    void modify_total_points(int points);


  /** @brief Modificadora de los partidos ganados y perdidos del jugador. 

      \pre Los enteros deben ser positivos.
      \post El resultado es el jugador con las estadísticas modificadas.
  */  
    void modifiy_matches(int won, int lost);

  /** @brief Modificadora de los sets ganados y perdidos del jugador. 

      \pre Los enteros deben ser positivos.
      \post El resultado es el jugador con las estadísticas modificadas.
  */  
    void modifiy_sets(int won, int lost);

  /** @brief Modificadora de los juegos ganados y perdidos del jugador. 

      \pre Los enteros deben ser positivos.
      \post El resultado es el jugador con las estadísticas modificadas.
  */  
    void modifiy_games(int won, int lost);

  /** @brief Operación de consulta de posición. 

      \pre <em>cierto</em>
      \post Retorna la posición del jugador en el ranking global.
  */  
    int get_rank_position() const;

  /** @brief Operación de consulta de nombre.

      \pre <em>cierto</em>
      \post Retorna el nombre del jugador.
  */  
    std::string get_name() const;

  /** @brief Operación de consulta de los puntos totales. 

      \pre <em>cierto</em>
      \post Retorna los puntos totales del jugador.
  */  
    int get_total_points() const;

  /** @brief Operación de consulta de estadísticas.

      \pre <em>cierto</em>
      \post Retorna las estadísticas del jugador.
  */  
    stadistics get_stadistics() const;

  /** @brief Imprime el nombre, la posición en el ranking, los puntos y el resto de estadísticas.

      \pre <em>cierto</em>
      \post Las estadísticas se habrán imprimido por pantalla.
  */  
    void print_player();
};

#endif