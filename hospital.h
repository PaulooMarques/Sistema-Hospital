#ifndef HOSPITAL_H
#define HOSPITAL_H

// Estrutura que representa um paciente
typedef struct {
	char nome[20];
	int idade;
	int gravidade;
	int tipoAtendimento;
} Paciente;

// Contadores globais
extern int pacientesTotal;
extern int pacientesAtendidos;
extern int pacientesRestantes;

// Utilitario
void exibirPacienteRemovido(Paciente p);

// Pilha (relatório)
#define MAX 100
extern Paciente *pilha;
void inicializarPilha();
void liberarPilha();
int empilhar(Paciente p);
int desempilhar();
int esta_vazia();
int esta_cheia();
int consultar_topo();
void mostrar_pilha();
extern int topo;

// Fila Linear (Consultas)
#define MAX_SIZE_CONSULTA 5
extern Paciente *fila;
extern int frente;
extern int tras;
void inicializarFilaConsulta();
void liberarFilaConsulta();
int enfileirarConsulta(Paciente p);
int desenfileirarConsulta();
int estaVaziaConsulta();
int estaCheiaConsulta();
void exibirfilaConsulta();

// Fila Circular (Exames)
#define MAX_SIZE 8
extern Paciente *filaCircular;
void inicializarFilaCircular();
void liberarFilaCircular();
int enfileirar(Paciente p);
int desenfileirar();
int estaVazia();
int estaCheia();
int consultarfrente();
void exibirFila();
extern int frenteCircular;
extern int trasCircular;

// fila prioridade (Emergência)
#define MAX_EMERGENCIA 5
extern Paciente *filaPrioridade;
extern int tamanho;
void inicializarEmergencia();
void liberarEmergencia();
int filaVazia();
int filaCheia();
int enfileirarEmergencia(Paciente p);
int desenfileirarEmergencia();
void mostrarEmergencia();
Paciente consultarEmergencia();

//teste
void testeTempoFilaPrioridade();
void testeTempoFilaCircular();
void testeTempoFilaLinear();
void testeTempoPilha();

void testeEstresseFilaPrioridade();
void testeEstresseFilaCircular();
void testeEstresseFilaLinear();
void testeEstressePilha();

#endif
