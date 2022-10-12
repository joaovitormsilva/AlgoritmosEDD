#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include <stdbool.h>
#include <stddef.h>

typedef struct no No;
typedef struct listaligada listaLigada;

listaLigada *listaligada_create();

void listaligada_addfirst(listaLigada *L,int val);
void listaligada_addlast(listaLigada *L,int val);
void listaligada_remove(listaLigada *L,int val);
void listaligada_destruir(listaLigada **ldest);
size_t listaligada_contador_lento(const listaLigada *L);
size_t listaligada_contador_rapido(const listaLigada *L);
void listaligada_imprimir(const listaLigada *L);
bool listaligada_vazia(const listaLigada *L);

#endif // LISTA_LIGADA_H
