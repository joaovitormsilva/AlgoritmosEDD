#include "lista_ligada.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct sno
{
    int valor;
    struct sno *proximo;
} sNo;

typedef struct listaligada
{
    sNo *comeco;
} listaLigada;

sNo *criar_no(int val)
{
    sNo *no = (sNo *)calloc(1, sizeof(sNo));
    no->valor = val;
    no->proximo = NULL;
    return no;
}

listaLigada *listaLigada_create()
{
    listaLigada *L = (listaLigada *)calloc(1, sizeof(listaLigada));
    L->comeco = NULL;
    return L;
}