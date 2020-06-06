#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#ifdef NAN
#endif // NAN

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
void imprimirResultados(int iteraciones,int iteracion,double x0,double x1,double fx0,double fx1,double x2,double fx2);
void imprimirCabecera(int iteraciones);
double asignarX2(double x0,double x1,double fx0,double fx1);
double funcion(double x);

int main(){
    //variables de los datos
    double x0,x1,x2,fx0,fx1,fx2;
    //iteraciones = iterariones a realizer      i = iterarodr
    int iteraciones,i,encontrado = 0;

    //Iteraciones que el usuario desea imprimir
    printf("Cuantas iteraciones quieres? ");
    scanf("%i",&iteraciones);

    //datos a pedir del usuario como parametro inicial
    printf("Parametro inicial x1: ");
    scanf("%lf",&x0);
    printf("Parametro inicial x2: ");
    scanf("%lf",&x1);
    system("clear");

    fx0 = funcion(x0);
    fx1 = funcion(x1);
    imprimirCabecera(iteraciones);
    for(i = 1;i <= iteraciones;i++){
        //bloque para asignar datos
        x2 = asignarX2(x0,x1,fx0,fx1);
        fx2 = funcion(x2);

        if(isnan(fx2)){
            encontrado = 1;
            break;
        }
        //imprimir datos del bloque de asignacion
        imprimirResultados(iteraciones,i,x0,x1,fx0,fx1,x2,fx2);

        //actualizacion de datos
        x0 = x1;
        fx0 = fx1;
        x1 = x2;
        fx1 = fx2;
    }
    if(encontrado == 1){
        printf("La raiz es: %.100lf\n",x1);

    }else {
        printf("La mejor representacion de la raiz es: %.100lf\n",x1);
    }
    return 0;
}

//Funcion a resolver
double funcion(double x){
    return (3*x*cos(2*x))-(pow(x+1,2))+6;
}
//Posibles funciones extra a necesitar
double asignarX2(double x0,double x1,double fx0,double fx1){
     return x1-(fx1*((x0 - x1)/(fx0 - fx1)));
}


//seccion de impresion de la tabla
void imprimirResultados(int iteraciones,int iteracion,double x0,double x1,double fx0,double fx1,double x2,double fx2){
    imprimirNumero(iteraciones, iteracion);

    //impresion de celda con valores de la iteracion
    //imprimirCelda(<valor>);
    imprimirCelda(x0);
    imprimirCelda(x1);
    imprimirCelda(fx0);
    imprimirCelda(fx1);
    imprimirCelda(x2);
    imprimirCelda(fx2);
    if(iteracion == 1){
        imprimirCelda(0);
    }else {
        imprimirCelda(fabs((x1-x0)/x1));
    }

    imprimirFinLinea(3);
    imprimirLinea(1,iteraciones,7,3);
}

void imprimirCabecera(int iteraciones){
    imprimirLinea(2,iteraciones,7,2);
    imprimirNumeral(iteraciones);

    //Impresion de cabeceras
    //imprimirHeader("<texto deseado para la cabecera>");
    imprimirHeader("x0");
    imprimirHeader("x1");
    imprimirHeader("f(x0)");
    imprimirHeader("f(x1)");
    imprimirHeader("x2");
    imprimirHeader("f(x2)");
    imprimirHeader("Error Relativo");

    imprimirFinLinea(3);
    imprimirLinea(1, iteraciones, 7,1);
}
