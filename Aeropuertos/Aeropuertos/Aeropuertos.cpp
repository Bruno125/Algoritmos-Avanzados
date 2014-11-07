// Aeropuertos.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <queue>
#include <stdlib.h>
#include <vector>
#include <functional>

using namespace std;

struct Arista{
	int origen,destino,distancia;
	Arista(int o,int dest,int dist) {
		origen=o;	destino=dest;	distancia=dist;
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

	int nCasos;
	scanf("%d",&nCasos);
	for(int t=0;t<nCasos;t++){
		int nNodos,nConexiones,precioAeropuerto;
		scanf("%d %d %d",&nNodos,&nConexiones,&precioAeropuerto);

		myGrafo.clear();	myGrafo.resize(nNodos);
		for(int i=0;i<nConexiones;i++){
			int origen,destino,longitud;
			scanf("%d %d %d",&origen,&destino,&longitud);

			myGrafo[origen-1].push_back(Arista(origen-1,destino-1,longitud));
			myGrafo[destino-1].push_back(Arista(destino-1,origen-1,longitud));
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
		/*Al final, "contador" almacenerá el número de conexiones que se llegaron a realizar en el árbol de expansión mínima.
		Si todos los puntos estuviesen conectados, contador tendría un valor de nNodos-1. Sin embargo, si no todos los nodos estuviesen
		conectados, el contador no llegaría a nNodos-1, sino que tendría un valor menor. Si fuese nNodos-2, significa que se hallaron dos
		subgrafos que no están conectados, por lo tanto serán necesarios 2 aeropuertos. Si fuese nNodos-3, significaría que hay 3 subgrafos
		por lo cual serán necesarios 3 aeropuertos. De esa forma, se puede hallar el número de aeropuertos realizando: nNodos-contador
		*/
		int nAeropuertos=nNodos-contador;
		printf("Case #%d: %d %d\n",t+1,distancia_min+nAeropuertos*precioAeropuerto,nAeropuertos);
	}


	return 0;
}
