import unittest

class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if not nums:
            return 0
        
        slow = 1 #count element not duplicates

        for fast in range(1, len(nums)):
            if nums[fast] != nums[fast-1]:
                nums[slow] = nums[fast]
                slow += 1

        return slow

class TestRemoveDuplicates(unittest.TestCase):

    def test_remove_duplicates(self):
        solution = Solution()
        
        test_cases = [
            ([1, 1, 2], [1, 2]),
            ([0,0,1,1,1,2,2,3,3,4], [0, 1, 2, 3, 4]),
            ([], []),
            ([1, 2, 3], [1, 2, 3]),
        ]
        
        for nums, expectedNums in test_cases:
            # Run the method and get the result
            k = solution.removeDuplicates(nums)
            
            # Check that the length of unique elements matches expected length
            self.assertEqual(k, len(expectedNums), f"Failed on input: {nums}")
            
            # Check that the modified nums matches expectedNums up to k
            for i in range(k):
                self.assertEqual(nums[i], expectedNums[i], f"Failed on input: {nums}")


if __name__ == '__main__':
    unittest.main()