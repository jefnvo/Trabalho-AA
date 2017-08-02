#include "grafos.h"
int main()
{
    grafo* g;
    int pot=8,i,n,x,y;
    char nome[100];
    FILE* string = fopen("nomes.txt", "r");
    while(!feof(string)){
        fscanf(string,"%s ", nome);
        printf("%s\n",nome);
        FILE* grafo = fopen(nome,"r");
        n = pow(2,pot);
        g=cria_grafo(n);
        for(i=0;i<2*n;i++){
            fscanf(grafo, "%d %d", &x,&y);
            insere_aresta(g,x,y,1);
            //printf("alo\n");
        }
        pot++;
        fclose(grafo);
        libera_grafo(&g);
    }
    fclose(string);
    return 0;
}
