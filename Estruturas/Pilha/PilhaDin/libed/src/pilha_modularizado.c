#include "pilha_modularizado.h"
#include <stddef.h>
#include <stdio.h> 
#include <stdlib.h>

struct elemento{
    char operador;
    struct elemento *proximo;
};
typedef struct elemento elem;

pilha *pilhadin_cria_Pilha(){
    pilha *pi = (pilha *) malloc(sizeof(pilha));
    if(pi !=NULL)
        *pi=NULL;
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

int pilhadin_tamanho_pilha(pilha *pi){
    if(pi == NULL){
        return 0;
    }
    int size=0;
    elem *aux=(*pi);
    while(aux != NULL){
        size++;
        aux = aux->proximo;
    }
    return size;
}

void pilhadin_inserir(pilha *pi, char valor){
    if(pi == NULL){
        exit(0);
    }
    elem* no = (elem *) malloc(sizeof(elem));
    if(no == NULL)
        exit(0);
    elem *aux = *pi;
    if((*pi) == NULL){
        no->operador=valor;
        no->proximo=(*pi);
        *pi = no;
    }
    else{
        if(valor != aux->operador){
        (*pi)=(*pi)->proximo;
        free(aux);
        }
        else{
        no->operador=valor;
        no->proximo=(*pi);
        *pi = no;
        }
    }
       
}

void pilhadin_remover(pilha *pi){
    if(pi == NULL)
        exit(0);
    
    elem *aux = (*pi);
    while(aux != NULL){
        *pi = aux->proximo;
        free(aux);
        aux=(*pi);
    }

}

void pilhadin_imprimir(pilha *pi){

    if(pi == NULL)
        exit(0);

    elem *aux = *pi;
    printf("L ->");
    while(aux != NULL){
        printf(" %c ->",aux->operador);
        aux= aux->proximo;
    }
    printf(" NULL\n");
}

char pilhadin_consulta(pilha *pi){
    if(pi == NULL){
        return 0;
    }
    return ((*pi)->operador);
}

