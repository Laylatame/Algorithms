//
//  main.cpp
//  problema1
//
//  Created by Layla Tame on 3/13/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

//Problema 1. Divide y Venceras

#include <cstdlib>
#include <iostream>
#include <float.h>
using namespace std;
const int TAM = 500;
const int N = 21;
// DEFINICIONES DE DATOS NECESARIOS PARA LAS PRUEBAS

int arr1[10] = {-1,0,1,3,4,6,7,8,9,10};
int arr2[20] = {-4,-3,-2,-1,0,2,3,4,6,7,8,10,12,14,15,16,19,20,21,22};
int arr3[16] = {3,5,8,1,9,4,2,13,11,20,16,0,15,7,22,14};
float arr4[16] = {0, 0.2, 0.4, 0.6, 0.8, 0, 1.0, 1.2, 1.4, 1.6, 0, 1.8};
//int arr4[N] = {};

// Problema 1
int binSearch(int arr[], int iStart, int iFinish)
{
    int iIndex;
    if (iFinish >= iStart)
    {
        int iMiddle = (iStart + iFinish)/ 2;
        
        if (arr[iMiddle] == iMiddle)
        {
            return iMiddle;
        }
        
        else if (arr[iMiddle] > iMiddle)
        {
            iIndex = binSearch(arr, iStart, iMiddle - 1);
        }
        
        else
        {
            iIndex = binSearch(arr, iMiddle + 1, iFinish);
        }
    }
    else
    {
        iIndex = -1;
    }
    return iIndex;
}

// Problema 2
// Función para unir dos subarreglos ya ordenados
void une(int datos[], int inicio, int fin, int mitad)
{
    int i, j, k, aux[TAM];
    i = inicio;
    k = inicio;
    j = mitad + 1;
    while (i <= mitad && j <= fin)
    {
        if (datos[i] < datos[j])
        {
            aux[k] = datos[i];
            k++;
            i++;
        }
        else
        {
            aux[k] = datos[j];
            k++;
            j++;
        }
    }
    while (i <= mitad)
    {
        aux[k] = datos[i];
        k++;
        i++;
    }
    while (j <= fin)
    {
        aux[k] = datos[j];
        k++;
        j++;
    }
    for (i = inicio; i < k; i++)
    {
        datos[i] = aux[i];
    }
}
// Función recursiva para hacer el ordenamiento
void mergesortMod(int arr[], int inicio, int fin)
{
    int primArr, segArr;
    if (inicio < fin)
    {
        primArr = (fin-inicio)/3;
        segArr = fin - primArr;

        mergesortMod(arr,inicio,inicio+primArr);
        mergesortMod(arr,inicio+primArr+1,segArr);
        mergesortMod(arr,segArr+1,fin);
        une(arr,inicio,segArr,inicio+primArr);
        une(arr,inicio,fin,segArr);
    }
}
//Problema 3
// Algoritmo de Gilbert y Moore
float minimo(int i, int j, float A[N][N])
{
    float min = FLT_MAX;
    for(int m = i; m < j+1; m++)
    {
        if(A[i][m-1] + A[m+1][j] < min)
        {
            min = A[i][m-1] + A[m+1][j];
        }
    }
    return min;
}
float sumatoria(int i, int j, float p[])
{
    float sum = 0;
    for(int m = i; m < j+1; m++)
    {
        sum += p[m];
    }
    return sum;
}
float gilbertymoore (float p[], int n)
{
    float A[N][N], R[N][N];
    // se considera que se usarán la columnas 0 a n y los renglones 1 a n+1 en la matriz
    int j;
    for (int i = 1; i<= n; i++)
    {
        A[i][i-1] = 0; A[i][i] = p[i];
        R[i][i] = i; R[i][i-1] = 0;
    }
    A[n+1][n] = 0;
    R[n+1][n] = 0;
    for (int diag = 1; diag <= n-1; diag++)
        for (int i = 1; i <= n-diag; i++)
        {
            j = i+diag;
            A[i][j] = minimo(i, j, A) + sumatoria(i, j, p);
            // calcula el valor mínimo entre los diversos valores de:
            // A[i,k-1] + A[k+1, j] para k desde i hasta j.
            // La sumatoria calcula la suma de las probabilidades de la llave i hasta j
        }
    return A[1][n];
}
int main()
{
    cout << "Problema 1.1: " << binSearch(arr1, 0, 9) << endl;
    cout << "Problema 1.2: " << binSearch(arr2, 0, 19) << endl;
    
    mergesortMod(arr3, 0, 15);
    
    for(int i = 0; i < 16; i++)
    {
        cout << arr3[i] << " ";
    }
    cout << endl;
    
    cout << "Gilbert Moore: " << gilbertymoore(arr4, 4) <<endl;


}
