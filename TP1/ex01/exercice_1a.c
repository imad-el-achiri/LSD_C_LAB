#include <stdio.h>
#include <stdlib.h>
#define N 10


long double *descente(long double A[N][N], long double B[N], int n)
{
  long double   *x;
  x = malloc(sizeof(long double) * n);
  x[0]=B[0]/A[0][0];
    for(int i=1;i<n;++i){
        x[i]=B[i];
        for(int j=0;j<i;++j){
            x[i]-=A[i][j]*x[j];
        }
        x[i]/=A[i][i];
    }
  return (x);
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
  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%Lf", &B[i]);
  }

  /* The calculation of the result */
  x = descente(A, B, n);
  
  /* Printing the results */
  printf("\nThe resulting vector : [");
  for (int i = 0; i < n; i++)
    printf("%Lf%c", x[i], ",]"[i == n - 1]);
}
