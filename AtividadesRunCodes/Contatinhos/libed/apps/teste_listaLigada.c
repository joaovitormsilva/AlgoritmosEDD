#include <stdio.h>
#include "lista_ligada.h"
#include <stdbool.h>
#include <string.h>


int main(){
    listaLigada *L = listaligada_create();
    char opcao = '0';
    long int numero;
    char nome[100];
    char operacao;
    int vezes =0;
    do{
        scanf("%c",&operacao);
        if(operacao == '0')
            break;
        switch(operacao){
            case 'I':
                scanf("%s %ld",nome,&numero);

                fflush(stdin);
                char nome2[]=listaligada_confere_valor(L,nome);
                if(!strcmp(nome2,nome)){
                    listaligada_addfirst(L,nome,numero);

                }
           
                listaligada_imprimir(L);
                vezes++;
                break;
            case 'A':
                break;
            case 'P':
                scanf(" %s",nome);
                listaligada_pegar_valor(L,nome);
                break;
            case 'R':
                listaligada_remove(L,nome);
                break; 
        }
        fflush(stdin);
    }while(operacao != opcao);


    return 0;

}