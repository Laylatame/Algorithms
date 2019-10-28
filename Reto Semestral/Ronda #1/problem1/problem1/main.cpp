//
//  main.cpp
//  problem1
//
//  Created by Layla Tame on 2/5/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//Left Rotation - Easy
int main() {
    
    int iN, iD;
    cin >> iN >> iD;
    int arr[iN], temp[iD];
    
    for (int i = 0; i < iD; i++)
    {
        cin >> temp[i];
    }
    
    for (int i = 0; i<iN-iD; i++)
    {
        cin >> arr[i];
    }
    
    for (int i = iN-iD, k=0; i<iN; i++, k++)
    {
        arr[i] = temp[k];
    }
    
    for (int i = 0; i<iN; i++)
    {
        cout << arr[i];
        if (i<iN-1)
        {
            cout << " ";
        }
    }
    
}
