#include<stdio.h>
#include<stdlib.h>

void imprimirFinLinea(int caso);
void imprimirLinea(int caso, int cantidad);
void imprimirHeader(char texto[]);
void imprimirCelda(double dato);
void imprimirNumeral(int iteraciones);
void imprimirNumero(int iteraciones, int iteracion);
void imprimirLineaNumero(int caso, int iteraciones);
void imprimirCabecera(int iteraciones);
double funcion(double x);
double funcionDerivada(double x);

int main(){
    double x1,fx1,fdx1;
    int iteraciones,i;

    printf("Cuantas iteraciones quieres? ");
    scanf("%i",&iteraciones);

    printf("Parametro inicial x1: ");
    scanf("%lf",&x1);
    system("cls");

    imprimirCabecera(iteraciones);

    for(i = 1;i <= iteraciones;i++){
        fx1 = funcion(x1);
        fdx1 = funcionDerivada(x1);

        imprimirResultados(iteraciones,i,x1,fx1,fdx1);

        x1 = (x1-(fx1/fdx1));
    }
    return 0;
}

//funcion a evaluar. instertar manualmente
double funcion(double x){
    return (pow(x,3))+(pow(x,2))-4*x-1;
}

//derivada de la funcion
double funcionDerivada(double x){
    return (3*pow(x,2))+(2*x)-4;
}

void imprimirResultados(int iteraciones,int iteracion,double x1, double fx1, double fdx1){
    imprimirNumero(iteraciones, iteracion);

    imprimirCelda(x1);
    imprimirCelda(fx1);
    imprimirCelda(fdx1);

    imprimirFinLinea(3);

    imprimirLineaNumero(1,iteraciones);
    imprimirLinea(1,3);
    imprimirFinLinea(3);
}

void imprimirCabecera(int iteraciones){
    imprimirLineaNumero(2,iteraciones);
    imprimirLinea(2,3);//segundo parametro indica cuantas cabeceras debe haber
    imprimirFinLinea(2);

    imprimirNumeral(iteraciones);

    /*Parte que debe dar manualmente el programador para impirmir sus cabeceras*/
    imprimirHeader("x1");
    imprimirHeader("f(x1)");
    imprimirHeader("f'(x)");

    imprimirFinLinea(3);

    imprimirLineaNumero(1,iteraciones);
    imprimirLinea(1,3);
    imprimirFinLinea(1);
}
