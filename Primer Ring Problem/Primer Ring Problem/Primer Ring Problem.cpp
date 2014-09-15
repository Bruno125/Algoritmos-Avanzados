// Primer Ring Problem.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdio.h>
#include <vector>

using namespace std;

vector<int> casos;
vector<int> anillo;

bool estaEnVector(int n,vector<int> vec){
	for(int i=0;i<vec.size();i++)
		if(n==casos[i])	return true;
	return false;
}


bool esPrimo(int num){
	if(num==0)	return false;
	for(int i=2;i<num;i++)
		if(num%i==0)	return false;
	return true;
}

int siguienteNumero(int num){

	for(int i=num+1;i<=anillo.size();i++)
		if(!estaEnVector(i,anillo))	return i;
	return siguienteNumero(0);
}

void colocaNumero(int num,int pos){
	if(num==1 && !esPrimo(anillo[anillo.size()-1]+1)){//Caso de éxito1
		for(int i=0;i<anillo.size();i++)
			printf("%d",anillo[i]);
		printf("\n");
	}
	if(num==-1){
		colocaNumero(siguienteNumero(num),pos);
	}

	if(esPrimo(num+anillo[pos-1])){//Es un número válido
		anillo[pos]=num; //Coloca al número
		if(pos==anillo.size()) colocaNumero(1,0); //Si es el último, pasa al caso de éxito
		else
			colocaNumero(siguienteNumero(num),pos+1); //No es el último, coloca el número que
	}
	else
		colocaNumero(siguienteNumero(num),pos);


}

void ColocaNumeros(){
	anillo[0]=1;
	colocaNumero(2,1);
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
		ColocaNumeros();
		
	}

    return 0;
}
