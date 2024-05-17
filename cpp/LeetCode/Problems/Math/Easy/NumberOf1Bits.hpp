//
//  NumberOf1Bits.hpp
//  LeetCode
//
//  Created by Salvatore on 17/5/24.
//

#ifndef NumberOf1Bits_hpp
#define NumberOf1Bits_hpp

#include <stdio.h>

namespace NumberOf1Bits {
    int hammingWeight(int n) {
        int ans = 0;
        while ( n > 0 ) {
            ans += (n % 2) == 1;
            n /= 2;
        }
        return ans;
    }
    void test() {
        vector<int> n = {11, 128, 2147483645};
        vector<int> expected = {3, 1, 30};
        
        for (int i = 0; i < n.size(); ++i) {
            int result = hammingWeight(n[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* NumberOf1Bits_hpp */
