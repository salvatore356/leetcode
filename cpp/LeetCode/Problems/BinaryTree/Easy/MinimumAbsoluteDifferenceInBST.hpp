//
//  MinimumAbsoluteDifferenceInBST.hpp
//  LeetCode
//
//  Created by Salvatore on 14/8/23.
//

#ifndef MinimumAbsoluteDifferenceInBST_hpp
#define MinimumAbsoluteDifferenceInBST_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace MinimumAbsoluteDifferenceInBST {

    void getMinimumDifference(TreeNode<int>* root, TreeNode<int> *&prev, int &minDiff) {
        
        if (root == nullptr) return;

        TreeNode<int> *left = root->left;
        getMinimumDifference(left, prev, minDiff);

        if (prev != nullptr)
            minDiff = min(minDiff, abs(root->val - prev->val));

        prev = root;

        TreeNode<int> *right = root->right;
        getMinimumDifference(right, prev, minDiff);
    }

    int getMinimumDifference(TreeNode<int>* root) {
        
        int minDiff = INT_MAX;
        TreeNode<int> *prev = nullptr;
        getMinimumDifference(root, prev, minDiff);
        return minDiff;
    }

    vector<vector<int>> cases = {
        {4, 2, 6, 1, 3},
        {1, 0, 48, INT_MIN, INT_MIN, 12, 49},
    };

    vector<int> expected = {
        1,
        1,
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            
            bool solution = getMinimumDifference(tree);
            
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
#endif /* MinimumAbsoluteDifferenceInBST_hpp */
