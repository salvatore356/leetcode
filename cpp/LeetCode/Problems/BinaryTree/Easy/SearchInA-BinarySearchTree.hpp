//
//  SearchInA-BinarySearchTree.hpp
//  LeetCode
//
//  Created by Salvatore on 28/8/23.
//

#ifndef SearchInA_BinarySearchTree_hpp
#define SearchInA_BinarySearchTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace SearchInABinarySearchTree {

    TreeNode<int>* searchBST(TreeNode<int>* root, int val) {

        if (root == nullptr) return nullptr;
        if (root->val == val) return root;

        TreeNode<int>* left = searchBST(root->left, val);
        if(left != nullptr) return left;

        return searchBST(root->right, val);
    }

    vector<vector<int>> cases = {
        { 4, 2, 7, 1, 3 },
        { 4, 2, 7, 1, 3 },
    };

    vector<int> vals = {
        2,
        5,
    };

    vector<vector<int>> expected = {
        { 2, 1, 3 },
        {}
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solutionTree = searchBST(tree, vals[i]);
            auto solution = treeToArray(solutionTree);
            
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
#endif /* SearchInA_BinarySearchTree_hpp */
