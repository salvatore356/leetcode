//
//  SameTree.hpp
//  LeetCode
//
//  Created by Salvatore on 10/8/23.
//

#ifndef SameTree_hpp
#define SameTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace SameTree {

    bool inorder(TreeNode<int>* p, TreeNode<int>* q){
        if(p == nullptr && q == nullptr) return true;
        else if(p == nullptr && q != nullptr) return false;
        else if(p != nullptr && q == nullptr) return false;
        else if(p->val != q->val) return false;

        return inorder(p->left, q->left) && inorder(p->right, q->right);
    }

    bool isSameTreeSlower(TreeNode<int>* p, TreeNode<int>* q) {
        return inorder(p, q);
    }

    bool isSameTree(TreeNode<int>* p, TreeNode<int>* q){
        if(!p && !q) return true;
        if (!p || !q) return false;

        return q->val == p->val &&
            isSameTree(p->right, q->right) &&
            isSameTree(p->left, q->left);
    }

    vector<vector<int>> treesP = {
        {1, 2, 3},
        {1, 2},
        {1, 2, 1}
    };

    vector<vector<int>> treesQ = {
        {1, 2, 3},
        {1, INT_MIN, 2},
        {1, 1, 2}
    };

    vector<bool> expected = {
        true,
        false,
        false,
    };

    inline void test() {
        
        for(int i = 0; i < treesP.size(); ++i) {
            TreeNode<int> *p =  loadTree(treesP[i]);
            TreeNode<int> *q =  loadTree(treesQ[i]);
            bool result = isSameTree(p, q);
            
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* SameTree_hpp */
