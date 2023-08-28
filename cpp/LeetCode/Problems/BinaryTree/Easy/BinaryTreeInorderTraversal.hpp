//
//  BinaryTreeInorderTraversal.hpp
//  LeetCode
//
//  Created by Salvatore on 28/8/23.
//

#ifndef BinaryTreeInorderTraversal_hpp
#define BinaryTreeInorderTraversal_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace BinaryTreeInorderTraversal {

    void inorder(TreeNode<int>* node, vector<int> &ans){
        if (node == NULL) return;

        inorder(node->left, ans);
        ans.push_back(node->val);

        inorder(node->right, ans);
    }

    vector<int> inorderTraversal(TreeNode<int>* root) {
        vector<int> ans;
        inorder(root, ans);
        return ans;
    }

    vector<vector<int>> cases = {
        { 1, INT_MIN, 2, INT_MIN, INT_MIN, 3 },
        {},
        { 1 }
    };

    vector<vector<int>> expected = {
        {1, 3, 2},
        {},
        {1}
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = inorderTraversal(tree);
            
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

#endif /* BinaryTreeInorderTraversal_hpp */
