//
//  SingleNumber.hpp
//  LeetCode
//
//  Created by Salvatore on 16/5/24.
//

#ifndef SingleNumber_hpp
#define SingleNumber_hpp

#include <stdio.h>

namespace SingleNumber {

    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int &n : nums) {
            ans ^= n;
        }
        return ans;
    }

    void test() {
        vector<vector<int>> nums = {
            {2,2,1}, {4,1,2,1,2}, {1}
        };
        
        vector<int> expected = {1, 4, 1};
        
        for (int i = 0; i < nums.size(); ++i) {
            int result = singleNumber(nums[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }

}

#endif /* SingleNumber_hpp */
