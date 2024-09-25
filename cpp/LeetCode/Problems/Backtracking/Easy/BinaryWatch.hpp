//
//  BinaryWatch.hpp
//  LeetCode
//
//  Created by Salvatore on 25/9/24.
//

#ifndef BinaryWatch_hpp
#define BinaryWatch_hpp

#include <stdio.h>

namespace BinaryWatch {
    string format(string value) {
        std::string hourBinary = value.substr(0, 4);
        std::string minuteBinary = value.substr(4, 6);

        // Convert binary strings to integers
        int hours = std::bitset<4>(hourBinary).to_ulong();  // Convert 4-bit binary string to integer (0-23)
        int minutes = std::bitset<6>(minuteBinary).to_ulong();

        if (hours > 11 || minutes > 59) return "";

        return to_string(hours) + ":" + (minutes < 10 ? "0" : "") + to_string(minutes);
    }

    void generateCombination(
        vector<string> &ans, int expected,
        string acum, int position, int count
    ) {
    
        if (count > expected) return;
        if (position >= acum.size()) {
            if (count == expected) {
                string time = format(acum);
                if (!time.empty()) {
                    ans.push_back(time);
                }
            }
            return;
        }
        
        generateCombination(ans, expected, acum, position + 1, count);
        acum[position] = '1';
        generateCombination(ans, expected, acum, position + 1, count + 1);
    }

    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        generateCombination(ans, turnedOn, "0000000000", 0, 0);
        return ans;
    }
    
    void test(){
        vector<int> turnedOn = {1, 9};
        vector<vector<string>> expected = {
            {"0:01","0:02","0:04","0:08","0:16","0:32","1:00","2:00","4:00","8:00"},
            {}
        };
        
        for (int i = 0; i < turnedOn.size(); ++i) {
            auto result = readBinaryWatch(turnedOn[i]);
            assert(result == expected[i], result, expected[i]);
        }
    }
}

#endif /* BinaryWatch_hpp */
