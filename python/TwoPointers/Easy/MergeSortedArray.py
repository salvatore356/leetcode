import unittest

class Solution(object):
    def merge(self, nums1, m, nums2, n):
        index1 = m - 1
        index2 = n - 1
        total = m + n - 1

        while index2 >= 0:
            if index1 >= 0 and nums1[index1] > nums2[index2]:
                nums1[total] = nums1[index1]
                index1 -= 1
            else:
                nums1[total] = nums2[index2]
                index2 -= 1
            total -= 1


class TestMergeSortedArray(unittest.TestCase):

    def test_merge(self):
        solution = Solution()

        test_cases = [
            ([1,2,3,0,0,0], 3, [2,5,6], 3, [1,2,2,3,5,6]),
            ([1], 1, [], 0, [1]),
            ([0], 0, [1], 1, [1]),
            ([2,0], 1, [1], 1, [1,2])
        ]

        for nums1, m, nums2, n, expectedNums in test_cases:
            # Run the method and get the result
            solution.merge(nums1, m, nums2, n)

            # Check that the length of unique elements matches expected length
            self.assertEqual(nums1, expectedNums, f"Failed on input: {nums1}")

            # Check that the modified nums matches expectedNums up to k
            for i in range(m + n):
                self.assertEqual(nums1[i], expectedNums[i], f"Failed on input: {nums1}")


if __name__ == '__main__':
    unittest.main()