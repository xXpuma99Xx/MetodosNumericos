#include<stdio.h>
#include<stdlib.h>
#include<math.h>

void imprimirFinLinea(int caso);
void imprimirLinea(int caso, int cantidad);
void imprimirHeader(char texto[]);
void imprimirCelda(double dato);
void imprimirNumeral(int iteraciones);
void imprimirNumero(int iteraciones, int iteracion);
void imprimirLineaNumero(int caso, int iteraciones);

int main(){
    double a, b, p, fa, fb, fp;
    int iteraciones,i;

    printf("Cuantas iteraciones quieres? ");
    scanf("%i",&iteraciones);

    printf("Parametro inicial A: ");
    scanf("%lf",&a);
    printf("Parametro inicial B: ");
    scanf("%lf",&b);
    system("cls");



    imprimirCabecera(iteraciones);

    for(i = 1;i <= iteraciones;i++){


        imprimirResultados(iteraciones,i,a,b,p,fa,fb,fp);


    }

    return 0;
}

double funcion(double x){
    return (((x+1)*x-4)*x-1);
}

void imprimirResultados(int iteraciones,int iteracion,double a, double b, double p, double fa, double fb, double fp){
    imprimirNumero(iteraciones, iteracion);

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
    imprimirLinea(2,6);//segundo parametro indica cuantas cabeceras debe haber
    imprimirFinLinea(2);

    imprimirNumeral(iteraciones);

    /*Parte que debe dar manualmente el programador para impirmir sus cabeceras*/


    imprimirFinLinea(3);

    imprimirLineaNumero(1,iteraciones);
    imprimirLinea(1,6);
    imprimirFinLinea(1);
}
