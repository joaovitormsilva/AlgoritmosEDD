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
    return L;
}

bool listaligada_vazia(const listaLigada *L){
   return (L->comeco==NULL && L->end==NULL);
}
 
void listaligada_addfirst(listaLigada *L,int val){
    sNo *p = criar_no(val);
    p->proximo=L->comeco;
    
    if(listaligada_vazia(L)){
        L->end=p;
    }   
    L->comeco=p;
 
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
}

void listaligada_remove(listaLigada *L,int val){
    if(!listaligada_vazia(L)){
        
        if(L->comeco->valor == val){
            sNo *aux=L->comeco;

            if(L->end == L->comeco){
                L->end = NULL;
            }
            L->comeco = L->comeco->proximo;
            free(aux);
        }
        else{
            sNo *atual = L->comeco->proximo;
            sNo *anterior=L->comeco;

            while(atual != NULL && atual->valor!=val){
                anterior=atual;
                atual=atual->proximo;
            }
            if(atual!=NULL){
                anterior->proximo=atual->proximo;
                
                if(atual->proximo == NULL){
                    L->end = anterior;
                }
                printf("End é: %d\n",L->end->valor);
                free(atual);
            }
        }
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
