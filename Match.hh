/** @file Match.hh
    @brief Especificaciones de Match
*/

#ifndef AKIRA_MATCH_HH
#define AKIRA_MATCH_HH

#ifndef NO_DIAGRAM
#include <string>
#endif


/** @class Match
    @brief Representa un partido tennis.

    Permite almacenar el resultado de un partido y así calcular todas las estadísticas correspondientes, incluido el ganador de este.
*/
class Match
{
    
private:
  /** @brief Un set es un par de enteros. La primer componente representa los juegos ganados por el jugador izquierdo, y la segunda componente, los juegos ganados por el derecho.*/
    typedef std::pair<int, int> set;
    /** @brief Cierto si el ganador es el jugador izquierdo y falso si es el derecho.*/
    bool b_winner;
    /** @brief Representa la posición del jugador izquierdo en el torneo actualmente jugado. */
    int left_pos;
    /** @brief Representa la posición del jugador derecho en el torneo actualmente jugado.*/
    int right_pos;
    /** @brief Representa los sets ganados por el jugador izquierdo.*/
    int left_sets = 0;
    /** @brief Representa los sets ganados por el jugador derecho.*/
    int right_sets = 0;
    /** @brief Representa los juegos ganados por el jugador izquierdo.*/
    int left_games = 0;
    /** @brief Representa los juegos ganados por el jugador derecho.*/
    int right_games = 0;
    /** @brief Pasa a ser verdadero si se usa la segunda constructura opcional, la cual sirve como hoja vacía para el árbol de resultados.*/
    bool empty = false;
    /** @brief El resumen del partido en formato string.*/
    std::string input;

/** @brief Lee un set y lo descompone en forma de enteros.

      \pre 'i + 2' no puede ser mayor al tamaño del string 'input'.
      \post El resultado es el set modificado pasado por referencia y la 'i' aumentada en 4 unidades para así apuntar al siguiente set del partido.
            Los juegos totales de cada jugador también se modifican con su correspondiente puntaje.
  */  
    void read_set(set& s, int& i);
    /** @brief Recorre todos los sets y decide el ganador del partido.

      \pre <em>cierto<em>
      \post El resultado es el booleano ganador modificado y las estadísticas del partido actualizadas.
  */  
    void read_match();
public:

/** @brief Creadora por defecto. 

      Se ejecuta automáticamente al declarar categorías.
      \pre El string debe ser un resumen válido de un partido y las posiciones deben deben existir en el torneo desde el que se llama.
      \post El resultado es un partido con los parámetros introducidos y con el ganador ya computado.
  */  
    Match(const std::string& input, int left_pos, int right_pos);

/** @brief Creadora opcional. 
    Sirve esencialmente para usarse de hoja en el árbol de resultados y así facilitar la recursividad.

      \pre El entero debe ser una posición válida del torneo.
      \post Se creará un partido sin resultados en el cual el ganador es el entero introducido.
  */  
    Match(int only);

 /** @brief Consultora para el ganador del partido.

      \pre El partido no debe estar vacío.
      \post Retorna la posición en torneo del ganador del partido.
  */  
    int get_winner() const;

 /** @brief Consultora de los sets del partido.

      \pre El partido no debe estar vacío.
      \post Retorna los sets del jugador izquierdo si el booleano es verdadero y, el del derecho si es falso.
  */  
    int get_sets(bool left) const;

 /** @brief Consultora de los juegos del partido.

      \pre El partido no debe estar vacío.
      \post Retorna los juegos del jugador izquierdo si el booleano es verdadero y, el del derecho si es falso.
  */  
    int get_games(bool left) const;

 /** @brief Consultora de las posiciones de los jugadores del partido.

      \pre El partido no debe estar vacío.
      \post Retorna la posición del jugador izquierdo en el torneo si el booleano es verdadero y, el del derecho si es falso.
  */  
    int get_pos(bool left) const;

 /** @brief Consultora del booleano ganador.

      \pre El partido no debe estar vacío.
      \post Retorna verdadero si ha ganado el jugador izquierdo y falso si ha ganado el derecho.
  */  
    bool get_bool() const;

 /** @brief Consultora del resultado del partido.

      \pre El partido no debe estar vacío.
      \post Retorna el resumen del partido en forma de string, es decir, por ejemplo: '6-4,6-3'.
  */  
    std::string get_result() const;
    
/** @brief Consultora del booleano vacío.

    El hecho de que sea verdadero, indica que es una hoja del árbol de emparejamientos.
      \pre <em>cierto<em>
      \post Retorna verdadero si el partido está vacío, es decir, si ha sido inicializado con la constructora opcional y, falso, si ha sido creado con la consultora por defecto.
  */  
    bool is_empty() const;
};


#endif
