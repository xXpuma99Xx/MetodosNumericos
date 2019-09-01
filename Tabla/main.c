#include<stdio.h>
#include<stdlib.h>

//funciones de la libreria tabla
void imprimirFinLinea(int caso);
void imprimirLinea(int caso, int cantidad);
void imprimirHeader(char texto[]);
void imprimirCelda(double dato);
void imprimirNumeral(int iteraciones);
void imprimirNumero(int iteraciones, int iteracion);
void imprimirLineaNumero(int caso, int iteraciones);

//Funciones propias de main
void imprimirResultados(int iteraciones,int iteracion/*, <demas parametros a imprimir*/);
double funcion(double x);

int main(){
    //variables de los datos
    //double ;
    //iteraciones = iterariones a realizer      i = iterarodr
    int iteraciones,i;

    //Iteraciones que el usuario desea imprimir
    printf("Cuantas iteraciones quieres? ");
    scanf("%i",&iteraciones);

    //datos a pedir del usuario como parametro inicial
    /*
    printf("Parametro inicial A: ");
    scanf("%lf",&a);
    printf("Parametro inicial B: ");
    scanf("%lf",&b);
    */
    system("clear");

    imprimirCabecera(iteraciones);
    for(i = 1;i <= iteraciones;i++){
        //bloque para asignar datos


        //imprimir datos del bloque de asignacion
        imprimirResultados(iteraciones,i/*,<demas parametros a imprimir>*/);

        //actualizacion de datos

    }

    return 0;
}

//Funcion a resolver
/*
double funcion(double x){
    return <funcion>;
}*/
//Posibles funciones extra a necesitar



//seccion de impresion de la tabla
void imprimirResultados(int iteraciones,int iteracion/*, <demas parametros a imprimir*/){
    imprimirNumero(iteraciones, iteracion);

    //impresion de celda con valores de la iteracion
    //imprimirCelda(<valor>);


    imprimirFinLinea(3);

    imprimirLineaNumero(1,iteraciones);
    //imprimirLinea(1,<numero de celdas que hay>);
    imprimirFinLinea(3);
}

void imprimirCabecera(int iteraciones){
    imprimirLineaNumero(2,iteraciones);
    //imprimirLinea(2,<numero de celdas que hay>);
    imprimirFinLinea(2);

    imprimirNumeral(iteraciones);

    //Impresion de cabeceras
    //imprimirHeader("<texto deseado para la cabecera>");

    imprimirFinLinea(3);

    imprimirLineaNumero(1,iteraciones);
    //imprimirLinea(1,<numero de celdas que hay>);
    imprimirFinLinea(1);
}
