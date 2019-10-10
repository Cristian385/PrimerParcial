#include <stdio.h>
#include <stdlib.h>
#include "Equipos.h"
#define MAX 100

int main()
{
    char menu;
    int salir = 1;
    char respuesta = 's';
    eEquipo equipos[MAX];
    int codigoEquipo;
    int codigoJugador;
    do
    {
        printf("Bienvenido al parcial de Cristian Fumacoo \n \n");
        printf("Presione 1 para ingresar un equipo. \n");
        printf("Presione 2 para ingresar un jugador. \n");
        printf("presione 3 para ingresar un referi. \n");
        fflush(stdin);
        scanf("%c", &menu);

        switch(menu)
        {
        case '1':
            ingresarEquipo (equipos, codigoEquipo);
            codigoEquipo++;
            printf("Se ha cargado correctamente. \n");
            system("pause");
            break;

        case '2':
            ingresarJugador(equipos, codigoJugador);
            codigoJugador++;
            printf("Se ha cargado correctamente. \n");
            system("pause");
            break;

            break;
        /*case '3':

            printf("Seleccione el empleado a eliminar \n");

            printEmployees(equipos);

            scanf("%d", &employeesId);

            //solo si el ID seleccionado es valido, entramos a eliminar el usuario
            validate = validationIdEmployees(equipos, employeesId);
            while(validate == 0)
            {
                printf("Id del empleado incorrecto, vuelva a seleccionar");
                scanf("%d", &employeesId);
                validate = validationIdEmployees(equipos, employeesId);
            }

            deleteEmployees (equipos, employeesId);

            printf("Se ha eliminado con exito \n");
            system("pause");

            break;

        case '4':
        {
            int reportOption;

            printf("¿Que informe quiere saber? \n");
            printf("1.Mostrar Empleados. \n");
            printf("2.Mostrar promedios. \n");
            fflush(stdin);
            scanf("%d", &reportOption);


            switch (reportOption)
            {
                case 1:
                    orderEmployees(equipos);
                    printEmployees (equipos);

                    break;
                case 2:
                    salaries (equipos);

                    break;
                default:
                    printf("Opcion incorrecta, intente nuevamente");

                    break;
            }

            system("pause");
            break;
        }*/

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
