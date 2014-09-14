// Algoritmo de Kosaraju.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stack>
#include <vector>

using namespace std;
typedef vector<int> Arista;
typedef vector<Arista> Grafo;

Grafo grafo;
int cantidadComponentes;
vector<bool> explorados;
stack<int> orden;

void DFS (int pNodo,Grafo grafo){
	explorados[pNodo]=true;
	for(int i=0;i<grafo[pNodo].size();i++){
		if(!explorados[grafo[pNodo][i]]){
			DFS(grafo[pNodo][i],grafo);
		}
	}
	orden.push(pNodo);
}

int _tmain()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	int nNodos,nAristas;
	scanf("%d %d",&nNodos,&nAristas);

	grafo.clear();
	grafo.resize(nNodos);

	Grafo grafoInvertido;
	grafoInvertido.resize(nNodos);
	//Setea los grafos original e invertidos
	for(int i=0;i<nAristas;i++){
		int origen,destino;
		scanf("%d %d",&origen,&destino);
		grafo[origen].push_back(destino);
		grafoInvertido[destino].push_back(origen);
	}
	explorados.clear();
	explorados.resize(nNodos,false);
	//Primera pasada, 
	for(int i=0;i<nNodos;i++){
		if(!explorados[i])
			DFS(i,grafo);
	}

	cantidadComponentes=0;
	//Segunda pasada, utilizando el grafo invertido
	for(int i=0;i<nNodos;i++)	explorados[i]=false;
	while(!orden.empty()){
		int nodoTop=orden.top();
		if(!explorados[nodoTop]){
			DFS(nodoTop,grafoInvertido);
			cantidadComponentes++;
		}
		orden.pop();
	}
	printf("%d",cantidadComponentes);


}

