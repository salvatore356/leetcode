//
//  MaximumDepthOfBinaryTree.hpp
//  LeetCode
//
//  Created by Salvatore on 9/5/24.
//

#ifndef MaximumDepthOfBinaryTree_hpp
#define MaximumDepthOfBinaryTree_hpp

#include <stdio.h>

namespace MaximumDepthOfBinaryTree {
    
    int maxDepth(TreeNode<int>* root, int currentDepth) {
        if (root == NULL) return currentDepth;

        ++currentDepth;
        int left = maxDepth(root->left, currentDepth);
        int right = maxDepth(root->right, currentDepth);
        
        return max(left, right);

    }

    int maxDepth(TreeNode<int>* root) {
        int currentDepth = 0;
        return maxDepth(root, currentDepth);
    }

    void test() {
        vector<vector<int>> root = {
            {3,9,20,INT_MIN,INT_MIN,15,7},
            {1,INT_MIN,2}
        };
        
        vector<int> expected = {3,2};
        
        for (int i = 0; i < root.size(); ++i) {
            TreeNode<int> *t = loadTree(root[i]);
            int result = maxDepth(t);
            
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* MaximumDepthOfBinaryTree_hpp */
