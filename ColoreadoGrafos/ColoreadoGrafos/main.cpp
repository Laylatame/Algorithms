//
//  main.cpp
//  ColoreadoGrafos
//
//  Created by Layla Tame on 4/5/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

// EJERCICIO DE BACKTRACKING CON EL COLOREADO DE GRAFOS

#include <cstdlib>
#include <iostream>

using namespace std;

const int n = 5;  // cantidad de nodos
const int m = 3;  // cantidad de colores
int iSum = 0;


//Grafo que modela el mapa
int mapa[n][n] = {{0, 1, 0, 0, 0}, {1, 0, 1, 1, 0}, {0, 1, 0, 1, 1}, {0, 1, 1, 0, 1}, {0, 0, 1, 1, 0}};

int vcolor[n+1]; //arreglo en el que se guarda el color asignado al nodo i

bool valido(int i)
{
    int j = 1;
    bool sw = true;
    
    while (j < i && sw)
    {  if (mapa[i-1][j-1] && vcolor[i] == vcolor[j]) // 1 es true, 0 es false
        return false;
        j++;
    }
    return true; // True si no hay un nodo adyacente que tenga el mismo color
}

void coloreado (int i)
{
    if (valido(i))
        if (i == n)
        {  cout << "-------------------------------------- \n";
            iSum++;
            for (int x = 1; x <= n; x++)
                cout << "Nodo " << x << " se pinta del color #" << vcolor[x] << "\n";
        }
        else
            for (int color=1; color <= m; color++)
            {  vcolor[i+1] = color;
                coloreado(i+1);
            }
}

int main()
{
    coloreado(0);
    cout << "Suma: " << iSum << endl;

    system("PAUSE");
    return EXIT_SUCCESS;
}

