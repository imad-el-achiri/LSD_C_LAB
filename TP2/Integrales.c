#include<stdio.h>
#include<math.h>
double rectangle_gauche(double(*f)(double),double a,double b,int n){
    double I=0,h=(b-a)/n,x=a;
    for(int i=1;i<n+1;i++){
        I+=f(x);
        x+=h;
    }
    return(h*I);
}
double rectangle_droit(double(*f)(double),double a,double b,int n){
    double I=0,h=(b-a)/n,x=a;
    for(int i=0;i<n;i++){
        I+=f(x);
        x+=h;
    }
    return(h*I);
}
double trapeze(double(*f)(double),double a,double b,int n){
    double I=(f(a) + f(b))/2,h=(b-a)/n,x=a+h;
    for(int i=0;i<n-1;i++){
        I+=f(x);
        x+=h;
    }
    return(h*I);
}
double simpson(double(*f)(double),double a,double b,int n){
    double h=(b-a)/n,x=a+h,z=a+h/2,I1=0,I2=f(z);
    for(int i=0;i<n-1;i++){
        z+=h;
        I1+=f(x);
        I2+=f(z);
        x+=h;
    }
    return(h/6)*(f(a) + f(b) + 2*I1 + 4*I2);
}
//we don't have the equivalent of the quad function in c, so we have to calculate it manually, then pass it as an argument.
unsigned nombre_necessaire(double(*f)(double),double a,double b,double Err,double (*Methode)(double(*)(double),double,double,int),double true_integ){
    int n=1;
    while((Methode(exp,a,b,n)-true_integ)>Err || (Methode(exp,a,b,n)-true_integ)<-Err){
        n+=1;
    }
    return(n);
}
int main(){
    printf("%u\n",nombre_necessaire(exp,0,1,0.000000000000001,simpson,exp(1)-1));
}