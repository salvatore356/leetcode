//
//  InsertInterval.hpp
//  LeetCode
//
//  Created by Salvatore on 18/7/24.
//

#ifndef InsertInterval_hpp
#define InsertInterval_hpp

#include <stdio.h>

namespace InsertInterval {

    bool hasOverlap(int s1, int e1, int s2, int e2) {
        return s2 >= s1 && s2 <= e1;
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        
        bool inserted = false;
        for (int i = 0; i < intervals.size(); ++i) {
            if (newInterval[0] < intervals[i][0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                inserted = true;
                break;
            }
        }

        if (!inserted) intervals.push_back(newInterval);
        
        for (int i = 0; i < intervals.size(); ++i) {
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
            {{1,3},{6,9}},
            {{1,2},{3,5},{6,7},{8,10},{12,16}},
            {}
        };
        
        vector<vector<int>> newInterval = {{2,5}, {4,8}, {5,7}};
        
        vector<vector<vector<int>>> expected = {
            {{1,5},{6,9}},
            {{1,2},{3,10},{12,16}},
            {{5,7}}
        };
        
        for (int i = 0; i < intervals.size(); ++i) {
            auto result = insert(intervals[i], newInterval[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* InsertInterval_hpp */
