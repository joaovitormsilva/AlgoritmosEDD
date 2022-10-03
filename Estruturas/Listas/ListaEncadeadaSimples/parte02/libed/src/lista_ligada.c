#include "lista_ligada.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct sno{
    int valor;
    struct sno *proximo;
} sNo;

typedef struct listaligada{
    sNo *comeco;
} listaLigada;

listaLigada *listaLigada_create(){
    listaLigada *L = (listaLigada*) calloc(1,sizeof(listaLigada));
    L->comeco=NULL;
    return L;
}