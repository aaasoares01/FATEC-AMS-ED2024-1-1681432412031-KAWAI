/*---------------------------------------------------------------------*/
/*     FATEC-AR                      Estrutura de Dados                */ 
/*     Lab9 :  Listas - Estrutura de dados                             */
/*     Nome: Kawai Bonilha Soares                                      */
/*---------------------------------------------------------------------*/
/* Programa: listaLigadaNo.C                                           */
/* Função: cria uma lista que recebe as função de entrada e processos: */
/* 0 - Sair                                                            */
/* 1 - Incluir                                                         */
/* 2 - Consultar                                                       */
/* 3 - Deletar                                                         */
/* 4 - Listar todos                                                   */
/*---------------------------------------------------------------------*/

#include <stdio.h>
struct lista {
    int info;
    struct lista* prox;
};

typedef struct lista Lista;

Lista* lst_cria(void) {
    return NULL;
}

Lista* lst_insere(Lista* l, int i) {
    Lista* novo = (Lista*)malloc(sizeof(Lista));
    novo->info = i;
    novo->prox = l;
    return novo;
}

void lst_imprime(Lista* l) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox)
        printf("%d\n", p->info);
}

int lst_vazia(Lista* l) {
    if (l == NULL)
        return 1;
    else
        return 0;
}

int lst_busca(Lista* l, int v) {
    Lista* p;
    for (p = l; p != NULL; p = p->prox) {
        if (p->info == v) {
            printf("Encontrou: %d\n", v);
            return 1;
        }
    }
    printf("Nao encontrou: %d\n", v);
    return 0;
}

void lst_libera(Lista* l) {
    Lista* p = l;
    while (p != NULL) {
        Lista* t = p->prox;
        free(p);
        p = t;
    }
}

int lst_deleta(Lista** l, int v) {
    Lista* ant = NULL; 
    Lista* p = *l;     
  
    while (p != NULL && p->info != v) {
        ant = p;
        p = p->prox;
    }

    if (p == NULL) {
        printf("Nao encontrou elemento para DELETAR: %d\n", v);
        return 1; 
    }
    if (ant == NULL) {
        *l = p->prox;
    } else {
        ant->prox = p->prox;
    }

    free(p);
    return 0;
}

void lst_listar_todos(Lista* l) {
    if (l == NULL) {
        printf("Lista vazia!\n");
        return;
    }

    printf("Lista de elementos:\n");
    lst_imprime(l);
}

int main(void) {
    Lista *l;
    int opcao, item;
    l = lst_cria();

    while (1) {
        printf("\nEscolha uma opcao:\n");
        printf("0 - Sair\n");
        printf("1 - Incluir na lista\n");
        printf("2 - Consultar na lista\n");
        printf("3 - Deletar elemento da lista\n");
        printf("4 - Listar todos os elementos\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 0:
                lst_libera(l);
                return 0;
            case 1:
                printf("Insira o item na lista:\n");
                scanf("%d", &item);
                if (item != 0)
                    l = lst_insere(l, item);
                break;
            case 2:
                printf("Insira o valor a ser consultado:\n");
                scanf("%d", &item);
                lst_busca(l, item);
                break;
            case 3:
                printf("Insira o valor a ser deletado:\n");
                scanf("%d", &item);
                lst_deleta(&l, item);
                break;
            case 4:
                lst_listar_todos(l);
                break;
            default:
                printf("Opcao invalida! Tente novamente.\n");
        }
    }
    return 0;
}
