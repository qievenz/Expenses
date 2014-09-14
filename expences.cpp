#include <iostream>
#include <stdio.h>
#include <time.h>
#include <fstream>
#include <typeinfo>
using namespace std;

//*****DECLARACION DE VARIABLES

typedef struct entrada {
	float gasto;
	//time_t fecha;
	//descripcion/articulo
};

//******FUNCIONES
//mostrar menu
void mostrar_menu(int &a)
{
	int opciones_totales = 2;
	do {
		scanf("***Consumos del mes***\n\n\
		1- Ingresar consumos\n\
		2- Mostrar promedio del mes\n\
		0- SALIR\n\
		%i", a);
	} while ( (a > opciones_totales) or (typeid(a).name() != typeid(int).name()) );
}
//ingresar datos
void ingreso_consumo(struct entrada reg) 
{
	cout << "Ingrese hasta que se canse";
	int contador = 0;
	do {
		scanf("Consumo: ", reg.gasto);
		//scanf("Fecha: ", reg.fecha);
		contador++;
		if (contador == sizeof(reg)) reg.resize(reg.size() + 1);
	} while (typeid(reg.gasto).name() != typeid(float).name());
	
}
//grabar datos
void grabar_datos(struct entrada reg)
{
	FILE *arch;
	arch = fopen("/home/ivan/Programando/Consumos/gastos.dat", 'a+b');
	fwrite(&reg, sizeof(struct entrada reg), 1, reg);
	arch.close();		
}
//promedio
float promediar(entrada a, int n)
{
	float prom = 0;
	for (i=0, i<=n, i++) prom += a.gasto;
	prom = prom/n;
	return prom;
}
//salir
void salir()
{
	return 0;
}	
	
int main()
{
	int opcion;
	struct entrada consumo(100);
	do {
		mostrar_menu(opcion);
		switch (opcion)
		{
			case 0:
				salir();		
			case 1:
				ingreso_consumo(consumo);
				grabar_datos(&consumo);
			case 2:
				for (i=0, i<=sizeof(consumo.gasto), i++){
					cout << promediar(consumo, sizeof(consumo));
				}
		}
	} while true;



	return 0;
}
