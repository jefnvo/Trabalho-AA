#include <stdio.h>
#include <stdlib.h>
#include <math.h>

char * geraNome (char *tipo, int tam)
{
    char cam[100];
    char tamAux[10];
    char aux[50];

    strcpy(cam,"arranjos\\\\");

    itoa(tam,tamAux,10);

    if(tipo == "cresc")
        strcpy(aux, "crescente");

    if(tipo == "decre")
        strcpy(aux, "decrescente");

    if(tipo == "aleat")
        strcpy(aux, "aleatorio");

    if(tipo == "parci")
        strcpy(aux, "parcialmente");

    strcat(aux, tamAux);
    strcat(aux,".txt");
    strcat(cam, aux);
    return cam;
}

int i = 0;

void geraVetoresCresc (FILE *arq, int tam)
{
    char cam[150];
    strcpy(cam, geraNome("cresc", tam));

    arq = fopen(cam,"w");

    for (i=0; i<=tam; i++)
    {
        fprintf(arq, "%d \n", i);
    }

    fclose(arq);
}

void geraVetoresDecre (FILE *arq, int tam)
{
    char cam[150];
    strcpy(cam, geraNome("decre", tam));

    arq = fopen(cam,"w");

    for (i=tam; i>=0; i--)
    {
        fprintf(arq, "%d \n", i);
    }

    fclose(arq);
}

void geraVetoresAleat (FILE *arq, int tam)
{
    char cam[150];
    strcpy(cam, geraNome("aleat", tam));

    arq = fopen(cam,"w");

    for (i=0; i<=tam; i++)
    {
        fprintf(arq, "%d \n", rand()%1000);
    }

    fclose(arq);
}

void geraVetoresParci (FILE *arq, int tam, float porc)
{
    char cam[150];

    strcpy(cam, geraNome("parci", tam));

    arq = fopen(cam,"w");

    for (i=0; i<=((int)(tam * porc)); i++)
    {
        fprintf(arq, "%d \n", i);
    }

    for (i=0; i<=((int)(tam - (tam * porc))); i++)
    {
        fprintf(arq, "%d \n", rand()%1000);
    }

    fclose(arq);
}


int main()
{
    int k;
    srand((unsigned)time(NULL));
    FILE *arq;

    for (k=2; k<=13; k++)
    {
        int tam  = pow(2,k);

        geraVetoresCresc(arq,tam);
        geraVetoresDecre(arq,tam);
        geraVetoresAleat(arq,tam);
        geraVetoresParci(arq,tam,0.9);
    }

    return 0;
}
