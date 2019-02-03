#include <stdio.h>

int main() {


/*



*/

Alura, mi chiede di usare enum, che non avevo mai visto prima.

Se non ho capito male, è una specie di #define più complesso e flessibile.


I commenti sotto le righe sono la mia interpretazione in plain language di quello che accade:


enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun}; 
// crea "week", che è una specie di datatype, 
// composto da un array di valori identificati 
// dalla loro posizione nell'array.

// ma in realtà potrei anche definire internamente valori diversi e arbitrari, tipo
// enum week {Mon = 23, Tue = 68} etc etc

int main() 
{ 
    enum week day;
    // inizializza "day", che praticamente è una variabile di tipo "enum week"
    
    day = Wed;
    // imposto "day" con label "Wed", che in questo caso ha valore 2. 
    // Praticamente è come se fosse un puntatore, che al posto degli indirizzi di memoria
    // usa le label che io imposto quando inizializzo "enum NAME"
    // in questo caso lui sa che "day" è una variabile di tipo "enum week", quindi andrà
    // nel set "enum week" a vedere il valore di "Wed"


    printf("%d",day); 
    // gli dico di printare "day", e lui va a ritroso su "wed", che rimanda al valore 2, e lo printa.
    
    return 0; 
}










return 0;

}