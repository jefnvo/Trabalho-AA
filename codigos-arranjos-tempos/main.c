#include "ordenacoes.h"
#include "algoritmos.h"

int main()
{
    FILE *reader = fopen(NOMES, "r");
    FILE *tempos;

    int op;

    do
    {
        printf("1 - corte haste\n");
        printf("2 - corte haste memoizado\n");
        printf("3 - corte haste bottom up\n");
        printf("4 - \n");
        printf("5 - Seletor guloso de atividades\n");
        printf("6 - Seletor guloso de atividades recursivo\n");
        printf("7 - Arvore Huffman\n");
        printf("6 - Seletor guloso de atividades recursivo\n");
        printf("0 - sair\n\n");

        fflush(stdin);
        scanf("%d", &op);

        switch (op)
        {
        case 1:
            tempos = fopen("tempos/corteHaste.txt", "w");
            le_ordena_grava_tempo(corteHaste,tempos,reader);
            rewind(reader);
            break;

        case 2:
            tempos = fopen("tempos/corteHasteMemoizado.txt", "w");
            le_ordena_grava_tempo(corteHasteMemoizado, tempos,reader);
            rewind(reader);
            break;

        case 3:
            tempos = fopen("tempos/corteHasteBottomUp.txt", "w");
            le_ordena_grava_tempo(corteBottomUp, tempos,reader);
            rewind(reader);
            break;

        case 4:
            tempos = fopen("tempos/radixsort.txt", "w");
//            le_ordena_grava_tempo(radixSort, tempos, reader);
            rewind(reader);
            break;

        case 5:
            tempos = fopen("tempos/seletorGuloso.txt", "w");
            le_ordena_grava_tempo(corteBottomUp, tempos,reader);
            rewind(reader);
            break;

        case 6:
            tempos = fopen("tempos/seletorGulosoRecursivo.txt", "w");
            le_ordena_grava_tempo(corteBottomUp, tempos,reader);
            rewind(reader);
            break;

        case 7:
            tempos = fopen("tempos/huffmanTree.txt", "w");
            le_ordena_grava_tempo(corteBottomUp, tempos,reader);
            rewind(reader);
            break;
        }
    }
    while (op != 0);

    fclose(reader);
    fclose(tempos);

    return 0;
}
