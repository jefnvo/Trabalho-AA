#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#include <values.h>

int corteHaste(int *p, int n);
int corteHasteMemoizado(int *p, int n);
int corteBottomUp(int *p, int n);
int MatrixChainOrder(int *p, int n );
int scm(int *X, int *Y, int m, int n );
void seltorIterativo(int *s, int *f, int n );
void seletorRecursivo (int *s, int *f, int i, int j, int *a);
int mochilaBooleana (int *wt, int* val, int n, int w );
int mochilaFracionaria ( int w, int *wt, int* val, int n );
