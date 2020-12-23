#include <stdlib.h>
#include <stdio.h>
#define N 10

long double *remontee(long double A[N][N], long double * B, int n)
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
long double *descente_LU(long double A[N][N], long double * B, int n)
{
  long double   *x;
  x = malloc(sizeof(long double) * n);
  x[0]=B[0];
    for(int i=1;i<n;++i){
        x[i]=B[i];
        for(int j=0;j<i;++j){
            x[i]-=A[i][j]*x[j];
        }
    }
  return (x);
}
/*long double ** Identite(int n){
    long double ** I=malloc(n*sizeof(long double *));
    for(int i=0;i<n;i++){
        I[i]=malloc(n*sizeof(long double));
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            i==j ? I[i][j]=1 : I[i][j]=0;
        }
    }
    return(I);
}*/
long double *lu(long double A[N][N], long double B[N], int n)
{
    long double L[N][N];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            L[i][j]=(i==j) ? 1 : 0;
        }
    }
    for(int k=0;k<n-1;k++){
        for(int i=k+1;i<n;i++){
            L[i][k]=A[i][k]/A[k][k];
            for(int j=k;j<n;j++){
                A[i][j]=A[i][j] - L[i][k]*A[k][j];
            }
        }
    }
    long double *x1=malloc(n*sizeof(long double)),*x2=malloc(n*sizeof(long double));
    x1=descente_LU(L,B,n);
    x2=remontee(A,x1,n);
    return (x2);
}

int main()
{
  long double   A[N][N], B[N];
  long double   *x;
  int     n;

  printf("Enter the size of the matrix: ");
  scanf("%d", &n);
  x=malloc(n*sizeof(long double));
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
  x = lu(A, B, n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%Lf%c", x[i], ",]"[i == n - 1]);
}
