//
//  ClimbingStairs.hpp
//  LeetCode
//
//  Created by Salvatore on 13/5/24.
//

#ifndef ClimbingStairs_hpp
#define ClimbingStairs_hpp

#include <stdio.h>

namespace ClimbingStairs {

    int climbStairs(int n) {

        if (n < 2) return 1;

        int prev = 1;
        int current = 2;
        int temp;

        for (int i = 3; i <= n; ++i) {
            temp = current;
            current += prev;
            prev = temp;
        }

        return current;
    }

    void test() {
        vector<int> n = {2, 3, 4, 5, 6 };
        vector<int> expected = {2, 3, 5, 8, 13};
        
        for (int i = 0; i < n.size(); ++i) {
            int result = climbStairs(n[i]) ;
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* ClimbingStairs_hpp */
