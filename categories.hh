/** @file categories.hh
    @brief Especificaciones de tournament
*/

#ifndef AKIRA_CATEGORIES_HH
#define AKIRA_CATEGORIES_HH

#ifndef NO_DIAGRAM
#include <vector>
#endif

class categories
{
private:
    int max_lvl;
    int max_categories;
    std::vector<std::string> names;
    std::vector<std::vector<int> > points_per_level;
public:
/** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar categorías.
      \pre <em> cierto <em>
      \post El resultado es una instancia de categorías vacio.
  */  
    categories();
    ~categories();


  /** @brief Operación de lectura para guardar todas las categorías. Primero lee el número de categorías, después el nivel máximo, 
   *    y a continuación, los puntos por cada categoría y nivel junto con su nombre.

      \pre el número total de puntos debe ser max_lvl * max_categories
      \post El resultado son todas las categorías con sus nombres y su respectivos datos almacenados.
  */  
    void read_categories();

  /** @brief Operación de consulta para los puntos de una cierta categoría y nivel.

      \pre <em>cierto</em>
      \post Retorna los puntos que hay que sumar al jugador en función de la categoría y el nivel introducidos.
  */  
    int get_points(int category, int level) const;

 /** @brief Consultora para el nombre de la categoría.

      \pre El entero debe existir entre 1 y max_categories.
      \post Retorna el nombre de la categoría introducida.
  */  
    int get_name(int category) const;

 /** @brief Consultora para el nivel de un nombre de una categoría.

      \pre El string debe ser un nombre válido de una categoría
      \post Retorna el nivel de la categoría introducida.
  */  
    int get_level(const std::string name) const;

 /** @brief Consultora para el nivel máximo de las categorías.

      \pre <em> cierto <em>
      \post Retorna el nivel máximo de las categorías
  */  
    int get_max_lvl() const;

 /** @brief Consultora para la cantidad de categorías.

      \pre <em> cierto <em>
      \post Retorna el número de categorías existente
  */ 
    int get_max_categories() const;

  /** @brief Imprime por orden creciente de identificador, el nombre y la tabla de putnos por niveles de cada categoría.

      \pre <em>cierto</em>
      \post Se habrán imprimido los datos por pantalla.
  */  
    void print_categories();
};
#endif