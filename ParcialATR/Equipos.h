#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char  nombreEquipo[51];
    char  localidad[51];
    int estaVacio;
}eEquipo;

typedef struct
{
    int codigo;
    char  nombreJugador[31];
    char  apellidoJugador[31];
    char  sexoJugador;
    char fechaNacimientoJugador;
    eEquipo equipo;
}eJugador;

typedef struct
{
    int codigo;
    char  nombreReferi[31];
    char  apellidoReferi[31];
    char  sexoReferi;
    char  eMail[31];
    char fechaNacimientoReferi;
}eReferi;

typedef struct
{
    int codigo;
    eEquipo equipo;
    eJugador jugador;
    eReferi referi;
    char fecha;
}ePartido;

//////////////////////////////////////
void inicializarEquipos(eEquipo[]);

void ingresarEquipo(eEquipo[], int);

int validacionNombreEquipo (char[]);

int validacionLocalidadEquipo(char[]);

void mostrarEquipos(eEquipo[]);

int menuEquipo(eEquipo[], int);
//////////////////////////////////////
void ingresarJugador(eJugador[],int);

int validacionNombreJugador(char[]);

int validacionApellidoJugador(char[]);

int validacionSexoJugador(char);

int validarFechaNacimientoJugador(int, int, int);
//////////////////////////////////////////
void ingresarReferi(eReferi[], int);

int validacionNombreReferi(char[]);

int validacionApellidoReferi(char[]);

int validacionSexoReferi(char);

int validacionFechaNacimientoReferi(int, int, int);

void menuJugador(eJugador[],int);
//////////////////////////////////////
