#include<stdio.h>
#include<stdlib.h>

//funciones de la libreria tabla
void imprimirFinLinea(int caso);
void imprimirLinea(int caso, int iteraciones, int cantidad, int casoFin);
void imprimirLineaCelda(int caso, int cantidad);
void imprimirHeader(char texto[]);
void imprimirCelda(double dato);
void imprimirNumeral(int iteraciones);
void imprimirNumero(int iteraciones, int iteracion);
void imprimirLineaNumero(int caso, int iteraciones);

//Funciones propias de main
void imprimirResultados(int iteraciones,int iteracion,double x1, double fx1, double fdx1);
double funcion(double x);
double funcionDerivada(double x);

int main(){
    double x1,fx1,fdx1;
    int iteraciones,i,encontrado = 0;

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

        if(fdx1 == 0){
            encontrado = 1;
            break;
        }
        x1 = (x1-(fx1/fdx1));
    }
    if(encontrado == 1){
        printf("La raiz es: %.100lf\n",x1);

    }else {
        printf("La mejor representacion de la raiz es: %.100lf\n",x1);
    }
    return 0;
}

//funcion a evaluar. instertar manualmente
double funcion(double x){
    return (pow(x,3))+(pow(x,2))-4*x-2;
}

//derivada de la funcion
double funcionDerivada(double x){
    return (3*pow(x,2))+(2*x)-4;
}

//seccion de impresion de la tabla
void imprimirResultados(int iteraciones,int iteracion,double x1, double fx1, double fdx1){
    imprimirNumero(iteraciones, iteracion);

    //impresion de celda con valores de la iteracion
    //imprimirCelda(<valor>);
    imprimirCelda(x1);
    imprimirCelda(fx1);
    imprimirCelda(fdx1);

    imprimirFinLinea(3);
    imprimirLinea(1,iteraciones,3,3);
}

void imprimirCabecera(int iteraciones){
    imprimirLinea(2,iteraciones,3,2);
    imprimirNumeral(iteraciones);

    //Impresion de cabeceras
    //imprimirHeader("<texto deseado para la cabecera>");
    imprimirHeader("x1");
    imprimirHeader("f(x1)");
    imprimirHeader("f'(x)");

    imprimirFinLinea(3);
    imprimirLinea(1, iteraciones, 3,1);
}
