#include <stdio.h>
#include <stdlib.h>
#define N 10

long double *remontee(long double A[N][N], long double B[N], int n)
{
  long double * x=malloc(n*sizeof(long double));
  x[n-1]=B[n-1]/A[n-1][n-1];
    for(int i=n-2;i!=-1;--i){
        x[i]=B[i];
        for(int j=i+1;j<n;++j){
            x[i]-=A[i][j]*x[j];
        }
        x[i]/=A[i][i];
    }
  
  return x;
}

int main()
{
  long double   A[N][N], B[N];
  long double   *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);

  /* Filling the matrix A */
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%Lf", &A[i][j]);
    }
  }

  /* Filling the vector B*/
  printf("Filling the vector B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%Lf", &B[i]);
  }

  /* The calculation of the result */
  x = remontee(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%Lf%c", x[i], ",]"[i == n - 1]);
}
