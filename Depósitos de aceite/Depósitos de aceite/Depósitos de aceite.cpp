// Depósitos de aceite.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

typedef vector<vector<char>>mapa;
typedef vector<mapa> Mapas;

Mapas mapas;
mapa map;
int cant;
stack<pair<int,int>> pendientes;
vector<vector<bool>>explorados;

void detectaAdyacentes(int f,int c){
	pendientes.pop();
	for(int i=f-1;i<=f+1;i++){
		if(i<0 || i>=map.size())	continue;
		for(int j=c-1;j<=c+1;j++){
			if(j>=0 && j<map[i].size()){
				if(map[i][j]=='@' && !explorados[i][j]){
					explorados[i][j]=true;
					pendientes.push(make_pair(i,j));
				}
			}
		}
	}
}

void BFS(){
	cant=0;
	explorados.resize(map.size());
	for(int i=0;i<map.size();i++)
		explorados[i].resize(map[i].size(),false);

	for(int i=0;i<map.size();i++){	
		for(int j=0;j<map[i].size();j++){
			if(!explorados[i][j] && map[i][j]=='@'){//Evalua casilla
				explorados[i][j]=true;
				pendientes.push(make_pair(i,j));
				while(!pendientes.empty()){
					pair<int,int> coord=pendientes.top();
					detectaAdyacentes(coord.first,coord.second);
				}
				cant++;
			}
		}
	}
}

int main(array<System::String ^> ^args)
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	while(1){
		int f,c;
		scanf("%d %d",&f,&c);
		if(f==0 && c==0)	break;
		mapa mapaLeido;
		mapaLeido.resize(f);
		for(int i=0;i<f;i++){//Itera cada fila
			mapaLeido[i].resize(c);
			scanf("%c");
			for(int j=0;j<c;j++){//Lee cada linea
				char s;
				scanf("%c",&s);
				mapaLeido[i][j]=s;
			}
		}
		mapas.push_back(mapaLeido);
	}

	for(int i=0;i<mapas.size();i++){//Evalua cada mapa
		map=mapas[i];
		BFS();
		printf("%d\n",cant);
	}

    return 0;
}
