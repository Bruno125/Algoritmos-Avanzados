// Primer Ring Problem.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> casos;
vector<int> anillo;

bool estaEnVector(int n,vector<int> vec){
	for(int i=0;i<vec.size();i++)
		if(n==vec[i])	return true;
	return false;
}

vector<int> devolverFaltantes(vector<int> vec){
	vector<int> arrayNuevo;
	for(int i=1;i<=vec.size();i++){
		if(!estaEnVector(i,vec))
			arrayNuevo.push_back(i);
	}
	return arrayNuevo;
}

bool esPrimo(int num){
	if(num==1)	return false;
	for(int i=2;i<num;i++)
		if(num%i==0)	return false;
	return true;
}

int siguienteNumero(int num){

	for(int i=num+1;i<=anillo.size();i++)
		if(!estaEnVector(i,anillo))	return i;
	return 0;
}

void colocaNumero(int pos){
	if(!estaEnVector(-1,anillo)){//El vector está lleno
		if(esPrimo(anillo[anillo.size()-1]+1)){//Comprueba que la suma del ultimo y el primer elemento del anillo sea primo
			//Imprime el arreglo
			for(int i=0;i<anillo.size();i++)
				printf("%d",anillo[i]);
			printf("\n");
		}
	}else{
		vector<int> faltantes=devolverFaltantes(anillo);//Te devuelve cuales son los numeros que falta colocar en el anillo
		for(int i=0;i<faltantes.size();i++){//Para cada uno de los elementos faltantes...
			if(esPrimo(faltantes[i]+anillo[pos-1])){//Se comprueba que sea un número válido
				anillo[pos]=faltantes[i]; //Coloca el número en la posicion que le corresponde
				colocaNumero(pos+1); //Para dicho número, se pasa a colocar el resto de los elementos desde la siguiente posición
				anillo[pos]=-1;//Se setea el número a -1. Esto ocurre cuando ya se intentaron colocar todos los elementos faltantes, se hayan logrado colocar o no.
			}
		}
	}


}

void ColocaNumeros(){
	anillo[0]=1;
	colocaNumero(1);
}

int main(array<System::String ^> ^args)
{
    freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	while(1){
		int num=-1;
		scanf("%d%c",&num);
		if(num==-1)	break;
		else
			if(!estaEnVector(num,casos) && num%2==0)	casos.push_back(num);
	}

	for(int i=0;i<casos.size();i++){
		anillo.clear();
		anillo.resize(casos[i],-1);
		printf("Caso %d:\n",i+1);
		ColocaNumeros();
		printf("\n");
	}

    return 0;
}
