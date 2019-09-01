#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//funciones de la libreria tabla
void imprimirFinLinea(int caso);
void imprimirLinea(int caso, int cantidad);
void imprimirHeader(char texto[]);
void imprimirCelda(double dato);
void imprimirNumeral(int iteraciones);
void imprimirNumero(int iteraciones, int iteracion);
void imprimirLineaNumero(int caso, int iteraciones);

//Funciones propias de main
void imprimirResultados(int iteraciones,int iteracion,double a,double b,double fa,double fb,double p,double fp);
double funcion(double x);

int main(){
    //variables de los datos
    double a,b,fa,fb,p,fp;
    //iteraciones = iterariones a realizer      i = iterarodr
    int iteraciones,i;

    //Iteraciones que el usuario desea imprimir
    printf("Cuantas iteraciones quieres? ");
    scanf("%i",&iteraciones);

    //datos a pedir del usuario como parametro inicial
    printf("Parametro inicial A: ");
    scanf("%lf",&a);
    printf("Parametro inicial B: ");
    scanf("%lf",&b);
    system("clear");

    fa = funcion(a);
    fb = funcion(b);
    imprimirCabecera(iteraciones);
    for(i = 1;i <= iteraciones;i++){
        //bloque para asignar datos
        p = (a + b)/2;
        fp = funcion(p);

        //imprimir datos del bloque de asignacion
        imprimirResultados(iteraciones,i,a,b,fa,fb,p,fp);

        //actualizacion de datos
        if((fa * fp) < 0){
            b = p;
            fb = fp;
        }else if((fb * fp) < 0){
            a = p;
            fa = fp;
        }else{
            printf("hubo un error");
            return 1;
        }
    }

    return 0;
}

//Funcion a resolver
double funcion(double x){
    return ((9.8*68.1)/x)*(1-pow(exp(1),-(x/68.1)*10))-40;
}
//Posibles funciones extra a necesitar



//seccion de impresion de la tabla
void imprimirResultados(int iteraciones,int iteracion,double a,double b,double fa,double fb,double p,double fp){
    imprimirNumero(iteraciones, iteracion);

    //impresion de celda con valores de la iteracion
    //imprimirCelda(<valor>);
    imprimirCelda(a);
    imprimirCelda(b);
    imprimirCelda(fa);
    imprimirCelda(fb);
    imprimirCelda(p);
    imprimirCelda(fp);

    imprimirFinLinea(3);

    imprimirLineaNumero(1,iteraciones);
    imprimirLinea(1,6);
    imprimirFinLinea(3);
}

void imprimirCabecera(int iteraciones){
    imprimirLineaNumero(2,iteraciones);
    imprimirLinea(2,6);
    imprimirFinLinea(2);

    imprimirNumeral(iteraciones);

    //Impresion de cabeceras
    //imprimirHeader("<texto deseado para la cabecera>");
    imprimirHeader("a");
    imprimirHeader("b");
    imprimirHeader("f(a)");
    imprimirHeader("f(b)");
    imprimirHeader("p");
    imprimirHeader("f(p)");

    imprimirFinLinea(3);

    imprimirLineaNumero(1,iteraciones);
    imprimirLinea(1,6);
    imprimirFinLinea(1);
}
