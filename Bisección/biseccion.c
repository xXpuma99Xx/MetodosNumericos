#include<stdio.h>

double funcion(double x){
    return (((x+1)*x-4)*x-1);
}

void obtenerP(double a, double b, double *p){
    *p = (a + b)/2;
}

void imprimirHeader(){
    printf("___________________________________________________________________________________________________________________\n");
    printf("|        a         |        b         |       f(a)       |       f(b)       |        p         |       f(p)       |\n");
    printf("-------------------+------------------+------------------+------------------+------------------+-------------------\n");
}

void celda(double dato){
    if(dato < 0){
        if(dato > -10){
            printf("|  %.13lf",dato);
        }else if(dato > -100){
            printf("| %.13lf",dato);
        }else {
            printf("|%.13lf",dato);
        }
    }else{
        if(dato < 10){
            printf("|   %.13lf",dato);
        }else if(dato < 100){
            printf("|  %.13lf",dato);
        }else {
            printf("| %.13lf",dato);
        }
    }
}

void imprimirResultados(double a, double b, double p, double fA, double fB, double fP){
    celda(a);
    celda(b);
    celda(fA);
    celda(fB);
    celda(p);
    celda(fP);
    printf("|\n-------------------+------------------+------------------+------------------+------------------+-------------------\n");
}

void cambioAB(double *a, double *b, double p, double *fA, double *fB, double fP){
    if((*fA*fP) < 0){
        *b = p;
        *fB = fP;
    }else if((*fB*fP) < 0){
        *a = p;
        *fA = fP;
    }
}

int main(){
    double a = 1, b = 2, p, fA, fB, fP;
    int i;
  
    fA = funcion(a);
    fB = funcion(b);

    imprimirHeader();

    for(i = 0;i < 50;i++){
        obtenerP(a,b,&p);
        fP = funcion(p);

        imprimirResultados(a,b,p,fA,fB,fP);
        cambioAB(&a,&b,p,&fA,&fB,fP);
    }

    return 0;
}