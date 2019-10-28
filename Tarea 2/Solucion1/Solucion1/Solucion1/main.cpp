//
//  main.cpp
//  Tarea 2. Solución 1
//
//  Created by Layla Tame on 1/26/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <chrono>
using namespace std;

//Programa que carga un archivo de texto a un arreglo y busca una matrícula comparando dato por dato.

int main()
{
    int aMatr[154733], iSize = 0, iMat, iComp = 0;
    ifstream fMatriculas;
    fMatriculas.open("matriculas.txt");
    bool bFound = false;
    
    //Cargar archivo a arreglo de enteros.
    while(!fMatriculas.eof())
    {
        fMatriculas >> aMatr[iSize];
        iSize++;
    }
    fMatriculas.close();
    
    cout << "Ingrese matricula: ";
    cin >> iMat;
    
    //Ciclo que permite buscar tantas matriculas como el usuario desee
    while (iMat != -1)
    {
        clock_t t1 = clock();
        //Comparar todos los datos
        for (int i=0; i<iSize; i++)
        {
            iComp++;
            if(aMatr[i] == iMat)
            {
                bFound = true;
                break;
            }
        }
        t1 = clock() - t1;
        
        if (bFound == true)
        {
            cout << "Se encontró la matrícula " << iMat << endl;
        }
        else
        {
            cout << "No se encontró la matrícula " << iMat << endl;
        }
        
        cout << "Comparaciones: " << iComp << endl;
        cout << "Tiempo de ejecución: " << t1 << endl;
        
        cout << "Ingrese matrícula o para terminar ingrese -1: ";
        cin >> iMat;
        iComp = 0;
    }
}
