#include "lista_ligada.h"

typedef struct sno{
    int valor;
    struct sno *proximo;
} sNo;

typedef struct listaligada{
    sNo *comeco;
} listaLigada;
