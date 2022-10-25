#ifndef FILA_H
#define FILA_H

typedef struct fila Fila;

Fila* cria_Fila();
void libera_Fila(Fila* fi);
int consulta_Fila(Fila* fi, int val);
int insere_Fila(Fila* fi, int val);
int remove_Fila(Fila* fi,int val);
int tamanho_Fila(Fila* fi);
int Fila_vazia(Fila* fi);
int Fila_cheia(Fila* fi);
void imprime_Fila(Fila* fi);

#endif