//
//  LowestCommonAncestorOfABinarySearchTree.hpp
//  LeetCode
//
//  Created by Salvatore on 23/9/23.
//

#ifndef LowestCommonAncestorOfABinarySearchTree_hpp
#define LowestCommonAncestorOfABinarySearchTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace LowestCommonAncestorOfABinarySearchTree {

    TreeNode<int>* lowestCommonAncestor(
        TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q
    ) {
        if (root == NULL) return NULL;

        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestor(root->left, p, q);
        else if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestor(root->right, p, q);
        else return root;

    }

    TreeNode<int>* lowestCommonAncestorV2(
      TreeNode<int>* root, TreeNode<int>* p, TreeNode<int>* q
    ) {
        TreeNode<int> *ancestor = root;

        while(true) {
            if (p->val < ancestor->val && q->val < ancestor->val)
                ancestor = ancestor->left;
            else if (p->val > ancestor->val && q->val > ancestor->val)
                ancestor = ancestor->right;
            else break;
        }

        return ancestor;
    }

    vector<vector<int>> cases = {
        { 6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5 },
        { 6, 2, 8, 0, 4, 7, 9, INT_MIN, INT_MIN, 3, 5},
        { 2, 1 }
    };

    vector<int> expected = { 6, 2, 2 };

    vector<int> P = { 2, 2, 2 };
    vector<int> Q = { 8, 4, 4 };

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

#endif /* LowestCommonAncestorOfABinarySearchTree_hpp */
