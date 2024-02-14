#include <stdio.h>  
#include <stdlib.h>


typedef struct Processo{
    int tempo;
    int prioridade;
    int id;
    int estado;
    int tempoChegada;
    int tempoExecucao;
    int tempoEspera;
    int tempoResposta;
    int tempoRetorno;
    int tempoFinal;
    int tempoRestante;
    int tempoInicio;
    int tempoFim;
    int tempoTotal;
    int tempoBloqueado
} Processo;


typedef struct Fila{
    Processo* processo;
    struct Fila* next;
} Fila;

Fila* criarFila(){
    Fila* fila = (Fila*) malloc(sizeof(Fila));
    fila->processo = NULL;
    fila->next = NULL;
    return fila;
}

int pop(Fila *fila, Processo *processo) {
    
}

int push(Fila *fila){
    Fila* novo = cria
};

int main (){


}