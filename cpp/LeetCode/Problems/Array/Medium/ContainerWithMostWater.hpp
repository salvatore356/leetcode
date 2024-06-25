//
//  ContainerWithMostWater.hpp
//  LeetCode
//
//  Created by Salvatore on 20/6/24.
//

#ifndef ContainerWithMostWater_hpp
#define ContainerWithMostWater_hpp

#include <stdio.h>

namespace ContainerWithMostWater {
    
    int maxArea(vector<int>& height) {
        int left = 0;
        int right = (int)height.size() - 1;

        int area = 0;
        
        while (left < right) {
            area = max(area, (right - left) * min(height[left], height[right]));

            if (height[left] < height[right])
                ++left;
            else --right;
        }

        return area;
    }

    void test() {
        vector<vector<int>> height = {{1,8,6,2,5,4,8,3,7}, {1,1}};
        vector<int> expected = {49, 1};
        
        for (int i = 0; i < height.size(); ++i) {
            int result = maxArea(height[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* ContainerWithMostWater_hpp */
