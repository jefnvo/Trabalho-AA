#include "algoritmos.h"

int max(int a, int b)
{
    if(a>=b)
        return a;
    else return b;
}


//corte haste
int corteHaste(int *p, int n)
{
    if(n<=0) return 0;
    int i;
    int q = INT_MIN;
    for(i=0;i<n;i++)
    {
        q = max(q, p[i]+corteHaste(p, n-i-1));
    }
    return q;
}

//corte haste memoizado
int corteHasteMemoizado(int *p, int n)
{
    int i, r[n];
    for(i=0;i<n;i++)
    {
        r[i] = INT_MIN;
//        printf("%d  ", r[i]);
    }
    return corteHasteMemoizadoAux(p,n,r);
}

int corteHasteMemoizadoAux(int *p, int n, int *r)
{
    if(r[n-1]>=0) return r[n-1];
    int i;
    int q = INT_MIN;
    for(i=0;i<n;i++)
    {
        q = max(q, p[i]+corteHaste(p, n-i-1));
        r[n] = q;
//        printf("%d ", r[n]);
    }
    return q;
}

int corteBottomUp(int *p, int n)
{
    int r[n], i, j, q;
    r[0] = 0;
    for(j=1; j<=n; j++)
    {
        q = INT_MIN;
        for(i=1;i<=j;i++)
        {
            q = max(q, p[i-1]+r[j-i-1]);
//            printf("%d  ", q);
        }
        r[j-1]=q;
    }
    return r[n-1];
}
