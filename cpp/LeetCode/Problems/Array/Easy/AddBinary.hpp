//
//  AddBinary.hpp
//  LeetCode
//
//  Created by Salvatore on 22/5/24.
//

#ifndef AddBinary_hpp
#define AddBinary_hpp

#include <stdio.h>

namespace AddBinary {

    char sum_carry(char &a, char &b, char &carry) {
        int sum = (a - '0') + (b - '0') + (carry - '0');
        carry = '0';
        if (sum >= 2)  carry = '1';
        return (sum % 2) + '0';
    }

    string addBinary(string a, string b) {
        
        int max_len = (int) max(a.size(), b.size());
        while (a.size() < max_len) a = '0' + a;
        while (b.size() < max_len) b = '0' + b;

        char carry = '0';
        
        for (int i = max_len - 1; i >= 0; --i)
            a[i] = sum_carry(a[i], b[i], carry);

        if (carry == '1') a = '1' + a;
        
        return a;
    }

    void test() {
        vector<string> a = {"1010", "11"};
        vector<string> b = {"1011", "1"};
        vector<string> expected = {"10101", "100"};
        
        for (int i = 0; i < a.size(); ++i) {
            string result = addBinary(a[i], b[i]);
            assert(result == expected[i], result, expected[i]);
        }
        
    }
}

#endif /* AddBinary_hpp */
