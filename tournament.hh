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
    int difficulty; // tipo de categoría
    ranking local_rank;
    int n_levels; // número de niveles del torneo
    categories cat;
    
    bool already_played = false;

    BinTree <string> pairing_chart;
    BinTree <int> results;

    void init_tour();

public:
/** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un torneo.
      \pre Debe ser una categoría válida entre 1 y C.
      \post El resultado es un torneo con un nombre y dificultad asignadas.
  */  
    tournament(std::string name, int difficulty, categories cat);
    ~tournament();

  /** @brief Empieza un torneo, confecciona la tabla de emparejamientos e imprime por pantalla la tabla.

      \pre El número de jugadores inscritos no puede ser superior al número total de jugadores del circuito.
      \post El árbol binario "pairing_chart" está completado con la 
            tabla de emparejamientos y el árbol estará impreso por pantalla.
  */
    void start_tour();

  /** @brief Acaba con el torneo, da los resultatos finales y actualiza la ficha de los jugadores.

      \pre El torneo debe haber sido empezado y los resultados tienen 
            que escribirse como un árbol binario de strings en preorden y en el orden del cuadro de emparejamientos.
      \post El árbol binario "results" está lleno, los puntos y las estadísticas de los jugadores actualizadas, 
            y already_played pasa a ser verdadero. Imprime también el ranking local sin reordenar.
  */
    void end_tour();


  /** @brief Consulta si este torneo es la primera vez que se celebra o no.

      \pre <em> cierto <em>
      \post Retorna verdadero si el torneo ya ha sido jugado previamente y falso si esta es la primera edición que se juega.
  */
    bool already_played() const;

  /** @brief Consulta el identificador del torneo

      \pre <em> cierto <em>
      \post Retorna el identificador del torneo
  */
    std::string get_name() const;

  /** @brief Imprime el nombre y la categoría del torneo.

      \pre <em>cierto</em>
      \post Se ha imprimido el nombre y la categoría por pantalla.
  */  
    void print_tournament();
};



#endif