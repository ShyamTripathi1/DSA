# Time Complexity: O(N)
# Space Complexity: O(1)

class Solution:
    def missingNumber(self, array, n):
        expected_sum = n * (n + 1) // 2
        actual_sum = sum(array)
        return expected_sum - actual_sum