
/*

Esercizio 3. (6 punti)
Scrivere la funzione C che riceve in ingresso una lista sequenziale di valori float e la ordina con l’algoritmo di
selezione.
 */


// struttura dati

struct list
{
    struct record * buffer;
    int first;
    int free;
    int size;

};

struct record
{
    float value;
    int next;
};


// funzione

void troll_sort(struct list * list)
{
    float temp[list->size]; // creo un array temp dove mettere i valori da ordinare
    int temp_index = 0; // index array da popolare
    int index = list->first; // index di visita lista

    // popolo l'array con i valori della lista
    while( index != list->size)
    {     
        temp[temp_index] = list->buffer[index].value; // copio il valore
        index = list->buffer[index].next; // next index in lista collegata
        temp_index++; // incremento indice array temp
    }

    // a questo punto applico selection sort su temp[]

    int * min;
    int swap;

    for(int i = 0; i < list->size; i++) // per ogni valore
    {
        min = &temp[i]; // lo assegno come più basso

        for(int k = i+1; k < list->size; k++) // cerco il minimo
        {
            if(temp[k] < *min) // se lo trovo lo punto
            {
                min = &temp[k];
            }
        }

        // swappo
        swap = temp[i];
        temp[i] = *min;
        *min = swap;
    }

    // sorting terminato, ricopio i valori in ordine nella lista

    // riparto da capo
    index = list->first;
    temp_index = 0;

    // ricopio nella lista
    while( index != list->size)
    {     
        list->buffer[index].value = temp[temp_index]; // copio il valore nella lista originale

        index = list->buffer[index].next; // next index in lista collegata
        temp_index++; // incremento indice array temp
    }


    // fine
}










int main()
{

    struct list * list;

    selectin_sort(list);


    return 0;
}