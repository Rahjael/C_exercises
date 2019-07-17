
Boolean binary_search_ricorsivo(int * V, int size, int target)
{
    if(size > 0)
    {
        if( V[size/2] == target)
        {
            return TRUE;
        }
        
        else
        {
            if(V[size/2] > target)
            {
                return binary_search_ricorsivo(V, size/2, target);
            }
            else
            {
                return binary_search_ricorsivo(&V[(size/2)+1], size-(size/2)-1, target);
            }
            
        }
    }

    return FALSE;

}


Boolean binary_search_iterativo(int * V, int size, int target)
{
    Boolean found = FALSE;
    int start = 0;
    
    while(size > 0 && found == FALSE)
    {
        if(V[start+size/2] == target)
        {
            found = TRUE;
        }
        else
        {
            if(V[start+size/2] > target)
            {
                size = size/2;
            }
            else
            {
                start = start+(size/2)+1;
                size = size - (size/2) - 1;
            }
    }

    return found;
}