#include "tempos.h"

uint64_t soma;

void le_ordena_grava_tempo (void funcao(int *arr, int size), FILE *tempos, FILE *reader)
{
    int size, *vet, i;

    char nome[80];

    clock_t tempo;
    double time_taken;

    while(!feof(reader))
    {
        fscanf(reader, "%s\n", &nome);
        size = 0;
        soma = 0.0;

        for (i=0; i<NUM_EXECS; i++)
        {
            vet = preenche_vetor(nome, &size);
            CRONOMETRA1(funcao, vet, size);
            soma += tempo_de_cpu;
        }

        fprintf(tempos, "%d \t %llu\n",(size-1), (long long unsigned int) (soma / (uint64_t) NUM_EXECS));
    }
}

