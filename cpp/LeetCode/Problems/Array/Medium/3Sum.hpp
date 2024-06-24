//
//  3Sum.hpp
//  LeetCode
//
//  Created by Salvatore on 24/6/24.
//

#ifndef _Sum_hpp
#define _Sum_hpp

#include <stdio.h>

namespace _3Sum {

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        int left, right, sum;

        for (int i = 0; i < nums.size() - 2; ++i) {
            
            if (i > 0 && nums[i] == nums[i- 1]) continue;
            
            left = i + 1;
            right = (int)nums.size() - 1;
            
            while (left < right) {
                sum = nums[left] + nums[right] + nums[i];
                
                if (sum == 0) {
                    ans.push_back({nums[i], nums[left], nums[right]});
                    ++left; --right;
                    while (left < right && nums[left] == nums[left - 1]) ++left;
                    while (left < right && nums[right] == nums[right + 1]) --right;
                }
                
                else if (sum < 0) ++left;
                else --right;
            }
        }
        
        return ans;
    }

    void test() {
        vector<vector<int>> nums = {{-1,0,1,2,-1,-4}, {0,1,1}, {0,0,0}, {0,0,0,0}};
        vector<vector<vector<int>>> expected = {
            {{-1,-1,2},{-1,0,1}}, {}, {{0,0,0}}, {{0,0,0}}
        };
        
        for (int i = 0; i < nums.size(); ++i) {
            auto result = threeSum(nums[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* _Sum_hpp */
