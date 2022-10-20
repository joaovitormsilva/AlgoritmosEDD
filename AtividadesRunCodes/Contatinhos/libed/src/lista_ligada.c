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
} sNo;

typedef struct listaligada
{
    sNo *comeco;
    sNo *end;
    size_t tamanho;

} listaLigada;

sNo *criar_no(char nome[100],long int numero)
{
    sNo *no = (sNo *)calloc(1, sizeof(sNo));
    no->numero = numero;
    strcpy(no->nome,nome);
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
 
void listaligada_addfirst(listaLigada *L,char nome[100],long int numero){
    sNo *p = criar_no(nome,numero);
    p->proximo=L->comeco;
    
    if(listaligada_vazia(L)){
        L->end=p;
    }   
    L->comeco=p;
    L->tamanho++;
}

/*void listaligada_addlast(listaLigada *L,int val){
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

}*/

void listaligada_remove(listaLigada *L,char nome[100]){
    if(!listaligada_vazia(L)){
        sNo *atual = L->comeco->proximo;
        sNo *anterior=L->comeco;
        
        while(atual != NULL && strcmp(atual->nome,nome)){
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
              L->tamanho--;
        }
    }
}


void listaligada_imprimir(const listaLigada *L){
    sNo *no=L->comeco;
    printf("L -> ");
    while(no != NULL){
        printf("%s %ld -> ", no->nome,no->numero);
        no=no->proximo;
    }
    printf("NULL\n");

    printf("tamanho: %llu\n",L->tamanho);
   
}
/*
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

int listaligada_primeiro_valor(const listaLigada *L){
    if(L->tamanho !=0){
        return L->comeco->valor;
    }
    else{
        return EXIT_FAILURE;
    }
}
int listaligada_ultimo_valor(const listaLigada *L){
    if(L->tamanho !=0){
        return L->end->valor;
    }
    else{
        return EXIT_FAILURE;
    }
}
*/
int listaligada_pegar_valor(const listaLigada *L,char index[100]){
    sNo *aux=L->comeco;
    if(!listaligada_vazia(L)){
        /*if(index < 0 || index>= L->tamanho){
            printf("Index invalido\n");
            return EXIT_FAILURE;
        }*/
        while(aux !=NULL){
            //printf("aux->nome:%s e index:%s\n",aux->nome,index);
            if(!strcmp(aux->nome,index)){
                printf("Contatinho encontrado: telefone %ld\n",aux->numero);
                return 0;
            }
            aux=aux->proximo;
        }
        printf("Operacao invalida: contatinho nao encontrado\n");
    }
    else{
        printf("Operacao invalida: contatinho nao encontrado\n");
        return 0;
    }
}

char listaligada_confere_valor(const listaLigada *L,char index[100]){
    sNo *aux=L->comeco;
    if(!listaligada_vazia(L)){
        /*if(index < 0 || index>= L->tamanho){
            printf("Index invalido\n");
            return EXIT_FAILURE;
        }*/
        while(aux !=NULL){
            //printf("aux->nome:%s e index:%s\n",aux->nome,index);
            if(!strcmp(aux->nome,index)){
                return aux->nome;
            }
            aux=aux->proximo;
        }
    }
    else{
        printf("Operacao invalida: contatinho nao encontrado\n");
        return 0;
    }
}