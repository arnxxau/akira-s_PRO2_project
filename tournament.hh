/** @file tournament.hh
    @brief Especificaciones de tournament
*/

#ifndef AKIRA_TOUR_HH
#define AKIRA_TOUR_HH

#include "ranking.hh"
#include "categories.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#endif

class tournament
{
private:
    std::string name;
    int difficulty;
    ranking local_rank;
    int n_levels;
    categories cat;
    
    bool already_played = false;

    BinTree <string> pairing_chart;
    BinTree <int> results;
public:
    tournament(std::string name, int difficulty, categories cat);
    ~tournament();


  /** @brief Inicializa un torneo leyendo todos los datos necesarios.

      \pre Los jugadores ya existen en la lista global del circuito
      \post El torneo está inicializado y el ranking local ya contiene los participantes.
  */
    void init_tour();

  /** @brief Empieza un torneo y confecciona la tabla de emparejamientos.

      \pre El torneo debe haber sido inicializado.
      \post El árbol binario "paring_chart" está completado con la tabla de emparejamientos
  */
    void start_tour();

  /** @brief Acaba con el torneo, da los resultatos finales y actualiza la ficha de los jugadores.

      \pre El torneo debe haber sido empezado.
      \post El árbol binario "results" está lleno, los puntos y las estadísticas de los jugadores actualizadas, 
            y already_played pasa a ser verdadero.
  */
    void end_tour();


  /** @brief Consulta si este torneo es la primera vez que se celebra o no.

      \pre ...
      \post Retorna verdadero si el torneo ya ha sido jugado previamente y falso si esta es la primera edición que se juega.
  */
    bool already_played();

  /** @brief Consulta el identificador del torneo

      \pre ...
      \post Retorna el identificador del torneo
  */
    std::string get_name();

  /** @brief Imprime el nombre y la categoría del torneo.

      \pre <em>cierto</em>
      \post ...
  */  
    void print_tournament();
};



#endif