#ifndef EDITOR_H
#define EDITOR_H

// Cria um texto do zero, palavra por palavra, usando a fila para montar o
// texto (FIFO) e a pilha para desfazer a última palavra digitada (LIFO).
// "caminho_arquivo" é usado como sugestão de destino ao salvar.
void editor_criar_do_zero(const char *caminho_arquivo);
void editor_importar_arquivo(const char *caminho_arquivo);

#endif