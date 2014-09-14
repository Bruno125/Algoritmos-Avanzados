// PropagandoNoticias.cpp : main project file.

#include "stdafx.h"
#include <vector>
#include <queue>
#include <stdio.h>
#define INFINITO 1000000;

using namespace std;

typedef vector<int> TListaAristas;
typedef vector<TListaAristas> TGrafo;

TGrafo grafo;

vector<int> BFS(int origen){
	vector<int>distancias;
	distancias.resize(grafo.size());

	queue<int> colaPendientes;

	for(int i=0;i<distancias.size();i++)
		distancias[i]=-1;

	distancias[origen]=0;

	colaPendientes.push(origen);
	while(!colaPendientes.empty()){
		int tempNodo=colaPendientes.front();
		colaPendientes.pop();
		for(int i=0;i<grafo[tempNodo].size();i++){
			int destino=grafo[tempNodo][i];
			if(distancias[destino]==-1){
				colaPendientes.push(destino);
				distancias[destino]=distancias[tempNodo]+1;
			}
		}
	}
	return distancias;

}

void main()
{
	freopen("input.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int cantEmpleados=0;
	scanf("%d",&cantEmpleados);
	grafo.resize(cantEmpleados);
	for(int i=0;i<cantEmpleados;i++){
		int cantAmigos=0;
		scanf("%d",&cantAmigos);
		//grafo[i].resize(cantAmigos);
		for(int j=0;j<cantAmigos;j++){
			int amigoTemp=0;
			scanf("%d",&amigoTemp);
			//grafo[i][j]=amigoTemp;
			grafo[i].push_back(amigoTemp);
		}
	}

	int cantPruebas=0;
	scanf("%d",&cantPruebas);
	for(int i=0;i<cantPruebas;i++){
		int empleadoOrigen=0;
		scanf("%d",&empleadoOrigen);
		vector<int>distanciasPrueba=BFS(empleadoOrigen);
		vector<int> contarFrec;
		contarFrec.resize(cantEmpleados);
		for(int j=0;j<cantEmpleados;j++){
			if(distanciasPrueba[j]!=-1){
				contarFrec[distanciasPrueba[j]]=contarFrec[distanciasPrueba[j]]+1;
			}
		}
		int diaAuge=0;

		for(int j=0;j<cantEmpleados;j++){
			if(contarFrec[j]>diaAuge)
				diaAuge=i;
		}

		printf("Dia auge: %d Valor auge: %d\n",contarFrec[diaAuge],diaAuge);



	}

	getchar();


}
