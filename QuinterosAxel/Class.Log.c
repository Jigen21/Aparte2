#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Class.Log.h"
#include "Class.Services.h"

eMelodia* newMelodia()
{
    eMelodia* newMelody = (eMelodia*) malloc(sizeof(eMelodia));
    return newMelody;
}

int cargarMelodia(ArrayList* pList)
{
    int result = -1;

    if(pList != NULL)
    {
        char nota[100], volume[100], duration[100];
        FILE* pFile;
        pFile = fopen("melodia.txt", "r");
        pList->clear(pList);

        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                eMelodia* melodia= newMelodia();

                if(melodia != NULL)
                {
                    fscanf(pFile,"%[^;];%[^;];%[^\n]\n", nota, duration, volume);

                    melodia->nota=nota[0];
                    melodia->volume = atoi(volume);
                    melodia->duration = atoi(duration);




                    result = pList->add(pList, melodia);
                }
                else
                {
                    break;
                }
            }
            fclose(pFile);
        }
    }
    return result;
}




int crearARchivo(ArrayList* pList)
            {
                int result = 0;
                if(pList != NULL)
                {
                    FILE* pFile;


                    pFile = fopen("melodia_corregida.txt", "a");


                    if(pFile != NULL)
                    {
                        int i;
                        for(i = 0; i < pList->len(pList); i++)
                        {
                            //eMelodia* melodiaAux=newMelodia();

                            eMelodia* melodiaAux = pList->get(pList, i);

                            if(melodiaAux != NULL)
                            {
                                if(melodiaAux->nota!='E'&&melodiaAux->nota!='C'&&melodiaAux->nota!='D')
                                {
                                   fprintf(pFile,"%c;%d;%d\n",melodiaAux->nota,melodiaAux->duration,melodiaAux->volume);
                                   continue;

                                }


                                if(melodiaAux->nota=='C')
                                {
                                   melodiaAux->nota='D';
                                   fprintf(pFile,"%c;%d;%d\n",melodiaAux->nota,melodiaAux->duration,melodiaAux->volume);
                                   continue;

                                }

                                if(melodiaAux->nota=='D')
                                {
                                  melodiaAux->nota='E';
                                  fprintf(pFile,"%c;%d;%d\n",melodiaAux->nota,melodiaAux->duration,melodiaAux->volume);
                                  continue;

                                }

                                if(melodiaAux->nota=='E')
                                {
                                   //melodiaAux->nota='C';
                                   char auxChar;
                                   auxChar='C';

                                   fprintf(pFile,"%c;%d;%d\n",auxChar,melodiaAux->duration,melodiaAux->volume);
                                   continue;

                                }


                            }
                        }
                        fclose(pFile);
                    }
                }
                return;
            }





