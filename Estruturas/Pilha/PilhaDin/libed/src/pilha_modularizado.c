#include "pilha_modularizado.h"
#include <stddef.h>
#include <stdio.h> 

struct data{
    int dia, mes, ano;
};
struct elemento{
    struct data dados;
    struct elemento *proximo;
};
typedef struct elemento elem;

pilha *pilhadin_cria_Pilha(){
    pilha *pi = (pilha *) malloc(sizeof(pilha));
    if(pi !=NULL)
        pi=NULL;
    return pi;
}

void pilhadin_liberapilha(pilha* pi){
    if(pi !=NULL){
        elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->proximo;
            free(no);
        }
        free(pi);
    }
}