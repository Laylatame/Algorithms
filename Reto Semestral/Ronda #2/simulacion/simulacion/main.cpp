//
//  main.cpp
//  simulacion
//
//  Created by Layla Tame on 3/7/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
#include <queue>
#include <sstream>
#include <tuple>
using namespace std;


//Definition for a binary tree node.
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
private:
    pair<int, int> tempNode1, tempNode2;
    int tempFather = 0;
public:
    bool isCousins(TreeNode* root, int x, int y)
    {
        if(root == NULL)
        {
            return false;
        }
        
        int depth = 0;
        pair<int, int> depth1 = findDepth(x, root, depth);
        pair<int, int> depth2 = findDepth(y, root, depth);
        
        if(depth1.first == depth2.first && depth1.second != depth2.second)
        {
            return true;
        }
        
        return false;
    }
    
    pair<int, int> findDepth(int x, TreeNode* nodeSearch, int depth)
    {
        //Buscar si existe el número y encontrar en que nivel está
        if(nodeSearch == NULL)
        {
            return make_pair(0, 0);
        }
        
        if(nodeSearch->val == x)
        {
            return make_pair(depth, 1);
        }
        else
        {
            tempFather = nodeSearch->val;
            tempNode1 = findDepth(x, nodeSearch->left, depth+1);
            if(tempNode1.first != 0)
            {
                return make_pair(tempNode1.first, tempFather);
            }
            tempFather = nodeSearch->val;
            tempNode2 = findDepth(x, nodeSearch->right, depth+1);
            if(tempNode2.first != 0)
            {
                return make_pair(tempNode2.first, tempFather);
            }
        }
        return make_pair(0, 0);
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }
    
    string item;
    stringstream ss;
    ss.str(input);
    
    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);
    
    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();
        
        if (!getline(ss, item, ',')) {
            break;
        }
        
        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }
        
        if (!getline(ss, item, ',')) {
            break;
        }
        
        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int x = stringToInteger(line);
        getline(cin, line);
        int y = stringToInteger(line);
        
        bool ret = Solution().isCousins(root, x, y);
        
        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}
