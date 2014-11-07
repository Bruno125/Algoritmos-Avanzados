// Dijkstra,Dijkstra.cpp : main project file.

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
vector<bool> explorado;

bool comparaDistancias(const TNodo &A,const TNodo &B){
	return A.first>B.first;
}

int Dijkstra (int pNodoOrigen, int pNodoDestino){
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
		if(distancias[tempNodo.second]>=tempNodo.first){
			for(int i=0;i<myGrafo[tempNodo.second].size();i++){
				TNodo nodoEvaluar=myGrafo[tempNodo.second][i];
				if(!explorado[tempNodo.second]){
					if(distancias[tempNodo.second]+nodoEvaluar.first<distancias[nodoEvaluar.second]){
						distancias[nodoEvaluar.second]=distancias[tempNodo.second]+nodoEvaluar.first;
						ColaPendientes.push(TNodo(distancias[nodoEvaluar.second],nodoEvaluar.second));
						ComoLLegoA[nodoEvaluar.second]=tempNodo.second;
					}
				}
			}
		}
	}

	int siguiente=pNodoDestino;
	while(siguiente!=-1){
		int subsiguiente=ComoLLegoA[siguiente];
		for(int i=0;i<myGrafo[siguiente].size();i++){
			if(myGrafo[siguiente][i].second==subsiguiente){
				myGrafo[siguiente].erase(myGrafo[siguiente].begin()+i);
				break;
			}	
		}
		if(subsiguiente!=-1){
			for(int i=0;i<myGrafo[subsiguiente].size();i++){
				if(myGrafo[subsiguiente][i].second==siguiente){
					myGrafo[subsiguiente].erase(myGrafo[subsiguiente].begin()+i);
					break;
				}	
			}
		}
		siguiente=subsiguiente;

	}
	return distancias[pNodoDestino];

}

int main(){
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	
		int nNodos;
		scanf("%d",&nNodos);
	while(nNodos!=0){
		myGrafo.clear();	myGrafo.resize(nNodos);
		explorado.clear();	explorado.resize(nNodos,false);

		int nConexiones;
		scanf("%d",&nConexiones);
		for(int i=0;i<nConexiones;i++){
			int origen,destino,peso;
			scanf("%d %d %d",&origen,&destino,&peso);
			myGrafo[origen-1].push_back(make_pair(peso,destino-1));
			myGrafo[destino-1].push_back(make_pair(peso,origen-1));
		}

		int camino1=Dijkstra(0,nNodos-1);
		int camino2=Dijkstra(0,nNodos-1);
		if(camino1!=INFINITO && camino2!=INFINITO)	printf("%d\n",camino1+camino2);
		else										printf("Back to jail\n");

		scanf("%d",&nNodos);
	}
}