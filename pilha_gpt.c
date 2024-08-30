#include <stdio.h>
#include <stdlib.h>

// Definição da estrutura da pilha
struct Pilha {
    int topo;
    int capacidade;
    float *elementos;
};

// Protótipos das funções
void empilhar(struct Pilha *p, float valor);
float desempilhar(struct Pilha *p);
float retornatopo(struct Pilha *p);
int estacheia(struct Pilha *p);
int estavazia(struct Pilha *p);

int main() {
    struct Pilha minhapilha;
    minhapilha.topo = -1;
    minhapilha.capacidade = 10;
    minhapilha.elementos = (float *)malloc(minhapilha.capacidade * sizeof(float));

    int op;
    float valor;

    while(1) {
        printf("\n1- empilhar (push)\n");
        printf("2- desempilhar (POP)\n");
        printf("3- Mostrar o topo\n");
        printf("4- sair\n");

        printf("\nopcao? ");
        scanf("%d", &op);

        switch (op) {
            case 1: //push
                if(estacheia(&minhapilha) == 1)
                    printf("\nPILHA CHEIA! \n");
                else {
                    printf("\nVALOR? ");
                    scanf("%f", &valor);
                    empilhar(&minhapilha, valor);
                }
                break;

            case 2: //pop
                if(estavazia(&minhapilha) == 1)
                    printf("\nPILHA VAZIA! \n");
                else {
                    valor = desempilhar(&minhapilha);
                    printf("\n%.1f DESEMPILHADO!\n", valor);
                }
                break;

            case 3: //mostrar o topo
                if(estavazia(&minhapilha) == 1)
                    printf("\nPILHA VAZIA!\n");
                else {
                    valor = retornatopo(&minhapilha);
                    printf("\nTOPO: %.1f\n", valor);
                }
                break;

            case 4:
                exit(0);

            default:
                printf("\nOPCAO INVALIDA!\n");
        }
    }

    free(minhapilha.elementos); // Libera a memória alocada para a pilha
    return 0;
}

// Função para empilhar um valor na pilha
void empilhar(struct Pilha *p, float valor) {
    p->elementos[++p->topo] = valor;
}

// Função para desempilhar um valor da pilha
float desempilhar(struct Pilha *p) {
    return p->elementos[p->topo--];
}

// Função para retornar o valor no topo da pilha
float retornatopo(struct Pilha *p) {
    return p->elementos[p->topo];
}

// Função para verificar se a pilha está cheia
int estacheia(struct Pilha *p) {
    return p->topo == p->capacidade - 1;
}

// Função para verificar se a pilha está vazia
int estavazia(struct Pilha *p) {
    return p->topo == -1;
}
