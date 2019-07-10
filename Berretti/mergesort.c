
// INIZIO MERGESORT

void mergesort_impera(int * main, int size, int * temp)
{
    // creo gli indici per gli array
    int l_index = 0; // fino a (size/2)-1
    int r_index = (size/2); // fino a size-1
    int main_index = 0;
    
    for(int i = 0; i < size; i++) // copio main in temp
    {
        temp[i] = main[i];
    }

    while(l_index < (size/2) && r_index < size) // finché entrambi i subarray hanno valori
    {
        if(temp[l_index] < temp[r_index])
        {
            main[main_index] = temp[l_index];
            l_index++;
        }
        else
        {
            main[main_index] = temp[r_index];
            r_index++;
        }

        main_index++;
    }

    // se esiste solo il subarray di sinistra
    while(l_index < (size/2))
    {
        main[main_index] = temp[l_index];
        l_index++;
        main_index++;
    }

    //se esiste solo il subarray di destra
    while(r_index < size)
    {
        main[main_index] = temp[r_index];
        r_index++;
        main_index++;
    }

}

void mergesort_divide(int * main_array, int size, int * temp)
{
    if(size > 2) // divide fino a che size = 2
    {
        mergesort_divide(main_array, (size/2), temp);
        mergesort_divide(&main_array[size/2], size-(size/2), &temp[size/2]);
        mergesort_impera(main_array, size, temp);
    }
    else
    {
        if(size == 2) // size = 2, dimensione minima ordinabile. Ordinala.
        {
            if(main_array[0] > main_array[1])
            {
                int swap = main_array[1];
                main_array[1] = main_array[0];
                main_array[0] = swap;
            }
        }
    }    
}


void mergesort_main(int * main_array, int size)
/*  
    Funzione che contiene il resto dell'algoritmo
    Creo un solo array temp e lo passo tra le funzioni, 
    in questo modo evito di richiamare malloc() e free() ogni volta che splitto l'array.
    In pratica il processo di divisione viene solo virtualizzato e lo swap avviene in place sull'array temp
*/
{
    int * temp;
    temp = (int *)malloc(sizeof(int)*size); // creo l'array di appoggio

    mergesort_divide(main_array, size, temp); // chiamo il divide ricorsivo: in pratica tutto l'algoritmo si svolge qui dentro

    free(temp); // libero l'array di appoggio ed esco dalla funzione
}
// FINE MERGESORT
