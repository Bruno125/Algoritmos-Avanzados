// WQU_con_path_compresion.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <vector>

using namespace std;
//WQU_PC= Weighted quick union with path compression
vector<int> id,cant_hijos;


int WQC_PC_findSet(int a){
	if(a==id[a])	return a;
	else
		//El findSet busca el padre original recursivamente. Luego, se le irá asignando ese padre a cada uno de los nodos por los cuales haya pasado este algoritmo
		return id[a]=WQC_PC_findSet(id[a]);
}

void WQC_PC_initSet(int n){
	id.clear();	id.resize(n);
	cant_hijos.clear();	cant_hijos.resize(n,1);
	for(int i=0;i<n;i++)	id[i]=i;
}

bool WQC_PC_sameSet(int a,int b){
	return	(WQC_PC_findSet(a)== WQC_PC_findSet(b));
}

void WQC_PC_unionSet(int a,int b){
	int padreA=WQC_PC_findSet(a);
	int padreB=WQC_PC_findSet(b);

	if(padreA==padreB)	return;

	if(cant_hijos[padreA]<cant_hijos[padreB]){//El set de A
		id[padreA]=padreB;
		cant_hijos[padreB]+=cant_hijos[padreA];
	}else{
		id[padreB]=padreA;
		cant_hijos[padreA]+=cant_hijos[padreB];
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	WQC_PC_initSet(10);

	WQC_PC_unionSet(4 , 3);
	WQC_PC_unionSet(3, 8);
	WQC_PC_unionSet(6, 5);
	WQC_PC_unionSet(9, 4);
	WQC_PC_unionSet(2, 1);
	if(WQC_PC_sameSet(0, 7))	printf("Verdadero\n");	else	printf("Falso\n");
	if(WQC_PC_sameSet(8, 9))	printf("Verdadero\n");	else	printf("Falso\n");
	WQC_PC_unionSet(5, 0);
	WQC_PC_unionSet(7, 2);
	WQC_PC_unionSet(6, 1);
	WQC_PC_unionSet(1, 0);
	if(WQC_PC_sameSet(0, 7))	printf("Verdadero\n");	else	printf("Falso\n");

	printf("\n\n");
	for(int i=0;i<id.size();i++){
		printf("%d --> %d\n",i,id[i]);
	}

	getchar();
}

