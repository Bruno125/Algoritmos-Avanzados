// Algoritmos de Movimiento de enemigo.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <vector>


using namespace std;
vector<vector<int>> tablero;

int main(array<System::String ^> ^args)
{
    freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	int f,c;
	scanf("%d %d",&f,&c);
	tablero.resize(f);
	for(int i=0;i<f;i++){
		tablero[i].resize(c);
		for(int j=0;j<c;j++){
			int a;
			scanf("%d",&a);
			tablero[i][j]=a;
		}
	}





    return 0;
}
