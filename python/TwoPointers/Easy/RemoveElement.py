import unittest

class Solution(object):
    def removeElement(self, nums, val):
        """
        :type nums: List[int]
        :type val: int
        :rtype: int
        """
        slow = 0 #count elements not equal to val

        for fast in range(len(nums)):
            if nums[fast] != val:
                nums[slow] = nums[fast]
                slow += 1
        
        return slow

class TestRemoveDuplicates(unittest.TestCase):

    def test_remove_duplicates(self):
        solution = Solution()
        
        test_cases = [
            ([3,2,2,3], [2, 2], 3),
            ([0,1,2,2,3,0,4,2], [0,1,3,0,4], 2),
            ([], [], 3),
            ([1, 2, 3], [1, 2, 3], 4),
        ]
        
        for nums, expectedNums, val in test_cases:
            # Run the method and get the result
            k = solution.removeElement(nums, val)
            
            # Check that the length of unique elements matches expected length
            self.assertEqual(k, len(expectedNums), f"Failed on input: {nums}")
            
            # Check that the modified nums matches expectedNums up to k
            for i in range(k):
                self.assertEqual(nums[i], expectedNums[i], f"Failed on input: {nums}")


if __name__ == '__main__':
    unittest.main()