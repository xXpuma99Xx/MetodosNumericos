#include<stdio.h>
#include<string.h>

void imprimirFinLinea(int caso);
void imprimirLinea(int caso, int iteraciones, int cantidad, int casoFin);
void imprimirLineaCelda(int caso, int cantidad);
void imprimirHeader(char texto[]);
void imprimirCelda(double dato);
void imprimirNumeral(int iteraciones);
void imprimirNumero(int iteraciones, int iteracion);
void imprimirLineaNumero(int caso, int iteraciones);

void imprimirHeader(char texto[]){
    int tamanio;

    tamanio = strlen(texto);

    switch(tamanio){
        case 1:printf("|        %s         ",texto);
            break;
        case 2:printf("|        %s        ",texto);
            break;
        case 3:printf("|       %s        ",texto);
            break;
        case 4:printf("|       %s       ",texto);
            break;
        case 5:printf("|      %s       ",texto);
            break;
        case 6:printf("|      %s      ",texto);
            break;
        case 7:printf("|     %s      ",texto);
            break;
        case 8:printf("|     %s     ",texto);
            break;
        case 9:printf("|    %s     ",texto);
            break;
        case 10:printf("|    %s    ",texto);
            break;
        case 11:printf("|    %s   ",texto);
            break;
        case 12:printf("|   %s   ",texto);
            break;
        case 13:printf("|   %s  ",texto);
            break;
        case 14:printf("|  %s  ",texto);
            break;
        case 15:printf("|  %s ",texto);
            break;
        case 16:printf("| %s ",texto);
            break;
        case 17:printf("| %s",texto);
            break;
        case 18:printf("|%s",texto);
            break;
        default:printf("Necesito agregar caso.");
    }
}

void imprimirLinea(int caso, int iteraciones, int cantidad, int casoFin){
    imprimirLineaNumero(caso,iteraciones);
    imprimirLineaCelda(caso,cantidad);
    imprimirFinLinea(casoFin);
}

void imprimirFinLinea(int caso){
    switch(caso){
        case 1:printf("-\n");
            break;
        case 2:printf("_\n");
            break;
        case 3:printf("|\n");
            break;
        default:printf("Necesito agregar caso.");
    }
}

void imprimirLineaCelda(int caso, int cantidad){
    int i;
    switch(caso){
        case 1:for(i = 0;i < cantidad;i++)printf("+------------------");
            break;
        case 2:for(i = 0;i < cantidad;i++)printf("___________________");
            break;
        default:printf("Necesito agregar caso.");
    }

}

void imprimirLineaNumero(int caso, int iteraciones){
    if(iteraciones < 10){
        switch(caso){
            case 1:printf("|---");
                break;
            case 2:printf("____");
                break;
        }
    }else if(iteraciones < 100){
        switch(caso){
            case 1:printf("|----");
                break;
            case 2:printf("_____");
                break;
        }
    }else if(iteraciones < 1000){
        switch(caso){
            case 1:printf("|-----");
                break;
            case 2:printf("______");
                break;
        }
    }else{
        printf("Agregar nuevo parametro");
    }
}

void imprimirCelda(double dato){
    if(dato < 0){
        if(dato > -10) printf("|  %.13lf",dato);
        else if(dato > -100) printf("| %.13lf",dato);
        else printf("|%.13lf",dato);

    }else{
        if(dato < 10) printf("|   %.13lf",dato);
        else if(dato < 100) printf("|  %.13lf",dato);
        else printf("| %.13lf",dato);
    }
}

void imprimirNumeral(int iteraciones){
    if(iteraciones < 10) printf("| # ");
    else if(iteraciones < 100) printf("|  # ");
    else if(iteraciones < 1000) printf("|  #  ");
}

void imprimirNumero(int iteraciones, int iteracion){
    if(iteraciones < 10) printf("| %i ",iteracion);
    else if(iteraciones < 100){
        if(iteracion < 10) printf("|  %i ",iteracion);
        else if(iteracion < 100) printf("| %i ",iteracion);
    }else if(iteraciones < 1000){
        if(iteracion < 10) printf("|  %i  ",iteracion);
        else if(iteracion < 100) printf("|  %i ",iteracion);
        else if(iteracion < 1000) printf("| %i ",iteracion);
    }
}

