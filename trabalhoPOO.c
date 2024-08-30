#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ITENS 100 //define o limite máximo de itens que podem ser registrados no carrinho do operador de caixa.

// Superclasse
typedef struct {
    char nome[50];
    float preco;
} Item;

// Subclasse
typedef struct {
    Item item;  // Herança - atributos genéricos na superclasse
    int quantidade;  // Atributo específico na classe de tema do trabalho
} ItemCarrinho;

// Classe
typedef struct {
    ItemCarrinho carrinho[MAX_ITENS];
    int quantidade_itens;
} OperadorDoCaixa;

// Métodos set e get para encapsular os atributos criados
void setNomeItem(Item *item, const char *nome) {
    strncpy(item->nome, nome, sizeof(item->nome) - 1);
}

void setPrecoItem(Item *item, float preco) {
    item->preco = preco;
}

const char *getNomeItem(const Item *item) {
    return item->nome;
}

float getPrecoItem(const Item *item) {
    return item->preco;
}

// Função para adicionar item ao carrinho
void adicionarItem(OperadorDoCaixa *operador, const char *nome, float preco, int quantidade) {
    if (operador->quantidade_itens < MAX_ITENS) {
        ItemCarrinho *itemCarrinho = &operador->carrinho[operador->quantidade_itens++];
        setNomeItem(&itemCarrinho->item, nome); // Atributos específicos são setados usando métodos set
        setPrecoItem(&itemCarrinho->item, preco);
        itemCarrinho->quantidade = quantidade; // Atributo específico é setado diretamente
    } else {
        printf("Carrinho cheio. Não é possível adicionar mais itens.\n");
    }
}

// Função para calcular o total da compra
float calcularTotalCompra(const OperadorDoCaixa *operador) {
    float total = 0;
    for (int i = 0; i < operador->quantidade_itens; i++) {
        total += getPrecoItem(&operador->carrinho[i].item) * operador->carrinho[i].quantidade;
    }
    return total;
}

int main() {
    OperadorDoCaixa operador = { .quantidade_itens = 0 };

    printf("Bem-vindo! Vamos começar a registrar os itens de compra.\n");

    // Adicionando alguns itens ao carrinho para teste
    adicionarItem(&operador, "Pão", 2.50, 2);
    adicionarItem(&operador, "Leite", 3.00, 1);

    printf("\nItens registrados:\n");
    for (int i = 0; i < operador.quantidade_itens; i++) {
        printf("- %s (R$ %.2f) - Quantidade: %d\n", 
               getNomeItem(&operador.carrinho[i].item),
               getPrecoItem(&operador.carrinho[i].item),
               operador.carrinho[i].quantidade);
    }

    printf("\nTotal da compra: R$ %.2f\n", calcularTotalCompra(&operador));

    return 0;
}
