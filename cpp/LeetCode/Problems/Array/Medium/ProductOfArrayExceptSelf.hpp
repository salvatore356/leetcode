//
//  ProductOfArrayExceptSelf.hpp
//  LeetCode
//
//  Created by Salvatore on 10/6/24.
//

#ifndef ProductOfArrayExceptSelf_hpp
#define ProductOfArrayExceptSelf_hpp

#include <stdio.h>

namespace ProductOfArrayExceptSelf {

    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix(nums.size()), sufix(nums.size());
        int n = (int)nums.size() - 1;
        prefix[0] = nums.front();
        sufix[n] = nums.back();

        for (int i = 1; i < n; ++i) {
            prefix[i] = nums[i] * prefix[i - 1];
            int index = n - i;
            sufix[index] = nums[index] *  sufix[index + 1];
        }
        
        nums[0] = sufix[1];
        nums[n] = prefix[n-1];
        for (int i = 1; i < n; ++i)
            nums[i] = prefix[i - 1] * sufix[i + 1];
        return nums;
    }

    void test() {
        vector<vector<int>> nums = {
            {1,2,3,4}, {-1,1,0,-3,3}
        };
        
        vector<vector<int>> expected = {
            {24,12,8,6}, {0,0,9,0,0}
        };
        
        for (int i = 0; i < nums.size(); ++i) {
            auto result = productExceptSelf(nums[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* ProductOfArrayExceptSelf_hpp */
