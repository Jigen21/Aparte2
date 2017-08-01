#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "utn.h"

typedef struct
{
   int numero;
   char nombre[50];
   int par;
   int impar;
   int primo;


}eNumero;


int main()
{
    char opcion;
    char opcionAoB;
    int opcionNumero;
    FILE* archivoNumeros;
    int numeroAux;
    int numeroAuxDos;
    char nuevoNumero[100];
    int i;
    int flag=0;
    int a=0;
    int j;
    int flagOpcionUno=0;
    int esPrimo;





    ArrayList* arrayNumeros=al_newArrayList();
    char nombre[100] ,numero[100],par[100],impar[100],primo[100];



    char nombreAux[50];

    while(opcion!='s')
    {
        printf("1-Alta del archivo\n");
        printf("2-modificar numero\n");
        printf("3-Baja de numero\n");
        printf("4-Completar de numero\n");
        printf("5-generar y listar de numero\n");
        printf("6-informar de numero\n");
        scanf("%d",&opcionNumero);

       switch(opcionNumero)
       {
       case 1:

           if(flagOpcionUno!=0)
           {
                            eNumero* auxNumeroDin=malloc(sizeof(eNumero));

                            //printf("ingrese nuevo numero\n");
                            //scanf("%d",&numeroAux);
                            numeroAux=getValidInt("Ingrese un numero\n","ERROR\n",0,5000);

                            printf("ingrese el nombre del numero\n");
                            fflush(stdin);
                            scanf("%s",nuevoNumero);
                            fflush(stdin);


                            auxNumeroDin->numero=numeroAux;
                            strcpy(auxNumeroDin->nombre,nuevoNumero);
                            arrayNumeros->add(arrayNumeros,auxNumeroDin);
           }



           if(flagOpcionUno==0)
           {
                    opcionAoB=getChar("Elija A o B,solo va a poder apretar la A(cargar un archivo)una sola vez\n");

                       if(opcionAoB=='a')
                       {
                            if(archivoNumeros=fopen("datos.csv","r"))
                               {
                                   while(!feof(archivoNumeros))
                                   {
                                    eNumero* numeroDin=malloc(sizeof(eNumero));
                                    fscanf(archivoNumeros,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",numero,nombre,par,impar,primo);

                                    numeroDin->numero = atoi(numero);
                                    numeroDin->par = atoi(par);
                                    numeroDin->impar = atoi(impar);
                                    numeroDin->primo = atoi(primo);
                                    strcpy(numeroDin->nombre, nombre);

                                    printf("%s -   %s\n",numero,nombre);

                                    arrayNumeros->add(arrayNumeros, numeroDin);



                                   }
                                   fclose(archivoNumeros);
                                   flagOpcionUno=1;
                               }
                       }


                       if(opcionAoB=='b')
                       {
                            eNumero* auxNumeroDin=malloc(sizeof(eNumero));

                            //printf("ingrese nuevo numero\n");
                            //scanf("%d",&numeroAux);

                            numeroAux=getValidInt("Ingrese un numero\n","ERROR\n",0,5000);


                            printf("ingrese el nombre del numero\n");
                            fflush(stdin);
                            scanf("%s",nuevoNumero);
                            fflush(stdin);


                            auxNumeroDin->numero=numeroAux;
                            strcpy(auxNumeroDin->nombre,nuevoNumero);
                            arrayNumeros->add(arrayNumeros,auxNumeroDin);

                       }


           }


        break;

       case 2:

           printf("Porfavor ingrese numero a modificar\n");
           scanf("%d",&numeroAux);

               for(i=0;i<arrayNumeros->size;i++)
               {
                   eNumero* auxNumeroDin=malloc(sizeof(eNumero));
                   auxNumeroDin=arrayNumeros->get(arrayNumeros,i);
                   if(auxNumeroDin->numero==numeroAux)
                   {
                       if(flag==0)
                       {
                           printf("Coincidencia encontrada,ingrese nuevo numero\n");
                           scanf("%d",&numeroAuxDos);

                           printf("ingrese nombre del nuevo numero\n");
                           scanf("%s",nuevoNumero);
                           flag=1;
                       }

                       auxNumeroDin->numero=numeroAuxDos;
                       strcpy(auxNumeroDin->nombre,nuevoNumero);
                   }
               }

               for(i=0;i<arrayNumeros->size;i++)
               {
                eNumero* auxNumeroDin=malloc(sizeof(eNumero));
                auxNumeroDin=arrayNumeros->get(arrayNumeros,i);
                printf("%d---%s---%d---%d---%d\n",auxNumeroDin->numero,auxNumeroDin->nombre,auxNumeroDin->par,auxNumeroDin->impar,auxNumeroDin->primo);
               }

             flag=0;
       break;

       case 3:

           printf("Porfavor ingrese numero a buscar para dar de baja\n");
           scanf("%d",&numeroAux);

           for(i=0;i<arrayNumeros->size;i++)
           {
               eNumero* auxNumeroDin=malloc(sizeof(eNumero));
               auxNumeroDin=arrayNumeros->get(arrayNumeros,i);

                   if(auxNumeroDin->numero==numeroAux)
                   {
                       arrayNumeros->remove(arrayNumeros,i);
                       printf("Numero dado de baja con exito\n");
                   }
           }

           for(i=0;i<arrayNumeros->size;i++)
            {
                eNumero* auxNumeroDin=malloc(sizeof(eNumero));
                auxNumeroDin=arrayNumeros->get(arrayNumeros,i);
                printf("%d---%s---%d---%d---%d\n",auxNumeroDin->numero,auxNumeroDin->nombre,auxNumeroDin->par,auxNumeroDin->impar,auxNumeroDin->primo);
            }





        break;

        case 4:

            for(i=0;i<arrayNumeros->size;i++)
            {
              eNumero* auxNumeroDin=malloc(sizeof(eNumero));
              auxNumeroDin=arrayNumeros->get(arrayNumeros,i);
              esPrimo=auxNumeroDin->numero;
              a=0;
              if(auxNumeroDin->numero%2==0)
              {
                  auxNumeroDin->par=1;
              }
              if(auxNumeroDin->numero%2!=0)
              {
                  auxNumeroDin->impar=1;
              }
                  for(j=1;j<=esPrimo;j++)
                        {
                         if(esPrimo%j==0)
                            {
                              a++;
                            }
                        }

                     if(a==2)
                        {
                          auxNumeroDin->primo=1;
                        }
                     else
                     {
                            auxNumeroDin->primo=0;
                     }



            }


            for(i=0;i<arrayNumeros->size;i++)
            {
                eNumero* auxNumeroDin=malloc(sizeof(eNumero));
                auxNumeroDin=arrayNumeros->get(arrayNumeros,i);
                printf("%d---%s---%d---%d---%d\n",auxNumeroDin->numero,auxNumeroDin->nombre,auxNumeroDin->par,auxNumeroDin->impar,auxNumeroDin->primo);
            }



        break;

        case 5:


        break;

        case 6:



        break;

        case 7:

        opcion='s';

        break;



       }
    }








    return 0;
}
