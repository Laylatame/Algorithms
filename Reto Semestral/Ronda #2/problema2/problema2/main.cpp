//
//  main.cpp
//  problema2
//
//  Created by Layla Tame on 3/4/19.
//  Copyright © 2019 Layla Tame. All rights reserved.
//

#include <iostream>
using namespace std;

//Minimum Depth of Binary Tree

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int minDepth(TreeNode* root, int depth) {
        if(root == NULL)
        {
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            return 1;
            
        }
        
        else
        {
            depth++;
            //int iLeft = minDepth(root->left, depth); //regresa 1
            //int iRight = minDepth(root->right, depth); //regresa 1
            if(root->left != NULL)
            {
                depth = (depth > minDepth(root->left) ?
                         depth : minDepth(root->left))
                //depth = min(depth, minDepth(root->left));
            }
            if(root->right != NULL)
            {
                depth = (depth > minDepth(root->right) ?
                         depth : minDepth(root->right))
                //depth = min(depth, minDepth(root->right));
            }*/
            return depth;
            //return depth;
        }
        
        
        /*if(root->left == NULL && root->right == NULL)
         {
         return 1;
         }
         
         else
         {
         //min = 2
         int iLeft = minDepth(root->left); //regresa 1
         int iRight = minDepth(root->right); //regresa 1
         if(iLeft == 0)
         {
         iLeft = iRight;
         }
         if(iRight == 0)
         {
         iRight = iLeft;
         }
         return min(iLeft, iRight)+1;
         }*/
        
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

int main() {
    string line;
    int depth = 0;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().minDepth(root, depth);
        
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int depth = 0, depth1 = 0, depth2 = 0;
public:
    /* int minDepth(TreeNode* root) {
     if(root == NULL)
     {
     return 0;
     }
     
     /*if(root->left == NULL && root->right == NULL)
     {
     return 1;
     
     }
     
     else
     {
     //depth++;
     cout << "Depth inicial: " << depth << endl;
     //int iLeft = minDepth(root->left, depth); //regresa 1
     //int iRight = minDepth(root->right, depth); //regresa 1
     if(root->left != NULL)
     {
     depth = depth + minDepth(root->left);
     //depth1 = (depth > minDepth(root->left, depth) ?
     //             depth : minDepth(root->left, depth));
     //depth = min(depth, minDepth(root->left));
     cout << "Depth left: " << depth << endl;
     cout << "MinDepth: " << minDepth(root->left) << endl;
     }
     if(root->right != NULL)
     {
     depth = depth + minDepth(root->right);
     //depth2 = (depth > minDepth(root->right, depth) ?
     //       depth : minDepth(root->right, depth));
     //depth = min(depth, minDepth(root->right));
     cout << "Depth right: " << depth << endl;
     }
     //depth = (depth1 > depth2 ?
     //           depth1 : depth2);
     cout << "Depth final: " << depth << endl << endl;
     return depth;
     //return depth;
     }*/
    
    
    /*if(root->left == NULL && root->right == NULL)
     {
     return 1;
     }
     
     else
     {
     //min = 2
     depth1 = depth + (depth > minDepth(root->left) ? depth : minDepth(root->left));
     //depth + minDepth(root->left); //regresa 1
     depth2 = depth + (depth > minDepth(root->right) ? depth : minDepth(root->right));
     //depth + minDepth(root->right); //regresa 1
     /*if(iLeft == 0)
     {
     iLeft = iRight;
     }
     if(iRight == 0)
     {
     iRight = iLeft;
     }
     return (depth1 > depth2 ? depth1 : depth2);
     //min(iLeft, iRight)+1;*/
    // }
    
    // }*/
    int minDepth(TreeNode *root)
    {
        // Corner case. Should never be hit unless the code is
        // called on root = NULL
        if (root == NULL)
            return 0;
        
        // Base case : Leaf Node. This accounts for height = 1.
        if (root->left == NULL && root->right == NULL)
            return 1;
        
        // If left subtree is NULL, recur for right subtree
        if (!root->left)
            return minDepth(root->right) + 1;
        
        // If right subtree is NULL, recur for left subtree
        if (!root->right)
            return minDepth(root->left) + 1;
        
        return min(minDepth(root->left), minDepth(root->right)) + 1;
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

int main() {
    string line;
    int depth = 0;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        
        int ret = Solution().minDepth(root);
        
        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}




/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
private:
    int depth = 0;
public:
    int minDepth(TreeNode *root)
    {
        if(root == NULL)
        {
            return 0;
        }
        
        if(root->left == NULL && root->right == NULL)
        {
            return 1;
        }
        
        else
        {
            int depth1, depth2;
            if(root->left != NULL)
            {
                depth1 = depth + (depth > minDepth(root->left) ?
                                  depth : minDepth(root->left));
            }
            if(root->right != NULL)
            {
                depth2 = depth + (depth > minDepth(root->right) ?
                                  depth : minDepth(root->right));
            }
            
            depth = (depth1 > depth2 ? depth1 : depth2);
            return depth;
        }
    }
};
