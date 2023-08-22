//
//  AverageOfLevelsInBinaryTree.hpp
//  LeetCode
//
//  Created by Salvatore on 22/8/23.
//

#ifndef AverageOfLevelsInBinaryTree_hpp
#define AverageOfLevelsInBinaryTree_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace AverageOfLevelsInBinaryTree {

    void averageOfLevels ( TreeNode<int>* root, vector<double> &averages, vector<int> &nodes, int level ) {
        if(root == nullptr) return;

        int nextLevel = level + 1;

        if(averages.size() < nextLevel) {
            averages.resize(nextLevel);
            nodes.resize(nextLevel);
        }

        averages[level] += root->val;
        ++nodes[level];

        averageOfLevels (root->left, averages, nodes, nextLevel);
        averageOfLevels (root->right, averages, nodes, nextLevel);
    }

    vector<double> averageOfLevels(TreeNode<int>* root) {
        vector<double> averages;
        vector<int> nodes;

        averageOfLevels (root, averages, nodes, 0);

        for(int i = 0; i < nodes.size(); ++i)
            averages[i] /= nodes[i];

        return averages;
    }

    vector<vector<int>> cases = {
        { 3, 9, 20, INT_MIN, INT_MIN, 15, 7 },
        { 3, 9, 20, 15, 7 },
    };

    vector<vector<double>> expected = {
        { 3.00000, 14.50000, 11.00000 },
        { 3.00000, 14.50000, 11.00000 },
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            
            auto solution = averageOfLevels(tree);
            
            bool passed = compareArrays(solution, expected[i]);
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\t\tp ");
            printArray(cases[i]);
            printf("expected:\t");
            printArray(expected[i]);
            printf("solution:\t");
            printArray(solution);
            printf("\n");
        }
    }

}

#endif /* AverageOfLevelsInBinaryTree_hpp */
