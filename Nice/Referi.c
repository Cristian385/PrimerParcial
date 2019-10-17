#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Referi.h"

#define MAX 100
#define CANT 51

/*INICIO FUNCIONES REFERI*/
void ingresarReferi(eReferi referi[MAX], int codigoReferi)
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        printf("Ingrese el nombre del referi: ");
        fflush(stdin);
        scanf("%s", &referi[i].nombreReferi);

        while(validacionNombreReferi(referi[i].nombreReferi) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(referi[i].nombreReferi);
        }

        printf("Ingrese el apellido del referi: ");
        fflush(stdin);
        scanf("%s", &referi[i].apellidoReferi);

        while(validacionLocalidadEquipo(referi[i].apellidoReferi) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(referi[i].apellidoReferi);
        }

        /////////////////////////////////////////////

        char sexo;

        printf("Ingrese sexo del referi: \n");
        fflush(stdin);
        scanf("%c", &sexo);

        while(validacionSexoJugador(sexo) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            scanf("%c", &sexo);
        }
        referi[i].sexoReferi = sexo;

        int anio;
        int mes;
        int dia;

        printf("Ingrese nacimiento, (dia/mes/año): \n");
        fflush(stdin);
        scanf("%d/%d/%d", &dia, &mes, &anio);

        while (validacionFechaNacimientoReferi(dia,mes,anio) == 0)
        {
            fflush(stdin);
            scanf("%d/%d/%d", &dia, &mes, &anio);
        }
        referi[i].fechaNacimientoReferi = dia + '/' + mes + '/' + anio;
        break;

    }
}

int validacionNombreReferi(char str[CANT])
{
        int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int validacionApellidoReferi(char str[CANT])
{
    int i=0;
    while (str[i] != '\0')
    {
        if((str[i] != ' ') && (str[i] <  'a' || str [i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
            return 0;
        i++;
    }
    return 1;
}

int validacionSexoReferi(char str)
{
    if(str != 'F' && str != 'M' && str != 'f' && str != 'm')
    {
        return 0;
    }
        return 1;
}

int validacionFechaNacimientoReferi(int dia, int mes, int anio)
{
    if(anio>=1900 && anio<=9999)
    {
        if(mes>=1 && mes<=12)
        {
            if((dia>=1 && dia<=31) && (mes==1 || mes==3 || mes==5 || mes==7 || mes==8 || mes==10 || mes==12))
                return 1;
            else if((dia>=1 && dia<=30) && (mes==4 || mes==6 || mes==9 || mes==11))
                return 1;
            else if((dia>=1 && dia<=28) && (mes==2))
                return 1;
            else if(dia==29 && mes==2 && (anio%400==0 ||(anio%4==0 && anio%100!=0)))
                return 1;
            else
            {
                printf("El dia es invalido.\n");
                return 0;
            }

        }
        else
        {
            printf("El mes es invalido.\n");
            return 0;
        }
    }
    else
    {
        printf("El año es invalido.\n");
        return 0;
    }
}
/*FIN FUNCIONES REFERI*/

