#include "Lista.h"
/*
Constructor:
@Parametros:No recibe ningun parametro
@Result: No devuelve nada
Crea un nodo de con H y T apuntando a NULL
*/
	Lista::Lista()
	{
		this->H=NULL;
		this->T=NULL;
	}
/*
Constructor
@Parametros:un de tipo entero
@Result: No devuelve nada
Crea un nodo que apunta a H y a T
*/

	Lista::Lista(int Dato)
	{
		Nodo * aux= new Nodo(Dato);
		this->H=aux;
		this->T=aux;
		
	}

/*
Lista Vacia
@Parametros: No recibe parametros
@Result: DEVUELVE UN TRUE O UN FALSE DEPENDIENDO DEL CASO
Comprueba si la lista esta vacia revisando los apuntadores
de H y T si apuntan a NULL devuelve un true de lo contrario
un false
*/
	bool Lista::ListaVacia()
	{
		if (this->H == NULL && this->T == NULL)
			return true;
		return false;
	}
/*
AddInicio
@Parametros: recibe un dato de tipo entero 
@Result: No devuelve nada
Este metodo crea un nodo auxiliar que apunta a H 
llama al metodo lista vacia si se encuentra vacia 
agrega el elemento y asigna a T el nodo creado
de lo contrario H se le asigna el nuevo nodo
*/
	void Lista::AddInicio(int Dato)
	{
		Nodo* aux = new Nodo(Dato,this->H);
		if (ListaVacia())
		{
			this->T= aux;
		}
			this->H= aux;
	}
/*
AddFinal
@Parametros:Recibe un dato de tipo entero
@Result: No devuelve nada
Crea un nuevo nodo con dato nuevo, verifica si 
la lista esta vacia si si lo esta a H y T se le asigna
 el nuevo nodo, de lo contrario a T apunta a l nuevo nodo
 y a T se le asigna el nodo que se ha creado
*/
	void Lista::AddFinal(int Dato)
	{
		Nodo* aux=new Nodo (Dato);
		if(ListaVacia())
		{
			this->H= aux;
		 	this->T= aux;
		}else{
			this->T->setSig(aux);
			this->T= aux;
		}

	}
/*
AddRef
@Parametros:Dos datos de tipo entero 
@Result: No devuelve nada
Verifica si la lista esta vacia llamando al metodo lista Vacia
si esto se cumple crea un dato con un dato a H se le asigna 
el nodo creado y finalmente T es igual a H e imprime una leyenda
de lo contrario crea un nodo que apunta a H recorre la lista 
hasta que el nodo tenga el valor de la referencia y apunte 
a un valor diferente de T si se cumple lo  anterior apuntara
al siguiente valor hasta que llegue al elemento de referencia
una vez llegado verifica si el nodo no apunta a null
si  esto se cumple crea un nodo con el valor de dato y 
que apunta al siguiente del nodo que se creo y que 
apuntaba a H y finalmente a el primer nodo creado
se le asigna la referencia a la que apuntaba el segundo
nodo creado
si esto no se cumple arroja una leyenda
*/
	void Lista::AddRef(int Dato,int Ref)
	{
		if(ListaVacia())
		{
			Nodo* aux=new Nodo(Dato);
			this->H=aux;
			this->T=H;
			std::cout<<"No se encontro la referencia por que la lista esta vacia"<<std::endl;
			return;
		}

			Nodo*aux=this->H;
			while(aux->getDato()!=Ref && aux!=this->T)
			{
				aux=aux->getSig();
			}
			if(aux!=NULL)
			{
					Nodo* aux2=new Nodo(Dato,aux->getSig());
					aux->setSig(aux2);
			}else
			{
					std::cout<<"NO EXISTE LA REFERENCIA EN LA LISTA"<<std::endl;
			}
	}
/*
Remove Lista
@Parametros: No Recibe
@Result: Devuelve un entero
verifica que la lista este vacia con el metodo lista Vacia
Si se cumple arroja una leyenda y regresamos un cero
si no creamos una variablede tipo entero y le asignamos
 el valor de H despues H ahora apuntara al siguiente de H
 y preguntamos si H apunta NULL
si apunta a NULL si apunta entonces T tambien apuntara a NULL
si no solo retorna un dato
*/
	int Lista::RemoveInicio()
	{
		if(ListaVacia())
		{
			std::cout<<"LA LISTA ESTA VACIA"<<std::endl;
			return NULL;
		}else
		{
			int Dato=H->getDato();
			this->H=H->getSig();
			if(this->H==NULL)
				this->T=NULL;
			return Dato;
		}
	}
