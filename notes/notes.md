# circuitos, ranking y torneos
## características circuito
- Formado por T torneos (se identifican por un nombre) (no constante)
- Agrupados en C categorías (constante)
- Las categorías van de 1 a C y también tienen nombre ej -> **categoria 1**: "Open Austrialia"
																									**nombre categoria 1**: "Grand Slam"
- Todos los torneos tienen un número máximo de niveles K, y es común: n1 -> ganador,
n2 -> finalista, n2 -> semifinalistas ........
- Los puntos para cada jugador se calculan usando **i** (categoría del torneo) y **j** (nivel del jugador) 
- Los partidos se disputan al mejor de 3 sets. Si se llega a 6 -> tie-break
- Existe un registro P de los jugadores que pueden participiar en los torneos (no constante)
- Existirá también un ranking entre los jugadores

## características ranking
- Se asignarán cero puntos a todos los jugadores y se establecerá un ranking inicial con valores 1...P
- Después de cada torneo del circuito, se sumarán los puntos correspondientes a cada jugador
- Si no es la primera vez que se celebra dicho torneo, se le restarán los puntos correspondientes a cada jugador que haya participado en la edición anterior
- El ranking se actualiza cada vez que finaliza un torneo (refleja el puntaje de los torneos más recientes)
- Ordenado decrecientemente por puntos de jugador
- En caso de empate según el valor del ranking anterior a la actualización (orden creciente)
- Al añadir un nuevo jugador, éste pasa a ocupar la última posición del ranking con cero puntos
- Cuando un jugador se da de baja, los jugadores entre r + 1 y P mejoran una posición
- Cuando un torneo se da de baja, se restarán los puntos obtenidos de la última edición y se volverá a actualizar el ranking

## características torneo, fases
### 1 -  inscripciones
- ==8 <= n <= 2^K-1== (K -> número máximo de niveles)
- K - 1 -> número máximo de tondas de un torneo
- El resultado es una secuencia ordenada crecientemente de n enteros
- Se asocia un valor r de 1 a n que depende del valor del ranking global

### 2 - confección y publicación oficial del cuadro de emparejamientos
- árbol binario, representa los enfrentamientos
- ==n = número de hojas==
- ganará el jugador que tenga un mejor ranking

*propiedades árbol*
- los dos mejores solo podrán jugar entre ellos en la final, los cuatro mejores en semifinal.....
- inicialmente el mejor jugador estará en el árbol derecho y el peor en el izquierdo (después puede no cumplirse al ganar un jugador peor a uno mejor)
- ==altura árbol -> floor(log2(n)) + 1 ==
- número de nodos si n completo -> ==2^h-1==
- Si n = m -> b = m + 1 - a y 1 <= a <= m/2
- Si n < m -> m - n hojas en el nivel h - 1
- Las hojas anteriores corresponderían a los mejores del ranking (r entre 1 y m - n)
- Entonces las hojas en h son: m - 2 * (m - n), es decir, restamos las hojas de h - 1 en el último nivel completo
- b = m + 1 - a y (m - n + 1) <= a <= m/2
- de 1 <= l < h, estarán llenos de nodos a los que se les asignará un identificador provisional r siguiendo las normas de n = m
- l = 1, un nodo (raíz), con identificador provisional r = 1

### 3 - desarrollo del torneo
- No importa el orden de disputa entre rondas iguales
- Al acabar un partido el identificador del jugador se apunta en el nodo padre
- Al acabar el torneo, el identificador de la raíz será el ganador

### 4 - Publicación oficial del cuadro de resultados
- Los resultados también son un árbol binario
- ...

### 5 - Cálculo de puntos



## especificación
#### jugador
Es la unidad más básica.
Contiene los siguientes datos:
Nombre
Posición en el ranking
Puntos actuales
Estadísticas:
torneos disputados, número de partidos ganados y perdidos, número de sets ganados y perdidos, número de juegos ganados y perdidos
...
### jugadores -> ranking
### torneo
### torneos -> circuito
T -> Número de torneos






## comandos y programa principal
### nuevo_jugador, nj
Lee y añade un nuevo jugador con identificador p

### nuevo_torneo, nt
Lee un nuevo torneo con identificador t y categoría c y lo añade al circuito

### baja_jugador, bj
Da de baja en el circuito al jugador con identificador p

### baja_torneo, bt
Da de baja en el circuito al torneo con identificador t

### iniciar_torneo, it
Lee la inscripción en el torneo t y computa e imprime el cuadro de emparejamientons de los jugadores inscritos
![[ejemplo_cuadro.png]]

### finalizar_torneo, ft
Leen los resultados del torneo t, se produce e imprime el cuadro oficial de los resultados y se listan los puntos para el ranking ganados por cada uno de los participantes.
También se actualiza el ranking y las estadísticas de los jugadores.
**Los resultados del torneo de leen en como un árbol binario de strings en preorden!!**
![[ejemplo_torneo.png|400]]

### listar_ranking, lr
Imprime por orden creciente del ranking actual, la posición, el nombre y los puntos de cada jugador del circuito.
![[ejemplo_ranking.png|200]]
### listar_jugadores, lj
Imprime por orden creciente de identificador, el nombre, la posición en el ranking, los puntos y el resto de las estadísticas de cada jugador del circuito

### consultar_jugador, cj
Imprime el nombre del jugador, la posición en el ranking, los puntos y el resto de las estadísticas de cada jugador del circuito
