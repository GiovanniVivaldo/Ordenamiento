#include <stdio.h>
#include <stdlib.h>

typedef struct _Nodo
{
    int Dato;
    struct _Nodo *Siguiente;
    struct _Nodo *Anterior;
}
Nodo;
Nodo* Top;
Nodo *first;

Nodo* crearNodo(int Dato)
{
    Nodo* Nuevo=(Nodo*)malloc(sizeof(Nodo));

    Nuevo->Dato=Dato;
    Nuevo->Siguiente=NULL;
    Nuevo->Anterior=NULL;

    return Nuevo;
}

void Push(int Dato)
{
    Nodo* Aux=Top;
    Nodo* Nuevo=crearNodo(Dato);

    if(Top==NULL)
    {
        Top=Nuevo;

        return;
    }
    while(Aux->Siguiente!=NULL)
        Aux=Aux->Siguiente;

    Aux->Siguiente=Nuevo;
    Nuevo->Anterior=Aux;
}

void ver()
{
    Nodo* Aux=Top;

    printf("\nLista Ordenada:\n");

    while(Aux!=NULL)
    {
        printf("%d \n", Aux->Dato);
        Aux=Aux->Siguiente;
    }
}

void leer()
{
    FILE *Archivo;
    int Dato;

    Archivo=fopen("practica_3.txt", "r");

    printf("Lista Original\n");

    while(!feof(Archivo))
    {
        fscanf(Archivo, "%d", &Dato);
        printf("%d\n", Dato);
        Push(Dato);
    }
    fclose(Archivo);
}

void ordena_lista()
{

    leer();

    Nodo *actual, *siguiente;
    int n;

    actual = Top;

    while(actual->Siguiente != NULL)
    {
        siguiente = actual->Siguiente;

        while(siguiente != NULL)
        {
            if(actual->Dato > siguiente->Dato)
            {
                n = siguiente->Dato;
                siguiente->Dato = actual->Dato;
                actual->Dato = n;
            }

            siguiente = siguiente->Siguiente;

        }

        actual = actual->Siguiente;
        siguiente = actual->Siguiente;
    }

    ver();
}

void main()
{
    ordena_lista();
}

