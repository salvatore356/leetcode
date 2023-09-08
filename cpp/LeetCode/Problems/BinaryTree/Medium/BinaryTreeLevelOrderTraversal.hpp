//
//  BinaryTreeLevelOrderTraversal.hpp
//  LeetCode
//
//  Created by Salvatore on 8/9/23.
//

#ifndef BinaryTreeLevelOrderTraversal_hpp
#define BinaryTreeLevelOrderTraversal_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace BinaryTreeLevelOrderTraversal {

    void levelOrder(TreeNode<int> *&root, vector<vector<int>> &ans, int level) {
        if(root == NULL) return;
        int nextLevel = level + 1;
        if(ans.size() < nextLevel) ans.resize(nextLevel);

        ans[level].push_back(root->val);

        levelOrder(root->left, ans, nextLevel);
        levelOrder(root->right, ans, nextLevel);
    }

    vector<vector<int>> levelOrder(TreeNode<int>* root) {
        vector<vector<int>> ans;
        levelOrder(root, ans, 0);
        return ans;
    }

    vector<vector<int>> cases = {
        { 3, 9, 20, INT_MIN, INT_MIN, 15, 7 },
        { 1 },
        {}
    };

    vector<vector<vector<int>>> expected = {
        {
            { 3 }, { 9, 20 }, { 15, 7 }
        },
        {
            { 1 }
        },
        {
            
        }
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = levelOrder(tree);
            
            bool passed = true;
            for(int k = 0; k < expected[i].size(); ++k)
                passed = passed && compareArrays(solution[k], expected[i][k]);
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            printf("expected:\t\n");
            for(int k = 0; k < expected[i].size(); ++k){
                printf("\t");
                printArray(expected[i][k]);
            }
            printf("solution:\t\n");
            for(int k = 0; k < solution.size(); ++k) {
                printf("\t");
                printArray(solution[k]);
            }
            printf("\n");
        }
    }



}

#endif /* BinaryTreeLevelOrderTraversal_hpp */
