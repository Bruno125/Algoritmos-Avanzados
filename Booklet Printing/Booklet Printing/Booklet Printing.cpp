// Booklet Printing.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <vector>

using namespace std;

#define IZQ true
#define DER false
#define FRONT true
#define BACK false
#define LIBRE -1

typedef pair<int,int> Cara;
typedef pair<Cara,Cara> Hoja;
typedef vector<Hoja> Libro;

//vector<Libro> misLibros;
vector<int> misLibros;
Libro libro;
int nPaginas;

bool reversoLibre(bool cara, bool lado,int pagina){
	Cara caraComprobar= (cara==IZQ) ?	caraComprobar=libro[pagina].first : caraComprobar=libro[pagina].second;	
	int hoja= (lado==IZQ) ?	hoja=caraComprobar.first : hoja=caraComprobar.second;	
	return hoja==LIBRE;
}

void ImprimeLibro(){
	printf("Printing order for %d pages: \n",nPaginas);
	for(int i=0;i<libro.size();i++){//Recorre las hojas
		printf("Sheet %d, front:",i+1);
		if(libro[i].first.first==LIBRE)	printf("Blank");	else printf("%d",libro[i].first.first);
		if(libro[i].first.second==LIBRE)	printf("Blank");	else printf("%d",libro[i].first.second);
		printf("Sheet %d, back:",i+1);
		if(libro[i].second.first==LIBRE)	printf("Blank");	else printf("%d",libro[i].second.first);
		if(libro[i].second.second==LIBRE)	printf("Blank");	else printf("%d",libro[i].second.second);
	}
}

void colocaPagina(int num,bool cara,bool lado, int pagina){
	if(num>nPaginas){//Caso de exito
		ImprimeLibro();
		return;
	}
	if(reversoLibre(cara,lado,pagina)){
		colocaPagina(num+1,!cara,!lado,pagina);
	}else{
		if(pagina+1>=libro.size())
			colocaPagina();
	}


}

Libro libroConNumeroDePaginas(int nPaginas){
	Libro libro;
	int nHojas=(nPaginas+3)/4;
	libro.resize(nHojas);//Setea el libro a un numero de hojas dado el numero de caras;
	for(int i=0;i<nHojas;i++){//Setea cada una de las caras del libro a -1
		libro[i].first.first=LIBRE;
		libro[i].first.second=LIBRE;
		libro[i].second.first=LIBRE;
		libro[i].second.second=LIBRE;
	}

}

int main(array<System::String ^> ^args)
{
	while(1){
		int n;
		scanf("%d",&n);
		if(n==0)	break;
		misLibros.push_back(n);
	}
	
	for(int i=0;i<misLibros.size();i++){
		nPaginas=misLibros[i];
		libro=libroConNumeroDePaginas(nPaginas);
		colocaPagina(1,FRONT,DER,0);
	}

	return 0;
}
