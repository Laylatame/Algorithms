//
//  main.cpp
//  ronda3
//
//  Created by Layla Tame on 4/11/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//Ronda 3. Reto Semestral
class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int esc) {
        int costs[n][n], iSize[n][n], camino[n][n];
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(i==j){
                    costs[i][j] = 0;
                }
                else{
                    costs[i][j] = 99999;
                }
                iSize[i][j] = 0;
            }
        }
        
        for(int i=0; i<flights.size(); i++)
        {
            vector<int> temp = flights[i];
            int a = temp[0];
            int b = temp[1];
            costs[a][b] = temp[2];
        }
        
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    camino[i][j] = 0;
                else if (costs[i][j] != 9999)
                    camino[i][j] = i;
                else
                    camino[i][j] = -1;
            }
        }
        
        int iSum = 0;
        //Floyd
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if (costs[i][k]+costs[k][j] < costs[i][j]){
                        if(iSize[i][j] < esc){
                            costs[i][j] = costs[i][k]+costs[k][j];
                            iSize[i][j] += 1;
                            cout << "Size final: " << iSize[i][j] << endl;
                        }
                    }
                }
            }
        }
        
        
        /*if(contarEscalas(camino, i, j, iSum) < esc)
         {
         p[i][j] = p[i][k]+p[k][j];
         camino[i][j] = camino[k][j];
         iSize[i][j] = iSize[i][j] + 1;
         }*/
        
        /*
         cout << "Size inicial: " << iSize[i][j] << endl;
         if(iSize[i][j] < esc){
         costs[i][j] = costs[i][k]+costs[k][j];
         iSize[i][j] += 1;
         cout << "Size final: " << iSize[i][j] << endl;
         }
         */
        
        
        cout << "Matriz final: " << endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout << costs[i][j] << " ";
            }
            cout << endl;
        }
        
        cout << endl << endl << "Matriz Escalas: " << endl;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout << iSize[i][j] << " ";
            }
            cout << endl;
        }
        
        if(costs[src][dst] == 99999)
        {
            return -1;
        }
        
        return costs[src][dst];
    }
    
};
