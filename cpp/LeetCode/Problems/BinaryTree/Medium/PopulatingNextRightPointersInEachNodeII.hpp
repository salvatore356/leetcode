//
//  PopulatingNextRightPointersInEachNodeII.hpp
//  LeetCode
//
//  Created by Salvatore on 19/9/23.
//

#ifndef PopulatingNextRightPointersInEachNodeII_hpp
#define PopulatingNextRightPointersInEachNodeII_hpp

#include <stdio.h>

namespace PopulatingNextRightPointersInEachNodeII{

    void connectHelper(TreeNode<int> *&root, int currentLevel, vector<vector<TreeNode<int>*>> &levels) {
        if (root == NULL) return;

        int nextLevel = currentLevel + 1;
        if(levels.size() < nextLevel) levels.resize(nextLevel);

        if( levels[currentLevel].size() > 0)
            levels[currentLevel].back()->next = root;

        levels[currentLevel].push_back(root);

        connectHelper(root->left, nextLevel, levels);
        connectHelper(root->right, nextLevel, levels);

    }

    TreeNode<int>* connect(TreeNode<int>* root) {
        vector<vector<TreeNode<int>*>> levels;
        connectHelper(root, 0, levels);
        return root;
    }

    vector<vector<int>> cases = {
        { 1, 2, 3, 4, 5, 6, 7 },
        {},
    };

    vector<vector<vector<int>>> expected = {
        {
            { 1, INT_MIN },
            { 2, 3, INT_MIN },
            { 4, 5, 6, 7, INT_MIN },
        },
        {},
    };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            connect(tree);
            
            vector<vector<int>> solution = treeToArrayLevels(tree);
            
            bool passed = solution.size() == expected[i].size();
            
            if(passed)
            for(int k = 0; k < solution.size(); ++k){
                solution[k].push_back(INT_MIN);
                passed = passed && compareArrays(solution[k], expected[i][k]);
            }
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            printf("expected:\n");
            for(int k = 0; k < expected[i].size(); ++k) {
                printf("\t");
                printArray(expected[i][k]);
            }
            
            printf("solution:\n");
            for(int k = 0; k < solution.size(); ++k) {
                printf("\t");
                printArray(solution[k]);
            }
            
            printf("\n");
        }
    }


}

#endif /* PopulatingNextRightPointersInEachNodeII_hpp */
