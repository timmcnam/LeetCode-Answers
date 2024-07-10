# Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.
# 
#
# Example 1:
# 
# Input: haystack = "sadbutsad", needle = "sad"
# Output: 0
# Explanation: "sad" occurs at index 0 and 6.
# The first occurrence is at index 0, so we return 0.
#
# Example 2:
# 
# Input: haystack = "leetcode", needle = "leeto"
# Output: -1
# Explanation: "leeto" did not occur in "leetcode", so we return -1.
#
# Constraints:
# 1 <= haystack.length, needle.length <= 104
# haystack and needle consist of only lowercase English characters.
# 
# 
# 
# 





# Simple method: 
class Solution1:
    def strStr1(self, haystack: str, needle: str) -> int:
        return haystack.find(needle)
    


# another solution
class Solution2:
    def strStr2(self, haystack: str, needle: str) -> int:
        if not needle:
            return 0

        # Length of haystack and needle
        haystack_len = len(haystack)
        needle_len = len(needle)

        # Iterate through haystack
        for i in range(haystack_len - needle_len + 1):
            # Check if the substring from i to i + needle_len matches needle
            if haystack[i:i + needle_len] == needle:
                return i

        # If no match is found, return -1
        return -1
