#include <iostream>
#include "nodo_b.h"

using namespace std;
void agregar(nodo_b *);
void presentar(nodo_b *);

int op, x;
nodo_b *R,*T;		//Punteros 

int main(int argc, char** argv) 
{
	do
	{
		system("cls");
		cout<<"------------MENU ARBOLES BINARIOS-------------"<< endl;
		cout<<"1) AGREGAR VALOR"<< endl;
		cout<<"2) MOSTRAR VALORES"<< endl;
		cout<<"3) SALIR"<< endl;
		cout<<"SELECCIONE UNA OPCION: "<< endl;
		cin>>op;
		
		switch(op)
		{
			case 1: 
				cout<<"INGRESE UN NUMERO: "<< endl;
				cin>>x;
				agregar(R);
				system("PAUSE");
				break;
				
			case 2: 
				presentar(R);
				system("PAUSE");
				break;
				
			case 3:
				break;
				
			default:
				cout<<"INGRESE UNA OPCION VALIDA"<<endl;
				system("PAUSE");
			
		}
	
		
	}while(op!=3);
	
	return 0;
}

//AGREGAR VALORES

void agregar(nodo_b *f)
{
	if(R==NULL)
	{
		T = new nodo_b();
		T->id=x;
		T->Iz=NULL;
		T->Der=NULL;
		R=T;				//T es el nodo raiz
		
	}
	else if(x>f->id)
	{
		if(f->Der==NULL)
		{
			T = new nodo_b();
			T->id=x;
			T->Iz=NULL;
			T->Der=NULL;	
			f->Der=T;
		}
		else 
		{
			agregar(f->Der);
			
		}
		
		
	}
	else 
	{
		if(f->Iz==NULL)
		{
			T = new nodo_b();
			T->id=x;
			T->Iz=NULL;
			T->Der=NULL;	
			f->Iz=T;
			
		}
		else 
		{
			agregar(f->Iz);
			
		}
		
	}
	
	
}

//PRESENTAR VALORES

void presentar (nodo_b *f)
{
	if(f!=NULL)
	{
		cout<<"ID:  "<<f->id<<endl;
		presentar(f->Der);
		presentar(f->Iz);
		
		
	}
	
}




