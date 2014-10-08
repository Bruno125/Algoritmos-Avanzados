// Number Sequence.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdio.h>

using namespace System;

int main(array<System::String ^> ^args)
{
    freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	int nCasos;
	scanf("%d",&nCasos);
	for(int i=0;i<nCasos;i++){
		int pos;
		scanf("%d",&pos);
		int base=1,variacion=1;
		while((base+variacion)<=pos){
			base+=variacion;
			variacion++;
		}
		printf("%d\n",pos-base+1);

	}


    return 0;
}
