//
//  MinimumDistanceBetweenBSTNodes.hpp
//  LeetCode
//
//  Created by Salvatore on 30/8/23.
//

#ifndef MinimumDistanceBetweenBSTNodes_hpp
#define MinimumDistanceBetweenBSTNodes_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace MinimumDistanceBetweenBSTNodes {

    void minDiffInBST(TreeNode<int>* &root, int &minDiff, int &lastNode) {
        if ( root == nullptr ) return;

        minDiffInBST(root->left, minDiff, lastNode);

        if (lastNode != -1 ) {
            int currentDiff = abs(root->val - lastNode);
            minDiff = min(minDiff, currentDiff);
        }

        lastNode = root->val;

        minDiffInBST(root->right, minDiff, lastNode);
    }

    int minDiffInBST(TreeNode<int>* root) {
        int minDiff = INT_MAX, lastNode = -1;
        minDiffInBST(root, minDiff, lastNode);
        return minDiff;
    }

    vector<vector<int>> cases = {
        { 4, 2, 6, 1, 3 },
        { 1, 0, 48, INT_MIN, INT_MIN, 12, 49 },
    };

    vector<int> expected = {
        1,
        1
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            int solution = minDiffInBST(tree);
            
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

#endif /* MinimumDistanceBetweenBSTNodes_hpp */
