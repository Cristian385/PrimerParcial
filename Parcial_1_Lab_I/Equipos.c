#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Equipos.h"

#define MAX 100
#define CANT 51


void ingresarEquipo (eEquipo equipos[MAX], int codigo)
{
    int i;
    for(i = 0; i < MAX; i++)
    {
            printf("Ingrese el nombre del equipo: ");
            fflush(stdin);
            scanf("%s", &equipos[i].nombreEquipo);

            while(validacionNombreEquipo(equipos[i].nombreEquipo) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(equipos[i].nombreEquipo);
            }

            printf("Ingrese la localidad del equipo: ");
            fflush(stdin);
            scanf("%s", &equipos[i].localidad);

            while(validacionLocalidadEquipo(equipos[i].localidad) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(equipos[i].localidad);
            }
            break;
        }
}

void ingresarJugador(eJugador jugadores[],int codigo)
{
    int i;
    for(i = 0; i < MAX; i++)
    {
            printf("Ingrese el nombre del jugador: ");
            fflush(stdin);
            scanf("%s", &jugadores[i].nombreJugador);

            while(validacionNombreEquipo(jugadores[i].nombreJugador) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(jugadores[i].nombreJugador);
            }

            printf("Ingrese el apellido del jugador: ");
            fflush(stdin);
            scanf("%s", &jugadores[i].apellidoJugador);

            while(validacionLocalidadEquipo(jugadores[i].apellidoJugador) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(jugadores[i].apellidoJugador);
            }

            printf("Ingrese sexo del jugador: \n");
            fflush(stdin);
            scanf("%s", &jugadores[i].sexoJugador);

            while(validacionSexoJugador(jugadores[i].sexoJugador) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(jugadores[i].sexoJugador);
            }

            //Dia de nacimiento
            int auxDiaNacimiento[MAX];
            printf("Ingrese dia de Nacimiento del jugador");
            fflush(stdin);
            scanf("%d", &jugadores[i].diaNacimientoJugador);

            while(validarDiaNacimientoJugador(auxDiaNacimiento) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxDiaNacimiento);
            }
            jugadores[i].diaNacimientoJugador=atoi(auxDiaNacimiento);


            //Mes de nacimiento
            int auxMesNacimiento[MAX];
            printf("Ingrese Mes de Nacimiento del jugador");
            fflush(stdin);
            scanf("%d", &jugadores[i].mesNacimientoJugador);

            while(validarMesNacimientoJugador(auxMesNacimiento) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxMesNacimiento);
            }
            jugadores[i].mesNacimientoJugador=atoi(auxMesNacimiento);


            //año nacimiento
            int auxAnioNacimiento[MAX];
            printf("Ingrese Año de Nacimiento del jugador");
            fflush(stdin);
            scanf("%d", &jugadores[i].anioNacimientoJugador);

            while(validarAnioNacimientoJugador(auxAnioNacimiento) == 0)
            {
                printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
                fflush(stdin);
                gets(auxAnioNacimiento);
            }
            jugadores[i].anioNacimientoJugador=atoi(auxAnioNacimiento);


            break;
        }

}
//////////////////////////////////////
int validacionNombreEquipo(char str[])
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

int validacionLocalidadEquipo(char str[])
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
/////////////////////////////////////////////
int validacionNombreJugador(char str[])
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

int validacionApellidoJugador(char str[])
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

int validacionSexoJugador(char str)
{
        if((str != 'F' && str != 'M' && str != 'f' && str != 'm'))
        {
            return 0;
        }

            return 1;

}
int validarDiaNacimientoJugador(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9' || str[i]== '-' || str[i] == '/')
            return 0;
        i++;
    }
    return 1;
}

int validarMesNacimientoJugador(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9' || str[i]== '-' || str[i] == '/')
            return 0;
        i++;
    }
    return 1;
}

int validarAnioNacimientoJugador(char str[])
{
    int i=0;
    while(str[i] != '\0')
    {
        if(str[i] < '0' || str[i] > '9' || str[i]== '-' || str[i] == '/')
            return 0;
        i++;
    }
    return 1;
}









//////////////////////////////////////
