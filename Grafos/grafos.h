/*-- 10/mai/2003 --*/

#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#include<time.h>
#include<string.h>

#define MAXNUMVERTICES  100
#define MAXNUMARESTAS   4500
#define TRUE  1
#define FALSE 0
#define MAX 131072
typedef int  TipoPeso;
typedef struct{
    int **matriz;
    int NumVertices;
    int NumArestas;
} Grafo;
typedef int  TipoApontador;

TipoApontador Aux;
int i;
int V1, V2, Adj;
TipoPeso Peso;
int NVertices;
short NArestas;
short FimListaAdj;


