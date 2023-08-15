//
//  CountCompleteTreeNodes.hpp
//  LeetCode
//
//  Created by Salvatore on 10/8/23.
//

#ifndef CountCompleteTreeNodes_hpp
#define CountCompleteTreeNodes_hpp

#include <stdio.h>
#include "../../Utils/Utils.hpp"

/**
 Given the root of a complete binary tree, return the number of the nodes in the tree.

 According to Wikipedia, every level, except possibly the last, is completely filled in a complete binary tree, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 Design an algorithm that runs in less than O(n) time complexity.
 **/

namespace CountCompleteTreeNodes {

    int countNodes(TreeNode<int>* root) {
        if (!root) return 0;
        TreeNode<int> *left = root->left;
        TreeNode<int> *right = root->right;
        return 1 + countNodes(left) + countNodes(right);
    }

    vector<vector<int>> cases = {
        {1, 2, 3, 4, 5, 6},
        {},
        {1}
    };

    vector<int> expected = {
        6,
        0,
        1,
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            int solution = countNodes(tree);
            
            bool passed = solution == expected[i];
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\t\t");
            printArray(cases[i]);
            printf("expected:\t%d\n", expected[i]);
            printf("solution:\t%d\n", solution);
            printf("\n");
        }
    }
}

#endif /* CountCompleteTreeNodes_hpp */
