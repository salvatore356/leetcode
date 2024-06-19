//
//  TwoSumIInputArrayIsSorted.hpp
//  LeetCode
//
//  Created by Salvatore on 19/6/24.
//

#ifndef TwoSumIIInputArrayIsSorted_hpp
#define TwoSumIIInputArrayIsSorted_hpp

#include <stdio.h>

namespace TwoSumIIInputArrayIsSorted {
    
    vector<int> twoSum(vector<int>& numbers, int target) {
        int left = 0;
        int right = numbers.size() - 1;

        int temp = left + right ;
        
        while (temp != target) {
            temp = numbers[left] + numbers[right];
            if (temp == target) return {left + 1, right + 1};
            else if (temp > target) --right;
            else ++left;
        }

        return {};
    }

    void test() {
        vector<vector<int>> numbers = {{2,7,11,15}, {2,3,4}, {-1,0}};
        vector<int> target = {9, 6, -1};
        vector<vector<int>> expected = {{1,2}, {1,3}, {1,2}};
        
        for (int i = 0; i < numbers.size(); ++i) {
            vector<int> result = twoSum(numbers[i], target[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* TwoSumIIInputArrayIsSorted_hpp */
