#include <stdio.h>
#include "PilhaDin.h"
#include "fila.h"
#include <stdlib.h>

int main()
{
    char op, limpa;
    int quant, nPilha = 0, val;
    int aux,nfila=0;

    int vezes = 0;
    scanf("%d", &vezes); //quantidade de vezes que será rodado
    fflush(stdin);
    for (int i = 0; i < vezes; i++) //laço pra cada vez 
    {
        Pilha *pi = cria_Pilha(); // criando a EDD
        Fila *fi=cria_Fila(); //criando a EDD
        nPilha=0;
        nfila=0;
        scanf("%d", &quant); //Quantas ops vao ter 

        int j =quant;
        while(j>0){

        scanf(" %c %d", &op, &val);    //lendo cada coisa        
            if(op == 'i'){ //se for insercao
               
                insere_Pilha(pi, val); 
                /*
                Na inserção de ambas EDD, segue o padrão não foi feita nenhuma mudança
                uma vez que a inserção ocorre sem problemas
                */
                insere_Fila(fi,val);
        
            }
            else{
              
                if(nPilha == 0)
                    nPilha = remove_Pilha(pi, val);
                    /*Já na remoção, foi tomado o cuidado em cada EDD
                    Na pilha, a remocao foi alterada para verificar se o valor a ser removido era a cabeça
                    da pilha, se fosse retornava um valor estimado se não retornava outro que significava erro
                    
                    Já na fila, foi verificado se a remocao ocorreria na "cabeça"/frente da fila (FIFO) 
                    Então, se fosse retornava um valor estimado de sucesso, se não retornava outro de erro
                    */
                if(nfila == 0)
                    nfila = remove_Fila(fi,val);
            
                
            }
            j--;
        }
        // verificando através do retorno de cada remocao

        if(nPilha == 13 && nfila==0) //se a pilha retornasse ERRO e a fila não
            printf("fila\n");
        if(nPilha == 0 && nfila == 13) //se a pilha não der erro e a fila SIM
            printf("pilha\n");
        if(nPilha == 0 && nfila == 0) //se ambas derem certo
            printf("indefinido\n");
        if(nPilha == 13 && nfila == 13) //se ambas derem errado
            printf("impossivel\n");
    }

    return 0;
}