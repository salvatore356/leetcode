//
//  ConstructStringFromBinaryTree.hpp
//  LeetCode
//
//  Created by Salvatore on 18/8/23.
//

#ifndef ConstructStringFromBinaryTree_hpp
#define ConstructStringFromBinaryTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"


namespace ConstructStringFromBinaryTree {

    void buildString(
         TreeNode<int> *root,
         string &str, bool mandatory
     ) {

    if (root == nullptr) {
        if (mandatory) str += "()";
        return;
    }

        str += "(" + to_string(root->val);
        buildString(root->left, str, root->right != nullptr);
        buildString(root->right, str, false);
        str += ")";
    }

    string tree2str(TreeNode<int>* root) {
        string ans = to_string(root->val);
        buildString(root->left, ans, root->right != nullptr);
        buildString(root->right, ans, false);
        return ans;
    }
 
    vector<vector<int>> cases = {
        { 1, 2, 3, 4 },
        { 1, 2, 3, INT_MIN, 4 },
    };

    vector<string> expected = {
        "1(2(4))(3)",
        "1(2()(4))(3)"
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            
            string solution = tree2str(tree);
            
            bool passed = solution == expected[i];
            
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            
            printf("expected:\t%s\n", expected[i].c_str());
            
            printf("solution:\t%s\n", solution.c_str());
            printf("\n");
        }
    }
}

#endif /* ConstructStringFromBinaryTree_hpp */
