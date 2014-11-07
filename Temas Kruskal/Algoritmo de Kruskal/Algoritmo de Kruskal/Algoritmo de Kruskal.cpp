// Algoritmo de Kruskal.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <queue>
#include <stdio.h>
#include <functional>

#define INFINITO 10000000

using namespace std;

struct Arista{
	int origen,destino,distancia;
	Arista(int o,int dest,int dist) {
		origen=o;	destino=dest;	distancia=dist;
	}
	Arista(int dest,int dist) {
		origen=-1;	destino=dest;	distancia=dist;
	}
};

typedef pair<int,int> TNodo; //First= distancia, Second= nodo destino
typedef vector<Arista> TListaAristas;
typedef vector<TListaAristas> TGrafo;

vector<int> cant_hijos;
vector<int> id;

TGrafo myGrafo;
vector<bool> explorado;

bool comparaDistancias(const Arista &A,const Arista &B){
	return A.distancia>B.distancia;
}

int findSet(int a){
	if(a==id[a])	return a;
	else
		//El findSet busca el padre original recursivamente. Luego, se le irá asignando ese padre a cada uno de los nodos por los cuales haya pasado este algoritmo
		return id[a]=findSet(id[a]);
}

void initSet(int n){
	id.clear();	id.resize(n);
	cant_hijos.clear();	cant_hijos.resize(n,1);
	for(int i=0;i<n;i++)	id[i]=i;
}

bool sameSet(int a,int b){
	return	(findSet(a)== findSet(b));
}

void unionSet(int a,int b){
	int padreA=findSet(a);
	int padreB=findSet(b);

	if(padreA==padreB)	return;

	if(cant_hijos[padreA]<cant_hijos[padreB]){//El set de A
		id[padreA]=padreB;
		cant_hijos[padreB]+=cant_hijos[padreA];
	}else{
		id[padreB]=padreA;
		cant_hijos[padreA]+=cant_hijos[padreB];
	}
}

void une(int o,int d,int dist){
	myGrafo[o].push_back(Arista(o,d,dist));
	myGrafo[d].push_back(Arista(d,o,dist));
}

int _tmain()
{
	myGrafo.resize(9);
	une(0,1,4);		une(0,7,8);
	une(1,7,11);	une(1,2,8);
	une(2,8,2);		une(2,5,4);
	une(2,3,7);		une(3,5,14);
	une(3,4,9);		une(4,5,10);
	une(5,6,2);		une(7,8,7);
	une(7,6,1);		une(8,6,6);

	priority_queue<Arista,vector<Arista>,function<bool(Arista,Arista)>> ColaPendientes(comparaDistancias);
	for(int i=0;i<myGrafo.size();i++){
		for(int j=0;j<myGrafo[i].size();j++){
			Arista a=myGrafo[i][j];
			if(a.origen<a.destino)		ColaPendientes.push(a);
		}
	}

	int contador=0;
	initSet(myGrafo.size());
	int distancia_min=0;
	vector<Arista> MST; //Minimun spanning tree
	while(!ColaPendientes.empty() && contador<myGrafo.size()-1){//Se detiene cuando ya no quedan aristas, y cuando ya se encontró el número de aristas requerido
		Arista a=ColaPendientes.top();
		ColaPendientes.pop();
		if(!sameSet(a.origen,a.destino)){
			contador++;
			unionSet(a.origen,a.destino);
			distancia_min+=a.distancia;
			MST.push_back(a);
		}
	}

	for(int i=0;i<MST.size();i++){
		Arista a=MST[i];
		printf("Distancia:%d  Origen:%d  Destino:%d\n",a.distancia,a.origen,a.destino);
	}

	getchar();
	return 0;
}

