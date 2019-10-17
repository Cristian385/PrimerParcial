typedef struct
{
    int codigo;
    char  nombreReferi[31];
    char  apellidoReferi[31];
    char  sexoReferi;
    char  eMail[31];
    char fechaNacimientoReferi;
}eReferi;

void ingresarReferi(eReferi[], int);

int validacionNombreReferi(char[]);

int validacionApellidoReferi(char[]);

int validacionSexoReferi(char);

int validacionFechaNacimientoReferi(int, int, int);
