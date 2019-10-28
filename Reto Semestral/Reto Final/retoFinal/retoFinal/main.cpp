//
//  main.cpp
//  retoFinal
//
//  Created by Layla Tame on 4/26/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

#define TAM 10
int iTam = iEmp;
//int grafo1[iTam][iTam] = {0};

/*
void print(int array[iTam][iTam], int iSize)
{
    for(int i=0; i<iSize; i++)
    {
        for(int j=0; j<iSize; j++)
        {
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
}*/
vector<int> jefes;
/*void readInput()
{
    ////////CAMBIAR DE REGRESO A IEMP
    //int grafo[iTam][iTam] = {0};

    for(int i=0; i<iJefe; i++)
    {
        int jefe;
        cin >> jefe;
        jefes.push_back(jefe-1);
    }
    
    int j, e, v;
    
    for(int i=0; i<iRel; i++)
    {
        cin >> j >> e >> v;
        vector<int> temp = grafo[j-1];
        temp[e-1] = v;
        //grafo[j-1][e-1] = v;
    }
}*/

int suma[] = {0};
vector<vector<int>> answer;
vector<int> caminos;

struct point{
    int nodo;
    int valor;
}

int add(vector<vector<int>> grafo)
{
    for(int i=0; i<grafo.size(); i++)
    {
        vector<int> temp = grafo[i];
        caminos.clear();
        for(int j=0; j<grafo.size(); j++)
        {
                if(temp[j] != 0)
                {
                    suma[i] += temp[j];
                    caminos.push_back(j);
                }
            //}
        }
        answer.push_back(caminos);
    }
    return 0;
}

int iTotal = 0;
void recursivo(int sumas[], vector<int> vec, int i)
{
    if(!vec.empty())
    {
        iTotal += sumas[i];
        for(int j=0; j<vec.size(); j++)
        {
            recursivo(sumas, answer[vec[j]],vec[j]);
        }
        
    }
}



int main() {
    //READ INPUT
    int iEmp = 1, iJefe = 1, iRel = 1;

    cin >> iEmp >> iJefe >> iRel;
    
    for(int i=0; i<iJefe; i++)
    {
        int jefe;
        cin >> jefe;
        jefes.push_back(jefe-1);
    }
    
    int j, e, v;
    //int grafo[iEmp][iEmp] = {0};
    vector<vector<point>> grafo;
    for(int i=0; i<iRel; i++)
    {
        cin >> j >> e >> v;
        vector<point> temp = {e, v};
        //temp[e-1] = v;
        grafo[j-1][e-1] = v;
    }
    
    
    //readInput();
    cout << endl << endl;
    add(grafo);
    
    cout << "Sumas: " << endl;
    for (int i=0; i<iTam; i++)
    {
        cout << suma[i] << " ";
    }
    
    vector<int> vecTemp;
    cout << endl << endl;
    for (int i=0; i<answer.size(); i++)
    {
        if(!answer[i].empty())
        {
            cout << i+1 << ": ";
            vecTemp = answer[i];
            for(int j=0; j<vecTemp.size(); j++)
            {
                cout << vecTemp[j]+1 << " ";
            }
            cout << endl;
        }
    }
    
    cout << "JEFES: ";
    for(int i=0; i<jefes.size(); i++)
    {
        cout << "TOTAL PARA " << i+1 << ": ";
        recursivo(suma, answer[jefes[i]], jefes[i]);
        cout << iTotal << endl;
        iTotal = 0;
    }
}
