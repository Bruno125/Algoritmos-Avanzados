// Karger.cpp : main project file.

// Grafos basics.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <utility>
#include <time.h>
#define MONTOMAX 2500000

using namespace std;

typedef struct EdgeIncidente{
	int origen;
	int destino;
	int origen_estatico,destino_estatico;
   EdgeIncidente(int _origen, int _destino){ origen=origen_estatico=_origen;	destino=destino_estatico=_destino;}
};

typedef vector<EdgeIncidente>aristasIncidentes;

int main(){
	freopen("in-final.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	char li[3000];
	char* temp;
	aristasIncidentes graph,graph_aux;
	int nVertices=200,nVerticesAux=200;
	int nodo,nodo2;

	for(int i=0; i<nVertices;i++){
		gets(li);
		sscanf(strtok(li,"\t"),"%d",&nodo);
		temp=strtok(NULL,"\t");
		while(temp!=NULL){
			sscanf(temp,"%d",&nodo2);
			if(nodo2!=0)
				graph.push_back(EdgeIncidente(nodo,nodo2));
			temp=strtok(NULL,"\t");
		}

	}

	int min_corte=100000000000;
	int acumulado=MONTOMAX+1;
	while(acumulado>MONTOMAX)
	{
		//Se vacia el grafo auxiliar
		graph_aux.clear();
		//Se llena el grafo auxiliar con los valores del grafo base
		nVerticesAux=nVertices;
		for(int j=0;j<graph.size();j++){
			graph_aux.push_back(graph[j]);
		}

		acumulado=0;

		while (nVerticesAux>2)
		{//Realizar karger
			int arista_borrar=rand()%graph_aux.size();
			int nodo_borrar=graph_aux[arista_borrar].destino,nodo_guardar=nodo_guardar=graph_aux[arista_borrar].origen;
			graph_aux.erase(graph_aux.begin()+arista_borrar);

			if((nodo_borrar+nodo_guardar)%2==0)
				acumulado+=17800;
			else
				acumulado+=6500;
			int aux=nVertices-nVerticesAux;
			while(aux<graph_aux.size()){
				if(graph_aux[aux].origen==nodo_borrar){
					graph_aux[aux].origen=nodo_guardar;
				}
				if(graph_aux[aux].destino==nodo_borrar){
					graph_aux[aux].destino=nodo_guardar;
				}
				if(graph_aux[aux].origen==graph_aux[aux].destino){
					graph_aux.erase(graph_aux.begin()+aux);
				}else
					aux++;
			}
			nVerticesAux--;
		}
		if(graph_aux.size()<min_corte)
			min_corte=graph_aux.size();
	}

	for(int i=0;i<graph_aux.size();i++){
		printf("La %d pista a reparar va de %d a %d\n",i+1,graph_aux[i].origen_estatico,graph_aux[i].destino_estatico); 
	}

	printf("\n\nEl monto total ajustado sería de $%.2f",acumulado*1.00);

	fclose(stdin);
	getchar();
	return 0;
}