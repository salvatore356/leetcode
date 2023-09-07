//
//  UniqueBinarySearchTrees.hpp
//  LeetCode
//
//  Created by Salvatore on 6/9/23.
//

#ifndef UniqueBinarySearchTrees_hpp
#define UniqueBinarySearchTrees_hpp

#include <stdio.h>

#include "../../../Utils/Utils.hpp"

namespace UniqueBinarySearchTrees {
    
    int numTrees(int n) {
        int result = 1;

        for(int i = 0; i < n; ++i)
            result *= (2.0 * (2.0 * i + 1)) / (i + 2 );

        return result;
    }

    vector<int> cases = { 3, 1 };
    vector<int> expected = { 5, 1 };

    inline void test() {
        
        for(int i = 0; i < cases.size(); ++i) {
            //TreeNode<int> *tree =  loadTree(cases[i]);
            auto solution = numTrees(cases[i]);
            bool passed = solution == expected[i];
                
            
            printf("Case %d passed %d\n", (i + 1), passed );
            printf("input:\n");
            printf("\tp:\t%d\n", cases[i]);
            
            printf("expected:\t%d\n", expected[i]);
            
            printf("solution:\t%d\n", solution);
            printf("\n");
        }
    }
    

}

#endif /* UniqueBinarySearchTrees_hpp */
