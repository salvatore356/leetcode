//
//  T*reeNode.hpp
//  LeetCode
//
//  Created by Salvatore on 5/8/23.
//

#ifndef TreeNode_hpp
#define TreeNode_hpp

#include <stdio.h>

using namespace std;

template <typename T>
struct TreeNode {
    T val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

    
#endif /* TreeNode_hpp */
