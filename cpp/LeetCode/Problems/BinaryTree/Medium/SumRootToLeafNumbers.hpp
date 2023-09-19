//
//  SumRootToLeafNumbers.hpp
//  LeetCode
//
//  Created by Salvatore on 19/9/23.
//

#ifndef SumRootToLeafNumbers_hpp
#define SumRootToLeafNumbers_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace SumRootToLeafNumbers {

    void sumNumbersHelper(TreeNode<int>* root, int &total, int current) {
        if (root == NULL) return;

        current = current * 10 + root->val;
        if(root->left == NULL && root->right == NULL)
        total += current;

        sumNumbersHelper(root->left, total, current);
        sumNumbersHelper(root->right, total, current);

    }

    int sumNumbers(TreeNode<int>* root) {
        int total = 0;

        sumNumbersHelper(root, total, 0);

        return total;

    }

    vector<vector<int>> cases = {
        { 1, 2, 3 },
        { 4, 9, 0, 5, 1 },
    };

    vector<int> expected = { 25, 1026 };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = sumNumbers(tree);
            
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

#endif /* SumRootToLeafNumbers_hpp */
