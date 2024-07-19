//
//  MinimumNumberOfArrowsToBurstBalloons.hpp
//  LeetCode
//
//  Created by Salvatore on 19/7/24.
//

#ifndef MinimumNumberOfArrowsToBurstBalloons_hpp
#define MinimumNumberOfArrowsToBurstBalloons_hpp

#include <stdio.h>

namespace MinimumNumberOfArrowsToBurstBalloons {
    
    bool hasOverlap(int s1, int e1, int s2) {
        return s2 >= s1 && s2 <= e1;
    }

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());

        int count = 0;
        int s1, e1, s2;

        for (int i = 0; i < points.size(); ++i) {
            
            s1 = points[i][0]; e1 = points[i][1];
            for (int j = i + 1; j < points.size(); ++j) {
                s2 = points[j][0];
                if (!hasOverlap(s1 , e1,  s2)) break;
                s1 = max(s1, s2);
                e1 = min(e1, points[j][1]);
                i = j;
            }
            ++count;
        }

        return count;
    }

    void test() {
        vector<vector<vector<int>>> points = {
            {{10,16},{2,8},{1,6},{7,12}},
            {{1,2},{3,4},{5,6},{7,8}},
            {{1,2},{2,3},{3,4},{4,5}},
            {{9,12},{1,10},{4,11},{8,12},{3,9},{6,9},{6,7}}
        };
        vector<int> expected = {2, 4, 2, 2};
        
        for (int i = 0; i < points.size(); ++i) {
            int result = findMinArrowShots(points[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* MinimumNumberOfArrowsToBurstBalloons_hpp */
