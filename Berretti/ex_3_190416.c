
/*
Esercizio 3. (7 punti)
Scrivere la funzione C che riceve in ingresso una lista collegata con array ed indici di valori float ed un valore
target di tipo float e cancella dalla lista tutti gli elementi uguali a target. Gli elementi cancellati devono essere
memorizzati in una lista collegata con puntatori secondo l’ordine con cui si trovano nella lista iniziale e la nuova
lista deve essere restituita tra i parametri formali della funzione.
*/

#include <stdlib.h>

// struttura dei dati (teoricamente già presente nel programma)

struct array_record
{
    float value;
    int next
};

struct array_list
{
    struct array_record * buffer;
    int size;
    int first;
    int free;
};

struct pointers_node
{
    float value;
    struct pointers_node * next;
};



// funzione richiesta dall'esercizio
struct pointers_node * exercise_function(struct array_list * array_list, float target, struct pointers_node * root)
/*
cancella dalla lista tutti gli elementi uguali a target. Gli elementi cancellati devono essere
memorizzati in una lista collegata con puntatori secondo l’ordine con cui si trovano nella lista iniziale e la nuova
lista deve essere restituita tra i parametri formali della funzione.
*/
{
    // creo un iteratore per visitare la lista con array e indici
    int i = array_list->first; // gli dico da dove partire

    while(array_list->buffer[i].next != array_list->size) // visita ogni elemento della lista fino all'ultimo
    {
        if(array_list->buffer[i].value == target)
        {
            /* METTI IL VALORE NELLA LISTA CON PUNTATORI */

            struct pointers_node * newvalue; // alloco memoria per il nuovo elemento
            newvalue = (struct pointers_node *)malloc(sizeof(struct pointers_node));

            if(root == NULL)
            {
                root = newvalue; // se la lista è vuota il nuovo elemento è il primo
            }
            else
            {
                struct pointers_node * position; // altrimenti cerco l'ultimo elemento
                position = root;
                while(position->next != NULL)
                {
                    position = position->next;
                }
                // a questo punto dovrei essere all'ultimo elemento, lo faccio puntare al nuovo
                position->next = &newvalue;
            }
            
            // imposto il nuovo elemento come ultimo della lista
            newvalue->next = NULL;

            /* FINE AGGIUNTA ELEMENTO A LISTA PUNTATORI */
            


            /* INIZIO CANCELLA IL VALORE DALLA LISTA CON INDICI */

            // TODO

            /* FINE CANCELLAZIONE VALORE DALLA LISTA CON INDICI */



        } // qui finisce l'if(target == FOUND)


        // porto avanti l'iteratore all'indice successivo
        i = array_list->buffer[i].next;
    } // qui finisce il ciclo per la ricerca


    // restituisco la lista con puntatori contenente solo gli elementi cancellati dalla lista con indici

    return root;

}







int main()
{
    struct pointers_node * root;
    root = NULL;

    // CODICE VARIO

    // si suppone che array_list e target esistano già altrove
    exercise_function(&array_list, target, &root);

    // CODICE VARIO

    return 0;
}