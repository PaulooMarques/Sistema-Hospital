#include <stdio.h>
#include <stdlib.h>
#include "hospital.h"

// Ponteiro para fila dinâmica
Paciente *filaCircular;

int frenteCircular = -1;
int trasCircular = -1;


/* Inicializa a fila */
void inicializarFilaCircular() {

    filaCircular = (Paciente*) malloc(
        MAX_SIZE * sizeof(Paciente)
    );

    if (filaCircular == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
}


/* Libera memória */
void liberarFilaCircular() {
    free(filaCircular);
}


// Verifica se está vazia
int estaVazia() {
    return frenteCircular == -1;
}


// Verifica se está cheia
int estaCheia() {
    return frenteCircular == (trasCircular + 1) % MAX_SIZE;
}


// Enfileirar
int enfileirar(Paciente p) {

    if (estaCheia()) {
        printf("Erro: fila cheia! Não é possível enfileirar %s\n", p.nome);

        return 0;
    }

    if (estaVazia()) {
        frenteCircular = 0;
    }
    
    trasCircular =
    (trasCircular + 1) % MAX_SIZE;
    filaCircular[trasCircular] = p;
    printf("Paciente %s inserido no exame\n", p.nome);

    return 1;
}


// Desenfileirar
int desenfileirar() {

    if (estaVazia()) {
        printf("Erro: fila vazia!\n");
        return -1;
    }

    if (frenteCircular == trasCircular) {
        frenteCircular = -1;
        trasCircular = -1;
    }
    else {

        frenteCircular = (frenteCircular + 1) % MAX_SIZE;
    }

    return 0;
}


// Consultar frente
int consultarfrente() {

    if (estaVazia()) {

        printf("Fila vazia!\n");

        return -1;
    }

    printf("%s\n",filaCircular[frenteCircular].nome);

    return 0;
}


// Mostrar fila
void exibirFila() {

    if (estaVazia()) {

        printf("Fila vazia!\n");

        return;
    }

    printf("Exame:\n");

    int i = frenteCircular;

    while (i != trasCircular) {

        printf("%s\n",filaCircular[i].nome);

        i = (i + 1) % MAX_SIZE;
    }

    printf("%s\n",filaCircular[trasCircular].nome);
}
