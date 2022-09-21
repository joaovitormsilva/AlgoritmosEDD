#include "ListaDin.h"
#include <stdio.h>
#include <stdlib.h>

int criar(t_lista *lista){
	lista->primeiro = NULL;
	lista->ultimo = NULL;
}
	
int inserir(t_lista *lista, t_elemento elemento){
	t_apontador novo= (t_apontador) malloc(sizeof(t_apontador));
	if(novo == NULL)
		return ERRO_CHEIA;
	novo->proximo = lista->primeiro.proximo;
	lista->prim()
	}

static t_apontador pesquisa_pos(t_lista *lista, t_chave chave){
	t_apontador p = lista->primeiro;
	
	if(p==NULL)
		return NULL;
	
	while(p != null){
		if(p->elemento.chave == chave)
			return p;
		p=p->proximo;
	}

	return NULL;
}

t_elemento pesquisar(t_lista *lista, t_chave chave){
	t_apontador p = pesquisa_pos(lista,chave);
	return p->elemento;

}