#include <stdio.h>

#define FILENAME "rand_numbers.txt"

int get_array_size()
{

    FILE *p_file = fopen(FILENAME, "r");

    int size = 1;
    char c = fgetc(p_file);

    while (c != EOF)
    {
        if (c != EOF && c == '\n')
        {
            size++;
        }

        c = fgetc(p_file);
    }

    fclose(p_file);

    return size;
}


void populate_array(int * p_array, int size)
{
    int index = 0;
    int get;

    FILE *p_file = fopen(FILENAME, "r");

    do{
        fscanf(p_file, "%d", &p_array[index]);
        index++;
    } while (index < size);

}


int main(){

    int size = get_array_size(FILENAME);

    printf("Size: %d", size);

    int rand_nums[size];

    populate_array(rand_nums, size);

    for (int i = 0; i < size; i++){
        printf("Element at index [%d] : %d\n", i, rand_nums[i]);
    }

}