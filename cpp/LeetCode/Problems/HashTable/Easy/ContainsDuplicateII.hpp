//
//  ContainsDuplicateII.hpp
//  LeetCode
//
//  Created by Salvatore on 3/5/24.
//

#ifndef ContainsDuplicateII_hpp
#define ContainsDuplicateII_hpp

#include <stdio.h>

namespace ContainsDuplicateII {
    
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, int> lastIndex;
        for (int i = 0; i < nums.size(); ++i){
            if (lastIndex.find(nums[i]) != lastIndex.end()) {
                if (abs(i-lastIndex[nums[i]]) <= k ) return true;
            }
            lastIndex[nums[i]] = i;
        }
        return false;
    }

    void test() {
        vector<vector<int>> nums = {
            {1,2,3,1},
            {1,0,1,1},
            {1,2,3,1,2,3}
        };
        vector<int> k = {3, 1, 2};
        vector<bool> expected = {true, true, false};
        
        for (int i = 0; i < nums.size(); ++i) {
            bool result = containsNearbyDuplicate(nums[i], k[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* ContainsDuplicateII_hpp */
