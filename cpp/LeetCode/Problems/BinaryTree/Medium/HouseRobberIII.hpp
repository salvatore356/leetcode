//
//  HouseRobberIII.hpp
//  LeetCode
//
//  Created by Salvatore on 12/10/23.
//

#ifndef HouseRobberIII_hpp
#define HouseRobberIII_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace HouseRobberIII {

    pair<int, int> robHelper(TreeNode<int> *&root) {
        if (root == NULL) return { 0, 0 };

        pair<int, int> left = robHelper(root->left);
        pair<int, int> right = robHelper(root->right);

        int notRobbed =
            max( left.first,  left.second) +
            max(right.first, right.second);

        int robbed = root->val + left.first + right.first;
        
        return pair<int, int>{notRobbed, robbed};
    }

    int rob(TreeNode<int>* root) {
        pair<int, int> ans = robHelper(root);
        return max(ans.first, ans.second);
    }

    vector<vector<int>> cases = {
        { 3, 2, 3, INT_MIN, 3, INT_MIN, 1 },
        { 3, 4, 5, 1, 3, INT_MIN, 1 },
    };

    vector<int> expected = { 7, 9 };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = rob(tree);
            
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

#endif /* HouseRobberIII_hpp */
