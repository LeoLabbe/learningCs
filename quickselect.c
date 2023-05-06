#include <stdio.h>
#include <stdlib.h>

typedef struct vector{
	int totalTam;
	int totalElements;
	int* array;
} Vector;


Vector* iniciarVector() {
	Vector* newVec = (Vector*) malloc(sizeof(Vector));
	
	newVec -> totalTam = 2;
	newVec -> totalElements = 0;
	newVec -> array = (int*) malloc(2 * sizeof(int));

    return newVec;
}

void resizeVec(Vector* currVec) {

	currVec -> totalTam *= 2;
	currVec -> array = (int*) realloc(currVec -> array, currVec -> totalTam * sizeof(int));

}

void addElement(Vector* currVec, int num) {

	if(currVec -> totalTam == currVec -> totalElements)
		resizeVec(currVec);

	currVec -> array[currVec -> totalElements] = num;
	currVec -> totalElements += 1;
}

void swap(int* array, int a, int b)
{
    int aux;

    aux = array[a];
    array[a] = array[b];
    array[b] = aux;

}

int particionar(int* array, int inicio, int fim)
{
    int pivot = array[fim];
    int i = inicio;
    int j;

        for (j = inicio; j <= fim - 1; j++)
         {
            if(array[j] < pivot){
            swap(array, j, i);
            i++;
            }

        }
        swap(array, i, fim);
        return i;
}


int quickselect(int* array, int inicio, int fim, int k)
{
    int posicao;

    if(inicio == fim){
        return array[inicio];}

    posicao = particionar(array, inicio, fim);

    if (posicao == k)
    return array[posicao];

    if (posicao > k)
    return quickselect(array, inicio , posicao - 1 , k);

    else
     return quickselect(array, posicao + 1, fim, k);

}

int main (int argc, char* argv[]){

    Vector* array;
    int k, input;

    k=atoi(argv[2]);
    array = iniciarVector();

    
	while(!feof(stdin)){
		scanf("%d", &input);
		addElement(array, input);
	}
        

        printf("%d", quickselect(array -> array, 0, array ->totalElements - 1, k - 1));
    

    return 0;
}