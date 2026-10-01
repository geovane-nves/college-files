#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "produto.h"

int proximoId = 1;

Produto *criarProduto(char *nome, int quantidade, float preco, char *validade){
    Produto *produto = malloc(sizeof(Produto));

    if (produto == NULL) return NULL;

    produto->id = proximoId;
    strcpy(produto->nome, nome);
    produto->quantidade = quantidade;
    produto->preco = preco;
    strcpy(produto->validade, validade);

    proximoId += 1;
    return produto;
}

void exibir_produto(Produto *produto){
    if (produto == NULL) return;

    printf("\nID: %d\n", produto->id);
    printf("Nome: %s\n", produto->nome);
    printf("Quantidade: %d\n", produto->quantidade);
    printf("Preco: %.2f\n", produto->preco);
    printf("Validade: %s\n", produto->validade);
}

void alterar_quantidade(Produto *produto, int quantidade){
    if (produto == NULL) return;

    produto->quantidade = quantidade;
}

void alterar_preco(Produto *produto, float novo_preco){
        if (produto == NULL) return;

    produto->preco = novo_preco;
}