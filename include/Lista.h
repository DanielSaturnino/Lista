/*
Nombre: Daniel Manzano Saturnino
Descripcion: Este programa es una
lista contiene todos los metods que una
estructura de tipo lista debe de llevar
Atributos: NODO H Y NODO T
*/
#include "Nodo.h"

class Lista
{
public:
	Nodo* H;
	Nodo* T;	
	Lista();
	Lista(int Dato);
	bool ListaVacia();
	void AddInicio(int Dato);
	void AddFinal(int Dato);
	void AddRef(int Dato, int Ref);
	int RemoveInicio();
	int RemoveFinal();
	int RemoveRef(int Ref);
	int VaciarLista();
	Nodo* BuscarElemento(int Dato);
	void Show();
};