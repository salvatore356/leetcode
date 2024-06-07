//
//  JumpGameII.hpp
//  LeetCode
//
//  Created by Salvatore on 7/6/24.
//

#ifndef JumpGameII_hpp
#define JumpGameII_hpp

#include <stdio.h>

namespace JumpGameII {
    
    int jump(vector<int>& nums) {
        if (nums.size() < 2) return 0;

        int maxJump = 0;
        int jumps = 0;
        int end = 0;

        for (int i = 0; i < nums.size() - 1; ++i) {
            maxJump = max(maxJump, i + nums[i]);

            if (end == i) {
                ++jumps;
                end = maxJump;
                if(maxJump >= nums.size()) break;
            }
            
        }

        return jumps;

    }

    void test() {
        vector<vector<int>> nums = {
            {2,3,1,1,4}, {2,3,0,1,4}, {2,1}, {1}, {1,3,2}, {2,3,1}
        };
        
        vector<int> expected = {2, 2, 1, 0, 2, 1};
        
        for (int i = 0; i < nums.size(); ++i) {
            int result = jump(nums[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* JumpGameII_hpp */
