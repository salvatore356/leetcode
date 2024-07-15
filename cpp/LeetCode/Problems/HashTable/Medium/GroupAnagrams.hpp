//
//  GroupAnagrams.hpp
//  LeetCode
//
//  Created by Salvatore on 15/7/24.
//

#ifndef GroupAnagrams_hpp
#define GroupAnagrams_hpp

#include <stdio.h>

namespace GroupAnagrams {

    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        unordered_map<string, int> keys;

        for (int i = 0; i < strs.size(); ++i) {
            string key = strs[i];
            sort(key.begin(), key.end());

            int index = keys[key];
            if (index != 0) {
                ans[index - 1].push_back(strs[i]);
                continue;
            }

            keys[key] = ans.size() + 1;
            ans.push_back({strs[i]});
        }
        return ans;
    }

    void test() {
        vector<vector<string>> strs = {
            {"eat","tea","tan","ate","nat","bat"},
            {""},
            {"a"}
        };
        
        vector<vector<vector<string>>> expected = {
            {{"eat","tea","ate"},{"tan","nat"},{"bat"}},
            {{""}},
            {{"a"}}
        };
        
        for (int i = 0; i < strs.size(); ++i) {
            auto result = groupAnagrams(strs[i]);
            
            assert(result == expected[i], result, expected[i]);
        }

    }

}

#endif /* GroupAnagrams_hpp */
