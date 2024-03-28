//
//  RemoveElement.hpp
//  LeetCode
//
//  Created by Salvatore on 28/3/24.
//

#ifndef RemoveElement_hpp
#define RemoveElement_hpp

#include <stdio.h>
#include "../../../Utils/Utils.hpp"

namespace RemoveElement {
    
    bool compareArrayToIndex(vector<int> &nums, vector<int> &expected, int index) {
        
        sort(nums.begin(), nums.begin() + index);
        sort(expected.begin(), expected.end());
        
        for(int i = 0; i < index; ++i)
            if(expected[i] != nums[i]) return false;
        
        return true;
    }
    
    int removeElementA(vector<int>& nums, int val) {
        
        int index = 0;

        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != val) {
                nums[index] = nums[i];
                ++index;
            }
        }
        return index;
    }


    int removeElementB(vector<int>& nums, int val) {
        
        int i = 0, j = nums.size() - 1, count = 0;

           for(; i <= j; ++i) {

               if(nums[i] == val){
                   for(; j > i; --j){
                       if(nums[j] != val) {
                           swap(nums[i], nums[j]);
                           break;
                       }
                   }
               }

               count += nums[i] != val;
           }

           
           return count;
    }

    void test() {
        vector<vector<int>> nums = {
            {3, 2, 2, 3},
            {0, 1, 2, 2, 3, 0, 4, 2},
            {},
            {2},
            {3, 3}
        };
        
        vector<int> val = {3, 2, 0, 3, 5};
        
        vector<vector<int>> expected = {
            {2, 2},
            {0, 1, 4, 0, 3},
            {},
            {2},
            {3, 3}
        };
        
        for(int i = 0; i < nums.size(); ++i) {
            int k = removeElementB(nums[i], val[i]);
            
            assert(
                compareArrayToIndex(
                    nums[i], expected[i], k
                ),
                nums[i], expected[i]
            );
        }
    }

}

#endif /* RemoveElement_hpp */
