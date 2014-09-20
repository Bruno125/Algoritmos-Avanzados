// Caballo Viajante.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <vector>
#include <stdio.h>
#include <queue>
#include <math.h>
#define TAMAÑO_TABLERO 8

using namespace std;

typedef vector<vector<int>>Tablero;
//Guarda pares: origen y destino. Cada par está compuesto por dos valores: fila y columna
typedef vector<pair<pair<int,int>,pair<int,int>>>Casos;

Tablero tablero;
Casos casos;
queue<pair<int,int>>pendientes;
int distancia;

void inicializaTablero(){
	for(int i=0;i<TAMAÑO_TABLERO;i++)
		for(int j=0;j<TAMAÑO_TABLERO;j++)
			tablero[i][j]=-1;
	while(!pendientes.empty())
		pendientes.pop();
}

void posicionaAdyacentes(int distanciaPrevia,int f, int c){
	//Intenta modificar el valor de la distancia
	if(f<0 || f>=tablero.size() || c<0 || c>=tablero.size())	return; //Está fuera de los límites
	if(tablero[f][c]==-1){ //Aún no se setea la distancia, por eso se la seteamos
		tablero[f][c]=distanciaPrevia+1; // Su distancia es igual a la distancia previa + 1
		pendientes.push(make_pair(f,c)); // Se añade esta casilla a la cola de pendientes, para que también se le aplique BFS
	}
}

int MenorCantidadMovimientos(pair<int,int> origen,pair<int,int> destino){
	inicializaTablero(); // Inicializa el tablero con distancias=-1, y además vacía la cola de pendientes
	pendientes.push(origen); //Agrega la casilla origen a la cola de pendientes 
	tablero[origen.first][origen.second]=0; //La distancia a si misma es 0

	while(!pendientes.empty()){ //Bucle que finaliza sólo cuando ya no quedan más casillas por evaluar
		pair<int,int> casillaEvaluando=pendientes.front();
		pendientes.pop();
		int f=casillaEvaluando.first,c=casillaEvaluando.second;
		int distActual=tablero[f][c];
		if(f==destino.first && c==destino.second) //Se encontró la casilla destino
			return distActual;

		//Se intenta colocar al caballo en las casillas que le corresponden, debido a su movimiento en "L"
		posicionaAdyacentes(distActual,f+2,c+1);
		posicionaAdyacentes(distActual,f+1,c+2);
		posicionaAdyacentes(distActual,f-1,c+2);
		posicionaAdyacentes(distActual,f-2,c+1);
		posicionaAdyacentes(distActual,f+2,c-1);
		posicionaAdyacentes(distActual,f+1,c-2);
		posicionaAdyacentes(distActual,f-1,c-2);
		posicionaAdyacentes(distActual,f-2,c-1);
	}

}

int main(array<System::String ^> ^args)
{
    freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	tablero.resize(TAMAÑO_TABLERO);
	for(int i=0;i<TAMAÑO_TABLERO;i++)
		tablero[i].resize(TAMAÑO_TABLERO,false);

	while(1){
		char origenF=0,destinoF;
		int origenC,destinoC;
		scanf("%c%d %c%d",&origenF,&origenC,&destinoF,&destinoC);
		if(origenF==0)/*No se pudo leer (se terminó de leer el archivo)*/	break;
		casos.push_back(make_pair(make_pair(origenF-'a',origenC-1),make_pair(destinoF-'a',destinoC-1)));
		scanf("%c");
	}

	for(int i=0;i<casos.size();i++){
		printf("Para llegar de %c%d a %c%d, se necesitan %d movimientos\n",
			casos[i].first.first+'a',casos[i].first.second+1,
			casos[i].second.first+'a',casos[i].second.second+1,
			MenorCantidadMovimientos(casos[i].first,casos[i].second));
	}

    return 0;
}
