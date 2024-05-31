//
//  RemoveDuplicatesFromSortedArrayII.hpp
//  LeetCode
//
//  Created by Salvatore on 31/5/24.
//

#ifndef RemoveDuplicatesFromSortedArrayII_hpp
#define RemoveDuplicatesFromSortedArrayII_hpp

#include <stdio.h>

namespace RemoveDuplicatesFromSortedArrayII {
    int removeDuplicates(vector<int>& nums) {
        int index = 1;
        int count = 1;

        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i - 1] != nums[i]) {
                count = 1;
                nums[index++] = nums[i];
            } else if (count < 2) {
                ++count;
                nums[index++] = nums[i];
            }
        }
        return index;
    }

    void test() {
        vector<vector<int>> nums = {
            {1,1,1,2,2,3}, 
            {0,0,1,1,1,1,2,3,3},
            {1,1,1,2,2,2,3,3},
            {1,1,1,1},
            {-3,-1,-1,0,0,0,0,0,2}
        };
        
        vector<vector<int>> expected = {
            {1,1,2,2,3},
            {0,0,1,1,2,3,3}, 
            {1,1,2,2,3,3},
            {1,1},
            {-3,-1,-1,0,0,2}
        };
        
        for (int i = 0; i < nums.size(); ++i) {
            int k = removeDuplicates(nums[i]);
            assert(
                compareArrays(nums[i], expected[i], k), nums[i], expected[i]
            );
            
        }
    }

}

#endif /* RemoveDuplicatesFromSortedArrayII_hpp */
