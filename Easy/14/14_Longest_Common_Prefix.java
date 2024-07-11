/* 
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, return an empty string "".

 

Example 1:

Input: strs = ["flower","flow","flight"]
Output: "fl"
Example 2:

Input: strs = ["dog","racecar","car"]
Output: ""
Explanation: There is no common prefix among the input strings.
 

Constraints:

1 <= strs.length <= 200
0 <= strs[i].length <= 200
strs[i] consists of only lowercase English letters.
 */

class Solution {
    public String longestCommonPrefix(String[] strs) {
        if (strs == null || strs.length == 0) {
            return "";
        }
        
        String res = strs[0];
        for (int x = 1; x < strs.length; x++) {
            res = PrefixFinder(res.toCharArray(), strs[x].toCharArray());
            if (res.isEmpty()) break;
        }
        return res;
    }

    public String PrefixFinder(char[] s1, char[] s2) {
        StringBuilder prefix = new StringBuilder();
        int minLength = Math.min(s1.length, s2.length);
        
        for (int i = 0; i < minLength; i++) {
            if (s1[i] == s2[i]) {
                prefix.append(s1[i]);
            } else {
                break;
            }
        }
        
        return prefix.toString();
    }
}


