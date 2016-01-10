//useful functions
void quickSort(int * array, int inf, int sup)
{
    int sw, i = inf, j = sup, pivot = array[(i + j) / 2];
    while(i <= j)
    {
        while(array[i] < pivot) i++;
        while(array[j] > pivot) j--;
        if(i <= j)
        {
            sw = array[i];
            array[i] = array[j];
            array[j] = sw;
            i++;
            j--;
        }
    }
    if(i < sup) quickSort(array, i, sup);
    if(j > inf) quickSort(array, inf, j);
}

void quickSortForPolinoms(int * array, float* farray, int inf, int sup)
{
    int sw, i = inf, j = sup, pivot = array[(i + j) / 2];
    float fsw;
    while(i <= j)
    {
        while(array[i] > pivot) i++;
        while(array[j] < pivot) j--;
        if(i <= j)
        {
            sw = array[i];
            array[i] = array[j];
            array[j] = sw;
            fsw = farray[i];
            farray[i] = farray[j];
            farray[j] = fsw;
            i++;
            j--;
        }
    }
    if(i < sup) quickSortForPolinoms(array, farray, i, sup);
    if(j > inf) quickSortForPolinoms(array, farray, inf, j);
}
