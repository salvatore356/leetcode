//
//  226. Invert Binary Tree.hpp
//  LeetCode
//
//  Created by Salvatore on 5/8/23.
//

#ifndef InvertBinaryTree_hpp
#define InvertBinaryTree_hpp

#include <stdio.h>
#include "../../Utils/Utils.hpp"

/** Given the root of a binary tree, invert the tree, and return its root. **/

namespace InverTree {

    TreeNode<int>* invertTree(TreeNode<int>* root) {
        
        if(!root) return nullptr; // Base case: If the node is null, return nullptr.
        
        // Store the childs temporarily.
        TreeNode<int> *tempL = root->left;
        TreeNode<int> *tempR = root->right;
        
        // Swap the childs
        root->left = tempR;
        root->right = tempL;
        
        // Recursively invert the left and right subtrees.
        invertTree(root->left);
        invertTree(root->right);
        
        // Return the root of the inverted tree.
        return root;
    }

    vector<vector<int>> cases = {
        {4, 2, 7, 1, 3, 6, 9},
        {2, 1, 3},
        {},
        {1, 2, 3, 4, 5, 6, 7}
    };

    vector<vector<int>> expected = {
        {4, 7, 2, 9, 6, 3, 1},
        {2, 3, 1},
        {},
        {1, 3, 2, 7, 6, 5, 4}
    };

    inline void test() {
        vector<int> t = {};
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            TreeNode<int> *solution = invertTree(tree);
            
            vector<int> arr = treeToArray(solution);
            
            bool passed = compareArrays(arr, expected[i]);
            
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\t\t");
            printArray(cases[i]);
            printf("expected:\t");
            printArray(expected[i]);
            printf("solution:\t");
            printArray(arr);
            printf("\n");
        }
    }
}
#endif /* _26__Invert_Binary_Tree_hpp */
