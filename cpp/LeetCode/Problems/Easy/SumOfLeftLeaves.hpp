//
//  SumOfLeftLeaves.hpp
//  LeetCode
//
//  Created by Salvatore on 12/8/23.
//

#ifndef SumOfLeftLeaves_hpp
#define SumOfLeftLeaves_hpp

#include <stdio.h>

#include "../../Utils/Utils.hpp"

namespace SumOfLeftLeaves {
    
    int sumOfLeftLeaves(TreeNode<int>* root, bool isLeft) {
        if(root == nullptr) return 0;

        TreeNode<int> *left = root->left;
        TreeNode<int> *right = root->right;

        if(isLeft && left == nullptr && right == nullptr)
        return root->val;
        return sumOfLeftLeaves(left, true) + sumOfLeftLeaves(right, false);
    }

    int sumOfLeftLeaves(TreeNode<int>* root) {
        return sumOfLeftLeaves(root, false);
    }

    

    vector<vector<int>> cases = {
        {3, 9, 20, INT_MIN, INT_MIN, 15, 7},
        {1},
    };

    vector<int> expected = {
        24,
        0,
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            
            auto solution = sumOfLeftLeaves(tree);
            
            bool passed = solution == expected[i];
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            
            printf("expected:\t%d\n", expected[i]);
            
            printf("solution:\t%d\n", solution);
            printf("\n");
        }
    }
}
#endif /* SumOfLeftLeaves_hpp */
