//
//  SumOfRootToLeafBinaryNumbers.hpp
//  LeetCode
//
//  Created by Salvatore on 31/8/23.
//

#ifndef SumOfRootToLeafBinaryNumbers_hpp
#define SumOfRootToLeafBinaryNumbers_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace SumOfRootToLeafBinaryNumbers {

    void sumRootToLeaf(TreeNode<int>* root, int &sum, int prev) {

        if (root == nullptr) return;
        int current = (prev << 1) + root->val;

        if(root->left == nullptr && root->right == nullptr)
            sum += current;
        else {
            sumRootToLeaf(root->left, sum, current);
            sumRootToLeaf(root->right, sum, current);
        }
    }

    int sumRootToLeaf(TreeNode<int>* root) {
        int ans = 0;
        sumRootToLeaf(root, ans, 0);
        return ans;
    }

    vector<vector<int>> cases = {
        { 1, 0, 1, 0, 1, 0, 1 },
        { 0 },
    };

    vector<int> expected = { 22, 0 };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = sumRootToLeaf(tree);
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


#endif /* SumOfRootToLeafBinaryNumbers_hpp */
