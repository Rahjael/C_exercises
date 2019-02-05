#include <stdio.h>

int main() {


/*



*/


Sto cercando di capire come mai in C per fare una roba random ci sono tutti questi cazzi. Su Python era facilissimo.
Ho visto quali sono i passaggi ma non voglio applicarli a tavolino.

Vediamo se intanto ho capito time():

1. 
time_t è un datatype incluso in <time.h>, libreria che contiene i tools per gestire il tempo.

time_t pippo;

prende lo stack e mi prepara uno slot di nome "pippo" fatto in modo da inserirci dentro un valore che lui legge come type time_t, al pari di int, float etc etc


E fin qui tutto tranquillo direi.


2.
Sono un po' confuso dall'uso di time(), perché viene presentato in vari modi. Allora, vediamo se ho capito:

time(BOLZY)

cambia funzionamento a seconda se dichiaro una variabile o un puntatore

se BOLZY è definito come time_t BOLZY, allora devo usarla così:

time_t BOLZY;
BOLZY = time(NULL);

perché se time() ha parametro NULL, allora si limita a prendere il numero di secondi da EPOCH e me li butta nello slot chiamato BOLZY, predisposto nello stack per contenere dei bit impostati come type time_t


se invece BOLZY è definito come puntatore, e cioè time_t *BOLZY, allora avrò:

time_t * BOLZY;
time(&BOLZY);

che mi riempirà l'indirizzo del puntatore BOLZY con dei bit impostati come type "puntatore a time_t" 








time_t pippo;
pippo = time(NULL);

Oppure:

time_t *pippo;
time(&pippo);














return 0;

}