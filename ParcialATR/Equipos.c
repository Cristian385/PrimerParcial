#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "Equipos.h"

#define MAX 100
#define CANT 51

/*INICIO FUNCIONES DE LOS EQUIPOS*/
void inicializarEquipos(eEquipo equipos[MAX])
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        equipos[i].estaVacio = 0;
        equipos[i].codigo = 0;
        strcpy(equipos[i].localidad, ' ');
        strcpy(equipos[i].nombreEquipo, ' ');
    }
}
int menuEquipo(eEquipo equipos[MAX], int codigoEquipo)
{
    char respuesta = 's';
    char opcion;
    do
    {
        system("cls");
        printf("Ingrese la opcion a realizar.\n \n");
        printf("1.Ingresar. \n");
        printf("2.Modificar. \n");
        printf("3.Eliminar. \n");
        printf("4.Salir de este menu. \n");
        printf("El codigo del equipo es: %d", codigoEquipo);
        fflush(stdin);
        scanf("%c", &opcion);

        switch(opcion)
        {
            case '1':
                ingresarEquipo (equipos, codigoEquipo);
                codigoEquipo++;
                printf("Se ha cargado correctamente. \n");
                system("pause");
                break;
            case '4':
                respuesta = 'n';
        }

    }while(respuesta == 's');

    return codigoEquipo;
}
void ingresarEquipo (eEquipo equipos[MAX], int codigoEquipo)
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        //cuando encontramos el primer lugar del array vacio, asignamos los valores a ese espacio
        if(equipos[i].estaVacio == 0)
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

            /*asignamos los ultimos valores y salimos del metodo*/
            equipos[i].codigo = codigoEquipo;
            equipos[i].estaVacio = 1;//cambiamos la bandera para indicar que ya tiene valores cargados
            break;
        }
    }
}

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

int validacionLocalidadEquipo(char str[CANT])
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

void mostrarEquipos(eEquipo equipos[MAX])
{
    int i;
    printf("Listado de equipos ingresados: \n");
    printf("Codigo Equipo\t\t Nombre\t\t Localidad\t\t \n");

    for(i = 0; i < MAX; i++)
    {
        if(equipos[i].estaVacio == 1)
        {
            printf("%d\t\t %s\t\t %s\t\t \n", equipos[i].codigo, equipos[i].nombreEquipo, equipos[i].localidad);
        }
    }
}
/*FIN FUNCIONES DE LOS EQUIPOS*/

/*INICIO FUNCIONES JUGADOR*/
void ingresarJugador(eJugador jugadores[MAX],int codigoJugador)
{
    int i;
    for(i = 0; i < MAX; i++)
    {
        printf("Ingrese el nombre del Jugador: ");
        fflush(stdin);
        scanf("%s", &jugadores[i].nombreJugador);

        while(validacionNombreEquipo(jugadores[i].nombreJugador) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(jugadores[i].nombreJugador);
        }

        printf("Ingrese el apellido del Jugador: ");
        fflush(stdin);
        scanf("%s", &jugadores[i].apellidoJugador);

        while(validacionLocalidadEquipo(jugadores[i].apellidoJugador) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            gets(jugadores[i].apellidoJugador);
        }

        /////////////////////////////////////////////

        char sexo;

        printf("Ingrese sexo del Jugador: \n");
        fflush(stdin);
        scanf("%c", &sexo);

        while(validacionSexoJugador(sexo) == 0)
        {
            printf("Usted ha ingresado un dato incorrecto. Ingrese nuevamente: ");
            fflush(stdin);
            scanf("%c", &sexo);
        }
        jugadores[i].sexoJugador = sexo;

        int anio;
        int mes;
        int dia;

        printf("Ingrese nacimiento, (dia/mes/año): \n");
        fflush(stdin);
        scanf("%d/%d/%d", &dia, &mes, &anio);

        while (validarFechaNacimientoJugador(dia,mes,anio) == 0)
        {
            fflush(stdin);
            scanf("%d/%d/%d", &dia, &mes, &anio);
        }
        jugadores[i].fechaNacimientoJugador = dia + '/' + mes + '/' + anio;

        //una vez ingresados todos los datos, asignamos el codigo.
        jugadores[i].codigo = codigoJugador;
        break;
    }
}

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
    if(str != 'F' && str != 'M' && str != 'f' && str != 'm')
        return 0;

    return 1;
}

int validarFechaNacimientoJugador(int dia, int mes, int anio)
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
/*FIN FUNCIONES JUGADOR*/

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

