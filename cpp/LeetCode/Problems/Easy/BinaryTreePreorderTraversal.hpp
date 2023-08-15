//
//  BinaryTreePreorderTraversal.hpp
//  LeetCode
//
//  Created by Salvatore on 8/8/23.
//

#ifndef BinaryTreePreorderTraversal_hpp
#define BinaryTreePreorderTraversal_hpp

#include <stdio.h>
#include "../../Utils/Utils.hpp"

/** Given the root of a binary tree, return the preorder traversal of its nodes' values. **/

namespace PreOrderTraversal {
    void preOrderNode(vector<int> &arr, TreeNode<int> *node){
        if(node == nullptr) return;
        
        arr.push_back(node->val);
        preOrderNode(arr, node->left);
        preOrderNode(arr, node->right);
    }

    vector<int> preOrderTraversal(TreeNode<int>* root) {
        vector<int> ans;
        preOrderNode(ans, root);
        return ans;
    }

    vector<vector<int>> cases = {
        {1, INT_MIN, 2, INT_MIN, INT_MIN, 3},
        {},
        {1}
    };

    vector<vector<int>> expected = {
        {1, 2, 3},
        {},
        {1},
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            vector<int> solution = preOrderTraversal(tree);
            
            bool passed = compareArrays(solution, expected[i]);
            
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\t\t");
            printArray(cases[i]);
            printf("expected:\t");
            printArray(expected[i]);
            printf("solution:\t");
            printArray(solution);
            printf("\n");
        }
    }
}
#endif /* BinaryTreePreorderTraversal_hpp */
