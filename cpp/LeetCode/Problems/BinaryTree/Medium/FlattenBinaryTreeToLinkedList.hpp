//
//  FlattenBinaryTreeToLinkedList.hpp
//  LeetCode
//
//  Created by Salvatore on 18/9/23.
//

#ifndef FlattenBinaryTreeToLinkedList_hpp
#define FlattenBinaryTreeToLinkedList_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace FlattenBinaryTreeToLinkedList {

    /** Version used for the blog */
    void flattenHelper(TreeNode<int>* root, vector<short> &preorder) {
        if (root == NULL) return;
        preorder.push_back((short)root->val);
        flattenHelper(root->left, preorder);
        flattenHelper(root->right, preorder);
    }

    void flatten(TreeNode<int>* root) {
        vector<short> preorder;
        flattenHelper(root, preorder);

        TreeNode<int> *&head = root;
        for(int i = 1; i < preorder.size(); ++i){

            if(head->right == NULL) {
                head->right = new TreeNode<int>(preorder[i]);
            }else {
                head->right->val = preorder[i];
            }

            head->left = NULL;
            head = head->right;
        }
    }


    /** Alternative version V2 */
    void flattenV2(TreeNode<int>* root) {
        if (root == NULL) return;

        // Recursively flatten the left and right subtrees
        flatten(root->left);
        flatten(root->right);

        // Save the right subtree
        TreeNode<int>* rightSubtree = root->right;

        // Move the left subtree to the right
        root->right = root->left;
        root->left = NULL;

        // Find the rightmost node of the flattened left subtree
        TreeNode<int>* rightmost = root;
        while (rightmost->right != NULL) {
            rightmost = rightmost->right;
        }

        rightmost->right = rightSubtree;
    }

    /** Alternative version V3 */
    void flattenV3(TreeNode<int>* root) {
        if (root == NULL) return;

        TreeNode<int> *cur = root;
        TreeNode<int> *prev;

        while(cur != NULL){
            if ( cur->left != NULL ) {
                prev = cur->left;
                
                while (prev->right != NULL)
                    prev = prev->right;
                
                prev->right = cur->right;
                cur->right = cur->left;
            }
            cur->left = NULL;
            cur = cur->right;
        }
            
    }


    vector<vector<int>> cases = {
        { 1, 2, 5, 3, 4, INT_MIN, 6 },
        {},
        {0}
    };

    vector<vector<int>> expected = {
        {   1,
            INT_MIN, 2,
            INT_MIN, INT_MIN, INT_MIN, 3,
            INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 4,
            INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 5,
            INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 6 },
        {},
        {0}
        
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            flatten(tree);
            
            auto solution = treeToArray(tree);
            
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

#endif /* FlattenBinaryTreeToLinkedList_hpp */
