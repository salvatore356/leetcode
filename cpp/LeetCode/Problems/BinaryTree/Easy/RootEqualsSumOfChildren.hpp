//
//  RootEqualsSumOfChildren.hpp
//  LeetCode
//
//  Created by Salvatore on 1/9/23.
//

#ifndef RootEqualsSumOfChildren_hpp
#define RootEqualsSumOfChildren_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace RootEqualsSumOfChildren {
    
    bool checkTree(TreeNode<int>* root) {
        return root->val == (root->left->val + root->right->val);
    }

    vector<vector<int>> cases = {
        { 10, 4, 6 },
        { 5,3,1 },
    };

    vector<bool> expected = { true, false };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = checkTree(tree);
            bool passed = solution == expected[i];
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t");
            printArray(cases[i]);
            printf("expected:\t%d\n", (int)expected[i]);
            
            printf("solution:\t%d\n", solution);
            printf("\n");
        }
    }
}

#endif /* RootEqualsSumOfChildren_hpp */
