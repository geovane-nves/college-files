#include <stdio.h>
#include <stdlib.h>
#include "simples.h"
#include <string.h>


void inserirNoFinal(Produto produto, No** lista){
    No* novo = malloc(sizeof(No));
    if (novo == NULL){
        printf("Erro ao alocar memória \n");
        return;
    }

    novo->produto = produto;
    novo -> prox = NULL;

    if (*lista == NULL) {
        *lista = novo;
    
    } else {
        No* atual = *lista;

        while (atual->prox != NULL){
            atual = atual->prox;        
        }
        
        atual->prox = novo;
    }
    printf("Produto inserido com sucesso! \n");
    
}

void inserirNoInicio(Produto produto, No **lista){
    No *novo = malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        return;
    }

    novo->produto = produto;
    novo->prox = *lista;
    *lista = novo;
}

void remover_inicio(No **lista){
    if (*lista == NULL) {
        printf("A lista está vazia.\n");
        return;
    }

    No *remover = *lista;

    *lista = remover->prox;

    free(remover);

    printf("Produto inserido com sucesso.\n");
}

void remover_fim(No **lista)
{
    if (*lista == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    if ((*lista)->prox == NULL) {
        free(*lista);
        *lista = NULL;

        printf("Produto removido com sucesso.\n");
        return;
    }

    No *atual = *lista;

    while (atual->prox->prox != NULL) {
        atual = atual->prox;
    }

    free(atual->prox);
    atual->prox = NULL;

    printf("Produto removido com sucesso.\n");
}

void remover_por_id(No **lista, int id)
{
    if (*lista == NULL) {
        printf("A lista esta vazia.\n");
        return;
    }

    if ((*lista)->produto.id == id) {
        No *remover = *lista;

        *lista = remover->prox;

        free(remover);

        printf("Produto removido com sucesso.\n");
        return;
    }

    No *atual = *lista;

    while (atual->prox != NULL) {

        if (atual->prox->produto.id == id) {
            No *remover = atual->prox;

            atual->prox = remover->prox;

            free(remover);

            printf("Produto removido com sucesso.\n");
            return;
        }

        atual = atual->prox;
    }

    printf("ID nao encontrado.\n");
}

void listar(No* lista){

    if (lista == NULL) {
        printf("A lista está vazia \n");
        return;
    }

    printf("\nLista de produtos pereciveis: \n\n");

    while (lista != NULL){
        printf("ID: %d\n", lista->produto.id);
        printf("Nome: %s\n", lista->produto.nome);
        printf("Quantidade: %d\n", lista->produto.quantidade);
        printf("Preco: %.2f\n", lista->produto.preco);
        printf("\n");

        lista = lista->prox;
    }
}

void buscar_nome(No *lista, char *nome){
    int encontrou = 0;

    while (lista != NULL) {

        if (strstr(lista->produto.nome, nome) != NULL) {

            exibir_produto(&lista->produto);

            encontrou = 1;
        }

        lista = lista->prox;
    }

    if (encontrou == 0) {
        printf("Nenhum produto encontrado.\n");
    }
}

void atualizar_quantidade(No *lista, int id, int nova_quantidade)
{
    while (lista != NULL) {

        if (lista->produto.id == id) {

            alterar_quantidade(&lista->produto, nova_quantidade);

            printf("Quantidade atualizada com sucesso.\n");
            return;
        }

        lista = lista->prox;
    }

    printf("Produto com ID %d nao encontrado.\n", id);
}


int contar(No *lista)
{
    int quantidade = 0;

    while (lista != NULL) {
        quantidade++;
        lista = lista->prox;
    }

    return quantidade;
}


void esvaziar(No **lista)
{
    No *aux;

    while (*lista != NULL) {

        aux = *lista;

        *lista = (*lista)->prox;

        free(aux);
    }

    printf("Lista esvaziada com sucesso.\n");
}