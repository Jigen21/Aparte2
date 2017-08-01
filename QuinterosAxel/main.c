#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "Class.Log.h"
#include "Class.Services.h"

typedef struct
{
    char nota;
    int duration;
    int freq;
    int volume;

} eNotasFinales;


int main()
{
    char option[20], seguir = 's';
    ArrayList* arrayNota=al_newArrayList();
    ArrayList* arrayMelodia=al_newArrayList();
    ArrayList* arrayNotasFinales=al_newArrayList();
    int frecuenciaAux;
    int i;




    while(seguir == 's')
    {
        printf("-----------------------------------------------------------------\n");
        printf("-------------------------               -------------------------\n");
        printf("-----------------------------------------------------------------\n");
        printf("-               1-Leer los archivos de melodia y notas           -\n");
        printf("-               2-Reproducir                                     -\n");
        printf("-               3-Ecualizar                                      -\n");
        printf("-               4-Correcion                                      -\n");
        printf("-                                                               -\n");
        printf("-                                                               -\n");
        printf("-                                                               -\n");
        printf("-----------------------------------------------------------------\n");
        printf("--------------------------------------------------------- -------\n");
        printf("-----------------------------------------------------------------\n");
        get_string("Ingrese una opcion: ", option);

        switch(atoi(option))
        {
        case 1:

            cargarMelodia(arrayMelodia);
            cargarNotas(arrayNota);

            for(i=0; i<arrayMelodia->len(arrayMelodia); i++)
            {
                eNotasFinales* notasfinales=malloc(sizeof(eNotasFinales));

                eMelodia* auxMelodia=malloc(sizeof(eMelodia));
                auxMelodia=arrayMelodia->get(arrayMelodia,i);

                if(auxMelodia->nota== 'A')
                {
                    frecuenciaAux=220;
                }
                if(auxMelodia->nota== 'B')
                {
                    frecuenciaAux=247;
                }
                if(auxMelodia->nota== 'C')
                {
                    frecuenciaAux=261;
                }
                if(auxMelodia->nota== 'D')
                {
                    frecuenciaAux=293;
                }
                if(auxMelodia->nota== 'E')
                {
                    frecuenciaAux=330;
                }
                if(auxMelodia->nota== 'F')
                {
                    frecuenciaAux=349;
                }
                if(auxMelodia->nota== 'G')
                {
                    frecuenciaAux=392;
                }

                notasfinales->nota=auxMelodia->nota;
                notasfinales->freq=frecuenciaAux;
                notasfinales->duration=auxMelodia->duration;
                notasfinales->volume=auxMelodia->volume;


                arrayNotasFinales->add(arrayNotasFinales,notasfinales);

                printf("%c %d  %d   %d  \n ",notasfinales->nota,notasfinales->duration,notasfinales->volume,notasfinales->freq);

            }




            break;
        case 2:


            for(i=0; i<arrayNotasFinales->len(arrayNotasFinales); i++)
            {
                //eNotasFinales* notasFinAux=malloc(sizeof(eNotasFinales));
                notasFinAux=arrayNotasFinales->get(arrayNotasFinales,i);

                if(notasFinAux->volume>100)
                {
                    notasFinAux->volume=100;
                }




                printf("%dHz  %d   %d  \n ",notasFinAux->freq,notasFinAux->duration,notasFinAux->volume);
            }




            break;
        case 3:



            for(i=0; i<arrayNotasFinales->len(arrayNotasFinales); i++)
            {
                //eNotasFinales* notasFinAux=malloc(sizeof(eNotasFinales));
                notasFinAux=arrayNotasFinales->get(arrayNotasFinales,i);

                if(notasFinAux->freq>250)
                {
                    notasFinAux->freq=notasFinAux->freq*1.30;
                    if(notasFinAux->freq>100)
                    {
                        notasFinAux->freq=100;
                    }
                }

                if(notasFinAux->freq>330)
                {
                    notasFinAux->freq=notasFinAux->freq*1.50;
                    if(notasFinAux->freq>100)
                    {
                        notasFinAux->freq=100;
                    }
                }




                printf("%dHz  %d   %d  \n ",notasFinAux->freq,notasFinAux->duration,notasFinAux->volume);
            }












            break;
        case 4:

            crearARchivo(arrayMelodia);


            break;
        case 5:
            seguir = 'n';
            break;
        default:
            printf("Opcion incorrecta.\n");
        }
        clear_screen();
    }
    return 0;
}

