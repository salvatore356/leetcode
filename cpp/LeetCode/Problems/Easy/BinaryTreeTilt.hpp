//
//  BinaryTreeTilt.hpp
//  LeetCode
//
//  Created by Salvatore on 15/8/23.
//

#ifndef BinaryTreeTilt_hpp
#define BinaryTreeTilt_hpp

#include <stdio.h>

namespace BinaryTreeTilt {

    int sumTilt(TreeNode<int> *node, int &total) {
        if (node == nullptr) return 0;

        int left_sum = sumTilt(node->left, total);
        int right_sum = sumTilt(node->right, total);
        
        total += abs(left_sum - right_sum);

        return node->val + left_sum + right_sum;
    }

    int findTilt(TreeNode<int>* root) {
        int total = 0;
        sumTilt(root, total);
        return total;
    }

    vector<vector<int>> cases = {
        { 1, 2, 3 },
        { 4, 2, 9, 3, 5, INT_MIN, 7 },
        { 21, 7, 14, 1, 1, 2, 2, 3, 3}
    };

    vector<int> expected = {
        1,
        15,
        9
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            
            int solution = findTilt(tree);
            
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

#endif /* BinaryTreeTilt_hpp */
