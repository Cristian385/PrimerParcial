#include <stdio.h>
#include <stdlib.h>
#include "Equipos.h"
#define MAX 100

int main()
{
    char menu;
    char menuIngresar;
    char menuModificar;
    char menuEliminar;
    int salir = 1;
    int salirIngresar = 1;
    int salirModificar = 1;
    int salirEliminar = 1;
    char respuesta = 's';
    eEquipo equipos[MAX];
    eJugador jugadores[MAX];
    eReferi referi[MAX];
    int codigoEquipo = 1;
    int codigoJugador = 1;
    int codigoReferi = 1;
    int codigoPartido = 1;

    inicializarEquipos(equipos);
    inici


    do
    {
        printf("Bienvenido al parcial de Cristian Fumacoo \n \n");
        printf("¿Que menu desea? \n");
        printf("1.Equipo \n");
        printf("5.Salir \n");
        printf("El codigo del equipo es: %d", codigoEquipo);
        fflush(stdin);
        scanf("%c", &menu);

        switch(menu)
        {
            case '1':
                codigoEquipo = menuEquipo(equipos, codigoEquipo);
                break;
            case '2':



        case '5':
            printf("¿Seguro que quiere salir? s/n");
            fflush(stdin);
            scanf("%c", &respuesta);

            if(respuesta == 's')
                salir = 0;

            break;

        default:
            printf("Opcion incorrecta. Vuelva a seleccionar \n");
            system("pause");
            break;
        }

        system("cls");

    }while (salir == 1);
}
