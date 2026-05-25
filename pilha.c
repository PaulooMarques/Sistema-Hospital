#include <stdio.h>
#include <stdlib.h>
#include "hospital.h"

Paciente *pilha;// vetor que representa a pilha
int topo = -1; // controla o topo da pilha

/* Inicializa pilha */
void inicializarPilha() {

    pilha = (Paciente*) malloc(MAX * sizeof(Paciente));

    if (pilha == NULL) {
        printf("Erro ao alocar memoria!\n");
        exit(1);
    }
}

/* Libera mem�ria */
void liberarPilha() {
    free(pilha);
}

// Função para empilhar (push)
int empilhar(Paciente p) {
    if (topo == MAX - 1) {
        printf("Erro: Pilha cheia!\n");
        return 0;
    }
    topo++;
    pilha[topo] = p;
    printf("Enviado para pilha (relatorio): %s\n", p.nome);
    return 1;
}

// Função para desempilhar (pop)
int desempilhar() {
    if (topo == -1) {
        printf("Erro: Pilha vazia!\n");
        return -1;   // valor de erro
    }
    Paciente p = pilha[topo];
    topo--;
    return 0;
}

// Função para consultar o topo (peek)
int consultar_topo() {
    if (topo == -1) {
        printf("Erro: Pilha vazia!\n");
        return -1;
    }
    return 0;
}

// Verifica se a pilha está vazia
int esta_vazia() {
    return topo == -1;
}

// Verifica se a pilha está cheia
int esta_cheia() {
    return topo == MAX - 1;
}

// Mostrar toda a pilha (do topo até a base)
void mostrar_pilha() {
    if (esta_vazia()) {
        printf("Pilha vazia!\n");
        return;
    }
    
    printf("Historico:\n");
    int i;
    for (i = topo; i >= 0; i--) {
        printf("Nome: %s | Idade: %d | Gravidade: %d\n", pilha[i].nome, pilha[i].idade, pilha[i].gravidade);
    }
    printf("\n");
}
