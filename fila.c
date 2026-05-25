#include <stdio.h>
#include <stdlib.h>
#include "hospital.h"

Paciente *fila;

int frente = 0;
int tras = -1;

/* Aloca memória */
void inicializarFilaConsulta() {
    fila = (Paciente*) malloc(MAX_SIZE_CONSULTA * sizeof(Paciente));

    if (fila == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
}

/* Libera memória */
void liberarFilaConsulta() {
    free(fila);
}

int estaVaziaConsulta() {
    return frente > tras;
}

int estaCheiaConsulta() {
    return (tras - frente + 1) == MAX_SIZE_CONSULTA;
}

int enfileirarConsulta(Paciente p) {

    if (estaCheiaConsulta()) {

        printf("Erro: fila consulta cheia!\n");

        return 0;
    }

    if (estaVaziaConsulta()) {
        frente = 0;
        tras = -1;
    }

    else if (tras == MAX_SIZE_CONSULTA - 1) {

        int i;

        for(i = frente; i <= tras; i++) {
            fila[i-frente] = fila[i];
        }

        tras = tras - frente;
        frente = 0;
    }

    tras++;

    fila[tras] = p;

    printf("Paciente %s inserido na consulta\n",p.nome);

    return 1;
}

int desenfileirarConsulta() {

    if (estaVaziaConsulta()) {

        printf("Erro: fila vazia!\n");

        return -1;
    }

    frente++;

    return 0;
}

void exibirfilaConsulta() {

    if (estaVaziaConsulta()) {

        printf("Fila consulta vazia!\n");

        return;
    }

    printf("Consulta:\n");

    int i;

    for(i=frente;i<=tras;i++) {
        printf("%s\n",fila[i].nome);
    }

    printf("\n");
}
