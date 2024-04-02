//
//  RemoveDuplicatesFromSortedArray.hpp
//  LeetCode
//
//  Created by Salvatore on 2/4/24.
//

#ifndef RemoveDuplicatesFromSortedArray_hpp
#define RemoveDuplicatesFromSortedArray_hpp

#include <stdio.h>

namespace RemoveDuplicatesFromSortedArray {
    bool customJudge(
        vector<int> &nums, vector<int> &expected, int k
    ) {
        
        if( expected.size() != k) return false;
        
        
        for(int i = 0; i < k; ++i)
            if(expected[i] != nums[i]) return false;
        
        return true;
    }

    int removeDuplicates(vector<int>& nums) {
        
        int lastNonDuplicate = 1;

        for(int i = 1; i < nums.size(); ++i){
            lastNonDuplicate += ( nums[i] != nums[i - 1]);
            nums[lastNonDuplicate - 1] = nums[i];
        }

        return lastNonDuplicate;
    }

    void test() {
        vector<vector<int>> cases = {
            {1,1,2},
            {0,0,1,1,1,2,2,3,3,4}
        };
        
        vector<vector<int>> expected = {
            {1,2},
            {0,1,2,3,4}
        };
        
        vector<int> k_expected = {2, 5};
        
        for(int i = 0; i < cases.size(); ++i) {
            int k =  removeDuplicates(cases[i]);
            
            assert(
                customJudge(cases[i], expected[i], k),
                cases[i], expected[i]
            );
        }
    }
}

#endif /* RemoveDuplicatesFromSortedArray_hpp */
