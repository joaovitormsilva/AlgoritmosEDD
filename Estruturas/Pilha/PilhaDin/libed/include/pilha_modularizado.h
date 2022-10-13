#ifndef PILHA_MODULARIZADO_H
#define PILHA_MODULARIZADO_H

#include <stdbool.h>
#include <stddef.h>
#include <stdio.h> 
#include <stdlib.h>

typedef struct elemento* pilha;

pilha *pilhadin_cria_Pilha();
int pilhadin_tamanho_pilha(pilha *pi);
void pilhadin_inserir(pilha *pi, char valor);
void pilhadin_remover(pilha *pi);
char pilhadin_consulta(pilha *pi);
void pilhadin_imprimir(pilha *pi);





#endif