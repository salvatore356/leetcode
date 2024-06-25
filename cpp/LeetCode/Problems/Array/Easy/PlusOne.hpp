//
//  PlusOne.hpp
//  LeetCode
//
//  Created by Salvatore on 14/5/24.
//

#ifndef PlusOne_hpp
#define PlusOne_hpp

#include <stdio.h>

namespace PlusOne {
    vector<int> plusOne(vector<int>& digits) {
        
        int temp = 1;
        for ( int i = (int)digits.size() - 1; i >= 0; --i) {
            digits[i] += temp;
            temp = digits[i] / 10;
            if (temp == 0) break;
            digits[i] = digits[i] % 10;
        }
        if (temp > 0) digits.insert(digits.begin(), temp);
        return digits;
    }

    void test() {
        vector<vector<int>> digits = {
            {1,2,3}, {4,3,2,1}, {9}
        };
        
        vector<vector<int>> expected = {
            {1,2,4}, {4,3,2,2}, {1,0}
        };
        
        for (int i = 0; i < digits.size(); ++i) {
            auto result = plusOne(digits[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* PlusOne_hpp */
