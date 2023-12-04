#include <iostream>
#include <cstdlib>
using namespace std;

struct nodo 
{
	int dato;
	struct nodo *liga_vertice;
	struct nodo *liga_arista;
	
	
};

typedef struct nodo *registro;										//apuntadores 
registro sig_ver, ant_ver, cab_ver, sig_ari, ant_ari, dir1, dir2;

//registro del vertice
registro nuevo_vertice(int dat)
{
	registro reg_ver=new(struct nodo);
	reg_ver->dato=dat;
	reg_ver->liga_vertice=NULL;
	reg_ver->liga_arista=NULL;
	return reg_ver;
	
}

//insertar dato dentro del vertice
void insertarVertice(int dat)
{
	int sw=0;
	ant_ver=cab_ver;
	sig_ver=cab_ver;
	
	while(sig_ver!=NULL && sw==0)		//busca el dato, de encontrarse no se graba en el grafo, de no encontrarse significa que no ha sido borrado
	{
		if(sig_ver->dato==dat)
		{
			sw=1;
		}
		else
		{
			ant_ver=sig_ver;
			sig_ver=sig_ver->liga_vertice;
		}
		
	}
	if(sw==1)
	{
		cout<<"EL VERTICE YA EXISTE\n";
		
	}
	else 
	{
		if(cab_ver==NULL)
		{
			cab_ver=nuevo_vertice(dat);
			
		}
		else
		{
			ant_ver->liga_vertice=nuevo_vertice(dat);
			
		}
		cout<<"VERTICE AGREGADO\n";
		
	}
	
}

//buscar vertice de origen y de destino
registro recorrer_vertice(int dat)
{
	registro dir;
	dir=NULL;
	sig_ver=cab_ver;
	
	while(sig_ver!=NULL)
	{
		if(sig_ver->dato==dat)
		{
			dir=sig_ver;
			
		}
		sig_ver=sig_ver->liga_vertice;
		
	}
	return dir;
	
}

//registro de la arista
registro nueva_arista(int pes)
{
	registro reg_ari=new(struct nodo);
	reg_ari->dato=pes;
	reg_ari->liga_arista=NULL;
	reg_ari->liga_vertice=dir2;
	return reg_ari;
	
}

//insertar dato dentro de la arista
void insertarArista(int dato_destino)
{
	int pes, sw2=0;
	ant_ari=dir1;
	sig_ari=dir1;
	
	while(sig_ari!=NULL && sw2==0)
	{
		if(sig_ari->dato==dato_destino)
		{
			sw2=1;
			
		}
		else
		{
			ant_ari=sig_ari;
			sig_ari=sig_ari->liga_arista;
			
		}
		
	}
	
	if(sw2==1)
	{
		cout<<"LA ARISTA YA EXISTE\n";
		
	}
	else
	{
		ant_ari->liga_arista=nueva_arista(pes);
		
	}
	
	
}

//ver grafo
void verlista()
{
	cout<<"\n\n VER LISTA  DE VERTICES Y ARISTAS";
	sig_ver=cab_ver;
	
	while(sig_ver!=NULL)
	{
		cout<<"\n EL NODO:  ";
		cout<<(sig_ver->dato);
		cout<<" TIENE LOS SIGUIENTES VERTICES COMO ARISTAS: ";
		sig_ari=sig_ver->liga_arista;
		while(sig_ari!=NULL)
		{
			cout<<" ";
			dir1=sig_ari->liga_vertice;
			cout<<dir1->dato;
			sig_ari=sig_ari->liga_arista;
			
		}
		sig_ver=sig_ver->liga_vertice;
	}
	
	
}

int main()
{
	cab_ver=NULL;
	int dato_origen, dato_destino;
	int sw, opcion;
	
	do
	{
		cout<<"\n\t --SELECCIONE LA OPCION A REALIZAR-- \n"<<endl;
		cout<<"1) CREAR VERTICE"<<endl;
		cout<<"2) CREAR ARISTAS"<<endl;
		cout<<"3) MOSTRAR GRAFO"<<endl;
		cout<<"4) SALIR"<<endl;
		cout<<"\n Ingrese su opcion: ";
		cin>>opcion;
		
		switch(opcion)
		{
			case 1: 
			cout<<"INGRESE UN NUMERO PARA EL VERTICE:  ";
			cin>>dato_origen;
			insertarVertice(dato_origen);
			system("pause");
			break;
			
			case 2: 
			cout<<"INGRESE EL NODO DE ORIGEN:  ";
			cin>>dato_origen;
			cout<<"INGRESE EL NODO DEL DESTINO:  ";
			cin>>dato_destino;
			dir1=recorrer_vertice(dato_origen);
			dir2=recorrer_vertice(dato_destino);
			if(dir1==NULL || dir2==NULL)
			{
				cout<<"\nEL NODO DE ORIGEN O EL NODO DE DESTINO NO EXISTE\n";
				
			}
			else
			{
				insertarArista(dato_destino);
				
			}
			system("pause");
			break;
			
			case 3: 
			verlista();
			cout<<endl<<endl;
			system("pause");
			break;
			
			case 4:
				break;
			
			default:
			cout<<"INGRESE UNA OPCION VALIDA\n";
			system("pause");
			
		}
		system("cls");
	}while(opcion!=4);
	cout<<"\nVUELVA PRONTO:)";
	
	return 0;
}

