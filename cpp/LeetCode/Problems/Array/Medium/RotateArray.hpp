//
//  RotateArray.hpp
//  LeetCode
//
//  Created by Salvatore on 3/6/24.
//

#ifndef RotateArray_hpp
#define RotateArray_hpp

#include <stdio.h>

namespace RotateArray {
    void rotate(vector<int>& nums, int k) {
        
        vector<int> temp = nums;
        k %= nums.size();
        for (int i = 0; i < nums.size(); ++i) {
            int index = (k + i) % nums.size();
            nums[index] = temp[i];
        }
    }
    void test(){
        vector<vector<int>> nums = {
            {1,2,3,4,5,6,7},
            {-1,-100,3,99},
            {1,2,3,4,5,6,7}
        };
        vector<vector<int>> expected = {
            {5,6,7,1,2,3,4},
            {3,99,-1,-100},
            {7,1,2,3,4,5,6}
        };
        vector<int> k = {3, 2, 8};
        
        for (int i = 0; i < nums.size(); ++i) {
            rotate(nums[i], k[i]);
            
            assert(nums[i] == expected[i], nums[i], expected[i]);
        }
    }
}

#endif /* RotateArray_hpp */
