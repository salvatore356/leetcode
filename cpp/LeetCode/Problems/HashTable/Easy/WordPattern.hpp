//
//  WordPattern.hpp
//  LeetCode
//
//  Created by Salvatore on 25/4/24.
//

#ifndef WordPattern_hpp
#define WordPattern_hpp

#include <stdio.h>
#include "../../../Utils/Utils.hpp"

namespace WordPattern {
    
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> words;
        unordered_map<string, char> rev;

        int current = 0;
        string word = "";
        char key;
        for(int i = 0; i < s.size(); ++i){
            if(s[i] != ' ') word.push_back(s[i]);
            else if(word.size() > 0) {
                
                key = pattern[current++];
                if(rev.find(word) == rev.end() && words[key] == "") {
                    rev[word] = key;
                    words[key] = word;
                }

                if(rev[word] != key) return false;
                word = "";
            }
        }
        key = pattern[current];
        if(rev.find(word) == rev.end() && words[key] == "") {
            rev[word] = key;
            words[key] = word;
        }

        return (current + 1) == pattern.size() && words[key] == word;
    }

    void test() {
        vector<string> pattern = {
            "abba", "abba", "aaaa", "abba", "a", "abc", "jquery"
        };
        vector<string> s = {
            "dog cat cat dog", "dog cat cat fish", "dog cat cat dog",
            "dog dog dog dog", "a", "b c a", "jquery"
        };
        
        vector<bool> expected = {
            true, false, false, false, true, true, false
        };
        
        for(int i = 0; i < pattern.size(); ++i) {
            bool result = wordPattern(pattern[i], s[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* WordPattern_hpp */
