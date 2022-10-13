#ifndef LISTA_H
#define LISTA_H

typedef struct elemento* lista;

lista* listadliga_criar();
void listadliga_libera(lista* li);
int listadliga_size(lista* li);
void listadliga_inserir_inicio(lista* li,int val);
#endif