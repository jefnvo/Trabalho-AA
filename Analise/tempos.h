#include <stdint.h>
#include <time.h>

#include "algoritmos.h"
#include "leitura.h"

#define BILHAO 1000000000L
#define NUM_EXECS 5

#define CRONOMETRA1(funcao,vetor, tam) {                                                \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &inicio);                                    \
   funcao(vetor,tam);                                                                   \
   clock_gettime(CLOCK_PROCESS_CPUTIME_ID, &fim);                                       \
   tempo_de_cpu = BILHAO * (fim.tv_sec - inicio.tv_sec) + fim.tv_nsec - inicio.tv_nsec; \
   }


struct timespec inicio, fim;
uint64_t tempo_de_cpu;

void le_ordena_grava_tempo (void funcao_ordenacao(int *arr, int tam), FILE *tempos, FILE *reader);
