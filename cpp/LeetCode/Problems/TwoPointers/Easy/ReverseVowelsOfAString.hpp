//
//  ReverseVowelsOfAString.hpp
//  LeetCode
//
//  Created by Salvatore on 22/12/25.
//

#ifndef ReverseVowelsOfAString_hpp
#define ReverseVowelsOfAString_hpp

#include <stdio.h>

namespace ReverseVowelsOfAString {

    bool isvowel(char &v) {
        return  v == 'a' || v == 'A' ||
                v == 'e' || v == 'E' ||
                v == 'i' || v == 'I' ||
                v == 'o' || v == 'O' ||
                v == 'u' || v == 'U';
    }

    string reverseVowels(string s) {


        int left = 0;
        int right = s.size() - 1;

        bool lVowel, rVowel;

        while(left < right) {
            lVowel = isvowel(s[left]);
            rVowel = isvowel(s[right]);
            
            if (lVowel && rVowel) {
                swap(s[left], s[right]);
                ++left;
                --right;
                
            }else if (lVowel) {
                --right;
            }else if (rVowel) {
                ++left;
            } else {
                ++left;
                --right;
            }
        }

        return s;
    }
	
	string reverseVowelsV2(string s) {
		
		int left = 0;
		int right = s.size() - 1;

		while (left < right) {
			while (left < right && !isvowel(s[left])) left++;
			while (left < right && !isvowel(s[right])) right--;

			if (left < right) {
				swap(s[left], s[right]);
				left++;
				right--;
			}
		}
		return s;
	}
	
	void test(){
			vector<string> inputs = {"IceCreAm", "leetcode", ".,"};
			vector<string> expected = {"AceCreIm", "leotcede", ".,"};
			
			for (int i = 0; i < inputs.size(); ++i) {
					auto result = reverseVowels(inputs[i]);
					assert(result == expected[i], result, expected[i]);
			}
	}
}

#endif /* ReverseVowelsOfAString_hpp */
