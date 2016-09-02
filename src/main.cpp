#include "Lista.h"



int main()
{
	Lista l = Lista();
	l.AddInicio(3);
	l.AddInicio(2);
	l.AddFinal(8);
	l.AddFinal(6);
	l.AddRef(7,3);
	l.AddInicio(9);
	l.AddFinal(5);
	l.Show();
	std::cout<<"HASTA AQUIII SE AGREGAN ELEMENTOS"<<std::endl;
	l.BuscarElemento(2);
	std::cout<<"EMPLIEZA ELIMINACION"<<std::endl;
	l.RemoveRef(6);
	l.RemoveFinal();
	l.RemoveInicio();
	l.Show();
	std::cout<<"HASTA AQUIII SE quita ELEMENTOS"<<std::endl;
	l.VaciarLista();
	l.Show();
	return 0;
}