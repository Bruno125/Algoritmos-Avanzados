// IRR.cpp: archivo de proyecto principal.

#include "stdafx.h"
#include <stdio.h>
#include <vector>
#include <math.h>

using namespace std;
vector<int> cash_flows;

double ecuacionIRR(double IRR){
	double suma_flujos_positivos=0;
	for(int i=1;i<cash_flows.size();i++)
		suma_flujos_positivos+=(cash_flows[i]*1.0/pow(1+IRR,i));
	return cash_flows[0] + suma_flujos_positivos;
}


int main(array<System::String ^> ^args)
{
    freopen("in.txt","rt",stdin);
	freopen("out.txt","wt",stdout);

	int n;

	while(1){
		scanf("%d",&n);
		if(n==0)	break;
		cash_flows.clear();
		for(int i=0;i<n+1;i++){
			int valor;
			scanf("%d",&valor);
			cash_flows.push_back(valor);
		}

		int min=-1;
		int max=100000;
		double IRR=(min+max)/2.0;
		double resultado=ecuacionIRR(IRR);
		while(resultado!=0 && (min<max)){
			if(resultado>0)	min=IRR;
			else max=IRR;
			IRR=(min+max)/2.0;
			resultado=ecuacionIRR(IRR);
		}

		if(resultado!=0)	printf("No\n");
		else printf("%.2f\n",IRR);


	}

}
