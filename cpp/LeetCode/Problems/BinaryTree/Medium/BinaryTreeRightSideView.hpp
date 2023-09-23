//
//  BinaryTreeRightSideView.hpp
//  LeetCode
//
//  Created by Salvatore on 23/9/23.
//

#ifndef BinaryTreeRightSideView_hpp
#define BinaryTreeRightSideView_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace BinaryTreeRightSideView {

    void rightSideViewHelper( TreeNode<int>*& root, vector<int> &rightmost, int level) {
        if (root == NULL) return;
        int nextLevel = level + 1;
        if(rightmost.size() < nextLevel) rightmost.resize(nextLevel);

        rightmost[level] = root->val;
        rightSideViewHelper( root->left,  rightmost, nextLevel );
        rightSideViewHelper( root->right,  rightmost, nextLevel );

    }
    vector<int> rightSideView(TreeNode<int>* root) {
        vector<int> rightmost;
        rightSideViewHelper( root, rightmost, 0);
        return rightmost;
    }

    vector<vector<int>> cases = {
        { 1, 2, 3, INT_MIN, 5, INT_MIN, 4 },
        { 1, INT_MIN, 3},
        {}
    };

    vector<vector<int>> expected = {
        { 1, 3, 4 },
        { 1, 3 },
        {}
        
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = rightSideView(tree);
             
            bool passed = compareArrays(solution, expected[i]);
            
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            printf("expected:\t");
            printArray(expected[i]);
            
            printf("solution:\t");
            printArray(solution);
            
            printf("\n");
        }
    }
}

#endif /* BinaryTreeRightSideView_hpp */
