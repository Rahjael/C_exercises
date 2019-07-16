void quicksort(int * array, int start, int end)
{

    if(start < end)
    {

        int pivot = end;
        int left = start;
        int right = end;
        int temp;

        while(left < right)
        {
            while( array[left] <= array[pivot] && left < right)
            {
                left++;
            }
            while( array[right] >= array[pivot] && left < right)
            {
                
            }

        }


        temp = array[right];
        array[right] = array[pivot];
        array[pivot] = temp;


        
        quicksort(array, start, right-1);
        quicksort(array, right, end);
    }
}