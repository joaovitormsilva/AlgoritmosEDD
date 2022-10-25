#include "lista_ligada.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct sno
{
    long int numero;
    char nome[100];
    struct sno *proximo;
} sNo; //nós da lista

typedef struct listaligada
{
    sNo *comeco;
    sNo *end;
    size_t tamanho;

} listaLigada; //apontadores do começo e fim e tamanho da lista 

sNo *criar_no(char nome[100],long int numero)
{
    sNo *no = (sNo *)calloc(1, sizeof(sNo));
    no->numero = numero;
    strcpy(no->nome,nome);
    no->proximo = NULL;
    return no;
} //criacao do no

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
 
void listaligada_addfirst(listaLigada *L,char nome[100],long int numero){
    sNo *p = criar_no(nome,numero);
    p->proximo=L->comeco;
    
    if(listaligada_vazia(L)){
        L->end=p;
        L->comeco=p;
        L->tamanho++;
    }
    else{
        int ret=listaligada_confere_valor(L,nome);
        if(ret == 0){
            L->comeco=p;
            L->tamanho++;
        }
    }
 
}

void listaligada_remove(listaLigada *L,char nome[100]){
    if(!listaligada_vazia(L)){
        sNo *atual = L->comeco;
        sNo *anterior=NULL; 
        while(atual != NULL && strcmp(atual->nome,nome)){     
            anterior=atual;
            atual=atual->proximo;
        }
        if(atual!=NULL){
            
            if((L->end)==atual){
          
                L->end=anterior;
            }
            if((L->comeco)==atual){
          
                L->comeco=atual->proximo;
            }
            else{
    
                anterior->proximo=atual->proximo;
            }
            free(atual);
            L->tamanho--;
        }
        else{
            printf("Operacao invalida: contatinho nao encontrado\n");
        }
    }
}

void listaligada_pegar_valor(const listaLigada *L,char index[100]){
    sNo *aux=L->comeco;
    int achou=0;
    if(!listaligada_vazia(L)){
        while(aux !=NULL){
            //printf("aux->nome:%s e index:%s\n",aux->nome,index);
            if(!strcmp(aux->nome,index)){
                printf("Contatinho encontrado: telefone %ld\n",aux->numero);
                achou = 1;
            }
            aux=aux->proximo;
        }
        if(achou == 0)
        printf("Contatinho nao encontrado\n");
    }
    else{
        printf("Contatinho nao encontrado\n");
   
    }
}

int listaligada_confere_valor(const listaLigada *L,char index[100]){
    sNo *aux=L->comeco;
    if(!listaligada_vazia(L)){
        while(aux !=NULL){
            if(!strcmp(aux->nome,index)){
                printf("Contatinho ja inserido\n");
                return 1;
            }
            aux=aux->proximo;
        }
    }
    else{
        return 0;
    }
}

void listaligada_alterar(listaLigada *L,char nome[100],int numero){
    sNo *aux=L->comeco;
    int achou=0;
    if(!listaligada_vazia(L)){
        while(aux !=NULL){
            if(!strcmp(aux->nome,nome)){
                aux->numero=numero;
                achou= 1;
            }
            aux=aux->proximo;
        }
        if(achou==0)
            printf("Operacao invalida: contatinho nao encontrado\n");
    }
    else{
        printf("Operacao invalida: contatinho nao encontrado\n");
    }

}
