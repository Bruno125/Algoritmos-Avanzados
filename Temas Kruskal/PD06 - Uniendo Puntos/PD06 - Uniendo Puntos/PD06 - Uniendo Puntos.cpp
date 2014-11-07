// PD06 - Uniendo puntos.cpp : main project file.

#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <functional>
#include <queue>

using namespace std;

struct Arista{
	int origen,destino;
	double distancia;
	Arista(int o,int dest,double dist) {
		origen=o;	destino=dest;	distancia=dist;
	}
};

typedef vector<Arista> TListaAristas;
typedef pair<double,double> coord; // First=coord x, Second=coord y
typedef vector<TListaAristas> TGrafo;
TGrafo myGrafo;



vector<pair<int,int>> puntos;

vector<int> cant_hijos;
vector<int> id;

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


int main(array<System::String ^> ^args)
{
    freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	int nCasos;
	scanf("%d",&nCasos);
	for(int i=0;i<nCasos;i++){
		scanf("\n");
		int n;
		scanf("%d",&n);
		for(int j=0;j<n;j++){
			double coordx,coordy;
			scanf("%lf %lf",&coordx,&coordy);
			puntos.push_back(make_pair(coordx,coordy));
		}
		myGrafo.clear();	myGrafo.resize(n);

		for(int j=0;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				double distancia=sqrt(pow(puntos[j].first-puntos[k].first,2)+pow(puntos[j].second-puntos[k].second,2));
				myGrafo[j].push_back(Arista(j,k,distancia));
			}
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
		double distancia_min=0;
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

		printf("%.2lf\n",distancia_min);


	}


    return 0;
}
