//
//  BinaryTreePostorderTraversal.hpp
//  LeetCode
//
//  Created by Salvatore on 8/8/23.
//

#ifndef BinaryTreePostorderTraversal_hpp
#define BinaryTreePostorderTraversal_hpp

#include <stdio.h>
#include "../../Utils/Utils.hpp"

/** Given the root of a binary tree, return the preorder traversal of its nodes' values. **/

namespace PostOrderTraversal {

    void postOrderNode(vector<int> &arr, TreeNode<int> *node){
        if(node == nullptr) return;
        
        postOrderNode(arr, node->left);
        postOrderNode(arr, node->right);
        
        arr.push_back(node->val);
    }

    vector<int> postOrderTraversal(TreeNode<int>* root) {
        vector<int> ans;
        postOrderNode(ans, root);
        return ans;
    }

    vector<vector<int>> cases = {
        {1, INT_MIN, 2, INT_MIN, INT_MIN, 3},
        {},
        {1}
    };

    vector<vector<int>> expected = {
        {3, 2, 1},
        {},
        {1},
    };

    inline void test() {
        vector<int> t = {};
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            vector<int> solution = postOrderTraversal(tree);
            
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
#endif /* BinaryTreePostorderTraversal_hpp */
