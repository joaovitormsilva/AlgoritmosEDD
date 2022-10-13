#include "pilha_modularizado.h"
#include <stdio.h> 
#include <stdlib.h>
int main(){
    pilha *pi = pilhadin_cria_Pilha();
    
    pilhadin_inserir(pi,'(');
    pilhadin_inserir(pi,'(');
    pilhadin_inserir(pi,')');
    pilhadin_imprimir(pi);

}