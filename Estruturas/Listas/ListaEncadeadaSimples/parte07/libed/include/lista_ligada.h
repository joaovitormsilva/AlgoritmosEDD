#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H
#include <stdbool.h>

typedef struct no No;
typedef struct listaligada listaLigada;

listaLigada *listaligada_create();

void listaligada_addfirst(listaLigada *L,int val);
void listaligada_addlast(listaLigada *L,int val);
void listaligada_remove(listaLigada *L,int val);

void listaligada_imprimir(const listaLigada *L);
bool listaligada_vazia(const listaLigada *L);

#endif // LISTA_LIGADA_H
