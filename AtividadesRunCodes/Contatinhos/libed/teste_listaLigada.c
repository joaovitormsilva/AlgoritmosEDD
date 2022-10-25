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
        
        scanf("%c",&operacao); //ler o tipo de operacao
        if(operacao == '0')
            break;
        switch(operacao){
            case 'I': //se for inserir
                scanf("%s %ld",nome,&numero);
                fflush(stdin);
                listaligada_addfirst(L,nome,numero);
    
                vezes++;
                break;

            case 'A': //se for alterar
                scanf("%s %ld",nome,&numero);
                fflush(stdin);
                listaligada_alterar(L,nome,numero);
                
                break;

            case 'P': //se for procurar
                scanf(" %s",nome);
                fflush(stdin);
                listaligada_pegar_valor(L,nome);
                break;
            case 'R': //se for remover 
                scanf(" %s",nome);
                fflush(stdin);
           
                listaligada_remove(L,nome);

                break; 
        }
        fflush(stdin);
    }while(operacao != opcao);


    return 0;

}