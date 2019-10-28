//
//  main.cpp
//  problem1
//
//  Created by Layla Tame on 2/27/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

//Reto Semestral - Problema 1. Majority Element
int input, iSize = 0;
string line;
vector<int> numbers;

void readVector()
{
    cout << "Enter array: " << endl;
    getline(cin, line);
    istringstream stream(line);
    while(stream >> input)
    {
        numbers.push_back(input);
        iSize++;
    }
}

int majorityElement(vector<int> numbers, int iSize)
{
    sort(numbers.begin(), numbers.end());
    return numbers[iSize/2];
}

int main() {
    
    readVector();
    cout << majorityElement(numbers, iSize);
}
