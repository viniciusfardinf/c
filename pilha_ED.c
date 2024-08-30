#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da pilha
struct Pilha {
    int topo;          // Índice 
    int capacidade;    // Capacidade máxima da pilha
    float *elementos;  // Ponteiro 
};

// Protótipos das funções
void empilhar(struct Pilha *p, float valor);         // Função para empilhar um valor na pilha
float desempilhar(struct Pilha *p);                  // Função para desempilhar um valor da pilha
float retornatopo(struct Pilha *p);                  // Função para retornar o valor no topo da pilha
int estacheia(struct Pilha *p);                      // Função para verificar se a pilha está cheia
int estavazia(struct Pilha *p);                      // Função para verificar se a pilha está vazia

int main() {
    struct Pilha minhapilha;                          // Declaração de uma variável do tipo Pilha
    minhapilha.topo = -1;                             // Inicializa o índice do topo como -1 (pilha vazia)
    minhapilha.capacidade = 10;                       // Define a capacidade máxima da pilha como 10
    minhapilha.elementos = (float *)malloc(minhapilha.capacidade * sizeof(float)); // Aloca memória para a pilha

    int op;                                           // Variável para armazenar a opção do usuário
    float valor;                                      // Variável para armazenar valores a serem empilhados

    while(1) {                                        // Loop infinito
        printf("\n1- empilhar (push)\n");             // Opção para empilhar um valor
        printf("2- desempilhar (POP)\n");             // Opção para desempilhar um valor
        printf("3- Mostrar o topo\n");                // Opção para mostrar o valor no topo da pilha
        printf("4- sair\n");                          // Opção para sair do programa

        printf("\nopcao? ");                           // Solicitação para o usuário inserir uma opção
        scanf("%d", &op);                             

        switch (op) {                                  // Início do bloco switch para processar a opção do usuário
            case 1:                                   // Caso a opção seja 1 (empilhar)
                if(estacheia(&minhapilha) == 1)      // Verifica se a pilha está cheia
                    printf("\nPILHA CHEIA! \n");     // Imprime mensagem de erro se a pilha estiver cheia
                else {
                    printf("\nVALOR? ");              // Solicitação para o usuário inserir um valor
                    scanf("%f", &valor);
                    empilhar(&minhapilha, valor);    // Chama a função para empilhar o valor na pilha
                }
                break;

            case 2:                                   // Caso a opção seja 2 (desempilhar)
                if(estavazia(&minhapilha) == 1)      // Verifica se a pilha está vazia
                    printf("\nPILHA VAZIA! \n");     // Imprime mensagem de erro se a pilha estiver vazia
                else {
                    valor = desempilhar(&minhapilha); // Chama a função para desempilhar um valor da pilha
                    printf("\n%.1f DESEMPILHADO!\n", valor); // Imprime o valor desempilhado
                }
                break;

            case 3:                                   // Caso a opção seja 3 (mostrar o topo)
                if(estavazia(&minhapilha) == 1)      // Verifica se a pilha está vazia
                    printf("\nPILHA VAZIA!\n");       // Imprime mensagem de erro se a pilha estiver vazia
                else {
                    valor = retornatopo(&minhapilha); // Chama a função para retornar o valor no topo da pilha
                    printf("\nTOPO: %.1f\n", valor);  // Imprime o valor no topo da pilha
                }
                break;

            case 4:                                   // Caso a opção seja 4 (sair)
                exit(0);                             // Sai do programa
                break;

            default:                                  // Caso a opção seja inválida
                printf("\nOPCAO INVALIDA!\n");       // Imprime mensagem de erro
        }
    }

    free(minhapilha.elementos);                      // Libera a memória alocada para a pilha
    return 0;
}

// Função para empilhar um valor na pilha
void empilhar(struct Pilha *p, float valor) {
    p->elementos[++p->topo] = valor;                 // Incrementa o topo e atribui o valor à posição correspondente na pilha
}

// Função para desempilhar um valor da pilha
float desempilhar(struct Pilha *p) {
    return p->elementos[p->topo--];                  // Retorna e decrementa o topo para desempilhar um valor
}

// Função para retornar o valor no topo da pilha
float retornatopo(struct Pilha *p) {
    return p->elementos[p->topo];                    // Retorna o valor no topo da pilha
}

// Função para verificar se a pilha está cheia
int estacheia(struct Pilha *p) {
    return p->topo == p->capacidade - 1;             // Retorna verdadeiro se o topo for igual à capacidade - 1
}

// Função para verificar se a pilha está vazia
int estavazia(struct Pilha *p) {
    return p->topo == -1;                             // Retorna verdadeiro se o topo for igual a -1
}
