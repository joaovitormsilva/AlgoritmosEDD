#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

typedef struct no No;
typedef struct listaligada listaLigada;

listaLigada *listaligada_create();
void listaligada_addfirst(listaLigada *L,int val);
void listaligada_imprimir(const listaLigada *L);
#endif // LISTA_LIGADA_H
