

void swap (int *arr, int a, int b)
{
    int tmp = arr[a];
    arr[a] = arr[b];
    arr[b] = tmp;
}

/////////////////
//  COUTING   //
///////////////


void countingsort(int *vetor, int size)
{
    int i, maior=0;
    for(i=0; i<size; i++)
    {
        if(vetor[i]>maior)
            maior=vetor[i];
    }
    int B[size], C[maior+1];

    for(i = 0; i < maior+1; i++)
        C[i] = 0;

    for(i =0; i < size; i++)
        C[vetor[i]] = C[vetor[i]] + 1;

    for(i = 1; i < maior+1; i++)
        C[i] = C[i] + C[i-1];

    for(i = size-1; i >= 0; i--)
    {
        B[C[vetor[i]]-1] = vetor[i];
        C[vetor[i]] = C[vetor[i]] - 1;
    }
}


//////////////
//  HEAP   //
////////////

void heapify(int *arr, int i, int tam)
{
    int esq = i*2+1;
    int dir = esq++;
    int maior;

    if (esq <= tam && arr[esq] > arr[i])
        maior = esq;

    else
        maior = i;

    if (dir <= tam && arr[dir] > arr[maior])
        maior = dir;

    if (maior != i)
    {
        swap(arr, i, maior);
        heapify(arr, maior, tam);
    }
}

void heapsort(int *arr, int tam)
{
    int i;

    for (i = ceil(tam / 2); i >= 0; i--)
        heapify(arr, i, tam);

    for (i = tam; i > 0; i--)
    {
        swap(arr, 0, i);
        tam--;
        heapify(arr, 0, tam);
    }
}


///////////////////
//  INSERTION   //
/////////////////


void insertionSort(int vetor[], int tamVetor)
{
    int i, j, atual;
    for(i=1; i<tamVetor; i++)
    {
        atual = vetor[i];
        j=i-1;

        while((j>=0)&&(atual < vetor[j]))
        {
            vetor[j+1] = vetor[j];
            j=j-1;
        }
        vetor[j+1]=atual;
    }
}

///////////////
//  QUICK   //
/////////////

void quicksort (int *vet, int tam)
{
    quick(vet, 0, tam);
}

void quick (int *vet, int esq, int dir)
{
    int pivo;
    if (esq < dir)
    {
        pivo = particiona(vet, esq, dir);
        quick(vet, esq, pivo-1);
        quick(vet, pivo+1, dir);
    }
}

int particiona (int *vet, int esq, int dir)
{
    int i;
    int pivo = esq;

    for (i = esq+1; i <= dir; i++)
    {
        if (vet[i] < vet[esq])
        {
            pivo++;
            if (i != pivo)
                swap(vet, i, pivo);
        }
    }

    swap(vet, esq, pivo);

    return pivo;
}



///////////////
//  RADIX   //
/////////////

int getMax(int vetor[], int tamVetor)
{
    int max = vetor[0], i;
    for(i=1; i<tamVetor; i++)
    {
        if(vetor[i]>max)
        {
            max=vetor[i];
        }
    }
    return max;
}

void coutingsort_radix(int vetor[], int tamVetor, int exp)
{
    int saida[tamVetor]; //vetor de saída
    int i, count[10] = {0};

    for(i=0; i<tamVetor; i++)
        count[(vetor[i]/exp)%10]++;

    for(i=1; i<10; i++)
        count[i]+=count[i-1];

    for(i=tamVetor-1; i>=0; i--)
    {
        saida[count[(vetor[i]/exp)%10]-1]=vetor[i];
        count[(vetor[i]/exp)%10]--;
    }

    for(i=0; i<tamVetor; i++)
        vetor[i]=saida[i];
}

void radixSort(int vetor[], int tamVetor)
{
    int m = getMax(vetor, tamVetor), exp;
    for(exp=1; m/exp>0; exp*=10)
        coutingsort_radix(vetor, tamVetor, exp);
}


///////////////
//  MERGE   //
/////////////

void mergesort(int *arr, int tam)
{
    mergesort1(arr, 0, tam);
}

void mergesort1(int *arr, int p, int r)
{
    if(p<r-1)
    {
        int q = (p+r)/2;
        mergesort1(arr, p, q);
        mergesort1(arr, q, r);
        merge(arr, p, q, r);
    }
}
void merge(int *arr, int p, int q, int r)
{
    int i, j, k, *w;
    w = (int *) malloc((r-p)*sizeof(int));
    i=p;
    j=q;
    k=0;

    while(i<q && j<r)
    {
        if(arr[i]<=arr[j])
            w[k++]=arr[i++];

        else
            w[k++] = arr[j++];
    }

    while(i<q)
        w[k++]=arr[i++];

    while(j<r)
        w[k++]=arr[j++];

    for(i=p; i<r; ++i)
        arr[i]=w[i-p];

    free(w);
}
