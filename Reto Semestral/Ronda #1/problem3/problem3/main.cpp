//
//  main.cpp
//  problem3
//
//  Created by Layla Tame on 2/5/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main () {
    
    int iElem, iNum;
    cout << "Number of elements: ";
    cin >> iElem;
    vector<int> vec;
    
    for (int i = 0; i<iElem; i++)
    {
        cin >> iNum;
        vec.push_back(iNum);
    }
    
    sort(vec.begin(), vec.end());
    
    //PRINT
    for (int i = 0; i<iElem; i++)
    {
        cout << vec[i] << " ";
    }
}
