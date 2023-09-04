//
//  KthSmallestElementInABST.hpp
//  LeetCode
//
//  Created by Salvatore on 4/9/23.
//

#ifndef KthSmallestElementInABST_hpp
#define KthSmallestElementInABST_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace KthSmallestElementInABST {

    void kthSmallestHelper(TreeNode<int> *&root, int &k, int &ans) {

        if (root == NULL) return;

        kthSmallestHelper(root->left, k, ans);
        k = k - 1;
        if(k == 0) {
            ans = root->val;
            return;
        }
        kthSmallestHelper(root->right, k, ans);
    }

    int kthSmallest(TreeNode<int>* root, int k) {
        int ans = 0;
        kthSmallestHelper(root, k, ans);
        return ans;
    }

    vector<vector<int>> cases = {
        { 3, 1, 4, INT_MIN, 2 },
        { 5, 3, 6, 2, 4, INT_MIN, INT_MIN, 1 },
    };

    vector<int> K = { 1, 3 };
    vector<int> expected = { 1, 3 };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = kthSmallest(tree, K[i]);
            bool passed = solution == expected[i];
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            printf("expected:\t%d\n", (int)expected[i]);
            
            printf("solution:\t%d\n", solution);
            printf("\n");
        }
    }
    
}

#endif /* KthSmallestElementInABST_hpp */
