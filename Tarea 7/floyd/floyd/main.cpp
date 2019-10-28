//
//  main.cpp
//  prograDinamica
//
//  Created by Layla Tame on 3/13/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <cstdlib>
#include <iostream>
using namespace std;

int costos[7][7] = { {0, 9999, 9999, 500, 9999, 9999, 9999}, { 9999, 0, 9999, 9999, 9999, 9999, 480}, { 340, 9999, 0, 9999, 9999, 9999, 9999}, { 9999, 9999, 9999, 0, 9999, 1075,  9999}, { 9999, 900, 9999, 9999, 0, 9999, 9999}, { 9999, 9999, 760, 9999, 9999, 0, 120}, { 9999, 9999, 9999, 9999, 230, 9999, 0} };
int iSize[7][7] = {0};


//Problema 3
// Algoritmo de Floyd

int min(int a,int b)
{
    if(a<b)
        return(a);
    return(b);
}

void floyd(int p[7][7],int n)
{
    for(int k=0;k<n;k++)
    {
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (p[i][k]+p[k][j] < p[i][j])
                {
                    iSize[i][j] = k;
                    p[i][j] = p[i][k]+p[k][j];
                }
            }
        }
    }
}

void sinCamino(int p[7][7], int m[7][7])
{
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            if (p[i][j] == 9999)
            {
                iSize[i][j] = -1;
            }
        }
    }
    
}

void imprimirMatriz(int iSize[7][7])
{
    for(int i=0;i<7;i++)
    {
        for(int j=0;j<7;j++)
        {
            cout << iSize[i][j] << " ";
        }
        cout << endl;
    }
}

int main()
{
    floyd(costos, 7);
    sinCamino(costos, iSize);
    imprimirMatriz(iSize);
}
