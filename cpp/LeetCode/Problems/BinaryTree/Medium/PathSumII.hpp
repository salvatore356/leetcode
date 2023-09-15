//
//  PathSumII.hpp
//  LeetCode
//
//  Created by Salvatore on 15/9/23.
//

#ifndef PathSumII_hpp
#define PathSumII_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace PathSumII {

    void pathSumHelper( TreeNode<int> *&root,
        vector<int> &currentPath, vector<vector<int>> &ans,
        int &targetSum, int currentSum
    ) {
        if (root == NULL) return;

        int newSum = currentSum + root->val;

        currentPath.push_back(root->val);

        if( root->left == NULL && root->right == NULL ) {
            if( newSum == targetSum ) ans.push_back(currentPath);
            currentPath.pop_back();
            return;
        } else {
            if(root->left != NULL)
                pathSumHelper(root->left, currentPath, ans, targetSum, newSum);
            if(root->right != NULL)
                pathSumHelper(root->right, currentPath, ans, targetSum, newSum);
        }
        currentPath.pop_back();
    }
        
    vector<vector<int>> pathSum(TreeNode<int>* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> currentPath;
        pathSumHelper( root, currentPath, ans, targetSum, 0 );
        return ans;
    }

    vector<vector<int>> cases = {
        { 5,
          4, 8,
          11, INT_MIN, 13, 4,
          7, 2, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 5, 1 },
        { 1, 2, 3 },
        { 1, 2 }
    };

    vector<int> targetSum = { 22, 5, 0};

    vector<vector<vector<int>>> expected = {
        {
            { 5, 4, 11, 2 }, { 5, 8, 4, 5 }
        },
        { },
        { }
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = pathSum(tree, targetSum[i]);
            
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

#endif /* PathSumII_hpp */
