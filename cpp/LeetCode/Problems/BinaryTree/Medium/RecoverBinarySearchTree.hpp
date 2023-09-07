//
//  RecoverBinarySearchTree.hpp
//  LeetCode
//
//  Created by Salvatore on 7/9/23.
//

#ifndef RecoverBinarySearchTree_hpp
#define RecoverBinarySearchTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace RecoverBinarySearchTree {

    void trasverse(
       TreeNode<int>* root, TreeNode<int> *&prev,
       TreeNode<int> *&first, TreeNode<int> *&second
    ) {
        if (root == NULL) return;

        trasverse(root->left, prev, first, second);

        if (prev && root->val < prev->val) {
            if(first == NULL) first = prev;
            second = root;
        }
        prev = root;

        trasverse(root->right, prev, first, second);
    }

    void recoverTree(TreeNode<int>* root) {
        TreeNode<int> *prev = nullptr, *first = nullptr, *second = nullptr;
        // Perform an in-order traversal to find the misplaced nodes
        trasverse(root, prev, first, second);
        swap(first->val, second->val);
    }

    vector<vector<int>> cases = {
        { 3, 1, 4, INT_MIN, INT_MIN, 2 },
        { 1, 3, INT_MIN, INT_MIN, 2 },
    };
    
    vector<vector<int>> expected = {
        { 2, 1, 4, INT_MIN, INT_MIN, 3 },
        { 3, 1, INT_MIN, INT_MIN, 2 },
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            recoverTree(tree);
            auto solution = treeToArray(tree);
            parseVector(solution);
            
            bool passed = compareArrays(solution, expected[i]);
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            printf("expected:\t");
            printArray(expected[i]);
            printf("solution:\t");
            printArray(solution);
            printf("\n");
        }
    }


}

#endif /* RecoverBinarySearchTree_hpp */