/*
RemoveFinal
@Parametros: no tiene
@Result: Devuelve un entero
Verifica si la lista esta vacia con el metodo Lista Vacia
si esta vacia da una leyenda y retorna un cero 
si no crea un dato se le asigna el dato de T 
y pregunta si H es diferente de T si esto es correcto
crea un nodo que apunta a H recorre la lista con un 
while hasta que apunte a T cuando llegue sale y a T se
le asigna el nuevo nodo y T ahora el T anterior apunta a
un NULL, si no se cumplio lo anterior H y T apuntan a NuLL
al final regresa un dato  
*/
	int Lista::RemoveFinal()
	{
		if(ListaVacia())
		{
			std::cout<<"LA LISTA ESTA VACIA"<<std::endl;
			return NULL;
		}
		int Dato=T->getDato();
			if(this->H!=this->T)
			{
				Nodo* aux=this->H;
				while(aux->getSig()!=this->T)
				{
					aux=aux->getSig();
				}
					this->T=aux;
					this->T->setSig(NULL);
			}else
			{
				this->H=NULL;
				this->T=NULL;
			}
	return Dato;
	}
/*
RemoveRef
@Parametros:Recibe un entero 
@Result: devuelve un entero
Verifica si la lista esta vacia con el metodo Lista Vacia
si esta vacia retorna UN NuLL si no va crear dos nodos el primero 
se recorrera desde H hasta el dato dado por   el usuario
el segundo desde H hasta uno antes del primer nodo creado
y preguntamos si el primer nodo
creado no apunta NULL si se cumple al segundo creado se le
asigna el siguiente del primer nodo perdiendo la referencia del
primer nodo si apunta a NULL arroja una leyenda de que no se
encontro nada
retorna un Dato
*/

	int Lista::RemoveRef(int Ref)
	{
		if(ListaVacia())
		{
			std::cout<<"LA LISTA ESTA VACIA"<<std::endl;
			return NULL;
		}else
		{
			Nodo*aux=this->H;
			while(aux->getDato()!=Ref && aux!=this->T)
			{
					
				aux=aux->getSig();
			}
				Nodo* aux2=this->H;
				while(aux2->getSig()!=aux)
				{
					aux2=aux2->getSig();
				}
			if(aux!=NULL)
				{
						
						aux2->setSig(aux->getSig());
						
				}else
				{
						std::cout<<"NO EXISTE LA REFERENCIA EN LA LISTA"<<std::endl;
				}
				return Ref;
		}

	}
/*
Lista Vacia
@Parametros: No recibe nada
@Result: Devuelve un entero
Verifica si la liasta esta vacia con el metodo Lista vacia
si lo esta envia una leyenda y retorna un cero si
no a H y T los apunta a NULL e imprime una leyenda
retorna un cero
*/
	int Lista::VaciarLista()
	{
		if (ListaVacia())
		{
				std::cout<<"La lista esta vacia"<<std::endl;
				return 0;
		}else{
				this->H=NULL;
				this->T=NULL;
				std::cout<<"He vasiado la lista"<<std::endl;
			
		}
		return 0;
	}
/*
Buscar elemento 
@paramametros: Recibe un dato de tipo entero 
@Result: devuelve un nodo
Verifica con el metodo lista vacia si la lista esta vacia
si esta arroja una leyenda y devuelve un NULL
de lo contrario crea un nodo y lo recorre hasta encontrar
el dato y pregunta si el dato es igual al dato que esta en ese 
nodo entonces imprime una leyenda y el valor del nodo
si no devuelve una leyenda en ambos casos regresa el nodo
creado
*/
	Nodo* Lista::BuscarElemento(int Dato)
	{
		if (ListaVacia())
		{
			std::cout<<"NO SE ENCOTRO ELEMENTOS PORQUE LA LISTA ESTA VACIA"<<std::endl;	
			return NULL;
		}else
		{
			Nodo* aux=this->H;
			while(aux->getDato()!=Dato && aux!=this->T)
			{
				aux=aux->getSig();
			}
			if(aux->getDato()==Dato)
			{
				std::cout<<"ELEMENTO ENCONTRADO:"<<std::endl;
				std::cout<<aux->getDato()<<std::endl;
				return aux;
			}
			std::cout<<"NO se encontro el elemento"<<std::endl;
		}
			
	}
/*
Show
@parametros: no recibe nada
@Result: no devuelve nada
Crea un nodo auxiliar que apunta a H
y este nodo recorre la lista hasta llegar a NULL;
caba vez que cambia imprime el dato donde se encuentra
*/
	void Lista::Show()
	{
		Nodo* aux = this->H;
		while(aux!=NULL)
		{
			std::cout<<aux->getDato()<<std::endl;
			aux=aux->getSig();
		}
	}