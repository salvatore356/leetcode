//
//  ConvertSortedArrayToBinarySearchTree.hpp
//  LeetCode
//
//  Created by Salvatore on 24/5/24.
//

#ifndef ConvertSortedArrayToBinarySearchTree_hpp
#define ConvertSortedArrayToBinarySearchTree_hpp

#include <stdio.h>

namespace ConvertSortedArrayToBinarySearchTree {
    
    TreeNode<int>* helper(vector<int>& nums, int left, int right) {
        if (right < left) return NULL;

        int current = left + (right - left) / 2;

        TreeNode<int> *root = new TreeNode<int>(nums[current]);
        
        root->left = helper(nums, left, current - 1);
        root->right = helper(nums, current + 1, right);
        return root;

    }

    TreeNode<int>* sortedArrayToBST(vector<int>& nums) {
        return helper(nums, 0, (int)nums.size() - 1);
    }

    void test() {
        vector<vector<int>> nums ={{-10,-3,0,5,9}, {1,3}};
        vector<vector<int>> expected ={{0,-10,5,INT_MIN,-3,INT_MIN,9}, {1,INT_MIN,3}};
        
        
        for (int i = 0; i - nums.size(); ++i) {
            TreeNode<int> *result = sortedArrayToBST(nums[i]);
            
            vector<int> v_result = treeToArray(result);
            assert(v_result == expected[i], v_result, expected[i]);
            
        }
    }
}

#endif /* ConvertSortedArrayToBinarySearchTree_hpp */
