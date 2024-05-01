//
//  ValidAnagram.hpp
//  LeetCode
//
//  Created by Salvatore on 1/5/24.
//

#ifndef ValidAnagram_hpp
#define ValidAnagram_hpp

#include <stdio.h>

namespace ValidAnagram {

    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        vector<int> dict (26);

        for(int i = 0; i < s.size(); ++i){
            ++dict[s[i] - 'a'];
            --dict[t[i] - 'a'];
        }
            
        for(int i = 0; i < dict.size(); ++i)
            if(dict[i] != 0) return false;
        
        return true;
    }

    void test() {
        vector<string> t = {"anagram", "rat"};
        vector<string> s = {"nagaram", "car"};
        vector<bool> expected = {true};
        
        for(int i = 0; i < t.size(); ++i){
            bool result = isAnagram(s[i], t[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* ValidAnagram_hpp */
