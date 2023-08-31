//
//  CousinsInBinaryTree.hpp
//  LeetCode
//
//  Created by Salvatore on 31/8/23.
//

#ifndef CousinsInBinaryTree_hpp
#define CousinsInBinaryTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace CousinsInBinaryTree {

    struct Answer {
        int x, y;
        int parentX, parentY;

        bool areCousins() {
            return x == y && parentX != parentY;
        }
    };

    void isCousins( TreeNode<int>* root, Answer &answer, int x, int y, int floor, int parent) {
        if(root == nullptr) return;

        if(root->val == x) {
            answer.x = floor;
            answer.parentX = parent;
        }

        if(root->val == y) {
            answer.y = floor;
            answer.parentY = parent;
        }

        isCousins(root->left, answer, x, y, floor + 1, root->val );
        isCousins(root->right, answer, x, y, floor + 1, root->val );
    }

    bool isCousins(TreeNode<int>* root, int x, int y) {
        Answer answer;
        isCousins(root, answer, x, y, 1, root->val);
        return answer.areCousins();
    }

    vector<vector<int>> cases = {
        { 1, 2, 3, 4 },
        { 1, 2, 3, INT_MIN, 4, INT_MIN, 5 },
        { 1, 2, 3, INT_MIN, 4 }
    };

    vector<int> X = { 4, 5, 2 };
    vector<int> Y = { 3, 4, 3 };
    vector<bool> expected = { false, true, false };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = isCousins(tree, X[i], Y[i]);
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

#endif /* CousinsInBinaryTree_hpp */
