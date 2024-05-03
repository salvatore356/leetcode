//
//  SummaryRanges.hpp
//  LeetCode
//
//  Created by Salvatore on 3/5/24.
//

#ifndef SummaryRanges_hpp
#define SummaryRanges_hpp

#include <stdio.h>

namespace SummaryRanges {
    
    vector<string> summaryRanges(vector<int>& nums) {
        if(nums.size() == 0) return {};
        vector<string> ans;

        int lastIndex = 0;
        for (int i = 0; i < nums.size() - 1; ++i) {
            long n1 = nums[i + 1], n2 = nums[i];
            if (n1 - n2 == 1) continue;
            string key = to_string(nums[lastIndex]);
            if(lastIndex != i) key += "->" + to_string(nums[i]);
            lastIndex = i + 1;
            ans.push_back(key);
        }

        if (lastIndex == nums.size()-1)
            ans.push_back(to_string(nums.back()));
        else ans.push_back( to_string(nums[lastIndex]) +"->" + to_string(nums.back()));

        return ans;
    }

    void test() {
        vector<vector<int>> nums = {
            {0, 1, 2, 4, 5, 7},
            {0, 2, 3, 4, 6, 8, 9}
        };
        
        vector<vector<string>> expected = {
            {"0->2","4->5","7"},
            {"0","2->4","6","8->9"}
        };
        
        for (int i = 0; i < nums.size(); ++i) {
            auto result = summaryRanges(nums[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* SummaryRanges_hpp */
