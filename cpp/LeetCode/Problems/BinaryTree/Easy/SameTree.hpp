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

    bool isSameTree(TreeNode<int>* p, TreeNode<int>* q) {
        return inorder(p, q);
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
            bool solution = isSameTree(p, q);
            
            bool passed = solution == expected[i];
            
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(treesP[i]);
            printf("\tq:\t");
            printArray(treesQ[i]);
            printf("expected:\t%d\n", (int)expected[i]);
            
            printf("solution:\t%d\n", solution);
            printf("\n");
        }
    }
}

#endif /* SameTree_hpp */
