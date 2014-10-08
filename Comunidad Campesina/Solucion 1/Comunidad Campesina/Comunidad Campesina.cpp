// Comunidad Campesina.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdio.h>
#include <vector>


using namespace std;

#define EXPLORADO -1

vector<vector<int>> mapa;
int cantidad;

bool BFS(pair<int,int> origen,int objetivo){
	int f=origen.first,c=origen.second;
	cantidad++;
	int valor=mapa[f][c];
	if(valor==objetivo)	return true;
	mapa[f][c]=EXPLORADO;
	//Recorre aledaños --- NO LOS RECORRE EN SENTIDO HORARIO
	bool cond=false;
	for(int i=f-1;i<=f+1;i++){
		if(i<0 || i>=mapa.size())	continue;
		for(int j=c-1;j<=c+1;j++){
			if(j>=0 && j<mapa[i].size()){
				if(mapa[i][j]!=0 && mapa[i][j]!=EXPLORADO){
					cond= BFS(make_pair(i,j),objetivo);
					if(cond)	return true;
				}
			}
		}
	}
	return cond;
}

int main(array<System::String ^> ^args)
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	int nCasos;
	scanf("%d",&nCasos);
	for(int i=0;i<nCasos;i++){
		//Reseteando valores
		for(int i=0;i<mapa.size();i++)	mapa[i].clear();
		mapa.clear();
		cantidad=0;
		//Lectura de datos
		int nF,nC,origen,objetivo,cInicial,fInicial;
		scanf("%d %d \n %d %d",&nF,&nC,&origen,&objetivo);
		mapa.resize(nF);
		for(int j=0;j<nF;j++){
			mapa[j].resize(nC);
			for(int k=0;k<nC;k++){
				int num;
				scanf("%d",&num);
				mapa[j][k]=num;
				if(num==origen){
					fInicial=j;
					cInicial=k;
				}

			}
		}

		//Realiza el BFS desde la posicion inicial, y el valor de retorno será la condicion del if
		if(BFS(make_pair(fInicial,cInicial),objetivo)){//Se pudo llegar al objetivo desde las coordenadas iniciales
			printf("%d\n",cantidad-2 /*se resta dos, para no considerar la casa inicio ni la casa fin*/);
		} else{
			printf("No es posible");
		}

	}
	


    return 0;
}
