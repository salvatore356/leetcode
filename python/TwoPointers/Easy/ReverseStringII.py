import unittest

# Simple (slicing)
class SolutionSimple(object):
    def reverseStr(self, s, k):
        s = list(s)
        for i in range(0, len(s), 2 * k):
            s[i:i + k] = reversed(s[i:i + k])

        return "".join(s)

# Two pointers
class Solution(object):
    def reverseStr(self, s, k):
        s = list(s)
        size = len(s)
        for i in range(0, size, 2 * k):
            left = i
            right = min(i + k - 1, size - 1)
            while left < right:
                s[left], s[right] = s[right], s[left]
                left += 1
                right -= 1

        return "".join(s)

class TestReverseStringII(unittest.TestCase):
    def test_reverse_str(self):
        test_cases = [
            ("abcdefg", 2, "bacdfeg"),
            ("abcd", 2, "bacd"),
            ("abc", 5, "cba"),
            ("a", 1, "a"),
            ("abcdefg", 1, "abcdefg"),
        ]

        for solution in (SolutionSimple(), Solution()):
            for s, k, expected in test_cases:
                self.assertEqual(solution.reverseStr(s, k), expected, f"{type(solution).__name__} failed on input: s={s}, k={k}")

if __name__ == '__main__':
    unittest.main()
