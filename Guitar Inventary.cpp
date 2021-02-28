//Rafael de Jesús Anguiano Suárez del Real
//Inventario de Tienda de Guitarras 
//Campos: Codigo de inventario del producto, marca, Tipo de guitarra.
#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

struct Nodo{
	int ide;
	Nodo *izq;
	Nodo *der;
};

Nodo *invent=NULL;

void agregarNodo(Nodo *&arbol, int de)
{
	if(arbol==NULL)
	{
		Nodo *nuevoNodo=new Nodo();
		nuevoNodo->ide=de;
		nuevoNodo->izq=NULL;
		nuevoNodo->der=NULL;
		arbol=nuevoNodo;
	}
	else
	{
		int valorDeRaiz = arbol->ide;
		if(de<valorDeRaiz)
		{
			agregarNodo(arbol->izq, de);
		}
		else
		{
			agregarNodo(arbol->der, de);
		}
	}
}

void mostrarArbol(Nodo *&arbol, int nivel){
	if(arbol==NULL)
	{
		return;
	}
	else{
		mostrarArbol(arbol->der, nivel+1);
		for(int i=0; i<nivel; i++)
		{
			cout<<"   ";
		}
		cout<<"Cl:"<<arbol->ide<<endl;
		mostrarArbol(arbol->izq, nivel +1);
	}
}

