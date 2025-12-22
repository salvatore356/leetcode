import unittest

class Solution(object):
    def reverseString(self, s):
        left = 0
        right = len(s) - 1
        while left < right:
            s[left], s[right] = s[right], s[left]
            left += 1
            right -= 1

class TestReverseString(unittest.TestCase):
    def test_reverse_string(self):
        solution = Solution()
        
        test_cases = [
            (["h","e","l","l","o"], ["o","l","l","e","h"]),
            (["H","a","n","n","a","h"], ["h","a","n","n","a","H"]),
            ([], []),
            (["a"], ["a"]),
        ]
        
        for s, expected in test_cases:
            original_s = list(s)
            solution.reverseString(s)
            
            self.assertEqual(s, expected, f"Failed on input: {original_s}")

if __name__ == '__main__':
    unittest.main()
