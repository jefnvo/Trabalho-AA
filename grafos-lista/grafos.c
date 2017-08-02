#include "grafos.h"
grafo* cria_grafo(int nro_vertices)
{
    int i;
    if(nro_vertices<0)
        return NULL;
    grafo* g = (grafo *) malloc(sizeof(grafo));
    if(g==NULL)
        return NULL;
    g->qtde_vertices = nro_vertices;
    g->qtde_arestas = 0;
    g->grau = (int *) malloc(nro_vertices*sizeof(int));
    if(g->grau==NULL)
    {
        free(g->grau);
        free(g);
        return NULL;
    }
    memset(g->grau,(int)0, sizeof(int)*nro_vertices);
    g->aresta = (no **) malloc(nro_vertices*sizeof(no *));
    if(g->aresta==NULL)
    {
        free(g->aresta);
        free(g->grau);
        free(g);
        return NULL;
    }
    for(i=0; i<nro_vertices; i++)
        g->aresta[i] = NULL;
    return g;
}
int insere_aresta(grafo* g, int v1, int v2, int P)
{
    if(g==NULL||v1<0||v2<0)
        return -1;
    no* aux = g->aresta[v1];
    while(aux!=NULL&&aux->vertice!=v2)
    {
        aux=aux->prox;
    }
    if(aux!=NULL)
        return 0;//aresta ja existe
    no* new_node = (no *) malloc(sizeof(no));
    if(new_node==NULL)
        return NULL;
    new_node->vertice=v2;
    new_node->peso=P;
    new_node->prox = g->aresta[v1];
    g->aresta[v1]=new_node;
    //atualiza campos do grafo
    g->qtde_arestas++;
    g->grau[v1]++;
    g->grau[v2]++;
    //FILE* grafinho = fopen(grafo,"a");
    //if(grafinho==NULL)
    //printf("erro\n");
    //fprintf(grafinho,"%d %d\n", v1, v2);
    //fclose(grafinho);
    return 1;
}
int verifica_aresta(grafo* g, int v1, int v2)
{
    if(g==NULL||v1<0||v2<0)
        return -1;
    //procura a aresta desejada
    no* aux = g->aresta[v1];
    while(aux!=NULL&&aux->vertice!=v2)
        aux=aux->prox;
    if(aux==NULL)
        return 0;//aresta nao existe
    else
        return 1;//aresta existe
}
int remove_aresta(grafo* g, int v1, int v2)
{
    if(g==NULL||v1<0||v2<0)
        return -1;
    //percorre a lista procurando a aresta
    no* aux = g->aresta[v1];
    no* ant = NULL;
    while(aux!=NULL&&aux->vertice!=v2)
    {
        ant = aux;
        aux=aux->prox;
    }
    if(aux==NULL)
        return 0; //aresta nao existe
    if(ant==NULL)
        g->aresta[v1] = aux->prox;
    else
        ant = aux->prox;
    free(aux);
    g->qtde_arestas--;
    g->grau[v1]--;
    g->grau[v2]--;
    return 1;
}

int consulta_aresta(grafo* g, int v1, int v2, int *P)
{
    if(g==NULL||v1<0||v2<0)
        return -1;
    no* aux = g->aresta[v1];
    while(aux!=NULL&&aux->vertice!=v2)
        aux=aux->prox;
    if(aux==NULL)
        return 0;//aresta nao existe
    else
    {
        *P=aux->peso;
        return 1;
    }
}
void libera_grafo(grafo** g)
{
    int i;
    no *aux=NULL, *aux2=NULL;
    grafo* gaux = *g;
    for(i=0; i<gaux->qtde_vertices; i++)
    {
        aux = gaux->aresta[i];
        while(aux!=NULL)
        {
            aux2=aux;
            aux=aux->prox;
            free(aux2);
        }
    }
    free(gaux->aresta);
    free(gaux->grau);
    free(gaux);
    *g = NULL;
}
void mostra_adjacentes(grafo* g, int v)
{
    no* aux = NULL;
    if(g==NULL||v<0)
        printf("This graph is inconsistant or the vertex giving is not a valid vertex.\n");
    else
    {
        aux=g->aresta[v];
        if(aux==NULL)
            printf("The vertice V=%d have not vertex adjacent.\n");
        else
        {
            while(aux!=NULL)
            {
                printf("%d->%d = %d \n", v,aux->vertice,aux->peso);
                aux=aux->prox;
            }
        }
    }
}
void mostra_grafo(grafo* g)
{
    int i;
    if(g==NULL)
        printf("Graph does not exists.\n");
    else if(g->qtde_arestas==0)
        printf("Empty graph.\n");
    else
    {
        for(i=0; i<g->qtde_vertices; i++)
        {
            printf("Vertice %d:\n", i);
            mostra_adjacentes(g,i);
        }
    }
}
void busca_profundidade(grafo* g, int V, int *visitado)
{
    int i;
    no* aux = g->aresta[V];
    visitado[V]=1;
    mostra_adjacentes(g,V);
    while(aux!=NULL)
    {
        if(visitado[aux->vertice]==0)
            busca_profundidade(g,aux->vertice, visitado);
        aux=aux->prox;
    }
}

void DFS(grafo* g, int V)
{
    visitado = (int *) malloc(g->qtde_vertices*sizeof(int));
    memset(visitado,(int)0, sizeof(int)*g->qtde_vertices);
    busca_profundidade(g,V,visitado);
}
