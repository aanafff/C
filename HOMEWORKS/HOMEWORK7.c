//
//  main.c
//  HOMEWORK7
//
//  Created by Ana Ramirez on 06/05/21.
//

#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include "HOMEWORK7.h"

int
main (){

  char User[MAX];
  int Domingo;
  int Lunes;
  int Martes;
  int Miercoles;
  int Jueves;
  int Viernes;
  int Sabado;
  int Hora;
  int Min;
  int Trabajo;

header ();
  int i;
  int j;
  int pintemporal;
matrix = (int **) malloc (sizeof (int *) * USUARIOS);
  for (i = 0; i < USUARIOS; i++)
    {
      matrix[i] = (int *) malloc (sizeof (int) * 6);
      for (j = 0; j < 6; j++)
    {
      matrix[i][j] = -1;
    }
    }
  int salir = 0;
  int opcion = 0;
  while (salir == 0)
    {
      int limite;
      limite = count ();

      printf ("\nThere are %d registered workers\n", limite);
      scanf ("%d", &opcion);
      if (opcion == 1)
    {

      printf ("Enter your pin\n");
      scanf ("%d", &pintemporal);

    if (pintemporal <= 0)
        {
          printf ("Unvalid \n");
        }

    else if (pintemporal <= limite)
        {
          if (matrix[pintemporal - 1][1] == -1)
        {
          entradaosalida (pintemporal, 0);
        }
          else
        {
          printf
            ("Already registered entry\n");
        }
        }
    }
      else if (opcion == 2)
    {
      printf ("Enter your pin\n");
      scanf ("%d", &pintemporal);
      if (pintemporal <= 0)
        {
          printf ("Unvalid entry\n");
        }
      else if (pintemporal <= limite)
        {
          if (matrix[pintemporal - 1][1] != -1)
        {
          entradaosalida (pintemporal, 1);
        }
        }
      else
        {
          printf
        ("There are %d registered workers, you can't use that pin\n",
         limite);
        }
    }
      else if (opcion == 3)
    {
      registrar ();
    }
      else if (opcion == 4)
    {
    }
      else
    {
      printf ("Option not available\n\n");
    }
    }
  return 0;
}

int count ()
{
  FILE *sistema = fopen ("system.txt", "r");
  char c;
  int count = 0;
  while ((c = fgetc (sistema)) != EOF)
   {
     if (c == '\n')
    {
  count++;
    }
  }

  return count;
}
void
registrar ()
{
}
void
entradaosalida (int pin, int estado)
{
  int diferencia = 0;
  time_t tiempoahora;
  time (&tiempoahora);
  struct tm *mitiempo = localtime (&tiempoahora);
  int actualsec = mitiempo->tm_sec;
  int actualmin = mitiempo->tm_min;
  int actualhora = mitiempo->tm_hour;
  int actualyear = mitiempo->tm_year + 1900;
  int actualmes = mitiempo->tm_mon + 1;
  int actualdia = mitiempo->tm_mday;
  int actualwdia = mitiempo->tm_wday;
  if (estado == 0)
    {
      FILE *entrada = fopen ("entries.txt", "a");
      fprintf (entrada, "%d %d %d/%d/%d %d:%d:%d\n", pin, actualwdia,
           actualdia, actualmes, actualyear, actualhora, actualmin,
           actualsec);
      fclose (entrada);
      matrix[pin - 1][0] = actualhora;
      matrix[pin - 1][1] = actualmin;
      matrix[pin - 1][2] = actualsec;
      printf ("Registered entry\n");
    }
  if (estado == 1)
    {
      FILE *salida = fopen ("departuress.txt", "a");
      fprintf (salida, "%d %d %d/%d/%d %d:%d:%d\n", pin, actualwdia,
           actualdia, actualmes, actualyear, actualhora, actualmin,
           actualsec);
      fclose (salida);
      printf ("Registered departure\n");
      matrix[pin - 1][3] = actualhora;
      matrix[pin - 1][4] = actualmin;
      matrix[pin - 1][5] = actualsec;
      FILE *reporte = fopen ("report.txt", "a");
      if (totaldesalidas == 0)
    {
      fprintf (reporte, "Report created on: ");
      switch (actualwdia)
        {
        case 0:
          fprintf (reporte, "Sunday");
          break;
        case 1:
          fprintf (reporte, "Monday");
          break;
        case 2:
          fprintf (reporte, "Tuesday");
          break;
        case 3:
          fprintf (reporte, "Wednesday");
          break;
        case 4:
          fprintf (reporte, "Thursday");
          break;
        case 5:
          fprintf (reporte, "Friday");
          break;
        case 6:
          fprintf (reporte, "Saturday");
          break;
        }
      fprintf (reporte, " %d/%d/%d\n", actualdia, actualmes, actualyear);
    }

      fclose (reporte);
      matrix[pin - 1][0] = -1;
      matrix[pin - 1][1] = -1;
      matrix[pin - 1][2] = -1;
      matrix[pin - 1][3] = -1;
      matrix[pin - 1][4] = -1;
      matrix[pin - 1][5] = -1;

      totaldesalidas = 9;
    }
}

