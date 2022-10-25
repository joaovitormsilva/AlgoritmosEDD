#ifndef PILHA_DIN_H
#define PILHA_DIN_H

typedef struct elemento* Pilha;

Pilha* cria_Pilha();
void libera_Pilha(Pilha* pi);
int consulta_topo_Pilha(Pilha* pi, int valor);
int insere_Pilha(Pilha* pi, int valor);
int remove_Pilha(Pilha* pi, int val);
int tamanho_Pilha(Pilha* pi);
int Pilha_vazia(Pilha* pi);
int Pilha_cheia(Pilha* pi);
void imprime_Pilha(Pilha* pi);

#endif