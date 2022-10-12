#include <stdio.h>
#include "lista_ligada.h"
#include <stdbool.h>


int main(){
    listaLigada *L = listaligada_create();
    /*listaligada_addfirst(L,5);
    listaligada_addfirst(L,4);
    listaligada_addfirst(L,2);
    listaligada_addfirst(L,10);
    */
    printf("testando\n");

    listaligada_addlast(L,15);
    listaligada_addlast(L,7);
    listaligada_addlast(L,3);
    listaligada_addlast(L,11);
    
    listaligada_imprimir(L);
    printf("\n");

    listaligada_remove(L,99);
    listaligada_imprimir(L);
    printf("\n");

    size_t tamanho = listaligada_contador_lento(L);
    printf("Tmanho lento eh: %llu\n",tamanho);
    
    listaligada_addlast(L,11);
    listaligada_addlast(L,11);
    
    size_t size = listaligada_contador_rapido(L);
    printf("Tmanho rapido eh: %llu\n",size);


    listaligada_destruir(&L);



    return 0;
}