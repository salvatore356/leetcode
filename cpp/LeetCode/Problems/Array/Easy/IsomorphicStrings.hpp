//
//  IsomorphicStrings.hpp
//  LeetCode
//
//  Created by Salvatore on 24/4/24.
//

#ifndef IsomorphicStrings_hpp
#define IsomorphicStrings_hpp

#include <stdio.h>

namespace IsomorphicStrings {

    bool isIsomorphic(string s, string t) {
        vector<int> ascii(128), rev(128);
        for(int i = 0; i < t.size(); ++i){
            if(ascii[t[i]] == 0) {

                if(rev[s[i]] != 0) return false;
                ascii[t[i]] = s[i];
                rev[s[i]] = t[i];
            }
            t[i] = ascii[t[i]];
        }
        return s == t;
    }

    void test() {
        vector<string> s = {"egg", "foo", "paper"};
        vector<string> t = {"add", "bar", "title"};
        
        vector<bool> expected = {true, false, true};
        
        for(int i = 0; i < s.size(); ++i) {
            bool result = isIsomorphic(s[i], t[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* IsomorphicStrings_hpp */
