//
//  SymmetricTree.hpp
//  LeetCode
//
//  Created by Salvatore on 28/8/23.
//

#ifndef SymmetricTree_hpp
#define SymmetricTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace SymmetricTree {

    bool isSymmetric(TreeNode<int> *left, TreeNode<int> *right){

        if(left == nullptr ) return right == nullptr;
        if(right == nullptr) return false;

        return  left->val == right->val &&
                isSymmetric(left->left, right->right) &&
                isSymmetric(left->right, right->left);
    }

    bool isSymmetric(TreeNode<int>* root) {
        return isSymmetric(root->left, root->right);
    }

    vector<vector<int>> cases = {
        { 1, 2, 2, 3, 4, 4, 3 },
        { 1, 2, 2, INT_MIN, 3, INT_MIN, 3 },
    };

    vector<bool> expected = {
        true,
        false
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = isSymmetric(tree);
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

#endif /* SymmetricTree_hpp */
