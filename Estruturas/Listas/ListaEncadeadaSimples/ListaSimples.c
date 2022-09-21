#include <stdio.h>
#include "ListaSimples.h"

typedef struct no{
    int valor;
    struct no *proximo;
}No;

typedef struct lista{
    No *comeco;
}listaligada;