void header ()
{
  time_t tiempoahora;
  time (&tiempoahora);
  struct tm *mitiempo = localtime (&tiempoahora);
  switch (mitiempo->tm_wday)
    {
    case 0:
      printf ("Today is Sunday\n");
      break;
    case 1:
      printf ("Today is Monday\n");
      break;
    case 2:
      printf ("Today is Tuesday\n");
      break;
    case 3:
      printf ("Today is Wednesday\n");
      break;
    case 4:
      printf ("Today is Thursday\n");
      break;
    case 5:
      printf ("Today is Friday\n");
      break;
    case 6:
      printf ("Today is Saturday\n");
      break;
    }
  printf ("Day: %d/%d/%d\n", mitiempo->tm_mday, mitiempo->tm_mon + 1,
      mitiempo->tm_year + 1900);
  printf ("Hour: %d:%d\n", mitiempo->tm_hour, mitiempo->tm_min);
  printf ("Only %d users can be registered\n", USUARIOS);
}

void horario ()
{
  time_t tiempoahora;
  time (&tiempoahora);
  int pinleido;
  char usuarioleido[MAX];
  int domingohorario;
  int luneshorario;
  int marteshorario;
  int miercoleshorario;
  int jueveshorario;
  int vierneshorario;
  int sabadohorario;
  int horaleida;
  int minutoleido;
  int trabajo;
  int i;
  struct tm *mitiempo = localtime (&tiempoahora);
  FILE *leersistema = fopen ("system.txt", "r");
  FILE *escribirhorario = fopen ("schedule.txt", "w");
  char c;
  int count;
  while (fscanf
     (leersistema, "%d %s %d %d %d %d %d %d %d %d %d %d\n", &pinleido,
      usuarioleido, &domingohorario, &luneshorario, &marteshorario,
      &miercoleshorario, &jueveshorario, &vierneshorario, &sabadohorario,
      &horaleida, &minutoleido, &trabajo) == 12)
    {
      fprintf (escribirhorario,
           "User <%s> with the pin <%d> must enter at: %d:%d and must work for <%d segundos> the next days:\n",
           usuarioleido, pinleido, horaleida, minutoleido, trabajo);
      if (domingohorario == 1)
    fprintf (escribirhorario, "Sunday ");
      if (luneshorario == 1)
    fprintf (escribirhorario, "Monday ");
      if (marteshorario == 1)
    fprintf (escribirhorario, "Tuesday ");
      if (miercoleshorario == 1)
    fprintf (escribirhorario, "Wednesday ");
      if (jueveshorario == 1)
    fprintf (escribirhorario, "Thursday ");
      if (vierneshorario == 1)
    fprintf (escribirhorario, "Friday ");
      if (sabadohorario == 1)
    fprintf (escribirhorario, "Saturday ");

      fprintf (escribirhorario, "\n\n");
    }


  fclose (leersistema);
  fclose (escribirhorario);
}
