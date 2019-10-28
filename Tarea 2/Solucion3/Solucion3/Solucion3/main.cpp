//
//  main.cpp
//  Tarea 2. Solución 3
//
//  Created by Layla Tame on 1/30/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <chrono>
#include <array>
#include <list>
using namespace std;

//Programa que carga datos de un archivo de texto a una tabla de hashing e implementa una búsqueda sobre la misma

//Regresa los ultimos tres dígitos de la matricula
int hashFunction(int iMat)
{
    return iMat % 1000;
}

int main()
{
    ifstream fMatriculas;
    int iMat, iComp = 0, iIndex, iMatComp;
    array<list<int>, 1000> iMatr;
    bool result = false;
    
    fMatriculas.open("matriculas.txt");
    
    //Cargar archivo al arreglo
    while (!fMatriculas.eof())
    {
        fMatriculas >> iMat;
        iMatr[hashFunction(iMat)].push_back(iMat);
    }
    fMatriculas.close();
    
    cout << "Ingrese matrícula: ";
    cin >> iMatComp;
    
    while (iMatComp != -1)
    {
        iIndex = hashFunction(iMatComp);
        clock_t t1 = clock();
        
        //Mientras existan números en la lista
        while (!iMatr[iIndex].empty())
        {
            iComp++;
            if (iMatr[iIndex].front() == iMatComp)
            {
                result = true;
                break;
            }
            //Eliminar el elemento de la lista
            else
            {
                iMatr[iIndex].pop_front();
            }
        }
        
        t1 = clock() - t1;
        
        if (result == true)
        {
            cout << "Se encontró la matrícula " << iMatComp << endl;
        }
        else
        {
            cout << "No se encontró la matrícula " << iMatComp << endl;
        }
        
        cout << "Comparaciones: " << iComp << endl;
        cout << "Tiempo de ejecución: " << t1 << endl;
        
        cout << "Ingrese matrícula o para terminar ingrese -1: ";
        cin >> iMatComp;
        //Reiniciar la cuenta
        iComp = 0;
        result = false;
    }
}
