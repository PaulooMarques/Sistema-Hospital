#include <stdio.h>
#include <string.h>
#include <conio.h>
#include "hospital.h"

int pacientesTotal = 0;
int pacientesAtendidos = 0;
int pacientesRestantes = 0;

void exibirPacienteRemovido(Paciente p) {
	printf("paciente Atendido:\nNome: %s\nIdade: %d\ngravidade: %d\nTipo de atendimento: %d\n\n", p.nome, p.idade, p.gravidade, p.tipoAtendimento);
}

int main() {
	inicializarPilha();
    inicializarFilaConsulta();
    inicializarFilaCircular();
    inicializarEmergencia();

    printf("Hospital");
	int acao, sair = 0;
	while (!sair) {
		printf("\n1- cadastrar paciente\n2- atender paciente\n3- mostrar pacientes\n4- transferir paciente\n5- relatorios\n6- teste de tempo (100.000 de operacoes)\n7- teste de estresse (100.000.000 operacoes)\n0- sair");
		printf("\n>> ");
		scanf("%d", &acao);
		if (acao == 1) {
			char nome[20];
			int idade, gravidade, tipoAtendimento;
			Paciente p;
			printf("Preecha os dados do paciente:\n");
			printf("Nome: ");
			scanf("%s", nome);
			printf("Idade: ");
			scanf("%d", &idade);
			printf("gravidade (1-5): ");
			scanf("%d", &gravidade);
			if (gravidade == 4 || gravidade == 5) {
				tipoAtendimento = 1;
				printf("Encaminhado automaticamente para emergencia\n");
			} else {
				printf("tipo de atendimento (1: emergencia | 2: consulta | 3: exame): ");
				scanf("%d", &tipoAtendimento);
			}
			
			strcpy(p.nome, nome);
			p.idade = idade;
			p.gravidade = gravidade;
			p.tipoAtendimento = tipoAtendimento;
			int cadastrado = 0;
			if (tipoAtendimento == 1) {
				cadastrado = enfileirarEmergencia(p);
			}
			else if (tipoAtendimento == 2) {
				cadastrado = enfileirarConsulta(p);
			}
			else if (tipoAtendimento == 3) {
				if (estaCheia()) {
					Paciente pRemovido = filaCircular[frenteCircular];
					desenfileirar();
					pacientesAtendidos++;
					pacientesRestantes--;
					exibirPacienteRemovido(pRemovido);
				}
				cadastrado = enfileirar(p);
			}
			else {
				printf("Tipo de atendimento invalido!\n");
			}
			if (cadastrado) {
				pacientesTotal++;
				pacientesRestantes++;
			}
		}
		if (acao == 2) {
			printf("Qual departamento atender?\n1- emergencia | 2- consulta | 3- exame");
			int atendimento;
			printf("\n>> ");
			scanf("%d", &atendimento);
			Paciente p;
			if (atendimento == 1) {
				if (filaVazia()) {
					printf("Erro: Fila vazia!\n");
					continue;
				}
				p = consultarEmergencia();
				int sucesso = desenfileirarEmergencia();
				if (sucesso == 0) {
					pacientesAtendidos++;
					pacientesRestantes--;
					exibirPacienteRemovido(p);
					empilhar(p);
				}
			} else if (atendimento == 2) {
				if (estaVaziaConsulta()) {
					printf("Erro: Fila para Consulta vazia!\n");
					continue;
				}
				p = fila[frente];
				int sucesso = desenfileirarConsulta();
				if (sucesso == 0) {
					pacientesAtendidos++;
					pacientesRestantes--;
					exibirPacienteRemovido(p);
					empilhar(p);
				}
			} else if (atendimento == 3) {
				if (estaVazia()) {
					printf("Erro: filaCircular vazia! Nada para desenfileirar.\n");
					continue;
				}
				p = filaCircular[frenteCircular];
				int sucesso = desenfileirar();
				if (sucesso == 0) {
					pacientesAtendidos++;
					pacientesRestantes--;
					exibirPacienteRemovido(p);
					empilhar(p);
				}
			}
		}
		if (acao == 3) {
			printf("Exibir qual departamento?\n1- emergencia | 2- consulta | 3- exame");
			int departamento;
			printf("\n>> ");
			scanf("%d", &departamento);
			if (departamento == 1) {
				mostrarEmergencia();
			} else if (departamento == 2) {
				exibirfilaConsulta();
			} else if (departamento == 3) {
				exibirFila();
			}
		}
		if (acao == 4) {
			printf("\nDe qual departamento trasferir?\n1- emergencia | 2- consulta | 3- exame");
			int departamento;
			Paciente p;
			printf("\n>> ");
			scanf("%d", &departamento);
			if (departamento == 1) {
				if (filaVazia()) {
					printf("ninguem para transferir");
					continue;
				}
				p = consultarEmergencia();
				desenfileirarEmergencia();
			} else if (departamento == 2) {
				if (estaVaziaConsulta()) {
					printf("ninguem para transferir");
					continue;
				}
				
				p = fila[frente];
				desenfileirarConsulta();
			} else if (departamento == 3) {
				if (estaVazia()) {
					printf("ninguem para transferir");
					continue;
				}
				p = filaCircular[frenteCircular];
				desenfileirar();
			} else {
				printf("Departamento invalido!\n");
				continue;
			}
			
			printf("\nPara qual departamento trasferir?\n1- emergencia | 2- consulta | 3- exame");
			int transferir;
			printf("\n>> ");
			scanf("%d", &transferir);
			if (transferir == 1) {
				enfileirarEmergencia(p);
			} else if (transferir == 2) {
				enfileirarConsulta(p);
			} else if (transferir == 3) {
				enfileirar(p);
			}
		}
		if (acao == 5) {
			printf("\ntotal de pacientes do dia: %d\n", pacientesTotal);
			printf("total de pacientes atendidos: %d\n", pacientesAtendidos);
			printf("total de pacientes para serem atendidos: %d\n", pacientesRestantes);
			printf("\nPacientes atendidos:\n");
			mostrar_pilha();
			
		}
		if (acao == 6) {
			int teste;
			printf("\nQual algoritmo deseja testar?\n1- fila prioridade | 2- fila linear (consulta) | 3- fila circular (exame) | | 4- pilha (relatorio)\n>>");
			scanf("%d", &teste);
			if (teste == 1) {
				testeTempoFilaPrioridade();
			} else if (teste == 2) {
				testeTempoFilaLinear();
			} else if (teste == 3) {
				testeTempoFilaCircular();
			} else if (teste == 4) {
				testeTempoPilha();
			}
			
		}
		if (acao == 7) {
			int teste;
			printf("\nQual algoritmo deseja testar?\n1- fila prioridade | 2- fila linear (consulta) | 3- fila circular (exame) | | 4- pilha (relatorio)\n>>");
			scanf("%d", &teste);
			if (teste == 1) {
				testeEstresseFilaPrioridade();
			} else if (teste == 2) {
				testeEstresseFilaLinear();
			} else if (teste == 3) {
				testeEstresseFilaCircular();
			} else if (teste == 4) {
				testeEstressePilha();
			}
		}
		if (acao == 0) {
			sair = 1;
		}
	}
	liberarPilha();
	liberarFilaConsulta();
	liberarFilaCircular();
	liberarEmergencia();
	printf("\n\nFIM DO PROGRAMA... Pressione qualquer tecla para fechar\n");
	getch();
	return 0;
}
