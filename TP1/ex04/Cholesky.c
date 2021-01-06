#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long double * descente(long double * A,long double * B, int n){
    long double * X=malloc(n*sizeof(long double));
    X[0]=B[0]/A[0];
    for(int i=1;i<n;++i){
        X[i]=B[i];
        for(int j=0;j<i;++j){
            X[i]-=A[n*i+j]*X[j];
        }
        X[i]/=A[n*i+i];
    }
    return X;
}
long double * remontee(long double * A,long double * B, int n){
    long double * X=malloc(n*sizeof(long double));
    X[n-1]=B[n-1]/A[(n-1)*n + n-1];
    for(int i=n-2;i!=-1;--i){
        X[i]=B[i];
        for(int j=i+1;j<n;++j){
            X[i]-=A[n*i+j]*X[j];
        }
        X[i]/=A[n*i+i];
    }
    return X;
}
long double * Cholesky(long double * A,long double * B,int n){
    long double C[n*n],CT[n*n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            C[i*n+j]=(i==j) ? 1 : 0;
            CT[i*n+j]=(i==j) ? 1 : 0;
            
        }
    }
    long double sum;
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            if(i==j){
                sum=0;
                for(int k=0;k<i;k++){
                    sum+=C[i*n+k]*C[i*n+k];
                }
                C[i*n+i]=sqrt(A[i*n+i]-sum);
            }
            else{
                sum=0;
                for(int k=0;k<j;k++){
                    sum+=C[i*n+k]*C[j*n+k];
                }
                C[i*n+j]=A[i*n+j]-sum;
                C[i*n+j]/=C[j*n+j];
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<i+1;j++){
            CT[j*n+i]=C[i*n+j];
        }
    }
    long double *x1=malloc(n*sizeof(long double)),*x2=malloc(n*sizeof(long double));
    x1=descente(C,B,n);
    x2=remontee(CT,x1,n);
    return x2;
}
int main()
{
  int     n;
  printf("Enter the size of the matrix: ");
  scanf("%d", &n);
  long double *x=malloc(n*sizeof(long double));
  /*
  printf("Filling the matrix A\n");
  for(int i = 0; i < n; i++)
  {
    for(int j = 0; j < n; j++)
    {
      printf("A[%d][%d] = ", i, j);
      scanf("%Lf", &A[i*n+j]);
    }
  }

  printf("Filling the matrix B\n");
  for (int i = 0; i < n; i++)
  {
    printf("B[%d] = ", i);
    scanf("%Lf", &B[i]);
  }*/
    long double A[16]={4,-6,8,2,
    -6,10,-15,-3,
     8,-15,26,-1,
     2,-3,-1,62};
    long double B[4]={-6,6,-1,-13};
  /* The calculation of the result */
  x = Cholesky(A,B,n);

  /* Printing the results */
  printf("\nThe resulting vector: [");
  for (int i = 0; i < n; i++)
    printf("%Lf%c", x[i], ",]"[i == n - 1]);
  return (0);
}