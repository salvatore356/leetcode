//
//  EvaluateBooleanBinaryTree.hpp
//  LeetCode
//
//  Created by Salvatore on 1/9/23.
//

#ifndef EvaluateBooleanBinaryTree_hpp
#define EvaluateBooleanBinaryTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace EvaluateBooleanBinaryTree{
    
    bool evaluateTree(TreeNode<int>* root) {
        if (root->val < 2) return (bool)root->val;
        
        if(root->val == 3)
            return evaluateTree(root->left) && evaluateTree(root->right);
        
        return evaluateTree(root->left) || evaluateTree(root->right);
    }

    vector<vector<int>> cases = {
        { 2, 1, 3, INT_MIN, INT_MIN, 0, 1 },
        { 0 },
    };

    vector<bool> expected = { true, false };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = evaluateTree(tree);
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
#endif /* EvaluateBooleanBinaryTree_hpp */
