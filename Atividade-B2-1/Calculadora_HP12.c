#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK_SIZE 100

typedef struct {
    char* items[MAX_STACK_SIZE];
    double values[MAX_STACK_SIZE];
    int top;
} Stack;

void push(Stack *s, char* value, double num) {
    if (s->top == MAX_STACK_SIZE - 1) {
        printf("Erro: Pilha cheia.\n");
        exit(EXIT_FAILURE);
    }
    s->items[++(s->top)] = value;
    s->values[s->top] = num;
}

char* pop(Stack *s, double *num) {
    if (s->top == -1) {
        printf("Erro: Pilha vazia.\n");
        exit(EXIT_FAILURE);
    }
    *num = s->values[s->top];
    return s->items[(s->top)--];
}

double calcular(char op, double num1, double num2) {
    switch (op) {
        case '+':
            return num1 + num2;
        case '-':
            return num1 - num2;
        case '*':
            return num1 * num2;
        case '/':
            if (num2 == 0) {
                printf("Erro: Divisão por zero.\n");
                exit(EXIT_FAILURE);
            }
            return num1 / num2;
        default:
            printf("Operador inválido.\n");
            exit(EXIT_FAILURE);
    }
}

int main() {
    Stack pilha;
    pilha.top = -1;

    char entrada[100];
    printf("Digite a expressão RPN (use espaços entre os elementos): ");
    fgets(entrada, sizeof(entrada), stdin);

    char *ptr = entrada;
    while (*ptr != '\0') {
        if (isspace(*ptr)) {
            ptr++;
            continue; 
        }
        if (isdigit(*ptr)) {
            char* num = (char*) malloc(20 * sizeof(char));
            int i = 0;
            while (isdigit(*ptr) || *ptr == '.') {
                num[i++] = *ptr++;
            }
            num[i] = '\0';
            push(&pilha, num, atof(num));
        } else if (*ptr == '+' || *ptr == '-' || *ptr == '*' || *ptr == '/') {
            double num2, num1;
            char* str2 = pop(&pilha, &num2);
            char* str1 = pop(&pilha, &num1);
            char* expr = (char*) malloc((strlen(str1) + strlen(str2) + 4) * sizeof(char));
            sprintf(expr, "(%s %c %s)", str1, *ptr, str2);
            push(&pilha, expr, calcular(*ptr, num1, num2));
            ptr++;
        } else {
            printf("Caractere inválido na entrada: '%c'\n", *ptr);
            exit(EXIT_FAILURE);
        }
    }

    if (pilha.top != 0) {
        printf("Erro: Entrada inválida.\n");
        exit(EXIT_FAILURE);
    }

    double resultadoNum;
    char* resultadoExpr = pop(&pilha, &resultadoNum);
    printf("Resultado: %s = %.2f\n", resultadoExpr, resultadoNum);

    return 0;
}
