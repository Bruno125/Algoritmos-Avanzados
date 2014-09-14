// Grafos basics.cpp : Defines the entry point for the console application.
//

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
	int max_nodos=10, min_nodos=6;
	int max_aristas=5,min_aristas=1;
	int min_peso=10,max_peso=50;
	
	int V=rand()%(max_nodos-min_nodos+1)+min_nodos;
	Grafo miGrafo;
	miGrafo.clear();
	miGrafo.resize(V);

	for(int i=0;i<miGrafo.size();i++){
		int num_aristas=rand()%(max_aristas-min_aristas+1)+min_aristas;
		for(int j=0;j<num_aristas;j++){
			bool nodo_ok=false;
			int nodoDestino=-1;
			while(!nodo_ok){
				int duplicado=0;
				nodoDestino=rand()%V;
				for(int k=0;k<miGrafo[i].size();k++){
					if(miGrafo[i][k].nodo==nodoDestino){
						duplicado=1;
						break;
					}
				}
				if(duplicado==0 && nodoDestino!=i)
					nodo_ok=true;
			}
			miGrafo[i].push_back(
				Edge(nodoDestino, rand()%(max_peso-min_peso)+min_peso+1)	);
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
	freopen("in.txt","rt",stdin);
	char li[2000];
	char* temp;
	aristasIncidentes graph,graph_base,graph_aux;
	int nVertices,nVerticesAux=200;
	int cant_veces=1000;
	int nodo,nodo2;

	for(int i=0; i<nVertices;i++){
		gets(li);
		sscanf(strtok(li,"\t"),"%d",&nodo);
		temp=strtok(NULL,"\t");
		while(temp!=NULL){
			sscanf(strtok(NULL,"\t"),"%d",&nodo2);
			if(nodo2>i)
				graph.push_back(EdgeIncidente(nodo,nodo2));
			temp=strtok(NULL,"\t");
		}

	}

	for(int i=0;i<graph.size();i++){
		graph_base.push_back(graph[i]);
	}

	int min_corte=100000000000;
	
	for(int i=0;i<cant_veces;i++){
		graph.clear();
		for(int i=0;i<graph_base.size();i++){
			graph.push_back(graph_base[i]);
		}
	}

	//-------------------------------------

	for(int i=0;i<cant_veces;i++){
		//Se vacia el grafo auxiliar
		graph_aux.clear();
		//Se llena el grafo auxiliar con los valores del grafo base
		for(int j=0;j<graph.size();j++){
			graph_aux.push_back(graph[j]);
		}
		nVerticesAux=nVertices;
		while (nVerticesAux>2)
		{//Realizar karger
			int arista_borrar=rand()%graph_aux.size();
			int nodo_borrar=graph_aux[arista_borrar].destino,nodo_guardar=nodo_guardar=graph_aux[arista_borrar].origen;
			graph_aux.erase(graph_aux.begin()+arista_borrar);

			int aux=0;
			while(aux<graph_aux.size()){
				if(graph_aux[aux].origen==nodo_borrar){
					graph_aux[aux].origen=nodo_guardar;
				}
				if(graph_aux[aux].destino==nodo_borrar){
					graph_aux[aux].destino=nodo_guardar;
				}
				if(graph_aux[aux].origen=graph_aux[aux].destino){
					graph_aux.erase(graph_aux.begin()+aux);
				}
				aux++;
			}
			nVerticesAux--;
		}

		if(graph_aux.size()<min_corte)
			min_corte=graph_aux.size();

	}

	return 0;
}