//
//  MinimumSizeSubarraySum.hpp
//  LeetCode
//
//  Created by Salvatore on 25/6/24.
//

#ifndef MinimumSizeSubarraySum_hpp
#define MinimumSizeSubarraySum_hpp

#include <stdio.h>

namespace MinimumSizeSubarraySum {
    
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = (int)nums.size();
        int minLen = n + 1;

        int idx0 = 0, idx1 = 0, sum = 0;
        while (idx1 < n) {
            
            while (sum < target && idx1 < n)
                sum += nums[idx1++];

            while (sum >= target && idx0 < n) {
                
                minLen = min(idx1 - idx0, minLen);

                sum -= nums[idx0++];
            }
        }

        return minLen == n + 1 ? 0 : minLen;
    }
    
    void test(){
        vector<vector<int>> nums = {{2,3,1,2,4,3}, {1,4,4}, {1,1,1,1,1,1,1,1}};
        vector<int> target = {7, 4, 11};
        vector<int> expected = {2, 1, 0};
        
        for (int i = 0; i < nums.size(); ++i) {
            int result = minSubArrayLen(target[i], nums[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* MinimumSizeSubarraySum_hpp */
