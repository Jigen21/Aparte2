#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "Functions.h"
#include "Class.Services.h"

eNota* newNota()
{
    eNota* newNote = (eNota*) malloc(sizeof(eNota));
    return newNote;
}

int cargarNotas(ArrayList* pList)
{
    int result = -1;

    if(pList != NULL)
    {
        char nota[100], frecuencia[100];
        FILE* pFile;
        pFile = fopen("notas.txt", "r");
        pList->clear(pList);

        if(pFile != NULL)
        {
            while(!feof(pFile))
            {
                eNota* notaAux = newNota();
                if(notaAux != NULL)
                {
                    fscanf(pFile,"%[^;];%[^\n]\n", nota,frecuencia);
                    notaAux->frecuencia = atoi(frecuencia);
                    notaAux->nota=nota[0];


                    result = pList->add(pList, notaAux);
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

