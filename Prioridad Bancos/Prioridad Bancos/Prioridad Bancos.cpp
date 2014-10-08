// Prioridad Bancos.cpp : main project file.

#include "stdafx.h"
#include <queue>
#include <functional>

using namespace std;

enum Categoria {L,S,G,B};
typedef pair<int,int> cliente;
int damePrioridad (int horaLLegada,char categoria){
	int agregadoPorPrioridad;
	if(categoria=='L')	agregadoPorPrioridad=0;
	else if (categoria=='S')	agregadoPorPrioridad=7;
	else if (categoria=='G')	agregadoPorPrioridad=15;
	else if (categoria=='B')	agregadoPorPrioridad=30;
	return 540-horaLLegada+agregadoPorPrioridad;
}

bool comparaPrioridad(const cliente &a,const cliente &b){
	return a.first<b.first;
}

//bool colocaCliente(){
//	for(int i=0;i<3;i++){//Para cada una de las ventanillas
//		if(ventanillas[i]){
//			colaClientes.top();
//			return true;
//		}
//
//	}
//	return false;
//}

priority_queue<cliente,vector<cliente>,function<bool(cliente,cliente)>> colaClientes(comparaPrioridad);
bool ventanillas[3]={false,false,false};


int main(array<System::String ^> ^args)
{
	freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);
	int nAlertas;
	scanf("%d",&nAlertas);
	for(int i=0;i<nAlertas;i++){
		int t,a,s,id;
		scanf("%d %c %c %d\n",&t,&a,&s,&id);
		if(a=='C'){//LLegó un nuevo cliente
			colaClientes.push(make_pair(damePrioridad(t,s),id));
		}
		else if(a=='V'){//Se liberó una ventanilla
			/*ventanillas[id]=true;
			colocaCliente();*/
			if(!colaClientes.empty()){
				cliente clienteASerAtendido=colaClientes.top();
				printf("Cliente: %d Ventanilla:%d Prioridad:%d\n",clienteASerAtendido.second,id,clienteASerAtendido.first);
				colaClientes.pop();
			}

		}
	}

	



    return 0;
}
