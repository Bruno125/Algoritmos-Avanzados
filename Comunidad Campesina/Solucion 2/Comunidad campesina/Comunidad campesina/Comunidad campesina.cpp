// ComunidadCampesina.cpp: define el punto de entrada de la aplicación de consola.
//

#include "stdafx.h"
#include <vector>
#include <stdio.h>

#define VECINO_ENTERADO 10000000

using namespace std;

typedef vector<vector<int>> TMapa;
TMapa myMapa;
int cantidad_enterados,vecino_noticia, vecino_radio, largo_filas, ancho_columnas;

bool isValid(int pFila, int pColumna) {
	return (pFila>=0 && pColumna>=0 && pFila<largo_filas  && pColumna<ancho_columnas  && myMapa[pFila][pColumna]!=0 && myMapa[pFila][pColumna]!=VECINO_ENTERADO);
}

bool AvisaNoticia(int pFila, int pColumna) {
	if (myMapa[pFila][pColumna]==vecino_radio) {
		return true;
	} else {
		int vector_filas[]={-1,-1,-1,0,1,1,1,0};
		int vector_columnas[]={-1,0,1,1,1,0,-1,-1};
		/*
			Con estos vectores podemos recorrer al rededor de una posicion:
			Por ejemplo primero se buscara la posicion fila-1 y columna-1 es decir nor-oeste
			luego la fila-1 y columna es decir norte...
		*/
		for (int i=0;i<8; i++) {
			if (isValid(pFila+vector_filas[i],pColumna+vector_columnas[i])) {
				cantidad_enterados++;
				int num_casa=myMapa[pFila][pColumna];
				myMapa[pFila][pColumna]=VECINO_ENTERADO;
				if (AvisaNoticia(pFila+vector_filas[i],pColumna+vector_columnas[i]))
					return true;
				//cantidad_enterados--;
				/*
				La linea anterior esta comentada pues el problema te pide contar la cantidad de vecinos en total que se enterarian
				Si estubiera descomentada, entonces cantidad_enterados me daria la cantidad minima de vecinos que se enterarian si hubiese sido eficiente el camino de la noticia
				*/
			}
		}
	}
	return false;

}


int main()
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int CantCasos=0;
	scanf("%d",&CantCasos);
	for (int i=0;i<CantCasos;i++) {
		int fila_inicial, columna_inicial;
		cantidad_enterados=0;
		scanf("%d %d",&largo_filas,&ancho_columnas);
		scanf("%d %d",&vecino_noticia,&vecino_radio);
		myMapa.clear();
		myMapa.resize(largo_filas);
		for (int j=0; j<largo_filas; j++) {
			myMapa[j].resize(ancho_columnas);
			for (int k=0; k<ancho_columnas; k++) {
				scanf("%d",&myMapa[j][k]);
				if (myMapa[j][k]==vecino_noticia) {
					fila_inicial=j;
					columna_inicial=k;
				}
			}
		}

		if (AvisaNoticia(fila_inicial,columna_inicial))
			printf("%d\n",cantidad_enterados-1);
		else
			printf("No es posible\n");
	}

	
	
	return 0;
}

