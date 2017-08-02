#include "leitura.h"

char *insere_caminho (char *nome)
{
    char caminho[] = "arranjos/";
    int tam = (strlen(nome) + strlen(caminho))+1;
    char *caminho_completo = malloc(sizeof(char)*(tam));

    snprintf(caminho_completo, (tam), "%s%s", caminho, nome);

    return caminho_completo;
}

int array_size (FILE *arq)
{
    int count = 0;
    int aux = 0;

    while(!feof(arq))
    {
        fscanf(arq, "%d\n", &aux);
        count++;
    }

    return count;
}

int *preenche_vetor (char *nome, int *size)
{
    FILE *reader = fopen(insere_caminho(nome), "r");
    int tam = array_size(reader);
    fclose(reader);

    reader = fopen(insere_caminho(nome), "r");

    int *arr = calloc(tam,sizeof(int));

    int i;

    for(i=0; i<tam; i++)
        fscanf(reader, "%d\n", &arr[i]);

    fclose(reader);

    *size = tam;

    return arr;
}
