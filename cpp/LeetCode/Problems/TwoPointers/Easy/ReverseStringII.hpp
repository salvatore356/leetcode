//
//  ReverseStringII.hpp
//  LeetCode
//
//  Created by Salvatore on 22/9/26.
//

#ifndef ReverseStringII_hpp
#define ReverseStringII_hpp

#include <stdio.h>

namespace ReverseStringII {

    // Simple (copy)
    string reverseStr(string s, int k) {
        string ans = s;

        for (int i = 0; i < s.size(); i+=2*k) {
            int tope = min(k, (int)s.size()-i);
            for (int j = 0; j < tope; ++j) {
                ans[i+j] = s[i + tope - (j+1)];
            }
        }

        return ans;
    }

    // Two pointers
    string reverseStrV2(string s, int k) {
        int n1 = (int)s.size()-1;
        int k1 = k - 1;
        for (int i = 0; i < s.size(); i+=2*k) {
            int left = i;
            int right = min(i + k1, n1);

            while (left < right) {
                swap(s[left], s[right]);

                ++left;
                --right;
            }
        }

        return s;
    }

    void test(){
        vector<string> inputs = {"abcdefg", "abcd", "abc", "a", "abcdefg"};
        vector<int> ks = {2, 2, 5, 1, 1};
        vector<string> expected = {"bacdfeg", "bacd", "cba", "a", "abcdefg"};

        for (int i = 0; i < inputs.size(); ++i) {
            auto result = reverseStr(inputs[i], ks[i]);
            assert(result == expected[i], result, expected[i]);

            auto resultV2 = reverseStrV2(inputs[i], ks[i]);
            assert(resultV2 == expected[i], resultV2, expected[i]);
        }
    }
}

#endif /* ReverseStringII_hpp */