int main (){
	int opc, i, id=0;
	int clave, clbus;
	char marca[15], marbus[15];
	char nombre[15], nombus[15];
	char seg;
	char blanco[15]= "";
	FILE *inventario;
	do{
		system("cls");
		cout<<"PLATAFORMA DE INVENTARIO DE LA TIENDA MUSICAL\n";
		cout<<"\n 1) Agregar un registro.";
		cout<<"\n 2) Lista de Registros desde archivo.";
		cout<<"\n 3) Arbol de IDs.";
		cout<<"\n   Buscar...";
		cout<<"\n 4) ... en funcion de ID.";
		cout<<"\n 5) ... en funcion de Marca.";
		cout<<"\n 6) ... en funcion de Tipo de Guitarra.";
		cout<<"\n 7) Borrar archivos.";
		cout<<"\n 8) Salir\n";
		cout<<"\n 9) Imprimir registro 2 y 3. \n";
		cin>>opc;
		switch(opc)
		{
			case 1: //FINALIZADO
					inventario=fopen("inventario.dat", "a");
					system("cls");
					id=id+1;
					cout<<"\n Agregando registro:";
					cout<<"\n\t Clave: ";
					cin>>clave;
					cout<<"\n\t Marca: ";
					cin>>marca;
					cout<<"\n\t Tipo de Guitarra (No poner espacios): ";
					cin>>nombre;
					fwrite(&id, sizeof(id),1,inventario);
					fwrite(&clave, sizeof(clave),1,inventario);
					fwrite(&marca, sizeof(marca),1,inventario);
					fwrite(&nombre, sizeof(nombre),1,inventario);
					fclose(inventario);
					agregarNodo(invent, clave);
					cout<<"\n El registro se ha ingresado correctamente \n";
					system("pause");
				break;
			case 2: //Leer desde archivos FINALIZADO
					system("cls"); //OPCIONAL
					inventario=fopen("inventario.dat", "r");
					cout<<"\nClave\tMarca\tNombre\n";
					while(!feof(inventario)){
						fread(&id, sizeof(id),1,inventario);
						fread(&clave, sizeof(clave),1,inventario);
						if(!feof(inventario)){
							fread(&marca, sizeof(marca),1,inventario);
							fread(&nombre, sizeof(nombre),1,inventario);
							cout<<clave<<"\t"<<marca<<"\t"<<nombre<<"\n";
						}
					}
					cout<<"\n FIN DE LA LECTURA\n";
					fclose(inventario);
					system("pause");
				break;
			case 3: //Cargar estructuras 	FINALIZADO
					system("cls");
					cout<<"\nArbol de CLAVES de Guitarra:\n";
					mostrarArbol(invent, 0);
					system("pause");
				break;
			case 4: //Buscar desde ID FINALIZADO
					system("cls"); //OPCIONAL
					i=0;
					inventario=fopen("inventario.dat", "r");
					cout<<"Clave a buscar: ";
					cin>>clbus;
					cout<<"\n   Clave\tMarca\tNombre\n";
					while(!feof(inventario)){
						fread(&id, sizeof(id),1,inventario);
						fread(&clave, sizeof(clave),1,inventario);
						if(!feof(inventario)){
							fread(&marca, sizeof(marca),1,inventario);
							fread(&nombre, sizeof(nombre),1,inventario);
							if(clave==clbus)
							{
								i=i+1;
								cout<<i<<") "<<clave<<"\t"<<marca<<"\t"<<nombre<<"\n";
							}
						}
					}
					cout<<"\n Se encontraron "<<i<<" guitarras con esa clave.\n";
					fclose(inventario);
					system("pause");
				break;
			case 5: //Buscar desde Marca  FINALIZADO
					system("cls"); 
					i=0;
					inventario=fopen("inventario.dat", "r");
					cout<<"Marca a buscar: ";
					cin>>marbus;
					cout<<"\n   Marca\tClave\tNombre\n";
					while(!feof(inventario)){
						fread(&id, sizeof(id),1,inventario);
						fread(&clave, sizeof(clave),1,inventario);
						if(!feof(inventario)){
							fread(&marca, sizeof(marca),1,inventario);
							fread(&nombre, sizeof(nombre),1,inventario);
							if(strcmp(marca, marbus)==0)
							{
								i=i+1;
								cout<<i<<") "<<marca<<"\t"<<clave<<"\t"<<nombre<<"\n";
							}
						}
					}
					cout<<"\n Se encontraron "<<i<< " guitarras con esa Marca.\n";
					fclose(inventario);
					system("pause");
				break;
			case 6: //Buscar desde Tipo de guitarra   FINALIZADO
					system("cls"); 
					i=0;
					inventario=fopen("inventario.dat", "r");
					cout<<"Guitarra a buscar: ";
					cin>>nombus;
					cout<<"\n   Nombre\tClave\tMarca\n";
					while(!feof(inventario)){
						fread(&id, sizeof(id),1,inventario);
						fread(&clave, sizeof(clave),1,inventario);
						if(!feof(inventario)){
							fread(&marca, sizeof(marca),1,inventario);
							fread(&nombre, sizeof(nombre),1,inventario);
							if(strcmp(nombre, nombus)==0)
							{
								i=i+1;
								cout<<i<<") "<<nombre<<"\t"<<clave<<"\t"<<marca<<"\n";
							}
						}
					}
					cout<<"\n Se encontraron "<<i<<" guitarras con ese Nombre.\n";
					fclose(inventario);
					system("pause");
				break;
			case 7: //Borrar archivo  BORRA EL ARCHIVO (ERROR: Si se busca algún dato después de borrar, se buguea).
					system("del inventario.dat");
				break;
			case 8:
					cout<<"\n\n Muchas gracias por utilizar la plataforma.";
				break;
			case 9:
					system("cls"); //EL DEL EXAMEN
					i=0;
					inventario=fopen("inventario.dat", "r");
					cout<<"\n   Clave\tMarca\tNombre\n";
					while(!feof(inventario)){
						fread(&id, sizeof(id),1,inventario);
						fread(&clave, sizeof(clave),1,inventario);
						if(!feof(inventario)){
							fread(&marca, sizeof(marca),1,inventario);
							fread(&nombre, sizeof(nombre),1,inventario);
							if(id==2 || id==3)
							{
								i=i+1;
								cout<<i<<") "<<clave<<"\t"<<marca<<"\t"<<nombre<<"\n";
							}
						}
					}
					cout<<"\n Son las guitarras del registro 2 y 3.\n";
					fclose(inventario);
					system("pause");
				break;
	}
	}while(opc!=8);
	return 0;
}
