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
void imprimirResultados(int iteraciones,int iteracion,double x0,double x1,double fx0,double fx1,double x2,double fx2);
double formula(int caso, double x0, double x1, double fx0, double fx1);
double funcion(double x);

int main(){
    //variables de los datos
    double x0,x1,fx0,fx1,x2,fx2;
    //iteraciones = iterariones a realizer      i = iterarodr
    int iteraciones,i,encontrado;

    //Iteraciones que el usuario desea imprimir
    printf("Cuantas iteraciones quieres? ");
    scanf("%i",&iteraciones);

    //datos a pedir del usuario como parametro inicial
    printf("Parametro inicial x0: ");
    scanf("%lf",&x0);
    printf("Parametro inicial x1: ");
    scanf("%lf",&x1);
    system("clear");

    fx0 = funcion(x0);
    fx1 = funcion(x1);

    imprimirCabecera(iteraciones);
    for(i = 1;i <= iteraciones;i++){
        //bloque para asignar datos
        x2 = formula(1,x0,x1,fx0,fx1);
        fx2 = funcion(x2);

        //imprimir datos del bloque de asignacion
        imprimirResultados(iteraciones,i,x0,x1,fx0,fx1,x2,fx2);

        //actualizacion de datos
        if((fx0 * fx2) < 0){
            x1 = x2;
            fx1 = fx2;
        }else if((fx1 * fx2) < 0){
            x0 = x2;
            fx0 = fx2;
        }else if(fx2 == 0){
            encontrado = 1;
            break;
        }else{
            printf("hubo un error");
            return 1;
        }
    }
    if(encontrado == 1){
        printf("La raiz es: %.100lf\n",x2);
    }else{
        printf("La mejor representacion de la raiz es: %.100lf\n",x2);
    }

    return 0;
}

//Funcion a resolver
double funcion(double x){
    return ((9.8*68.1)/x)*(1-pow(exp(1),-(x/68.1)*10))-40;
}
//Posibles funciones extra a necesitar
double formula(int caso, double x0, double x1, double fx0, double fx1){
    switch(caso){
        case 1: return x1-(fx1*((x0 - x1)/(fx0 - fx1)));
            break;
        case 2: return x0-(fx0*((x1 - x0)/(fx1 - fx0)));
            break;
        default: printf("hubo un error");
    }
    return 1;
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
    imprimirHeader("x0");
    imprimirHeader("x1");
    imprimirHeader("f(x0)");
    imprimirHeader("f(x1)");
    imprimirHeader("x2");
    imprimirHeader("f(x2)");

    imprimirFinLinea(3);

    imprimirLineaNumero(1,iteraciones);
    imprimirLinea(1,6);
    imprimirFinLinea(1);
}
