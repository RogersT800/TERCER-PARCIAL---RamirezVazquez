#include <iostream>
#include <cmath>
#include "nodo_b.h"

using namespace std;

void agregar(nodo_b *);
void presentar(nodo_b *);
void completarNivel(nodo_b *, int, int);

int op, x;
nodo_b *R, *T; // Punteros

int main(int argc, char **argv)
{
    do
    {
    	system("cls");
        cout << "MENU" << endl;
        cout << "1) AGREGAR VALOR" << endl;
        cout << "2) MOSTRAR VALORES" << endl;
        cout << "3) SALIR" << endl;
        cout<<"SELECCIONE UNA OPCION: "<< endl;
        cin >> op;

        switch (op)
        {
        case 1:
            cout << "INGRESE 1 NUMERO: " << endl;
            cin >> x;
            agregar(R);
            system("PAUSE");
            break;

        case 2:
            presentar(R);
            system("PAUSE");
            break;

        case 3:
        	system("PAUSE");
            break;

        default:
            cout << "INGRESE UNA OPCION VALIDA" << endl;
            system("PAUSE");
        }

    } while (op != 3);

    return 0;
}

// AGREGAR VALORES

void agregar(nodo_b *f)
{
    if (R == NULL)
    {
        T = new nodo_b();
        T->id = x;
        T->Iz = NULL;
        T->Der = NULL;
        R = T; // T es el nodo raiz
    }
    else if (x > f->id)
    {
        if (f->Der == NULL)
        {
            T = new nodo_b();
            T->id = x;
            T->Iz = NULL;
            T->Der = NULL;
            f->Der = T;
            completarNivel(R, 1, 0); // Completar el nivel del lado derecho despues de agregar un nuevo nodo
        }
        else
        {
            agregar(f->Der);
        }
    }
    else
    {
        if (f->Iz == NULL)
        {
            T = new nodo_b();
            T->id = x;
            T->Iz = NULL;
            T->Der = NULL;
            f->Iz = T;
            completarNivel(R, 1, 0); // Completar el nivel del lado izquierdo despues de agregar un nuevo nodo
        }
        else
        {
            agregar(f->Iz);
        }
    }
}

// COMPLETAR NIVEL

void completarNivel(nodo_b *f, int nivel, int nivelActual)
{
    if (f != NULL)
    {
        if (nivel == nivelActual)
        {
            
            while (pow(2, nivelActual) <= nivel)
            {
                if (f->Iz == NULL)
                {
                    T = new nodo_b();
                    T->id = -1; 		// valor especial para un nodo NULL
                    T->Iz = NULL;
                    T->Der = NULL;
                    f->Iz = T;
                }
                if (f->Der == NULL)
                {
                    T = new nodo_b();
                    T->id = -1; 		// valor especial para un nodo NULL
                    T->Iz = NULL;
                    T->Der = NULL;
                    f->Der = T;
                }
                nivelActual++;
            }
        }

        completarNivel(f->Der, nivel, nivelActual + 1);
        completarNivel(f->Iz, nivel, nivelActual + 1);
    }
}

// PRESENTAR VALORES - INORDEN

void presentar(nodo_b *f)
{
    if (f != NULL)
    {
    	presentar(f->Iz);
        cout << "ID:  " << f->id << endl;
        presentar(f->Der);
        
    }
}
