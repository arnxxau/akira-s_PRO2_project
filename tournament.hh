/** @file tournament.hh
    @brief Especificaciones de tournament
*/

#ifndef AKIRA_TOUR_HH
#define AKIRA_TOUR_HH

#include "ranking.hh"
#include "match.hh"
#include "categories.hh"

#ifndef NO_DIAGRAM
#include "BinTree.hh"
#include <iostream>
#endif

/** @class tournament
    @brief Representa un torneo de tennis.

    Contiente las operaciones básicas para poder llevar a cabo la representación de un torneo de tennis, usando como clases base, player y ranking.
*/
class tournament
{
private:
    std::string name;
    int difficulty; // tipo de categoría
    bool played = false;
    std::vector<std::pair<std::string, int > > names_with_points;
    std::vector<std::pair<std::string, int > > history;
    BinTree <int> pairing_chart;
    BinTree <match> results;

    BinTree <int> arborescence(int n_players, int level, int root) const;
    BinTree<match> winner_arborescence(BinTree<int> pairing_copy, int level,
        const categories& cat, ranking& global_rank);
    void print_pairing_chart(const BinTree<int>& tree);
    void print_results(const BinTree<match>& tree);
    void init_tour(ranking& global_rank);
    static bool order(const std::pair<std::string, int >& p1, 
          const std::pair<std::string, int >& p2);

public:
/** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un torneo.
      \pre Debe ser una categoría válida entre 1 y C.
      \post El resultado es un torneo con el nombre y la dificultad asignadas.
  */  
    tournament(std::string name, int difficulty);

  /** @brief Empieza un torneo, confecciona la tabla de emparejamientos e imprime por pantalla la tabla.

      \pre El número de jugadores inscritos no puede ser superior al número total de jugadores del circuito.
      \post El árbol binario "pairing_chart" está completado con la 
            tabla de emparejamientos y el árbol estará impreso por pantalla.
  */
    void start_tour(ranking& global_rank);

    void remove_points(ranking& global_rank);

    void remove_player(const std::string name);

  /** @brief Acaba con el torneo, da los resultatos finales y actualiza la ficha de los jugadores.

      \pre El torneo debe haber sido empezado y los resultados tienen 
            que escribirse como un árbol binario de strings en preorden y en el orden del cuadro de emparejamientos.
      \post El árbol binario "results" está lleno, los puntos y las estadísticas de los jugadores actualizadas, 
            y already_played pasa a ser verdadero. Imprime también el ranking local sin reordenar.
  */
    void end_tour(const categories& cat, ranking& global_rank);

  /** @brief Consulta el identificador del torneo

      \pre <em> cierto <em>
      \post Retorna el identificador del torneo
  */
    std::string get_name() const;

  /** @brief Imprime el nombre y la categoría del torneo.

      \pre <em>cierto</em>
      \post Se ha imprimido el nombre y la categoría por pantalla.
  */  
    void print_tournament(const categories& c) const;
};

#endif