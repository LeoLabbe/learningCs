#include <stdio.h>
#include <stdlib.h>

int particionar(int array[], int esq, int dir)
{
    int aux;
    int cont = esq;

        for (int i = esq +1; i <= dir; i++)
         {
            if(array[i] < array[esq]){
            cont++;
            aux = array[i];
            array[i] = array[cont];
            array[cont] = aux;
            }

        }

    aux = array[esq];
    array[esq] = array[cont];
    array[cont] = aux;


    return cont;
}

void quicksort(int array[], int esq, int dir)
{
    int pos;
    if(esq<dir) {
        pos = particionar(array, esq, dir);
        quicksort(array, esq, pos -1);
        quicksort(array, pos +1, dir);

    }

}

int main (){

    int array[] = {5, 6, 3, 2, 1, 11, 23, 8, 42, 15};
    int tam = 10;
    quicksort(array, 0, tam);

    for(int i = 0; i < 11; i++)
    {
        printf("%d", array[i]);
        printf("\n");
    }

    return 0;
}