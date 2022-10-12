#include "lista_ligada.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct sno
{
    int valor;
    struct sno *proximo;
} sNo;

typedef struct listaligada
{
    sNo *comeco;
    sNo *end;
    size_t tamanho;

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
    L->end = NULL;
    L->tamanho= 0;
    return L;
}

void listaligada_destruir(listaLigada **ldest){
    listaLigada *L=*ldest;
    
    sNo *aux=L->comeco;
    sNo *anterior=NULL;

    while(aux != NULL){
        anterior=aux;
        aux=aux->proximo;
        free(anterior);
        L->tamanho--;
    }
    free(L);
    *ldest=NULL;
}

bool listaligada_vazia(const listaLigada *L){
   return (L->tamanho==0);
}
 
void listaligada_addfirst(listaLigada *L,int val){
    sNo *p = criar_no(val);
    p->proximo=L->comeco;
    
    if(listaligada_vazia(L)){
        L->end=p;
    }   
    L->comeco=p;
    L->tamanho++;
}

void listaligada_addlast(listaLigada *L,int val){
    sNo *p = criar_no(val);
    if(listaligada_vazia(L)){
        L->comeco=p;
        L->end=p;
    }
    else{
        L->end->proximo=p;
        L->end=L->end->proximo;
    }
    L->tamanho++;

}

void listaligada_remove(listaLigada *L,int val){
    if(!listaligada_vazia(L)){
        sNo *atual = L->comeco->proximo;
        sNo *anterior=L->comeco;
        
        while(atual != NULL && atual->valor!=val){
            anterior=atual;
            atual=atual->proximo;
        }
        if(atual!=NULL){
            if(L->end!=NULL){
                L->end=anterior;
            }
            if((L->comeco)=NULL){
                L->comeco=atual->proximo;
            }
            else{
                anterior->proximo=atual->proximo;
            }
            free(atual);
        }
        L->tamanho--;

    }
}


void listaligada_imprimir(const listaLigada *L){
    sNo *no=L->comeco;
    printf("L -> ");
    while(no != NULL){
        printf("%d -> ", no->valor);
        no=no->proximo;
    }
    printf("NULL\n");

    printf("tamanho: %llu\n",L->tamanho);
   
}

//É no modo lento
size_t listaligada_contador_lento(const listaLigada *L){
    sNo *aux = L->comeco;
    size_t contador =0;
    while(aux != NULL){
        contador++;
        aux=aux->proximo;
    }
    return contador;
}

size_t listaligada_contador_rapido(const listaLigada *L){
    return L->tamanho;
}