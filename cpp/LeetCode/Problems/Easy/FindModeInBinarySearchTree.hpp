//
//  FindModeInBinarySearchTree.hpp
//  LeetCode
//
//  Created by Salvatore on 12/8/23.
//

#ifndef FindModeInBinarySearchTree_hpp
#define FindModeInBinarySearchTree_hpp

#include <stdio.h>

#include "../../Utils/Utils.hpp"

namespace FindModeInBinarySearchTree {
    
    void transverse( vector<int> &modes, TreeNode<int> *root, int &maxValue, int &currCount, int &prevVal ){

        if( root == nullptr ) return;

        TreeNode<int> *left = root->left;
        transverse( modes, left, maxValue, currCount, prevVal );

        if ( root->val == prevVal ) ++currCount;
        else currCount = 1;
        
        if( currCount == maxValue ) {
            modes.emplace_back(root->val);
        } else if( currCount > maxValue ) {
            modes.clear();
            modes.emplace_back(root->val);
            maxValue = currCount;
        }

        prevVal = root->val;

        TreeNode<int> *right = root->right;
        transverse(modes, right, maxValue, currCount, prevVal);
    }

    vector<int> findMode(TreeNode<int>* root) {
        vector<int> modes;
        int maxValue = 0, currCount = 0;
        int prevVal = INT_MIN;

        transverse( modes,root, maxValue, currCount, prevVal );

        return modes;
    }

    vector<vector<int>> cases = {
        {1, INT_MIN, 2, INT_MIN, INT_MIN, 2},
        {0},
    };

    vector<vector<int>> expected = {
        {2},
        {0},
    };

    inline void test() {
        vector<int> t = {};
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            
            auto solution = findMode(tree);
            
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

#endif /* FindModeInBinarySearchTree_hpp */
