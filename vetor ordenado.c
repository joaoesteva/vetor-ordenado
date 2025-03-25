#include <stdio.h>

#define MAX 50

// Função para inserir um elemento de forma ordenada
void inserirOrdenado(int vetor[], int *tamanho, int valor) {
    if (*tamanho >= MAX) {
        printf("Erro: Capacidade máxima do vetor atingida!\n");
        return;
    }

    int i, j;
    for (i = 0; i < *tamanho; i++) {
        if (vetor[i] > valor) {
            break;
        }
    }

    for (j = *tamanho; j > i; j--) {
        vetor[j] = vetor[j - 1];
    }

    vetor[i] = valor;
    (*tamanho)++;
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    if (tamanho == 0) {
        printf("O vetor está vazio!\n");
        return;
    }
    printf("Vetor: ");
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

// Função de busca binária
int buscaBinaria(int vetor[], int tamanho, int valor) {
    int inicio = 0, fim = tamanho - 1, meio;
    while (inicio <= fim) {
        meio = (inicio + fim) / 2;
        if (vetor[meio] == valor) {
            return meio;
        } else if (vetor[meio] < valor) {
            inicio = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

// Função para remover um elemento do vetor
void removerElemento(int vetor[], int *tamanho, int valor) {
    int posicao = buscaBinaria(vetor, *tamanho, valor);
    if (posicao == -1) {
        printf("Elemento não encontrado!\n");
        return;
    }

    for (int i = posicao; i < *tamanho - 1; i++) {
        vetor[i] = vetor[i + 1];
    }
    (*tamanho)--;
    printf("Elemento %d removido com sucesso!\n", valor);
}

int main() {
    int vetor[MAX];
    int tamanho, opcao, valor;

    // Solicita o tamanho do vetor ao usuário
    do {
        printf("Digite o tamanho do vetor (entre 3 e 50): ");
        scanf("%d", &tamanho);
    } while (tamanho < 3 || tamanho > 50);

    // Inserção ordenada inicial
    printf("Digite %d valores para preencher o vetor (em qualquer ordem):\n", tamanho);
    int entrada;
    for (int i = 0; i < tamanho; i++) {
        scanf("%d", &entrada);
        inserirOrdenado(vetor, &i, entrada);
    }

    // Menu de opções
    do {
        printf("\nMENU:\n");
        printf("1 - Imprimir vetor\n");
        printf("2 - Buscar elemento\n");
        printf("3 - Remover elemento\n");
        printf("4 - Inserir elemento\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                imprimirVetor(vetor, tamanho);
                break;
            case 2:
                printf("Digite o valor a ser buscado: ");
                scanf("%d", &valor);
                int posicao = buscaBinaria(vetor, tamanho, valor);
                if (posicao == -1) {
                    printf("Elemento não encontrado!\n");
                } else {
                    printf("Elemento encontrado na posição %d\n", posicao);
                }
                break;
            case 3:
                printf("Digite o valor a ser removido: ");
                scanf("%d", &valor);
                removerElemento(vetor, &tamanho, valor);
                break;
            case 4:
                if (tamanho >= MAX) {
                    printf("O vetor já está cheio!\n");
                } else {
                    printf("Digite o valor a ser inserido: ");
                    scanf("%d", &valor);
                    inserirOrdenado(vetor, &tamanho, valor);
                    printf("Elemento inserido com sucesso!\n");
                }
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida! Tente novamente.\n");
        }
    } while (opcao != 0);

    return 0;
}
