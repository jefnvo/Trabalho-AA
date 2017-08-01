#include "grafos.h"
int main()
{
    FILE* arq = fopen("nomes.txt", "r");
    if(arq == NULL){
        printf("Erro ao abrir arquivo\n");
        exit(1);
    }
    Grafo g;
    int *arranjo, i=0, pot=8,n,x,y, pot1, arestas;
    char nomes[100];

    while(!feof(arq)){
        fscanf(arq, "%s \n", nomes);
        //printf("Este eh o nome %s\n", nomes);
        FILE* vetor = fopen(nomes, "r");

        n = pow(2, pot);
        arranjo = (int *) calloc(n,sizeof(int));
        while(!feof(vetor)){
            fscanf(vetor, "%d ", &arranjo[i]);
            i++;

        }
        srand(time(NULL));
        pot1 = pot+1;
        arestas = pow(2,pot1);
        printf("Arestas sao %d\n", arestas);
        FGVazio(&g, n,arestas);

        for (i=0;i<arestas;i++){
            x = rand()%n;
            y = rand()%n;
            while(g.matriz[x][y]==1 || g.matriz[y][x]==1){
                x = rand()%n;
                y = rand()%n;
            }
            InsereAresta(x,y,&g);

        }
        printf("%s\n", nomes);
        ImprimeGrafo(&g, nomes);
        LiberaGrafo(&g);
        free(arranjo);
        fclose(vetor);
        i=0;
        pot++;
    }

    fclose(arq);
    return 0;
}
