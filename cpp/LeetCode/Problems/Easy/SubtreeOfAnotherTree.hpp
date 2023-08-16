//
//  SubtreeOfAnotherTree.hpp
//  LeetCode
//
//  Created by Salvatore on 16/8/23.
//

#ifndef SubtreeOfAnotherTree_hpp
#define SubtreeOfAnotherTree_hpp

#include <stdio.h>

#include "../../Utils/Utils.hpp"

namespace SubtreeOfAnotherTree {

    bool isSameTree( TreeNode<int> *root, TreeNode<int> *sub ) {

        if ( root == nullptr ) return sub == nullptr;
        else if ( sub == nullptr ) return false;

        return  root->val == sub->val &&
                isSameTree( root->left, sub->left ) &&
                isSameTree( root->right, sub->right );
        
    }

    bool isSubtree(TreeNode<int>* root, TreeNode<int>* subRoot) {
        return  isSameTree(root, subRoot) ||
                (root != nullptr &&
                    (
                        isSubtree(root->left, subRoot) ||
                        isSubtree(root->right, subRoot)
                    )
                );
    }

    vector<vector<int>> treesP = {
        { 3, 4, 5, 1, 2 },
        { 3, 4, 5, 1, 2, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 0 },
    };

    vector<vector<int>> treesQ = {
        { 4, 1, 2 },
        { 4, 1, 2 },
    };

    vector<bool> expected = {
        true,
        false
    };

    inline void test() {
        
        for(int i = 0; i < treesP.size(); ++i) {
            TreeNode<int> *treeP =  loadTree(treesP[i]);
            TreeNode<int> *treeQ =  loadTree(treesQ[i]);
            
            bool solution = isSubtree(treeP, treeQ);
            
            bool passed = solution == expected[i];
            
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(treesP[i]);
            printf("\tq:\t");
            printArray(treesQ[i]);
            printf("expected:\t%d\n", (int)expected[i]);
            
            printf("solution:\t%d\n", solution);
            printf("\n");
        }
    }

    
}

#endif /* SubtreeOfAnotherTree_hpp */
