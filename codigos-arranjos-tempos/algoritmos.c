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
    for(i=0; i<n; i++)
    {
        q = max(q, p[i]+corteHaste(p, n-i-1));
    }
    return q;
}

//corte haste memoizado
int corteHasteMemoizado(int *p, int n)
{
    int i, r[n];
    for(i=0; i<n; i++)
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
    for(i=0; i<n; i++)
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
        for(i=1; i<=j; i++)
        {
            q = max(q, p[i-1]+r[j-i-1]);
//            printf("%d  ", q);
        }
        r[j-1]=q;
    }
    return r[n-1];
}



int MatrixChainOrder ( int p [], int n )
{
    int ** m, i, j, k, L, q ;;
    m = ( int *) malloc ( n * sizeof ( int ) ) ;
    for ( i =0; i < n ; i ++)
    {
        m [ i ] = ( int *) malloc ( n * sizeof ( int ) ) ;
    }

    for ( i =1; i < n ; i ++)
        m [ i ][ i ] = 0;

    for ( L =2; L < n ; L ++)
    {
        for ( i =1; i <n - L +1; i ++)
        {
            j = i +L -1;
            m [ i ][ j ] = INT_MAX ;
            for ( k = i ; k <= j -1; k ++)
            {
                q = m [ i ][ k ] + m [ k +1][ j ] + p [i -1]* p [ k ]* p [ j ];
                if ( q < m [ i ][ j ])
                    m [ i ][ j ] = q ;
            }
        }
    }
    return m [1][ n -1];
}


int scm ( int *X, int *Y, int m, int n )
{
    if ( m == 0 || n == 0)
        return 0;

    if ( X [m -1] == Y [n -1])
        return 1 + scm (X, Y, m -1, n -1) ;

    else

        return max ( scm (X, Y, m, n -1), scm (X, Y, m -1, n ) ) ;

}


void seltorIterativo ( int s [], int f [], int n )
{
    int i, j ;
// printf (" Selected Activities are :\ n ") ;
    i = 1;
// printf (" A % d " , i ) ;
    for ( j = 1; j < n ; j ++)
    {
        if ( s [ j ] >= f [ i ])
        {
// printf (" A % d " , j +1) ;
            i = j;
        }
    }
}

void seletorRecursivo ( int s [], int f [], int i, int j, int a [])
{
    int m = i + 1;
    while ( m < j && s [ m ] < f [ i ])
    {
        m = m + 1;
    }
    if ( m < j )
    {
        a [ m ] = 1;
        seletorRecursivo (s,f,m,j, a ) ;
    }
}

int mochilaBooleana (int *wt, int* val, int n, int w )
{
    int i, j, a, b, * mm, ** m, * s ;
    mm = calloc (( n + 1) * ( w + 1), sizeof ( int ) ) ;
    m = malloc (( n + 1) * sizeof ( int *) ) ;
    m [0] = mm ;
    for ( i = 1; i <= n ; i ++)
    {
        m [ i ] = & mm [ i * ( w + 1) ];
        for ( j = 0; j <= w ; j ++)
        {
            if ( items [ i - 1]. weight > j )
                m [ i ][ j ] = m [ i - 1][ j ];

            else
            {
                a = m [ i - 1][ j ];
                b = m [ i - 1][ j - items [ i - 1]. weight ] + items [ i - 1]. value ;
                m [ i ][ j ] = a > b ? a : b ;
            }

        }
    }
    s = calloc (n, sizeof ( int ) ) ;
    for ( i = n, j = w ; i > 0; i - -)
    {
        if ( m [ i ][ j ] > m [ i - 1][ j ])
        {
            s [ i - 1] = 1;
            j -= items [ i - 1]. weight ;
        }
    }
    free ( mm ) ;
    free ( m ) ;
    return s ;

}

int mochilaFracionaria ( int w, int *wt, int* val, int n )
{
    if ( n == 0 || W == 0)
        return 0;

    if ( wt [n -1] > W )
        return MochilaFracionaria (W, wt, val, n -1) ;

    else return max ( val [n -1] + MochilaFracionaria (W - wt [n -1], wt, val, n -1),
                          MochilaFracionaria (W, wt, val, n -1 ) ) ;

}












