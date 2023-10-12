//
//  PathSumIII.hpp
//  LeetCode
//
//  Created by Salvatore on 12/10/23.
//

#ifndef PathSumIII_hpp
#define PathSumIII_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace PathSumIII {

    void pathSumHelper(
        TreeNode<int> *&root,
        unordered_map<long, int> &sum_paths,
        long currentSum,
        int &targetSum, int &count
    ) {
        if (root == NULL) return;
        currentSum = currentSum + root->val;
        count = count + sum_paths[currentSum - targetSum];

        ++sum_paths[currentSum];
        pathSumHelper( root->left, sum_paths, currentSum, targetSum, count );
        pathSumHelper( root->right, sum_paths, currentSum, targetSum, count );
        --sum_paths[currentSum];
    }

    int pathSum(TreeNode<int>* root, int targetSum) {
        unordered_map<long, int> sum_paths;
        sum_paths[0] = 1;
        int count = 0;
        pathSumHelper( root, sum_paths, 0, targetSum, count );
        return count;
    }

    

    vector<vector<int>> cases = {
        { 10, 5, -3, 3, 2, INT_MIN, 11, 3, -2, INT_MIN, 1 },
        { 5, 4, 8, 11, INT_MIN, 13, 4, 7, 2, INT_MIN, INT_MIN, 5, 1 },
    };

    vector<int> targetSum = { 8, 22 };

    vector<int> expected = { 3, 3 };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = pathSum(tree, targetSum[i]);
            
            bool passed = solution == expected[i];
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            printf("expected:\t%d\n", expected[i]);
            
            printf("solution:\t%d\n", solution);
            printf("\n");
        }
    }
}

#endif /* PathSumIII_hpp */
