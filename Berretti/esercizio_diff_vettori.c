/*
    Differenza tra vettori
    Definire la funzione C che riceve in ingresso un array di interi V ed un array di interi W di
    dimensione N ed M, rispettivamente, e genera un vettore D differenza di V e W.
    D deve contenere solo gli elementi di V che non sono presenti in W.
*/


#include <stdio.h>
#include <stdlib.h>

#define V_VALUES {5,3,6,8,5,2,6,7,2,5,1,3,2,7,4,0,6}
#define W_VALUES {0,8,6,8,5,3,6,0}



// Function declarations:

int vector_subtract(int * v, int * w, int v_size, int w_size, int * d);


int main(void){

    int v[] = V_VALUES;
    int w[] = W_VALUES;

    int * d;
    int * clean_d;
    int d_size;

    int v_size = sizeof(v)/sizeof(v[0]);
    int w_size = sizeof(w)/sizeof(w[0]);

    d = (int*)malloc(v_size*sizeof(int));

    d_size = vector_subtract(v, w, v_size, w_size, d);

    clean_d = (int*)malloc(d_size*sizeof(int));

    for (int i = 0; i<d_size; i++)
        clean_d[i] = d[i];

    free(d);

    printf("\nArray v: ");
    for (int i = 0; i<v_size; i++)
        printf("%d ", v[i]);

    printf("\nArray w: ");
    for (int i = 0; i<w_size; i++)
        printf("%d ", w[i]);

    printf("\nArray d: ");
    for (int i = 0; i<d_size; i++)
        printf("%d ", clean_d[i]);



    return 0;
}



int vector_subtract(int * v, int * w, int v_size, int w_size, int * d)
{
    int d_index = 0;
    int is_present;

    for (int i = 0; i<v_size; i++){
        
        is_present = 0;
        
        for (int j = 0; j<w_size; j++){

            if (v[i] == w[j]){
                is_present = 1;
                break;
            }
        }
        
        if(is_present==0){
            d[d_index] = v[i];
            d_index++;
        }
    }

    return d_index;

}