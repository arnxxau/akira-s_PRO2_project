/** @file Categories.hh
    @brief Especificaciones de Categories
*/

#ifndef AKIRA_CATEGORIES_HH
#define AKIRA_CATEGORIES_HH

#ifndef NO_DIAGRAM
#include <vector>
#include <iostream>
#endif

/** @class Categories
    @brief Representa las categorías de los torneos.

    Permite almacenar las diferentes categorías de torneos, y de esta forma, ofrecer a la clase torneo una manera simple de obtener los puntos que debe sumar a cada jugador.
*/
class Categories
{
private:
    /** @brief Indica la cantidad de niveles máximo que puede poseer un torneo. */
    int max_lvl;
    /** @brief Indica el número de categorías del circuito. */
    int n_categories;
    /** @brief Nombre de las categorías ordenadas por niveles en orden creciente. */
    std::vector<std::string> names;
    /** @brief Matriz con los puntos por nivel. Cada fila corresponde a los puntos de cada categoría. */
    std::vector<std::vector<int> > points_per_level;
public:
/** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar categorías.
      \pre <em>cierto<em>
      \post El resultado es una instancia de categorías vacía.
  */  
    Categories();


  /** @brief Operación de lectura para guardar todas las categorías. Primero lee el número de categorías, después el nivel máximo, 
   *    y a continuación, los puntos por cada categoría y nivel junto con su nombre.

      \pre El número total de puntos debe ser max_lvl * n_categories
      \post El resultado son todas las categorías con sus nombres y su respectivos datos almacenados.
  */  
    void read_categories();

  /** @brief Operación de consulta para los puntos de una cierta categoría y nivel.

      \pre <em>cierto</em>
      \post Retorna los puntos que hay que sumar al jugador en función de la categoría y el nivel introducidos.
  */  
    int get_points(int category, int level) const;

 /** @brief Consultora para el nombre de la categoría.

      \pre El entero debe existir entre 1 y n_categories.
      \post Retorna el nombre de la categoría introducida.
  */  
    std::string get_name(int category) const;

 /** @brief Consultora para el nivel máximo de las categorías.

      \pre <em>cierto<em>
      \post Retorna el nivel máximo de las categorías
  */  
    int get_max_lvl() const;

 /** @brief Consultora para la cantidad de categorías.

      \pre <em>cierto<em>
      \post Retorna el número de categorías existente.
  */ 
    int get_n_categories() const;

  /** @brief Imprime por orden creciente de identificador, el nombre y la tabla de putnos por niveles de cada categoría.

      \pre <em>cierto</em>
      \post Se habrán imprimido los datos por pantalla.
  */  
    void print_categories() const;
};

#endif