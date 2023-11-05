#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Cria um vetor dinamico
typedef struct vector{
	int totalTam;
	int totalElements;
	int* array;
} Vector;

//Funções do vector
Vector* iniciarVector() {
	Vector* newVec = (Vector*) malloc(sizeof(Vector));
	
	newVec -> totalTam = 2;
	newVec -> totalElements = 0;
	newVec -> array = (int*) malloc(2 * sizeof(int));

    return newVec;
}

void realocaVec(Vector* currVec) {

	currVec -> totalTam *= 2;
	currVec -> array = (int*) realloc(currVec -> array, currVec -> totalTam * sizeof(int));

}

void addElement(Vector* currVec, int num) {

	if(currVec -> totalTam == currVec -> totalElements)
		realocaVec(currVec);

	currVec -> array[currVec -> totalElements] = num;
	currVec -> totalElements += 1;
}

// Divide a lista
int particionar(Vector* array, int esq, int dir)
{
    int aux;
    int cont = esq;
    int i;

        for (i = esq +1; i <= dir; i++)
         {
            if(array -> array[i] < array -> array[esq]){
            cont++;
            aux = array-> array[i];
           array -> array[i] = array -> array[cont];
            array -> array[cont] = aux;
            }

        }

    aux = array -> array[esq];
    array -> array[esq] = array -> array[cont];
    array -> array[cont] = aux;

    return cont;
}
int particiona_r(Vector* array, int esq, int dir)
{
    // Gera um numero aleatório entre
    // esq .. dir
    srand(time(NULL));
    int random = esq + (rand() % (dir - esq));
 
    int aux = array -> array[random];
    array -> array[random] =  array -> array[esq];
    array -> array[esq] = aux;
 
    return particionar(array, esq, dir);
}

void quicksort(Vector* array, int esq, int dir)
{
    int pos;
    if(esq<dir) {
        pos = particiona_r(array, esq, dir);
        quicksort(array, esq, pos -1);
        quicksort(array, pos +1, dir);

    }

}



void printArray(Vector* array, int tam)
{
    int i;
    for(i = 0; i < tam; i++)
    { 
        printf("%d", array -> array[i]);
        printf("\n");
    }
}


int main()
{

    Vector* array;
    array = iniciarVector();
    int input;

    while(!feof(stdin)){
	 	scanf("%d", &input);
		addElement(array, input);
	}
     
    quicksort(array, 0, array -> totalElements - 1);
    printArray(array, array -> totalElements);
     
    return 0;
}