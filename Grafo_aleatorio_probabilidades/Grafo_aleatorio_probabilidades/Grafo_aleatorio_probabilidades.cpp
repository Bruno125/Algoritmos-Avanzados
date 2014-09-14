// Grafo_aleatorio_probabilidades.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <time.h>

using namespace std;

typedef struct Edge{
	int nodo;
	int peso;
   Edge(int _nodo, int _peso){ nodo=_nodo;	peso=_peso;}
};

typedef struct EdgeIncidente{
	int origen;
	int destino;
   EdgeIncidente(int _origen, int _destino){ origen=_origen;	destino=_destino;}
};

typedef vector<Edge>aristas;
typedef vector<EdgeIncidente>aristasIncidentes;
typedef vector<aristas>Grafo;


void GeneraAleatorio()
{
	srand(time(NULL));
	int nDatos=100;
	double probabilidad=0.05;
	Grafo miGrafo;
	miGrafo.clear();
	miGrafo.resize(nDatos);

	for(int i=0;i<miGrafo.size()-1;i++){
		for(int j=i+1;j<miGrafo.size();j++){
			double valor_azar=rand()%100;
			if(valor_azar<probabilidad*100 && i!=j)
				miGrafo[i].push_back(Edge(i, j));
		}
	}

	for(int i=0;i<miGrafo.size();i++){
		printf("%d: ",i);
		for(int j=0;j<miGrafo[i].size();j++){
			printf("(D: %d, P: %d)",miGrafo[i][j].nodo,miGrafo[i][j].peso);
		}
		printf("\n");
	}
	getchar();
}

int main(){
	GeneraAleatorio();
    return 0;
}
