//
//  TwoSum.hpp
//  LeetCode
//
//  Created by Salvatore on 2/5/24.
//

#ifndef TwoSum_hpp
#define TwoSum_hpp

#include <stdio.h>

namespace TwoSum {
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> sums;

        int index;
        for(int i = 0; i < nums.size(); ++i) {

            index = target - nums[i];

            if(sums.find(index) == sums.end())
                sums[nums[i]] = i;
            else return {sums[index], i};
        }

        return {-1, -1};
    }

    void test() {
        vector<vector<int>> nums = {
            {3,2,4},
            {2,7,11,15},
            {3,3}
            
        };
        vector<int> target = {6, 9, 6};
        vector<vector<int>> expected = {
            {1,2},
            {0, 1},
            {0, 1}
        };
        
        for(int i = 0; i < nums.size(); ++i) {
            auto result = twoSum(nums[i], target[i]);
            
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* TwoSum_hpp */
