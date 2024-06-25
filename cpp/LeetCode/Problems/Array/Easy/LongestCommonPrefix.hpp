//
//  LongestCommonPrefix.hpp
//  LeetCode
//
//  Created by Salvatore on 18/4/24.
//

#ifndef LongestCommonPrefix_hpp
#define LongestCommonPrefix_hpp

#include <stdio.h>

namespace LongestCommonPrefix {

    string longestCommonPrefix(vector<string>& strs) {

        sort(strs.begin(), strs.end());
        string &front = strs.front();
        string &back = strs.back();
        int maxSize = (int)min(front.size(), back.size());

        string ans = "";

        for(int i = 0; i < maxSize; ++i){
            if(front[i] != back[i]) break;
            ans += front[i];
        }

        return ans;
    }

    void test() {
        vector<vector<string>> cases = {
            {"flower","flow","flight"},
            {"dog","racecar","car"}
        };
        
        vector<string> expected = {"fl", ""};
        
        for(int i = 0; i < cases.size(); ++i){
            string result = longestCommonPrefix(cases[i]);
            assert(result == expected[i], result, expected[i]);
        }
            
            
        
    }
}

#endif /* LongestCommonPrefix_hpp */
