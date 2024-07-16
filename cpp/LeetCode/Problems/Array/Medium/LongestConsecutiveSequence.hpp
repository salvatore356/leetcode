//
//  LongestConsecutiveSequence.hpp
//  LeetCode
//
//  Created by Salvatore on 16/7/24.
//

#ifndef LongestConsecutiveSequence_hpp
#define LongestConsecutiveSequence_hpp

#include <stdio.h>

namespace LongestConsecutiveSequence {

    int longestConsecutive(vector<int>& nums) {
        if(nums.empty()) return 0;
        sort(nums.begin(), nums.end());

        int consecutives = 1;
        int temp = 1;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) continue;
            
            if (nums[i] != (nums[i - 1] + 1))
                temp = 0;
            ++temp;

            consecutives = max(consecutives, temp);
        }
        return consecutives;
    }

    void test() {
        vector<vector<int>> nums = {
            {100,4,200,1,3,2}, {0,3,7,2,5,8,4,6,0,1}, {}, {1,2,0,1}
        };
        
        vector<int> expected = {4,9,0,3};
        
        for (int i = 0; i < nums.size(); ++i) {
            int result = longestConsecutive(nums[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* LongestConsecutiveSequence_hpp */
