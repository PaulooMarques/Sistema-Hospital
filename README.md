# Hospital Simulado – Sistema de Gerenciamento de Pacientes

Sistema desenvolvido em C que simula o fluxo de atendimento de um hospital, criado como atividade prática da disciplina de Estrutura de Dados.

O projeto utiliza diferentes estruturas de dados implementadas manualmente, aplicando cada uma em um cenário adequado ao contexto hospitalar. Além da implementação das estruturas, o projeto também inclui modularização, ponteiros, alocação dinâmica de memória e testes de desempenho.

---

## Funcionalidades

- Cadastro de pacientes com:
  - Nome
  - Idade
  - Gravidade (1–5)
  - Tipo de atendimento

- Encaminhamento automático:
  - Pacientes com gravidade ≥ 4 são enviados automaticamente para a Emergência

- Atendimento de pacientes

- Exibição de pacientes por setor

- Transferência entre setores

- Relatório contendo:
  - Total de pacientes cadastrados
  - Total de pacientes atendidos
  - Total de pacientes aguardando atendimento
  - listagem de pacietes atendios

---

## Estruturas utilizadas

| Estrutura | Aplicação |
|------------|------------|
| Fila de Prioridade | Emergência |
| Fila Linear | Consultas |
| Fila Circular | Exames |
| Pilha | Histórico de pacientes atendidos |

### Regras do sistema

**Emergência**
- Pacientes são atendidos pela gravidade
- Quanto maior a gravidade, maior a prioridade

**Consultas**
- Atendimento segue ordem de chegada (FIFO)

**Exames**
- Utiliza fila circular
- Ao atingir a capacidade máxima, o paciente mais antigo é removido automaticamente

**Histórico**
- Pacientes atendidos são armazenados em uma pilha

---

## Estrutura do Projeto

```
hospital/
├── hospital.h       # Struct Paciente, defines e protótipos de todas as funções
├── main.c           # Main e contadores globais
├── pilha.c          # Pilha com ponteiro — histórico de pacientes atendidos
├── fila.c           # Fila linear com ponteiro — setor de Consultas
├── filaCircular.c   # Fila circular com ponteiro — setor de Exames
└── FilaPrioridade.c # fila de prioridade com ponteiro - setor emergência
```

---

## Compilação

```bash
gcc main.c pilha.c fila.c filaCircular.c filaPrioridade.c teste.c -o main
```
ou
```bash
gcc *.c -o main
```
---
Executar:

```bash
start main.exe
```
## Testes realizados

### Teste de desempenho

| Estrutura | Operações | Tempo |
|------------|------------|--------|
| Pilha | 100000 inserções/remoções | 9.7 s |
| Fila Linear | 100000 inserções/remoções | 5.3 s |
| Fila Circular | 100000 inserções/remoções | 5.4 s |
| Fila de Prioridade | 100000 inserções/remoções | 5.2 s |

### Teste de estresse

Foram realizados testes com grandes volumes de operações para verificar estabilidade e comportamento do sistema sob carga elevada.

---

## Análise de bugs

Foi utilizada a ferramenta **Cppcheck** para análise do código, identificando possíveis problemas relacionados a:

- Variáveis não utilizadas
- Organização do código
- Possíveis problemas de memória
- Melhorias de implementação