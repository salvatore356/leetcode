//
//  UnivaluedBinaryTree.hpp
//  LeetCode
//
//  Created by Salvatore on 31/8/23.
//

#ifndef UnivaluedBinaryTree_hpp
#define UnivaluedBinaryTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace UnivaluedBinaryTree {

    bool isUnivalTree(TreeNode<int>* root, int prev) {
        if (root == nullptr) return true;

        return  prev == root->val &&
                isUnivalTree(root->left, prev) &&
                isUnivalTree(root->right, prev);
    }

    bool isUnivalTree(TreeNode<int>* root) {
        return isUnivalTree(root, root->val);
    }
    
    vector<vector<int>> cases = {
        { 1, 1, 1, 1, 1, INT_MIN, 1 },
        { 2, 2, 2, 5, 2 },
    };

    vector<bool> expected = {
        true,
        false
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = isUnivalTree(tree);
            bool passed = solution == expected[i];
            
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            printf("expected:\t%d\n", (int)expected[i]);
            
            printf("solution:\t%d\n", solution);
            printf("\n");
        }
    }


}

#endif /* UnivaluedBinaryTree_hpp */
