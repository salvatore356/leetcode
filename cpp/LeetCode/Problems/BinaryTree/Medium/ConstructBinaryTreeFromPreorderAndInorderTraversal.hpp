//
//  ConstructBinaryTreeFromPreorderAndInorderTraversal.hpp
//  LeetCode
//
//  Created by Salvatore on 11/9/23.
//

#ifndef ConstructBinaryTreeFromPreorderAndInorderTraversal_hpp
#define ConstructBinaryTreeFromPreorderAndInorderTraversal_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace ConstructBinaryTreeFromPreorderAndInorderTraversal {

    TreeNode<int>* buildTree(
        vector<int>& preorder,
        vector<int>& inorder,
        int& preorderIndex,
        int left, int right,
        unordered_map<int, int>& inorderIndexMap
    ) {

        if (left > right) return NULL;
        
        int rootValue = preorder[preorderIndex];
        TreeNode<int>* root = new TreeNode<int>(rootValue);
        int inorderIndex = inorderIndexMap[rootValue];
        
        ++preorderIndex;
        
        root->left = buildTree(
            preorder,
            inorder,
            preorderIndex,
            left, inorderIndex - 1,
            inorderIndexMap
        );

        root->right = buildTree(
            preorder,
            inorder,
            preorderIndex,
            inorderIndex + 1, right,
            inorderIndexMap
        );
        
        return root;
    }

    TreeNode<int>* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorderIndexMap;
        
        for (int i = 0; i < inorder.size(); ++i)
            inorderIndexMap[inorder[i]] = i;
        
        int preorderIndex = 0;
        
        return buildTree(
            preorder, inorder,
            preorderIndex,
            0, (int)inorder.size() - 1,
            inorderIndexMap
        );
    }

    vector<vector<int>> preorder = {
        { 3, 9, 20, 15, 7 },
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
        
        for(int i = 0; i < preorder.size(); ++i) {
            
            auto solutionTree = buildTree(preorder[i], inorder[i]);
            auto solution = treeToArray(solutionTree);
            parseVector(solution);
            
            bool passed = compareArrays(solution, expected[i]);
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(preorder[i]);
            
            printf("expected:\t");
            printArray(expected[i]);
            
            printf("solution:\t");
            printArray(solution);
            printf("\n");
        }
    }

    

}

#endif /* ConstructBinaryTreeFromPreorderAndInorderTraversal_hpp */
