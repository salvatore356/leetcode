//
//  MajorityElement.hpp
//  LeetCode
//
//  Created by Salvatore on 3/4/24.
//

#ifndef MajorityElement_hpp
#define MajorityElement_hpp

#include <stdio.h>

namespace MajorityElement {
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> count;
        int n = ceil(nums.size() / 2.0);

        for(int i = 0; i < nums.size(); ++i) {
            ++count[nums[i]];
            if(count[nums[i]] >= n) return nums[i];
        }

        return -1;
    }

    void test() {
        vector<vector<int>> cases = {
            {3,2,3},
            {2,2,1,1,1,2,2}
        };
        
        vector<int> expected = {
            3, 2
        };
        
        for(int i = 0; i < cases.size(); ++i) {
            int result = majorityElement(cases[i]);
            
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* MajorityElement_hpp */
