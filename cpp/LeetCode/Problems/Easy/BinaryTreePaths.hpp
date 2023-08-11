//
//  BinaryTreePaths.hpp
//  LeetCode
//
//  Created by Salvatore on 11/8/23.
//

#ifndef BinaryTreePaths_hpp
#define BinaryTreePaths_hpp

#include <stdio.h>

#include "../../Utils/Utils.hpp"

namespace BinaryTreePaths {

    void generatePaths(TreeNode<int>* node, string current, vector<string> &arr) {
        if(node == nullptr) return;

        if(current.empty()) current += to_string(node->val);
        else current += "->"+to_string(node->val);

        if(node->left == nullptr && node->right == nullptr)
        arr.push_back(current);

        TreeNode<int> *left = node->left;
        TreeNode<int> *right = node->right;
        generatePaths(left, current, arr);
        generatePaths(right, current, arr);
    }

    vector<string> binaryTreePaths(TreeNode<int>* root) {
        vector<string> ans;

        if(root == nullptr) return ans;
        string currentPath;

        vector<string> leftPath, rightPath;
        generatePaths(root, currentPath, ans);

        return ans;
    }

    vector<vector<int>> cases = {
        {1, 2, 3, INT_MIN, 5},
        {1},
    };

    vector<vector<string>> expected = {
        {"1->2->5", "1->3"},
        {"1"},
    };

    inline void test() {
        vector<int> t = {};
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            
            auto solution = binaryTreePaths(tree);
            
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

#endif /* BinaryTreePaths_hpp */
