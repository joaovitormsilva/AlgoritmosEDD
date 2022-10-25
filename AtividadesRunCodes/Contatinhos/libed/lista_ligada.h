#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include <stdbool.h>
#include <stddef.h>

typedef struct no No;
typedef struct listaligada listaLigada;

listaLigada *listaligada_create();

void listaligada_addfirst(listaLigada *L,char nome[100],long int numero);
void listaligada_addlast(listaLigada *L,int val);
void listaligada_remove(listaLigada *L,char nome[100]);
void listaligada_destruir(listaLigada **ldest);
size_t listaligada_contador_lento(const listaLigada *L);
size_t listaligada_contador_rapido(const listaLigada *L);
void listaligada_imprimir(const listaLigada *L);
bool listaligada_vazia(const listaLigada *L);

int listaligada_primeiro_valor(const listaLigada *L);
int listaligada_ultimo_valor(const listaLigada *L);
void listaligada_pegar_valor(const listaLigada *L,char index[100]);
int listaligada_confere_valor(const listaLigada *L,char index[100]);
void listaligada_alterar(listaLigada *L,char nome[100],int numero);

#endif // LISTA_LIGADA_H
