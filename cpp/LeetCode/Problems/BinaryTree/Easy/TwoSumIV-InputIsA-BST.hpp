//
//  TwoSumIV-InputIsA-BST.hpp
//  LeetCode
//
//  Created by Salvatore on 23/8/23.
//

#ifndef TwoSumIV_InputIsA_BST_hpp
#define TwoSumIV_InputIsA_BST_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace TwoSumIVInputIsABST {

    void inOrder(TreeNode<int> *node, vector<int> &inOrderValues) {
        if(node == NULL) return;

        inOrder(node->left, inOrderValues);
        inOrderValues.push_back(node->val);
        inOrder(node->right, inOrderValues);
    }

    bool findTarget(TreeNode<int>* root, int k) {
        vector<int> inOrderValues;
        inOrder(root, inOrderValues);

        int left = 0, right = (int)inOrderValues.size() - 1;
        while(left < right) {
            int sum = inOrderValues[left] + inOrderValues[right];

            if ( sum == k) return true;
            (sum < k)? ++left : --right;
        }

        return false;
    }

    vector<vector<int>> cases = {
        { 5, 3, 6, 2, 4, INT_MIN, 7 },
        { 5, 3, 6, 2, 4, INT_MIN, 7 },
    };

    vector<int> k = {
        9,
        28,
    };

    vector<bool> expected = {
        true,
        false
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            bool solution = findTarget(tree, k[i]);
            
            bool passed = solution == expected[i];
            
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            printf("\tk:\t%d\n", k[i]);
            printf("expected:\t%d\n", (int)expected[i]);
            
            printf("solution:\t%d\n", solution);
            printf("\n");
        }
    }

}
#endif /* TwoSumIV_InputIsA_BST_hpp */
