//
//  SecondMinimumNodeInABinaryTree.hpp
//  LeetCode
//
//  Created by Salvatore on 24/8/23.
//

#ifndef SecondMinimumNodeInABinaryTree_hpp
#define SecondMinimumNodeInABinaryTree_hpp

#include <stdio.h>
#include <map>

#include "../../../Utils/Utils.hpp"

namespace SecondMinimumNodeInABinaryTree {

    void findSecondMinimumValue(TreeNode<int>* root, map<unsigned, unsigned> &ordered) {
        if (root == nullptr) return;

        ordered[root->val] = 1;
        findSecondMinimumValue(root->left, ordered);
        findSecondMinimumValue(root->right, ordered);
    }
    
    int findSecondMinimumValue(TreeNode<int>* root) {
        map<unsigned, unsigned> ordered;
        findSecondMinimumValue(root, ordered);

        if (ordered.size() < 2) return -1;
        auto it = ordered.begin();
        ++it;
        return it->first;
    }

    vector<vector<int>> cases = {
        { 2, 2, 5, INT_MIN, INT_MIN, 5, 7 },
        { 2, 2, 2 },
    };

    vector<int> expected = {
        5,
        -1
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            int solution = findSecondMinimumValue(tree);
            
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

#endif /* SecondMinimumNodeInABinaryTree_hpp */
