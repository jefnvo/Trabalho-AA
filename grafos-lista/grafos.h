#include <stdio.h>
#include <stdlib.h>
typedef struct No{
    int vertice;
    int peso;
    struct No *prox;
}no;
typedef struct Grafo{
    int qtde_vertices, qtde_arestas;
    int *grau;
    no** aresta;
}grafo;

int *visitado;//verifica se dado vertice foi visitado ou nao

grafo* cria_grafo(int nro_vertices);
int insere_aresta(grafo* g, int v1, int v2, int P);
int remove_aresta(grafo* g, int v1, int v2);
int verifica_aresta(grafo* g, int v1, int v2);
int consulta_aresta(grafo* g, int v1, int v2, int *P);
void libera_grafo(grafo** g);
void mostra_adjacentes(grafo* g, int v);
void mostra_grafo(grafo* g);
//busca em profundidade
void busca_profundidade(grafo* g, int V, int *visitado);
void DFS(grafo* g, int V);
