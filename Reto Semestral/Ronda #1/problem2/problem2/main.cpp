//
//  main.cpp
//  problem2
//
//  Created by Layla Tame on 2/5/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <vector>
#include <iostream>
using namespace std;

// Complete the matchingStrings function below.
vector<int> matchingStrings(vector<string> strings, vector<string> queries, int queries_count, int strings_count) {
    
    vector<int> res(queries_count);
    
    for (int i = 0; i < queries_count; i++)
    {
        int iCount = 0;
        for (int j = 0; j < strings_count; j++)
        {
            if (queries[i] == strings[j])
            {
                iCount++;
            }
        }
        res[i] = iCount;
    }
    
    return res;
    
}

int main()
{
    
    int strings_count;
    cin >> strings_count;
    
    vector<string> strings(strings_count);
    string strings_item;

    for (int i = 0; i < strings_count; i++) {
        cin >> strings_item;
        strings[i] = strings_item;
    }
    
    int queries_count;
    cin >> queries_count;
    
    vector<string> queries(queries_count);
    string queries_item;

    for (int i = 0; i < queries_count; i++) {
        cin >> queries_item;
        queries[i] = queries_item;
    }
    
    vector<int> res = matchingStrings(strings, queries, queries_count, strings_count);
    
    for (int i = 0; i < res.size(); i++) {
        cout << res[i];
        
        if (i != res.size() - 1) {
            cout << "\n";
        }
    }
    
    cout << "\n";
        
    return 0;
}
