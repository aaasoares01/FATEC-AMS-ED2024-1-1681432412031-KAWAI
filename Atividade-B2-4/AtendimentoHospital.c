/*--------------------------------------------------------------------------*/
/*   FATEC-São Caetano do Sul                 Estrutura de Dados            */
/*                         Prof Veríssimo                                   */
/*             Objetivo: Atendimento hospitalar através de FILA             */
/*                                                                          */
/*                                                       Data:18/03/2024    */
/*--------------------------------------------------------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILA 100

typedef struct {
    char nome[50];
    int idade;
    char motivo[100];
    int prioridade;
} Paciente;

typedef struct {
    Paciente pacientes[MAX_FILA];
    int inicio, fim;
} FilaAtendimento;

void inicializarFila(FilaAtendimento *fila) {
    fila->inicio = 0;
    fila->fim = -1;
}

int filaVazia(FilaAtendimento *fila) {
    return (fila->fim < fila->inicio);
}

void adicionarPaciente(FilaAtendimento *fila, Paciente paciente) {
    if (fila->fim < MAX_FILA - 1) {
        fila->fim++;
        fila->pacientes[fila->fim] = paciente;
    } else {
        printf("Fila cheia! Impossível adicionar paciente.\n");
    }
}

void removerPaciente(FilaAtendimento *fila) {
    if (!filaVazia(fila)) {
        for (int i = fila->inicio; i < fila->fim; i++) {
            fila->pacientes[i] = fila->pacientes[i + 1];
        }
        fila->fim--;
    }
}

void atenderPacientes(FilaAtendimento *filaN, FilaAtendimento *filaP, FilaAtendimento *filaU, int n) {
    int count = 0;

    while (!filaVazia(filaU)) {
        printf("Atendendo paciente URGENTE: %s\n", filaU->pacientes[filaU->inicio].nome);
        removerPaciente(filaU);
    }

    while (count < n && !filaVazia(filaN)) {
        printf("Atendendo paciente NORMAL: %s\n", filaN->pacientes[filaN->inicio].nome);
        removerPaciente(filaN);
        count++;
    }

    if (count < n) {
        while (count < n && !filaVazia(filaP)) {
            printf("Atendendo paciente PRIORITÁRIO: %s\n", filaP->pacientes[filaP->inicio].nome);
            removerPaciente(filaP);
            count++;
        }
    }
}

void mostrarFila(FilaAtendimento *fila) {
    printf("Fila de Atendimento:\n");
    for (int i = fila->inicio; i <= fila->fim; i++) {
        printf("Nome: %s | Idade: %d | Motivo: %s | Prioridade: %d\n",
               fila->pacientes[i].nome, fila->pacientes[i].idade,
               fila->pacientes[i].motivo, fila->pacientes[i].prioridade);
    }
    printf("\n");
}

void cadastrarPaciente(FilaAtendimento *filaN, FilaAtendimento *filaP, FilaAtendimento *filaU) {
    Paciente novoPaciente;
    int prioridade;

    printf("Nome do paciente: ");
    scanf("%s", novoPaciente.nome);
    printf("Idade do paciente: ");
    scanf("%d", &novoPaciente.idade);
    printf("Motivo da consulta: ");
    scanf(" %[^\n]", novoPaciente.motivo);
    printf("Prioridade (0 - Normal, 1 - Prioritário, 2 - Urgente): ");
    scanf("%d", &prioridade);

    novoPaciente.prioridade = prioridade;

    switch (prioridade) {
        case 0:
            adicionarPaciente(filaN, novoPaciente);
            break;
        case 1:
            adicionarPaciente(filaP, novoPaciente);
            break;
        case 2:
            adicionarPaciente(filaU, novoPaciente);
            break;
        default:
            printf("Prioridade inválida!\n");
            break;
    }
}

int main() {
    FilaAtendimento filaNormal, filaPrioritaria, filaUrgente;
    inicializarFila(&filaNormal);
    inicializarFila(&filaPrioritaria);
    inicializarFila(&filaUrgente);

    int opcao;
    int numAtendimentos;

    do {
        printf("Menu:\n");
        printf("1. Cadastrar paciente\n");
        printf("2. Atender pacientes\n");
        printf("3. Mostrar filas\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarPaciente(&filaNormal, &filaPrioritaria, &filaUrgente);
                break;
            case 2:
                printf("Número de pacientes a serem atendidos: ");
                scanf("%d", &numAtendimentos);
                atenderPacientes(&filaNormal, &filaPrioritaria, &filaUrgente, numAtendimentos);
                break;
            case 3:
                printf("Filas de atendimento:\n");
                printf("Normal:\n");
                mostrarFila(&filaNormal);
                printf("Prioritária:\n");
                mostrarFila(&filaPrioritaria);
                printf("Urgente:\n");
                mostrarFila(&filaUrgente);
                break;
            case 4:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
                break;
        }
    } while (opcao != 4);

    return 0;
}
