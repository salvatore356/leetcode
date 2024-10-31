import unittest

class Solution(object):
    def strStr(self, haystack, needle):
        """
        :type haystack: str
        :type needle: str
        :rtype: int
        """
        size_haystack = len(haystack)
        size_needle = len(needle)

        slow = 0
        fast = 0

        while slow <= size_haystack - size_needle:
            fast = 0

            while fast < size_needle and haystack[slow + fast] == needle[fast]:
                fast += 1
            
            if fast == size_needle:
                return slow
            
            slow += 1

        return -1
    
    
class TestStrStr(unittest.TestCase):

    def test_strStr(self):
        solution = Solution()
        
        test_cases = [
            ("sadbutsad", "sad", 0),
            ("leetcode", "leeto", -1),
        ]
        
        for haystack, needle, expectedNum in test_cases:
            # Run the method and get the result
            k = solution.strStr(haystack, needle)
            
            # Check that the length of unique elements matches expected length
            self.assertEqual(k, expectedNum, f"Failed on input: {haystack}")
            


if __name__ == '__main__':
    unittest.main()