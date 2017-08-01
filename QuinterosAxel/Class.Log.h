#include "ArrayList.h"


typedef struct
{
    char nota;
    int duration;
    int volume;
}eMelodia;



eMelodia* newMelodia();

int cargarMelodia(ArrayList* pList);


