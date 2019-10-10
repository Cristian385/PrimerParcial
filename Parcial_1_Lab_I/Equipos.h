#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char  nombreEquipo[51];
    char  localidad[51];
}eEquipo;

typedef struct
{
    int codigo;
    char  nombreJugador[31];
    char  apellidoJugador[31];
    char  sexoJugador;
    char diaNacimientoJugador;
    char mesNacimientoJugador;
    char anioNacimientoJugador;
}eJugador;

typedef struct
{
    int codigo;
    char  nombreReferi[31];
    char  apellidoReferi[31];
    char  sexoReferi;
    char  eMail[31];
    char diaNacimientoReferi;
    char mesNacimientoReferi;
    char anioNacimientoReferi;
}eReferi;


void ingresarEquipo(eEquipo[], int);

int validacionNombreEquipo (char[]);

int validacionLocalidadEquipo(char[]);

//////////////////////////////////////

void ingresarJugador(eJugador[],int);

int validacionNombreJugador(char[]);

int validacionApellidoJugador(char[]);

int validacionSexoJugador(char);

int validarDiaNacimientoJugador(char[]);

int validarMesNacimientoJugador(char[]);

int validarAnioNacimientoJugador(char[]);

//////////////////////////////////////////







