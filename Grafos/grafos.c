#include "grafos.h"
void FGVazio(Grafo *g,int vertices, int arestas){
    int i,j;
    g->matriz = (int **) calloc(vertices, sizeof(int*));
    g->NumVertices = vertices;
    g->NumArestas = arestas;
    for(i=0;i<vertices;i++){
        g->matriz[i] = (int *) calloc(vertices, sizeof(int));
        for(j=0;j<vertices;j++){
            g->matriz[i][j] = 0;
        }
    }
    printf("Tudo certo\n");
}
void InsereAresta(int V1, int V2, Grafo *Grafo)
{
    Grafo->matriz[V1][V2] = 1;
}

short ExisteAresta(int Vertice1,
                   int Vertice2, Grafo *Grafo)
{
    return (Grafo->matriz[Vertice1][Vertice2] > 0);
}

/* Operadores para obter a lista de adjacentes */
short ListaAdjVazia(int *Vertice, Grafo *Grafo)
{
    TipoApontador Aux = 0;
    short ListaVazia = TRUE;
    while (Aux < Grafo->NumVertices && ListaVazia)
    {
        if (Grafo->matriz[*Vertice][Aux] > 0)
            ListaVazia = FALSE;
        else Aux++;
    }
    return (ListaVazia == TRUE);
}

TipoApontador PrimeiroListaAdj(int *Vertice,
                               Grafo *Grafo)
{
    int Result;
    TipoApontador Aux = 0;
    short ListaVazia = TRUE;
    while (Aux < Grafo->NumVertices && ListaVazia)
    {
        if (Grafo->matriz[*Vertice][Aux] > 0)
        {
            Result = Aux;
            ListaVazia = FALSE;
        }
        else Aux++;
    }
    if (Aux == Grafo->NumVertices)
        printf("Erro: Lista adjacencia vazia (PrimeiroListaAdj)\n");
    return Result;
}

void ProxAdj(int *Vertice, Grafo *Grafo,
             int *Adj, TipoPeso *Peso,
             TipoApontador *Prox, short *FimListaAdj)
{
    /* Retorna Adj apontado por Prox */
    *Adj = *Prox;
    *Peso = Grafo->matriz[*Vertice][*Prox];
    (*Prox)++;
    while (*Prox < Grafo->NumVertices &&
            Grafo->matriz[*Vertice][*Prox] == 0) (*Prox)++;
    if (*Prox == Grafo->NumVertices)
        *FimListaAdj = TRUE;
}

void RetiraAresta(int *V1, int *V2,
                  TipoPeso *Peso, Grafo *Grafo)
{
    if (Grafo->matriz[*V1][*V2] == 0)
        printf("Aresta nao existe\n");
    else
    {
        *Peso = Grafo->matriz[*V1][*V2];
        Grafo->matriz[*V1][*V2] = 0;
    }
}

void LiberaGrafo(Grafo *g){
    int i, j;
    for(i=0;i<g->NumVertices;i++)
        free(g->matriz[i]);
    free(g->matriz);
    printf("Liberado\n");

}

void ImprimeGrafo(Grafo *Grafo, char nomes[])
{
    int i, j;
    char prefixo[100]="Matriz";
    strcat(prefixo, nomes);

    printf("Temos %d vertices \n", Grafo->NumVertices);
    //getchar();

    FILE* matriz = fopen(prefixo, "w");
    if(matriz == NULL)
        exit(1);
    for (i = 0; i <  Grafo->NumVertices; i++){
        for (j = 0; j <Grafo->NumVertices; j++)
            fprintf(matriz,"%d\t", Grafo->matriz[i][j]);
        fprintf(matriz,"\n");
    }
    fclose(matriz);
}

//void GrafoTransposto(Grafo *g, Grafo *gt)
//{
//    int v, Adj;
//    TipoPeso Peso;
//    TipoApontador Aux;
//    FGVazio(gt);
//    gt->NumVertices = g->NumVertices;
//    gt->NumArestas = g->NumArestas;
//    for (v = 0; v <= g->NumVertices - 1; v++)
//    {
//        if (!ListaAdjVazia(&v, g))
//        {
//            Aux = PrimeiroListaAdj(&v, g);
//            FimListaAdj = FALSE;
//            while (!FimListaAdj)
//            {
//                ProxAdj(&v, g, &Adj, &Peso, &Aux, &FimListaAdj);
//                InsereAresta(&Adj, &v, &Peso, gt);
//            }
//        }
//    }
//}  /* GrafoTransposto */
