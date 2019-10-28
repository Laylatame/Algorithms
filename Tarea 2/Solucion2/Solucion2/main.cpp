//
//  main.cpp
//  Tarea 2. Solución 2
//
//  Created by Layla Tame on 1/28/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <chrono>
#include <vector>
#include <algorithm>
#include <math.h>
using namespace std;

//Programa que carga un archivo de texto a un arreglo dinámico, ordena los datos de menor a mayor y utiliza búsqueda binaria para encontrar un dato

int iComp = 0;
clock_t t1;

//Función de búsqueda binaria del arreglo de matrices
int binSearch(vector<int> vMat, int iStart, int iFinish, int iMatComp)
{
    int iIndex;
    if (iFinish >= iStart)
    {
        int iMiddle = (iStart + iFinish)/ 2;
        
        if (vMat[iMiddle] == iMatComp)
        {
            iComp++;
            iIndex = iMiddle;
        }
        
        else if (vMat[iMiddle] > iMatComp)
        {
            iComp++;
            iIndex = binSearch(vMat, iStart, iMiddle - 1, iMatComp);
        }
        
        else if (vMat[iMiddle] < iMatComp)
        {
            iComp++;
            iIndex = binSearch(vMat, iMiddle + 1, iFinish, iMatComp);
        }
    }
    else
    {
        iIndex = -1;
    }
    return iIndex;
}


int main()
{
    int iMatr, iSize=0, iMatComp;
    vector<int> vMat;
    ifstream fMatriculas;
    
    fMatriculas.open("matriculas.txt");
    while (!fMatriculas.eof())
    {
        fMatriculas >> iMatr;
        vMat.push_back(iMatr);
        iSize++;
    }
    fMatriculas.close();
    //Ordenar el vector en forma ascendente
    sort(vMat.begin(),vMat.end());
    
    cout << "Ingrese matrícula: ";
    cin >> iMatComp;
    
    while (iMatComp != -1)
    {
        t1 = clock();
        
        if (binSearch(vMat, 0, iSize-1, iMatComp) == -1)
        {
            cout << "No se encontró la matrícula " << iMatComp << endl;
        }
        else
        {
            cout << "Se encontró la matrícula " << iMatComp << endl;
        }
        
        t1 = clock() - t1;
        
        cout << "Comparaciones: " << iComp << endl;
        cout << "Tiempo de ejecución: " << t1 << endl;
        
        cout << "Ingrese matrícula o para terminar ingrese -1: ";
        cin >> iMatComp;
        //Reiniciar la cuenta de comparaciones realizadas
        iComp = 0;
    }
}
