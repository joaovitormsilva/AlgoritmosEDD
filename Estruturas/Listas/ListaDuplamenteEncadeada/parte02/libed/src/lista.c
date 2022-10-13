#include "lista.h"
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>

struct elemento{
    struct elemento *ant;
    int valor;
    struct elemento *prox;
};
typedef struct elemento elem;

lista* listadliga_criar(){
    lista *li = (lista *) malloc(sizeof(lista));
    if(li != NULL)
        *li=NULL;
    return li;
}
void listadliga_libera(lista* li){
    if(li != NULL){
        elem *aux;
        while((*li) != NULL){
            aux=*li;
            *li=(*li)->prox;
            free(aux);
        }
        free(li);
    }
}
int listadliga_size(lista* li){
    int size =0;
    if(li!=NULL){
        elem *aux= *li;
        while(aux != NULL){
            size++;
            aux= aux->prox;
        }
        return size;
    }
        return size;
}

void listadliga_inserir_inicio(lista* li,int val){
    elem* no = (elem*)malloc(sizeof(elem));
    no->valor=val;
    no->ant=NULL;
    no->prox=(*li);
    if(*li != NULL){
        (*li)->ant=no;
    }
    *li=no;
}

void listadliga_inserir_fim(lista* li,int val){
    elem* no = (elem*)malloc(sizeof(elem));
    no->valor=val;
    no->prox=NULL;
    if((*li)==NULL){
        no->ant=NULL;
        *li=no;
    }
    else{
        elem* aux = li;
        while(aux->prox!=NULL)
            aux=aux->prox;
        aux->prox=no;
        no->ant=aux;
    }

}