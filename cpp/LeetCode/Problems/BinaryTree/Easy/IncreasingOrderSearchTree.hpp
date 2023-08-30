//
//  IncreasingOrderSearchTree.hpp
//  LeetCode
//
//  Created by Salvatore on 30/8/23.
//

#ifndef IncreasingOrderSearchTree_hpp
#define IncreasingOrderSearchTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"


namespace IncreasingOrderSearchTree {

    void increasingBST(TreeNode<int>* root, vector<TreeNode<int>*> &vec) {
        if(root == nullptr) return;

        increasingBST(root->left, vec);
        vec.push_back(root);
        increasingBST(root->right, vec);
    }

    TreeNode<int>* increasingBST(TreeNode<int>* root) {
        if(root == nullptr) return root;
        
        vector<TreeNode<int>*> vec;
        increasingBST(root, vec);

        TreeNode<int>* ans = vec.front();
        TreeNode<int>* head = ans;

        ans->left = NULL;
        ans->right = NULL;
        
        for(int i = 1; i < vec.size(); ++i){
            head->right = vec[i];
            head = head->right;
            head->right = NULL;
            head->left = NULL;
        }
        
        return ans;
    }

    vector<vector<int>> cases = {
        { 5, 1, 7 },
        { 1 }
    };

    vector<vector<int>> expected = {
        { 1, INT_MIN, 5, INT_MIN, INT_MIN, INT_MIN, 7 },
        { 1 }
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solutionTree = increasingBST(tree);
            auto solution = treeToArray(solutionTree);
            parseVector(solution);
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

#endif /* IncreasingOrderSearchTree_hpp */
