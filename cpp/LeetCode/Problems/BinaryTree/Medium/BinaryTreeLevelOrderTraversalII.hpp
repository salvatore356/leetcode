//
//  BinaryTreeLevelOrderTraversalII.hpp
//  LeetCode
//
//  Created by Salvatore on 13/9/23.
//

#ifndef BinaryTreeLevelOrderTraversalII_hpp
#define BinaryTreeLevelOrderTraversalII_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace BinaryTreeLevelOrderTraversalII {

    void levelOrderBottomHelper(
        TreeNode<int>* root, vector<vector<int>> &levels, int level
    ) {
        if ( root == nullptr) return;
        
        int nextLevel = level + 1;
        
        if(levels.size() < nextLevel)
            levels.resize(nextLevel);
        
        levelOrderBottomHelper(root->left, levels, nextLevel);
        levelOrderBottomHelper(root->right, levels, nextLevel);

        levels[level].push_back(root->val);
    }

    vector<vector<int>> levelOrderBottom(TreeNode<int>* root) {
        vector<vector<int>> ans;
        levelOrderBottomHelper(root, ans, 0);

        reverse(ans.begin(), ans.end());

        return ans;
    }

    vector<vector<int>> cases = {
        { 3, 9, 20, INT_MIN, INT_MIN, 15, 7 },
        { 1 },
        {}
    };

    vector<vector<vector<int>>> expected = {
        {
            { 15, 7 }, { 9, 20 }, { 3 }
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
            auto solution = levelOrderBottom(tree);
            
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

#endif /* BinaryTreeLevelOrderTraversalII_hpp */
