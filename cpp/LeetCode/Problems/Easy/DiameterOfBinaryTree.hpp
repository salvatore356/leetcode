//
//  DiameterOfBinaryTree.hpp
//  LeetCode
//
//  Created by Salvatore on 14/8/23.
//

#ifndef DiameterOfBinaryTree_hpp
#define DiameterOfBinaryTree_hpp

#include <stdio.h>

#include "../../Utils/Utils.hpp"

namespace DiameterOfBinaryTree {

    int diameterOfBinaryTree(TreeNode<int>* root, int &maxDiameter) {
        if (root == nullptr) return 0;

        int left_h = diameterOfBinaryTree(root->left, maxDiameter);
        int right_h = diameterOfBinaryTree(root->right, maxDiameter);

        maxDiameter = max(maxDiameter, left_h + right_h);
        
        return 1 + max(left_h, right_h);
    }

    int diameterOfBinaryTree(TreeNode<int>* root) {
        int maxDiameter = 0;
        diameterOfBinaryTree(root, maxDiameter);
        return maxDiameter;
    }

    vector<vector<int>> cases = {
        { 1, 2, 3, 4, 5 },
    };

    vector<int> expected = {
        3,
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            
            int solution = diameterOfBinaryTree(tree);
            
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
#endif /* DiameterOfBinaryTree_hpp */
