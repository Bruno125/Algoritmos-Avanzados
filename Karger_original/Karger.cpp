// Karger.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include<stdio.h>
#include<string>
#include<string.h>
#include<vector>
#include <stdlib.h>
#include <time.h>       


using namespace std;

int main()
{
   freopen("in.txt","rt",stdin);
   //freopen("miCaso.txt","rt",stdin);
   freopen("out.txt","wt",stdout);
   srand ( time(NULL) );
   char li[1000], *aux;
   int id, ad;
   vector<pair<int,int> > edges;
   vector<pair<int,int> > edgesOrig;
   int nVertices = 200; //<<<<< SETEA ESTA VARIABLE!!!!!!!
   int cantidadVeces = 1000; //<<<<< SETEA ESTA VARIABLE!!!!!!!
   for (int i = 0 ; i < nVertices ; i++)
   {
      gets(li);
      sscanf(strtok(li,"\t"),"%d",&id); //asumo que id = i + 1
      aux = strtok(NULL,"\t");
      while (aux != NULL)
      {
         sscanf(aux,"%d",&ad);
         if (ad > id)
           edges.push_back(make_pair(id,ad)); //para no repetir los edges
         aux = strtok(NULL," \t");
      }
   }
   /////
   for (unsigned int i = 0; i < edges.size() ; i++)
      edgesOrig.push_back(edges[i]);
   int OrigNVertices = nVertices;
   int min = 1<<29;
   /////
   for (int q = 0 ; q < cantidadVeces ; q++)
   {
     edges.clear();
     for (unsigned int i = 0; i < edgesOrig.size() ; i++)
      edges.push_back(edgesOrig[i]);
     int nVertices = OrigNVertices;
     while (nVertices > 2)
     {
        int arista = rand() % edges.size();
        int nodoQueQueda = edges[arista].first;
        int nodoQueSeDestruye = edges[arista].second;
        edges.erase(edges.begin() + arista);
        unsigned int pos = 0 ;
        while (pos < edges.size())
        {
           if (edges[pos].first == nodoQueSeDestruye)
             edges[pos].first = nodoQueQueda;
           if (edges[pos].second == nodoQueSeDestruye)
             edges[pos].second = nodoQueQueda;
           if (edges[pos].first == edges[pos].second)
             edges.erase(edges.begin() + pos);
           else
             pos++;
        }
        nVertices--;
     }
     printf("Intento %5d: %d\n",q+1,edges.size());
     if (min > (int)edges.size())
        min = edges.size();
   }
   printf ("**********************************************\n");
   printf ("Mejor Solución = %d",min);

   return 0;
}

