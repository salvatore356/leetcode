//
//  FindACorrespondingNodeOfABinaryTreeInACloneOfThatTree.hpp
//  LeetCode
//
//  Created by Salvatore on 1/9/23.
//

#ifndef FindACorrespondingNodeOfABinaryTreeInACloneOfThatTree_hpp
#define FindACorrespondingNodeOfABinaryTreeInACloneOfThatTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace FindACorrespondingNodeOfABinaryTreeInACloneOfThatTree {
    
    void getTargetCopy(TreeNode<int>* root, TreeNode<int> *&ans, int target) {
        if (root == nullptr) return;

        if(root->val == target){
            ans = root;
            return;
        } else {
            getTargetCopy(root->left, ans, target);
            getTargetCopy(root->right, ans, target);
        }
    }

    TreeNode<int>* getTargetCopy(TreeNode<int>* original, TreeNode<int>* cloned, TreeNode<int>* target) {
        TreeNode<int> *ans;
        getTargetCopy(cloned, ans, target->val);
        return ans;
    }

    vector<vector<int>> originals = {
        { 7, 4, 3, INT_MIN, INT_MIN, 6, 19 },
        { 7 },
        {   8, //TODO improve the tree initialization method
            INT_MIN, 6,
            INT_MIN, INT_MIN, INT_MIN, 5,
            INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 4,
            INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 3,
            INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 2,
            INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, INT_MIN, 1
            
        },
    };
    
    vector<vector<int>> targets = {
        { 3 },
        { 7 },
        { 4 }
    };
    
    vector<int> expected = { 3 , 7 , 4 };

    inline void test() {
        
        for(int i = 0; i < originals.size(); ++i) {
            TreeNode<int> *original =  loadTree(originals[i]);
            TreeNode<int> *cloned =  original;
            TreeNode<int> *target =  loadTree(targets[i]);
            
            auto solution = getTargetCopy(original, cloned, target);
            //auto solution = treeToArray(solutionTree);
            bool passed = solution->val == expected[i];
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(originals[i]);
            printf("expected:\t%d\n", expected[i]);
            printf("solution:\t%d\n", solution->val);
            //printArray(solution);
            printf("\n");
        }
    }

}

#endif /* FindACorrespondingNodeOfABinaryTreeInACloneOfThatTree_hpp */
