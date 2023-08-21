//
//  MergeTwoBinaryTrees.hpp
//  LeetCode
//
//  Created by Salvatore on 21/8/23.
//

#ifndef MergeTwoBinaryTrees_hpp
#define MergeTwoBinaryTrees_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace MergeTwoBinaryTrees {

    TreeNode<int>* mergeTrees(TreeNode<int>* root1, TreeNode<int>* root2) {
        
        if (root1 == nullptr) return root2;
        if (root2 == nullptr) return root1;
        
        root1->val += root2->val;
        root1->left = mergeTrees(root1->left, root2->left);
        root1->right = mergeTrees(root1->right, root2->right);
        
        return root1;
    }

    vector<vector<int>> treesP = {
        { 1, 3, 2, 5 },
        { 1 },
    };

    vector<vector<int>> treesQ = {
        { 2, 1, 3, INT_MIN, 4, INT_MIN, 7 },
        { 1, 2 },
    };

    vector<vector<int>> expected = {
        { 3, 4, 5, 5, 4, INT_MIN, 7 },
        { 2, 2 },
    };

    inline void test() {
        
        for(int i = 0; i < treesP.size(); ++i) {
            TreeNode<int> *treeP =  loadTree(treesP[i]);
            TreeNode<int> *treeQ =  loadTree(treesQ[i]);
            TreeNode<int> *treeSolution = mergeTrees(treeP, treeQ);
            auto solution = treeToArray(treeSolution);
            bool passed = compareArrays(solution, expected[i]);
            
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\t\tp ");
            printArray(treesP[i]);
            printf("\t\t\tq ");
            printArray(treesQ[i]);
            printf("expected:\t");
            printArray(expected[i]);
            printf("solution:\t");
            printArray(solution);
            printf("\n");
        }
    }

}

#endif /* MergeTwoBinaryTrees_hpp */
