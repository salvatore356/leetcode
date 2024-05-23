//
//  SearchInsertPosition.hpp
//  LeetCode
//
//  Created by Salvatore on 23/5/24.
//

#ifndef SearchInsertPosition_hpp
#define SearchInsertPosition_hpp

#include <stdio.h>

namespace SearchInsertPosition {
    
    int searchInsert(vector<int>& nums, int target) {
        int i = 0;

        for (; i < nums.size(); ++i){
            if (nums[i] >= target)
                return i;
        }
        
        return i;
    }

    void test() {
        vector<vector<int>> nums = {{1,3,5,6}, {1,3,5,6}, {1,3,5,6}};
        vector<int> target = {5, 2, 7};
        vector<int> expected = {2, 1, 4};
        
        for (int i = 0; i < nums.size(); ++i) {
            int result = searchInsert(nums[i], target[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* SearchInsertPosition_hpp */
