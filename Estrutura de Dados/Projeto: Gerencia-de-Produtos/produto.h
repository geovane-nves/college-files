#ifndef PRODUTO_H
#define PRODUTO_H

typedef struct Produto{
    int id;
    char nome[51];
    int quantidade;
    float preco;
    char validade[11];
} Produto;

Produto *criarProduto(char *nome, int quantidade, float preco, char *validade);
void exibir_produto(Produto *p);
void alterar_quantidade(Produto *produto, int nova_quantidade);
void alterar_preco(Produto *produto, float novo_preco);
#endif