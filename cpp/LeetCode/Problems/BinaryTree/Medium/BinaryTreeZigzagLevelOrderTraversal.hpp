//
//  BinaryTreeZigzagLevelOrderTraversal.hpp
//  LeetCode
//
//  Created by Salvatore on 8/9/23.
//

#ifndef BinaryTreeZigzagLevelOrderTraversal_hpp
#define BinaryTreeZigzagLevelOrderTraversal_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace BinaryTreeZigzagLevelOrderTraversal {

    void zigzagLevelOrder(TreeNode<int> *&root, vector<vector<int>> &ans, int level, bool inverse) {

        if(root == NULL) return;
        int nextLevel = level + 1;

        if(ans.size() < nextLevel) ans.resize(nextLevel);

        if(inverse) ans[level].push_back(root->val);
        else ans[level].insert(ans[level].begin(), root->val);

        inverse = !inverse;
        zigzagLevelOrder(root->left, ans, nextLevel, inverse);
        zigzagLevelOrder(root->right, ans, nextLevel, inverse);

    }

    vector<vector<int>> zigzagLevelOrder(TreeNode<int>* root) {
        vector<vector<int>> ans;
        zigzagLevelOrder(root, ans, 0, true);
        return ans;
    }

    vector<vector<int>> cases = {
        { 3, 9, 20, INT_MIN, INT_MIN, 15, 7 },
        { 1 },
        {}
    };

    vector<vector<vector<int>>> expected = {
        {
            { 3 }, { 20, 9 }, { 15, 7 }
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
            auto solution = zigzagLevelOrder(tree);
            
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

#endif /* BinaryTreeZigzagLevelOrderTraversal_hpp */
