// Publicidad en redes sociales.cpp: archivo de proyecto principal.
#include "stdafx.h"
#include <stdio.h>
#include <conio.h>
#include <vector>


using namespace std;
vector<vector<int>> grafo;
vector<int>values;
vector<bool> explorados;
int cantidad;
double precio,total;

void BFS(int nOrigen){
	explorados[nOrigen]=true;
	total+=precio*values[nOrigen];
	cantidad++;
	for(int i=0;i<grafo[nOrigen].size();i++){
		if(!explorados[grafo[nOrigen][i]])
			BFS(grafo[nOrigen][i]);
	}
}

int main(array<System::String ^> ^args)
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	int nPersonas,nRelaciones;

	scanf("%d %lf %d",&nPersonas,&precio,&nRelaciones);
	grafo.resize(nPersonas);
	explorados.resize(nPersonas,false);
	for(int i=0;i<nPersonas;i++){
		int impresiones_persona;
		scanf("%d",&impresiones_persona);
		values.push_back(impresiones_persona);
	}
	for(int i=0;i<nPersonas;i++){
		int origen,destino;
		scanf("%d %d",&origen,&destino);
		grafo[origen-1].push_back(destino-1);
		grafo[destino-1].push_back(origen-1);
	}
	for(int i=0;i<nPersonas;i++){
		if(!explorados[i]){
			cantidad=total=0;
			BFS(i);
			printf("%d %.2f\n",cantidad,total);
		}
	}
    return 0;
}
