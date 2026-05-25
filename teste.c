#include <stdio.h>
#include <time.h>
#include <string.h>
#include "hospital.h"

// teste de tempo

void testeTempoFilaPrioridade() {
	inicializarEmergencia();

    Paciente p;

    strcpy(p.nome, "Teste4");
    p.idade = 20;
    p.tipoAtendimento = 1;

    clock_t inicio, fim;

    inicio = clock();

    for(int i = 0; i < 100000; i++){

        p.gravidade = (i % 5) + 1;

        enfileirarEmergencia(p);

        if(!filaVazia()){
            desenfileirarEmergencia();
        }
    }

    fim = clock();

    double tempo =((double)(fim - inicio)) / CLOCKS_PER_SEC;

	printf("\nTempo de execução de fila de prioridade (100000 vezes: %.6f segundos\n",tempo);

    liberarEmergencia();
}

void testeTempoFilaCircular() {
	inicializarFilaCircular();

    Paciente p;

    strcpy(p.nome, "Teste3");
    p.idade = 20;
    p.tipoAtendimento = 1;

    clock_t inicio, fim;

    inicio = clock();

    for(int i = 0; i < 100000; i++){

        p.gravidade = (i % 5) + 1;

        enfileirar(p);

        if(!estaVazia()){
            desenfileirar();
        }
    }

    fim = clock();

    double tempo =((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("\nTempo de execução de fila circular (100000 vezes: %.6f segundos\n",tempo);

    liberarFilaCircular();
}

void testeTempoFilaLinear() {
	inicializarFilaConsulta();

    Paciente p;

    strcpy(p.nome, "Teste2");
    p.idade = 20;
    p.tipoAtendimento = 1;

    clock_t inicio, fim;

    inicio = clock();

    for(int i = 0; i < 100000; i++){

        p.gravidade = (i % 5) + 1;

        enfileirarConsulta(p);

        if(!estaVaziaConsulta()){
            desenfileirarConsulta();
        }
    }

    fim = clock();

    double tempo =((double)(fim - inicio)) / CLOCKS_PER_SEC;

	printf("\nTempo de execucao de fila linear (100000 vezes: %.6f segundos\n",tempo);

    liberarFilaConsulta();
}

void testeTempoPilha() {
	inicializarPilha();

    Paciente p;

    strcpy(p.nome, "Teste1");
    p.idade = 20;
    p.tipoAtendimento = 1;

    clock_t inicio, fim;

    inicio = clock();

    for(int i = 0; i < 100000; i++){

        p.gravidade = (i % 5) + 1;

        empilhar(p);

        if(!esta_vazia()){
            desempilhar();
        }
    }

    fim = clock();

    double tempo =((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nTempo de execucao de pilha (100000 vezes: %.6f segundos\n",tempo);

    liberarPilha();
}

// teste de estresse

void testeEstresseFilaPrioridade() {
	inicializarEmergencia();

    Paciente p;

    strcpy(p.nome, "Teste4");
    p.idade = 20;
    p.tipoAtendimento = 1;

    clock_t inicio, fim;

    inicio = clock();

    for(int i = 0; i < 100000000; i++){

        p.gravidade = (i % 5) + 1;

        enfileirarEmergencia(p);

        if(!filaVazia()){
            desenfileirarEmergencia();
        }
    }

    fim = clock();

    double tempo =((double)(fim - inicio)) / CLOCKS_PER_SEC;

	printf("\nTempo de execucao de fila de prioridade (100000 vezes: %.6f segundos\n",tempo);

    liberarEmergencia();
}

void testeEstresseFilaCircular() {
	inicializarFilaCircular();

    Paciente p;

    strcpy(p.nome, "Teste3");
    p.idade = 20;
    p.tipoAtendimento = 1;

    clock_t inicio, fim;

    inicio = clock();

    for(int i = 0; i < 100000000; i++){

        p.gravidade = (i % 5) + 1;

        enfileirar(p);

        if(!estaVazia()){
            desenfileirar();
        }
    }

    fim = clock();

    double tempo =((double)(fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("\nTempo de execucao de fila circular (100000 vezes: %.6f segundos\n",tempo);

    liberarFilaCircular();
}

void testeEstresseFilaLinear() {
	inicializarFilaConsulta();

    Paciente p;

    strcpy(p.nome, "Teste2");
    p.idade = 20;
    p.tipoAtendimento = 1;

    clock_t inicio, fim;

    inicio = clock();

    for(int i = 0; i < 100000000; i++){

        p.gravidade = (i % 5) + 1;

        enfileirarConsulta(p);

        if(!estaVaziaConsulta()){
            desenfileirarConsulta();
        }
    }

    fim = clock();

    double tempo =((double)(fim - inicio)) / CLOCKS_PER_SEC;

	printf("\nTempo de execucao de fila linear (100000 vezes: %.6f segundos\n",tempo);

    liberarFilaConsulta();
}

void testeEstressePilha() {
	inicializarPilha();

    Paciente p;

    strcpy(p.nome, "Teste1");
    p.idade = 20;
    p.tipoAtendimento = 1;

    clock_t inicio, fim;

    inicio = clock();

    for(int i = 0; i < 100000000; i++){

        p.gravidade = (i % 5) + 1;

        empilhar(p);

        if(!esta_vazia()){
            desempilhar();
        }
    }

    fim = clock();

    double tempo =((double)(fim - inicio)) / CLOCKS_PER_SEC;

    printf("\nTempo de execução de pilha (100000 vezes: %.6f segundos\n",tempo);

    liberarPilha();
}
