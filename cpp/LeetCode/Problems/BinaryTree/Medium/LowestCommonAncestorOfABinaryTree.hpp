//
//  LowestCommonAncestorOfABinaryTree.hpp
//  LeetCode
//
//  Created by Salvatore on 23/9/23.
//

#ifndef LowestCommonAncestorOfABinaryTree_hpp
#define LowestCommonAncestorOfABinaryTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace LowestCommonAncestorOfABinaryTree {

    TreeNode<int>* lowestCommonAncestor(
        TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q
    ) {
        if ( root == NULL ) return NULL;

        if (root->val == p->val || root->val == q->val) return root;

        TreeNode<int>* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode<int>* rightLCA = lowestCommonAncestor(root->right, p, q);

        if (leftLCA != NULL && rightLCA != NULL) return root;

        return leftLCA != NULL ? leftLCA : rightLCA;
    }

    vector<vector<int>> cases = {
        { 3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4 },
        { 3, 5, 1, 6, 2, 0, 8, INT_MIN, INT_MIN, 7, 4 },
        { 1, 2 }
    };

    vector<int> expected = { 3, 2, 1 };

    vector<int> P = { 5, 5, 1 };
    vector<int> Q = { 1, 4, 2 };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            TreeNode<int> *p =  new TreeNode<int>(P[i]);
            TreeNode<int> *q =  new TreeNode<int>(Q[i]);
            auto solution = lowestCommonAncestor(tree, p, q);
             
            bool passed = solution->val == expected[i];
            
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            printf("expected:\t%d\n", expected[i]);
            
            printf("solution:\t%d\n", solution->val);
            
            printf("\n");
        }
    }
}

#endif /* LowestCommonAncestorOfABinaryTree_hpp */
