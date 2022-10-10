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

    listaligada_addfirst(L,51);
    listaligada_addfirst(L,47);
    listaligada_addfirst(L,5);
    listaligada_addfirst(L,10);
    listaligada_imprimir(L);
    return 0;
}