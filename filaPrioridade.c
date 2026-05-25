#include <stdio.h>
#include <stdlib.h>
#include "hospital.h"

Paciente *filaPrioridade;

int tamanho = 0;


/* Inicializar */
void inicializarEmergencia() {

    filaPrioridade = (Paciente*) malloc(MAX_EMERGENCIA * sizeof(Paciente));

    if(filaPrioridade == NULL){

        printf(
        "Erro de memoria!\n"
        );

        exit(1);
    }
}


/* Liberar */
void liberarEmergencia() {
    free(filaPrioridade);
}


/* Verifica vazia */
int filaVazia() {
    return tamanho == 0;
}


/* Verifica cheia */
int filaCheia() {
    return tamanho == MAX_EMERGENCIA;
}


/* Inserir */
int enfileirarEmergencia(Paciente p){

    if(filaCheia()){

        printf(
        "Emergencia cheia!\n"
        );

        return 0;
    }

    filaPrioridade[tamanho] = p;

    tamanho++;

    printf(
        "Paciente %s inserido na emergencia\n",
        p.nome
    );

    return 1;
}


/* Remover maior prioridade */
int desenfileirarEmergencia(){

    if(filaVazia()){

        printf(
        "Fila vazia!\n"
        );

        return -1;
    }

    int maior = 0;

    for(int i=1;i<tamanho;i++){

        if(filaPrioridade[i].gravidade > filaPrioridade[maior].gravidade){
            maior = i;
        }
    }

    Paciente p = filaPrioridade[maior];


    for(int i=maior;i<tamanho-1;i++){

        filaPrioridade[i] =
        filaPrioridade[i+1];
    }

    tamanho--;

    return 0;
}


/* Exibir */
void mostrarEmergencia(){

    if(filaVazia()){

        printf("Fila vazia!\n");

        return;
    }

    printf("\nEmergencia:\n");

    for(int i=0;i<tamanho;i++){
        printf("Nome: %s | Gravidade: %d\n", filaPrioridade[i].nome, filaPrioridade[i].gravidade);
    }
}

Paciente consultarEmergencia() {

    Paciente vazio = {"",0,0,0};

    if(filaVazia()) {
        return vazio;
    }

    int maior = 0;

    for(int i = 1; i < tamanho; i++) {

        if (filaPrioridade[i].gravidade > filaPrioridade[maior].gravidade) {
            maior = i;
        }
    }

    return filaPrioridade[maior];
}
