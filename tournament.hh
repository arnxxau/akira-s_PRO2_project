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
    /** @brief Nombre del torneo. */
    std::string name;
    /** @brief Nivel del torneo o tipo de categoría. */
    int difficulty;
    /** @brief Verdadero si ya se ha jugado antes el torneo y falso si es el primera vez que se juega. */
    bool played = false;
    /** @brief Ranking interno del torneo. El primer elemento del par contiene el nombre del jugador y el segundo los puntos ganados en ese mismo torneo. */
    std::vector<std::pair<std::string, int > > names_with_points;
    /** @brief Copia del ranking del torneo. Al jugarse más de una vez un torneo, éste estará lleno con los jugadores y los puntos de la edición anterior. */
    std::vector<std::pair<std::string, int > > history;
    /** @brief Árbol que representa el cuadro de emparejamientos del torneo. */
    BinTree <int> pairing_chart;
    /** @brief Árbol de partidos que representa los resultados finales del torneo. */
    BinTree <match> results;


  /** @brief Crea el árbol de emparejamientos.

      \pre El nivel debe empezar en dos y la raíz en uno.
      \post El árbol binario "pairing_chart" está completado con la tabla de emparejamientos.
  */
    BinTree <int> create_pairing_chart(int n_players, int level, int root) const;


  /** @brief Confiecciona los resultados del torneo.

      \pre El árbol debe ser de emparejamientos y el nivel debe empezar en 1.
      \post El árbol binario de partidos estará completo con los resultados del torneo y las estadísticas de los jugadores actualizadas.
  */ 
    BinTree<match> compute_results(const BinTree<int>& pairing, int level,
        const categories& c, ranking& global_rank);

  /** @brief Imprime la tabla de emparejamientos.

      \pre El torneo debe haber sido iniciado, y por ende, el árbol de emparejamientos lleno.
      \post La tabla de emparejamientos se habrá impreso por pantalla.
  */ 
    void print_pairing_chart(const BinTree<int>& tree) const;

  /** @brief Imprime los resultados del torneo.

      \pre El torneo debe haber sido finalizado, y por ende, el árbol de partidos lleno.
      \post Los resultados de los partidos del torneo se habrán impreso por pantalla.
  */ 
    void print_results(const BinTree<match>& tree) const;

  /** @brief Inicializa el torneo leyendo los jugadores participantes.

      \pre <em>cierto<em>
      \post El resultado es el vector de todos los jugadores participantes con los ganados puntos a 0.
  */ 
    void init_tour(ranking& global_rank);

      /** @brief Actualiza las estadísticas de cada jugador al finalizarse un partido.

      \pre El nivel debe estar comprendido entre 1 y el máximo nivel de la clase categorías.
      \post El resultado es la actualización de las estadísticas de ambos jugadores del partido en el ranking global.
  */
    void update_stats(const match& m, int level, const categories& cat, ranking& global_rank);

  /** @brief Imprime el resultado de un partido.
      \pre El partido no debe estar vacío.
      \post Se habrá impreso por pantalla el resultado del partido en el formato correspondiente.
  */
    void print_match(const match& m) const;

public:
/** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar un torneo.
      \pre Debe ser una categoría válida entre 1 y C.
      \post El resultado es un torneo con el nombre y la dificultad asignadas.
  */  
    tournament(const std::string& name, int difficulty);

/** @brief Borra los puntos de los anteriores participantes si no es la primera vez que se juega el torneo.
      \pre <cierto>
      \post El resultado es el ranking global actualizado con los nuevos puntajes.
  */  
    void remove_points(ranking& global_rank);

/** @brief Borra un jugador del vector de historial de puntos si este existe en este.
      \pre <cierto>
      \post El resultado es el vector de historial de puntos con un jugador menos (si este existia anteriormente).
  */  
    void remove_player(const std::string& name);

  /** @brief Empieza un torneo, confecciona la tabla de emparejamientos e imprime por pantalla la tabla.

      \pre El número de jugadores inscritos no puede ser superior al número total de jugadores del circuito.
      \post El árbol binario "pairing_chart" está completado con la 
            tabla de emparejamientos y el árbol estará impreso por pantalla.
  */
    void start_tour(ranking& global_rank);

  /** @brief Acaba con el torneo, da los resultatos finales y actualiza la ficha de los jugadores.

      \pre El torneo debe haber sido empezado y los resultados tienen 
            que escribirse como un árbol binario de strings en preorden y en el orden del cuadro de emparejamientos.
      \post El árbol binario "results" está lleno, los puntos y las estadísticas de los jugadores actualizadas, 
            y already_played pasa a ser verdadero. Imprime también el ranking local sin reordenar.
  */
    void end_tour(const categories& cat, ranking& global_rank);

  /** @brief Consulta el identificador del torneo.

      \pre <em>cierto<em>
      \post Retorna el identificador del torneo.
  */
    std::string get_name() const;

  /** @brief Imprime el nombre y la categoría del torneo.

      \pre <em>cierto</em>
      \post Se ha imprimido el nombre y la categoría por pantalla.
  */  
    void print_tournament(const categories& c) const;
};

#endif