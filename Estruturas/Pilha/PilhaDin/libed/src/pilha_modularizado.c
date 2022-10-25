#include "pilha_modularizado.h"
#include <stddef.h>
#include <stdio.h> 
#include <stdlib.h>

struct elemento{
    int valores;
    struct elemento *proximo;
};
typedef struct elemento Elem;

pilha *pilhadin_cria_Pilha(){
    pilha *pi = (pilha *) malloc(sizeof(pilha));
    if(pi !=NULL)
        *pi=NULL;
    return pi;
}

void pilhadin_liberapilha(pilha* pi){
    if(pi !=NULL){
        Elem* no;
        while((*pi) != NULL){
            no = *pi;
            *pi = (*pi)->proximo;
            free(no);
        }
        free(pi);
    }
}

int pilhadin_tamanho_pilha(pilha *pi){
    if(pi == NULL){
        return 0;
    }
    int size=0;
    Elem *aux=(*pi);
    while(aux != NULL){
        size++;
        aux = aux->proximo;
    }
    return size;
}

int pilhadin_inserir(pilha *pi, int valor){
    if(pi == NULL)
        return 0;
    Elem* no = (Elem *) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    Elem *aux = *pi;
    if((*pi) == NULL){
        no->valores=valor;
        no->proximo=(*pi);
        *pi = no;
    }
    else{
        if(valor != aux->valores){
        (*pi)=(*pi)->proximo;
        free(aux);
        }
        else{
        no->valores=valor;
        no->proximo=(*pi);
        *pi = no;
        }
    }
       
}

int pilhadin_remover(pilha *pi){
    if(pi == NULL)
        return 0;
    if((*pi) == NULL)
        return 0;
    Elem *no = *pi;
    *pi = no->proximo;
    free(no);
    return 1;

}

void pilhadin_imprimir(pilha *pi){
    Elem *aux = *pi;
    printf("P ->");
    while(aux != NULL){
        printf(" %d ->",aux->valores);
        aux= aux->proximo;
    }
    printf(" NULL\n");
}

char pilhadin_consulta(pilha *pi){
    if(pi == NULL){
        return 0;
    }
    return ((*pi)->valores);
}

