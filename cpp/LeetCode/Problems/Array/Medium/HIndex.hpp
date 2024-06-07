//
//  HIndex.hpp
//  LeetCode
//
//  Created by Salvatore on 7/6/24.
//

#ifndef HIndex_hpp
#define HIndex_hpp

#include <stdio.h>

namespace HIndex {
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        int citedPapers = 0;

        for (int i = 0; i < citations.size(); ++i) {

            if(citedPapers >= citations[i]) break;
            citedPapers += citations[i] > 0;
        }
        return citedPapers;
    }

    void test() {
        vector<vector<int>> citations = {
            {3,0,6,1,5}, {1,3,1}, {100}, {0}, {1}, {11,15}, {4,4,0,0}
        };
        vector<int> expected = {3, 1, 1, 0, 1, 2, 2};
        
        for (int i = 0; i < citations.size(); ++i) {
            int result = hIndex(citations[i]);
            
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* HIndex_hpp */
