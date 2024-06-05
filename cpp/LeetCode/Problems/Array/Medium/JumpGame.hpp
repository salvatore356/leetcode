//
//  JumpGame.hpp
//  LeetCode
//
//  Created by Salvatore on 5/6/24.
//

#ifndef JumpGame_hpp
#define JumpGame_hpp

#include <stdio.h>

namespace JumpGame {
    
    bool canJump2(vector<int>& nums) {
        for (int i = 0; i < nums.size()-1; ++i) {
            if (nums[i] == 0) {
                bool canSkip = false;
                for(int j = i - 1; j >= 0; --j) {
                    if (nums[j] > i-j) {
                        canSkip = true;
                        break;
                    }
                }
                if (!canSkip) return false;
            }
        }
        return true;
    }
    
    bool canJump(vector<int>& nums) {
        int jumps = nums.front();
        for (int i = 1; i < nums.size(); ++i) {
            if (jumps < i) return false;
            jumps = max(jumps, i + nums[i]);
        }
        return true;
    }

    void test(){
        vector<vector<int>> nums = {
            {2,5,0,0}, {2,0,0}, {0}, {3,2,1,0,4}, {2,3,1,1,4}
        };
        
        vector<bool> expected = {
            true, true, true, false, true
        };
        
        for (int i = 0; i < nums.size(); ++i) {
            bool result = canJump(nums[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* JumpGame_hpp */
