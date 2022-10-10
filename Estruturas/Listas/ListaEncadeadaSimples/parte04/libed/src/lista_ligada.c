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

listaLigada *listaligada_create()
{
    listaLigada *L = (listaLigada *)calloc(1, sizeof(listaLigada));
    L->comeco = NULL;
    return L;
}

void listaligada_addfirst(listaLigada *L,int val){
    sNo *p = criar_no(val);
    p->proximo=L->comeco;
    L->comeco = p;        
}

void listaligada_addlast(listaLigada *L,int val){
    sNo *p = criar_no(val);
    if(L->comeco == NULL)
        L->comeco=p;
    else{
        sNo *aux=L->comeco;
        while( aux->proximo != NULL){
            aux=aux->proximo;
        }
        aux->proximo=p;
        p->proximo=NULL;
    }
}



void listaligada_imprimir(const listaLigada *L){
    sNo *no=L->comeco;
    printf("L -> ");
    while(no != NULL){
        printf("%d -> ", no->valor);
        no=no->proximo;
    }
    printf("NULL");
   

}
