// Djikstra.cpp : main project file.

#include "stdafx.h"
#include <vector>
#include <queue>
#include <stdio.h>
#include <functional>

#define INFINITO 10000000

using namespace std;

typedef pair<int,int> TNodo; //First= distancia, Second= nodo destino
typedef vector<TNodo> TListaAristas;
typedef vector<TListaAristas> TGrafo;

TGrafo myGrafo;

bool comparaDistancias(const TNodo &A,const TNodo &B){
	return A.first>B.first;
}

vector<int> Dijkstra (int pNodoOrigen, int pNodoDestino){
	vector<int> ComoLLegoA;
	priority_queue <TNodo,vector<TNodo>,function<bool(TNodo,TNodo)>> ColaPendientes(comparaDistancias);
	vector<int> distancias;
	ComoLLegoA.resize(myGrafo.size(),-1);
	distancias.resize(myGrafo.size(),INFINITO);

	distancias[pNodoOrigen]=0;
	ColaPendientes.push(TNodo(distancias[pNodoOrigen],pNodoOrigen));

	while(!ColaPendientes.empty()){
		TNodo tempNodo=ColaPendientes.top();
		ColaPendientes.pop();
		if(pNodoDestino==tempNodo.second)	break;
		for(int i=0;i<myGrafo[tempNodo.second].size();i++){
			TNodo nodoEvaluar=myGrafo[tempNodo.second][i];
			if(distancias[tempNodo.second]+nodoEvaluar.first<distancias[nodoEvaluar.second]){
				distancias[nodoEvaluar.second]=distancias[tempNodo.second]+nodoEvaluar.first;
				ColaPendientes.push(TNodo(distancias[nodoEvaluar.second],nodoEvaluar.second));
				ComoLLegoA[nodoEvaluar.second]=tempNodo.second;
			}
		}
	}

	vector<int> pasos;
	pasos.push_back(pNodoDestino);
	while(ComoLLegoA[pNodoDestino]!=-1){
		pasos.push_back(ComoLLegoA[pNodoDestino]);
		pNodoDestino=ComoLLegoA[pNodoDestino];
	}
	reverse(pasos.begin(),pasos.end());

	return pasos;

}


int main()
{
	myGrafo.resize(5);
	myGrafo[0].push_back(make_pair(10,1));
	myGrafo[0].push_back(make_pair(5,3));
	myGrafo[1].push_back(make_pair(1,2));
	myGrafo[1].push_back(make_pair(2,3));
	myGrafo[2].push_back(make_pair(4,4));
	myGrafo[3].push_back(make_pair(3,1));
	myGrafo[3].push_back(make_pair(9,2));
	myGrafo[3].push_back(make_pair(2,4));
	myGrafo[4].push_back(make_pair(6,2));
	myGrafo[4].push_back(make_pair(7,0));
	
	vector<int> Camino;
	Camino=Dijkstra(0,2);
	for(int i=0;i<Camino.size();i++){
		printf("%d ",Camino[i]);
	}
	getchar();

    return 0;
}
