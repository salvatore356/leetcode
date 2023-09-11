//
//  ConstructBinaryTreeFromInorderAndPostorderTraversal.hpp
//  LeetCode
//
//  Created by Salvatore on 11/9/23.
//

#ifndef ConstructBinaryTreeFromInorderAndPostorderTraversal_hpp
#define ConstructBinaryTreeFromInorderAndPostorderTraversal_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace ConstructBinaryTreeFromInorderAndPostorderTraversal {

    TreeNode<int>* buildTree(
        vector<int>& postorder,
        vector<int>& inorder,
        int& postorderIndex,
        int left, int right,
        unordered_map<int, int>& inorderIndexMap
    ) {

        if (left > right) return NULL;
        
        int rootValue = postorder[postorderIndex];
        TreeNode<int>* root = new TreeNode<int>(rootValue);
        int inorderIndex = inorderIndexMap[rootValue];
        
        --postorderIndex;

        root->right = buildTree(
            postorder,
            inorder,
            postorderIndex,
            inorderIndex + 1, right,
            inorderIndexMap
        );
        
        root->left = buildTree(
            postorder,
            inorder,
            postorderIndex,
            left, inorderIndex - 1,
            inorderIndexMap
        );

        return root;
    }

    TreeNode<int>* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorderIndexMap;
        
        for (int i = 0; i < inorder.size(); ++i)
            inorderIndexMap[inorder[i]] = i;
        
        int postorderIndex = (int)inorder.size() - 1;
        
        return buildTree(
            postorder, inorder,
            postorderIndex,
            0, postorderIndex,
            inorderIndexMap
        );
    }

    vector<vector<int>> postorder = {
        { 9, 15, 7, 20, 3 },
        { -1 },
    };

    vector<vector<int>> inorder = {
        { 9, 3, 15, 20, 7 },
        { -1 },
    };

    vector<vector<int>> expected = {
        { 3, 9, 20, INT_MIN, INT_MIN, 15, 7 },
        { -1 },
    };



    inline void test() {
        
        for(int i = 0; i < postorder.size(); ++i) {
            
            auto solutionTree = buildTree(inorder[i], postorder[i]);
            auto solution = treeToArray(solutionTree);
            parseVector(solution);
            
            bool passed = compareArrays(solution, expected[i]);
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(postorder[i]);
            
            printf("expected:\t");
            printArray(expected[i]);
            
            printf("solution:\t");
            printArray(solution);
            printf("\n");
        }
    }

}

#endif /* ConstructBinaryTreeFromInorderAndPostorderTraversal_hpp */
