//
//  MergeIntervals.hpp
//  LeetCode
//
//  Created by Salvatore on 17/7/24.
//

#ifndef MergeIntervals_hpp
#define MergeIntervals_hpp

#include <stdio.h>

namespace MergeIntervals {
    bool hasOverlap(int s1, int e1, int s2, int e2) {
        return s2 >= s1 && s2 <= e1;
    }

    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        sort(intervals.begin(), intervals.end());
        int i = 0;

        for (; i < intervals.size(); ++i) {
            int s1 = intervals[i][0];
            int e1 = intervals[i][1];

            for (int j = i + 1; j < intervals.size(); ++j) {
                int s2 = intervals[j][0];
                int e2 = intervals[j][1];
                if (!hasOverlap(s1, e1, s2, e2)) break;
                
                s1 = min (s1, s2);
                e1 = max(e1, e2);
                ++i;
            }

            ans.push_back({s1, e1});
        }

        return ans;
    }

    void test() {
        vector<vector<vector<int>>> intervals = {
            {{1,3},{2,6},{8,10},{15,18}},
            {{1,4},{4,5}},
            {{1,4},{0,4}},
            {{2,3},{4,5},{6,7},{8,9},{1,10}}

        };
        
        vector<vector<vector<int>>> expected = {
            {{1,6},{8,10},{15,18}},
            {{1,5}},
            {{0,4}},
            {{1,10}}
        };
        
        for (int i = 0; i < intervals.size(); ++i) {
            auto result = merge(intervals[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* MergeIntervals_hpp */
