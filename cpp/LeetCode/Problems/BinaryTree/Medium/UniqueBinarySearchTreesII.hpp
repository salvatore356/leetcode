//
//  UniqueBinarySearchTreesII.hpp
//  LeetCode
//
//  Created by Salvatore on 5/9/23.
//

#ifndef UniqueBinarySearchTreesII_hpp
#define UniqueBinarySearchTreesII_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace UniqueBinarySearchTreesII {

    vector<TreeNode<int>*> createTrees(int start, int end) {
        
        if (start > end) return { NULL };
        else if (start == end) return { new TreeNode<int>(start) };
        
        vector<TreeNode<int>*> result;

        for (int i = start; i <= end; ++i) {
        
            vector<TreeNode<int>*> leftSubtrees = createTrees(start, i - 1);
            vector<TreeNode<int>*> rightSubtrees = createTrees(i + 1, end);

            for (TreeNode<int>* &leftTree : leftSubtrees) {
                for (TreeNode<int>* &rightTree : rightSubtrees) {
                    TreeNode<int>* root = new TreeNode<int>(i);

                    root->left = leftTree;
                    root->right = rightTree;
                    
                    result.push_back(root);
                }
            }
        }

        return result;
    }

    vector<TreeNode<int>*> generateTrees(int n) {
        return createTrees(1, n);
    }

    vector<int> cases = { 3, 1 };

    vector<vector<vector<int>>> expected = {
        {
            { 1, INT_MIN, 2, INT_MIN, INT_MIN, INT_MIN, 3 },
            { 1, INT_MIN, 3, INT_MIN, INT_MIN, 2 },
            { 2, 1, 3 },
            { 3, 1, INT_MIN, INT_MIN, 2 },
            { 3, 2, INT_MIN, 1 }
        },
        {
            { 1 }
        }
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            //TreeNode<int> *tree =  loadTree(cases[i]);
            vector<TreeNode<int>*> solution = generateTrees(cases[i]);
            
            bool passed = solution.size() == expected[i].size();
            
            if(passed)
                for(int j = 0; j < solution.size(); ++j){
                    auto tempS = treeToArray(solution[j]);
                    parseVector(tempS);
                    passed = passed && compareArrays(tempS, expected[i][j]);
                }
                
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t%d\n", cases[i]);
            
            printf("expected:\n");
            for(int k = 0; k < expected[i].size(); ++k)
                printArray(expected[i][k]);
            
            printf("solution:\n");
            for(int k = 0; k < solution.size(); ++k){
                auto tempS = treeToArray(solution[k]);
                parseVector(tempS);
                printArray(tempS);
            }
            printf("\n");
        }
    }
    
}

#endif /* UniqueBinarySearchTreesII_hpp */
