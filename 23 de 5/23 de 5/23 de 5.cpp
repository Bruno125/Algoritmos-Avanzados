// 23 de 5.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <vector>

using namespace std;

enum OPERACIONES {SUMA=0,RESTA,MULTIPLICACION};

vector<int> numeros;
vector<OPERACIONES> operaciones;
int tamaño;
int numDeseado;

bool hayAlternativas(){
	bool cond=true;
	for(int i=0;i<operaciones.size();i++)
		if(operaciones[i]!=MULTIPLICACION){
			return true;
		}
	return false;
}

void cambiarOperador(int n){
	//No es necesario validar que n<0, puesto que en ese caso no pasaría el filtro de hayAlternativa()
	switch(operaciones[n]){
	case SUMA: 
		operaciones[n]=RESTA;	break;
	case RESTA: 
		operaciones[n]=MULTIPLICACION;	break;
	case MULTIPLICACION: 
		operaciones[n]=SUMA;
		cambiarOperador(n-1);	break;
	}
}

int BT(int n){
	if(n<0)	return 0;
	if(n==0)	return numeros[n];
	int acum=BT(n-1);
	switch(operaciones[n-1]){//Realiza la operacion correspondiente
		case SUMA:	acum+=numeros[n];	break;
		case RESTA:	acum-=numeros[n];	break;
		case MULTIPLICACION: acum=acum*numeros[n];	break;
	}

	if(n==tamaño-1){//Se trabajaron todos los operadores
		if(acum==numDeseado){//Se obtuvo el resultado deseado
			printf("Posible");
		}else{//No se obtuvo el resultado, hay que cambiar los operadores
			if(!hayAlternativas())//Comprobando si aún hay mas alternativas
				printf("Imposible");//No se pudo cambiar los operadores, puesto que ya se probaron todas las alternativas.
			else{//Se cambia el valor del operador y se vuelve a calcular el resultado
				cambiarOperador(n-1);
				BT(n);
			}
		}
	}
	return acum;

}

void BuscaSolucion(){
	BT(tamaño-1);
}

void main()
{
	numDeseado=23;
	tamaño=5;
	//Leer input --- PENDIENTE

	numeros.push_back(3);	numeros.push_back(4);	numeros.push_back(8);	numeros.push_back(5);	numeros.push_back(2);
	numeros.push_back(7);
	for(int i=0;i<tamaño;i++)
		operaciones.push_back(SUMA);

	BuscaSolucion();

	tamaño=0;


}
