/** @file player.hh
    @brief Especificaciones de player
*/

#ifndef AKIRA_PLAYER_HH
#define AKIRA_PLAYER_HH

#ifndef NO_DIAGRAM
#include <string>
#endif
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
    
public:
    player(std::string name);
    ~player();


  /** @brief Modificadora de posición en el rango global. 

      \pre <em>cierto</em>
      \post El resultado es el jugador con la nueva posición asignada
  */  
    void modify_rank_position(int rank_pos);

  /** @brief Modificadora de puntos totales del jugador. 

      \pre El entero points tiene que ser más grande o igual a -total_points.
      \post El resultado es el jugador con los nuevos puntos sumados
  */  
    void modify_total_points(int points);

  /** @brief Modificadora de las estadísticas del jugador. 

      \pre Tiene que ser una struct de estadísticas válido.
      \post El resultado es el jugador con las estadísticas nuevas.
  */  
    void modify_stadistics(stadistics stats);

  /** @brief Operación de consulta de posición. 

      \pre <em>cierto</em>
      \post Retorna la posición del jugador en el ranking global.
  */  
    int get_rank_position();

  /** @brief Operación de consulta de nombre.

      \pre <em>cierto</em>
      \post Retorna el nombre del jugador.
  */  
    std::string get_name();

  /** @brief Operación de consulta de los puntos totales. 

      \pre <em>cierto</em>
      \post Retorna los puntos totales del jugador.
  */  
    int get_total_points();

  /** @brief Operación de consulta de estadísticas.

      \pre <em>cierto</em>
      \post Retorna las estadísticas del jugador.
  */  
    stadistics get_stadistics();

  /** @brief Imprime el nombre, la posición en el ranking, los puntos y el resto de estadísticas.

      \pre <em>cierto</em>
      \post ...
  */  
    void print_player();
};

#endif