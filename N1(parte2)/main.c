// -----------------------------------  //
// Autores: Bruno Tonaki & Kawai Soares //
// Instituição: Fatec Antonio Russo     //
// Professor: Carlos Veríssimo          //
// Data: 15/04/2024                     //
// -----------------------------------  //
#include <stdio.h>
#include <string.h>

typedef struct {
    int ID;
    char Cidadeorg[50];
    char Cidadedes[50];
    int Status;
    char Conteudo[100];
} PACOTE;

PACOTE pacotes[100];
int numPacotes = 0;

void Incluir() {
    PACOTE *pacote = &pacotes[numPacotes++];
    printf("\n--- Incluir Pacote ---\n");
    printf("Insira a Cidadeorg: ");
    scanf("%s", pacote->Cidadeorg);
    printf("Insira a Cidadedes: ");
    scanf("%s", pacote->Cidadedes);
    printf("Insira o conteudo: ");
    scanf(" %[^\n]", pacote->Conteudo);
    pacote->ID = numPacotes * 2;
    pacote->Status = 1;
    printf("\n");
}

void Alterar() {
    int id, valor;
    printf("\n--- Alterar Status do Pacote ---\n");
    printf("Digite o ID do pacote: ");
    scanf("%d", &id);
    if(id < 1 || id > numPacotes) {
        printf("Pacote não encontrado.\n");
        return;
    }
    printf("Digite valores de 1, 2 ,3 ,4 ou 99: ");
    scanf("%d", &valor);
    pacotes[id-1].Status = valor;
    printf("\n");
}

void Rastrear() {
    int ID;
    printf("\n--- Rastrear Pacote ---\n");
    printf("Digite o ID do pacote: ");
    scanf("%d", &ID);
    for(int i = 0; i < numPacotes; i++) {
        if(pacotes[i].ID == ID) {
            PACOTE *pacote = &pacotes[i];
            printf("\nDetalhes do Pacote:\n");
            printf("ID: %d\n", pacote->ID);
            printf("Cidadeorg: %s\n", pacote->Cidadeorg);
            printf("Cidadedes: %s\n", pacote->Cidadedes);
            printf("Status: %d\n", pacote->Status);
            printf("Conteudo: %s\n", pacote->Conteudo);
            printf("\n");
            return;
        }
    }
    printf("Pacote não encontrado.\n");
}

int main() {
    while(1) {
        int opcao;
        printf("\n--- Menu Principal ---\n");
        printf("1. Incluir pacote\n");
        printf("2. Alterar status do pacote\n");
        printf("3. Rastrear pacote\n");
        printf("4. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        getchar();
        switch(opcao) {
            case 1:
                Incluir();
                break;
            case 2:
                Alterar();
                break;
            case 3:
                Rastrear();
                break;
            case 4:
                return 0;
            default:
                printf("Opção inválida.\n");
        }
    }
}
