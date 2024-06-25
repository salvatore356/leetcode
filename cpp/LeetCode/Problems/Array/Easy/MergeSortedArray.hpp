//
//  MergeSortedArray.hpp
//  LeetCode
//
//  Created by Salvatore on 22/3/24.
//

#ifndef MergeSortedArray_hpp
#define MergeSortedArray_hpp

#include <stdio.h>
#include "../../../Utils/Utils.hpp"

namespace MergeSortedArray {
    
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int cur = (int)nums1.size();

        while(m > 0 && n>0){
            
            if (nums1[m - 1] >= nums2[n - 1]) {
                nums1[--cur] = nums1[--m];
            } else {
                nums1[--cur] = nums2[--n];
            }
            
        }
        while(n > 0) nums1[--cur] = nums2[--n];
    }

    void test() {
        vector<vector<int>> nums1 = {
            {1, 2, 3, 0, 0, 0},
            {1},
            {0}
        };
        
        vector<int> m = {
            3,
            1,
            0
        };
        
        vector<vector<int>> nums2 = {
            {2, 5, 6},
            {},
            {1}
        };
        
        vector<vector<int>> expected = {
            {1, 2, 2, 3, 5, 6},
            {1},
            {1}
        };
        
        for (int i = 0; i < nums1.size(); ++i) {
            
            merge(
                nums1[i], m[i], nums2[i], (int)nums2[i].size()
            );
            
            assert(
                compareArrays(nums1[i], expected[i]), nums1[i], expected[i]
            );
        }
        
        

    }
}

#endif /* MergeSortedArray_hpp */
