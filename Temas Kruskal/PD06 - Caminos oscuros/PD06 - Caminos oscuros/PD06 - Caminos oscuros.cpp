// PD06 - Caminos oscuros.cpp : main project file.

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <queue>
#include <stdlib.h>
#include <vector>
#include <functional>

#define COSTO_POR_METRO 1
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

//typedef pair<int,int> TNodo; //First= distancia, Second= nodo destino
typedef vector<Arista> TListaAristas;
typedef vector<TListaAristas> TGrafo;

vector<int> cant_hijos;
vector<int> id;

TGrafo myGrafo;

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

bool comparaDistancias(const Arista &A,const Arista &B){
	return A.distancia>B.distancia;
}


int main(array<System::String ^> ^args)
{
    freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	int nNodos,nCalles,metrosTotales=0;
	scanf("%d %d",&nNodos,&nCalles);
	while(nNodos!=0 && nCalles!=0){
		myGrafo.clear();	myGrafo.resize(nNodos);
		for(int i=0;i<nCalles;i++){
			int origen,destino,longitud;
			scanf("%d %d %d",&origen,&destino,&longitud);
			myGrafo[origen].push_back(Arista(origen,destino,longitud));
			myGrafo[destino].push_back(Arista(destino,origen,longitud));
			metrosTotales+=longitud;
		}

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
		printf("%d\n",(metrosTotales-distancia_min)*COSTO_POR_METRO);

		scanf("%d %d",&nNodos,&nCalles);
	}

    return 0;
}
