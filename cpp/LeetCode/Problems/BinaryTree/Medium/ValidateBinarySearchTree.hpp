//
//  ValidateBinarySearchTree.hpp
//  LeetCode
//
//  Created by Salvatore on 7/9/23.
//

#ifndef ValidateBinarySearchTree_hpp
#define ValidateBinarySearchTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace ValidateBinarySearchTree {

    void trasverse(TreeNode<int>* root, vector<int> &vec) {
        if (root == NULL) return;
        trasverse(root->left, vec);
        vec.push_back(root->val);
        trasverse(root->right, vec);
    }

    bool isValidBST(TreeNode<int>* root) {
        vector<int> inorder;
        trasverse(root, inorder);

        for(int i = 1; i < inorder.size(); ++i)
            if(inorder[i-1] >= inorder[i]) return false;

        return true;
    }

    vector<vector<int>> cases = {
        { 2, 1, 3 },
        { 5, 1, 4, INT_MIN, INT_MIN, 3, 6 },
    };

    vector<bool> expected = { true, false };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = isValidBST(tree);
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

#endif /* ValidateBinarySearchTree_hpp */
